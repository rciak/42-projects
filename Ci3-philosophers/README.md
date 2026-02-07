*This project has been created as part of the 42 curriculum by reciak.*

# Description

# Instructions

# Resources

## References

* Kerrisk, Michael. [*The Linux Programming Interface: A Linux and UNIX System Programming Handbook*](https://man7.org/tlpi/index.html). San Francisco: No Starch Press, 2010.

## AI usage

In the Scope of this project, AI was used to clarify some of the upcoming
technical questions and for documentation purposes. Regarding writing code,
AI was intentionally used in limited forms, like intelligent autocompletion or
occasionally during refactoring steps.

In particular, AI was used as assistant for the following tasks:

* Creating references in this README.md file.
* Doxygen documentation - Comments in source code.

An example of a
[conversation with Perplexity](#sample-conversation-with-perplexity)
can be found in the Appendix.

# Appendix

## Some interesting-looking questions for evaluations

1. Is it a good idea to *detach threads* that representing a philosopher,
   to *avoid* the thread equivalent of a *zombie* process?
2. Assume different threads need information stored in variables like
   `time_to_die`, `time_to_eat`, `time_to_sleep`, i.e. information
   that will never change after the corresponding variables once have been set.
   What are the pros. and cons. of the following two approaches:

   (a) Either access this variables via a pointer from all the threads?  
   (b) Copy them once to all of the threads stack and access the copied values.

3. Asssume having a programm with two threads `A` and `B`.

   (a) Do `A` and `B` share the heap, or do they have their own heap memory?  
   (b) Do `A` and `B` share the stack, or do they have their own stack memory?

   Global variables are forbidden in this project, but what do you think:  
   (c) Is a global variable shared between threads?  
   (d) What about static variables (instide a function)?

## Answers and notes

1. Caution: Likely the philo threads will access variables on the main thread's
   stack! Therefore main should not end before the other threads.

2. * (a) requires the use of mutexes, (b) requires (only) initial copying,
   * accessing speed / use of L1 / L2 / L3 caches, cf.
   [conversation with Perplexity](#sample-conversation-with-perplexity),
   * danger that the thread's individual stacks overflow should be not topic
     for the `philosopher` project.

3. *Not shared between threads:* stack - each thread has its own stack.  
   *Shared between threads:* heap-allocated, global and static variables.

## Sample conversation with Perplexity

### Original Query

In a C program with 201 threads and a struct of n long long variables (can either be allocated in the main function's stack or via malloc on the heap) that will never be changed again once they have been initialized, there are two possibilities:

a) Either access this struct via a pointer from all the threads start function  
or  
b) Copy them once to the threads stack and then access the copied values.

In which case access is likely to be faster?  
a) (but with the need to use mutexes)  
b) (not taking the initial time into account that is only once need to copy the values; really only about accessing and processing)

---

### Response 1: Initial Answer

Ignoring the one‑time copy cost, letting each thread work on its own stack copy (b) is generally faster than having all threads read a shared struct behind a mutex (a).

#### Why (b) is usually faster

* A mutex is very expensive compared to a simple memory read, especially when 201 threads contend on the same lock; each lock/unlock involves synchronization, cache‑coherence traffic, and potential blocking.  
* In your situation, the data are immutable once initialized, so there is no real need for synchronization to protect against data races; each thread can safely read its own copy without coordination.  
* Copying \(n\) small `long long` values once into each thread's stack frame is cheap compared to repeated lock/unlock operations while processing.  
* Stack vs heap location of the original struct is mostly irrelevant for access speed here; what dominates is whether you need synchronization and whether values are local to a thread.

#### When (a) could make sense

* If the struct were very large, so that copying to every thread's stack would risk stack overflow or consume too much memory, then sharing via a pointer (without a mutex, since data are read‑only) could be preferable.  
* If you truly must modify the data and keep it consistent across threads, you might need synchronization, in which case the cost of the mutex becomes unavoidable and design changes (e.g., per‑thread working copies, read‑mostly with rare writes, etc.) should be considered.

Given your description (read‑only data, many threads, focus on access/processing cost), per‑thread stack copies are the better choice for raw access performance.

---

### Follow-up Query 1

Can you please illustrate your thoughts also taking the different levels of processor memory caches into account?

### Response 2: Cache Analysis

Accessing per-thread stack copies (b) remains faster than shared access with mutexes (a), even when factoring in CPU cache levels (L1, L2, L3). Cache behavior amplifies the mutex overhead while favoring local copies.

#### Cache Impact on Option (a): Shared Pointer Access

Shared data resides at one address, likely in main's stack or heap, potentially cached in L3 (shared across cores).  
With 201 threads repeatedly accessing it under mutex lock/unlock:  

