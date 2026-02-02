*This project has been created as part of the 42 curriculum by reciak.*

# Description

# Instructions

# Resources

## References

* Kerrisk, Michael. [*The Linux Programming Interface: A Linux and UNIX System Programming Handbook*](https://man7.org/tlpi/index.html). San Francisco: No Starch Press, 2010.

## AI usage

In the Scope of this project, AI was used to clarify some of the upcoming technical questions and for documentation purposes.
In particular, AI was used as assistant for the following tasks:

* Creating references in this README.md file.
* Doxygen documentation - Comments in source code.

# Appendix

## Some interesting-looking questions for evaluations

1. Is it a good idea to *detach threads* that representing a philosopher,
   to *avoid* the thread equivalent of a *zombie* process?

## Answers and notes

1. Caution: Likely the philo threads will access variables on the main thread's
   stack! Therefore main should not end before the other threads.