* Each access triggers cross-core cache coherence via MESI protocol—invalidating lines in other cores' caches, forcing reloads from L3 or DRAM.  
* Mutex contention causes many threads to spin or block, flushing unrelated data from L1/L2 and worsening cache thrashing.  
* Result: High latency (100s of cycles per access), poor L1 hit rates (~50% or worse under contention), and bandwidth waste on snooping traffic.

#### Cache Impact on Option (b): Per-Thread Stack Copies

Each thread copies \(n\) `long long`s (e.g., 8n bytes) to its own stack frame at thread start.

* Stack data is local to the thread's core, loaded once into that core's private L1 cache (hit latency ~4 cycles).  
* Repeated reads during processing stay in L1/L2 (no coherence traffic since data is thread-private and read-only).  
* For small \(n\) (e.g., <32 longs, ~256 bytes), the entire copy fits in L1 data cache; even larger fits L2 (~1MB/core). No mutex means zero synchronization cost.  
* Result: Near-optimal L1 hit rates (>95%), minimal latency (~5 cycles/access).

#### Cache Hit Latency Comparison

| Cache Level | Typical Latency (cycles) | Option (a) Usage | Option (b) Usage |
|-------------|---------------------------|------------------|------------------|
| L1 (private) | 4 | Rare (coherence evicts) | Dominant |
| L2 (private) | 12 | Occasional fallback | Backup |
| L3 (shared) | 40 | Frequent (snooping) | Never |
| DRAM | 200+ | On misses/contention | On initial copy only |

#### Key Tradeoffs with Caches

Copying to stacks is a one-time cost (fits L1 easily, ~200-1000 cycles total), dwarfed by repeated shared accesses.  
If \(n\) is huge (e.g., >1MB/thread), stack overflow or L1 pollution could hurt (b)—then use heap-per-thread or read-only shared without mutex (still beats locking).  
Modern CPUs (Intel/AMD) optimize stack access heavily, making (b) the clear winner for 201 read-heavy threads.

---

### Follow-up Query 2

I forgot to mention that there are 201 stacks (created with pthreat_create) but that on the hardware side there are only 4 cores. Please take this also into acount and check if this has any influence to your previous reasonings.

### Response 3: 4 Cores / 201 Threads Analysis

With 201 threads on 4 cores (heavy oversubscription, ~50 threads/core), option (b)—per-thread stack copies—remains significantly faster than option (a)—shared access with mutexes—for read-only data access/processing.

#### Why Oversubscription Doesn't Change the Conclusion

Thread oversubscription means aggressive context switching (every few ms) and scheduler queuing, but this impacts both options similarly as baseline overhead.  
The key difference persists: (a) requires costly mutex contention among 201 threads fighting for one lock (exponential backoff, spinning, blocking), while (b) has zero synchronization.  
Each core rapidly cycles through ~50 threads via context switches, but local stack data per thread still loads into L1/L2 upon reactivation (stack frames are small, ~KB, and CPU TLBs track them efficiently).

#### Updated Cache Behavior Under 4 Cores / 201 Threads

* **Option (a) worsens dramatically**: L3 cache (shared across 4 cores) becomes a hotspot. Mutex acquires trigger MESI snoop storms across cores; 201 threads amplify lock wait queues, causing 1000s of cycles/core in futile spinning. Cache pollution from scheduler + unrelated thread data tanks hit rates (<30%).
* **Option (b) holds strong**: Each thread's stack copy (~64n bytes for longs) is private. On context switch-in, it reloads to that core's L1/L2 (quick for small data; stacks often stay hot in L2). No inter-core coherence needed. Oversubscription adds minor TLB flushes, but L1 hits dominate during processing bursts (~4-12 cycles/access).

#### Performance Comparison Table (Adjusted for Oversubscription)

| Aspect              | Option (a): Shared + Mutex (201 on 4 cores) | Option (b): Per-Thread Stack Copies |
|---------------------|---------------------------------------------|-------------------------------------|
| Sync Overhead       | Crushing (~10k cycles/lock per core avg.)  | None                               |
| L1 Hit Rate         | Poor (~20-40%; thrashing)                  | High (~90%+; local data)           |
| Context Switch Cost | High (mutex state + cache evict)           | Low (just stack reload)            |
| Total Access Latency| 500-2000+ cycles/read                      | 5-50 cycles/read                   |

#### Practical Caveats with 201 Threads on 4 Cores

Copying to 201 stacks is still cheap upfront (~few μs total), but oversubscription itself kills scalability—throughput drops vs. 4 threads.  
For huge \(n\) (e.g., >100KB/thread), per-thread heap allocation beats stack to avoid overflows, but principle holds: private copy > shared lock.  
Test with `perf` or `valgrind --tool=callgrind` to confirm; real perf hinges on your workload's read frequency.
