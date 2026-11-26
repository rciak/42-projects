_This project has been created as part of the 42 curriculum by reciak._

# Description

The project __NetPractice__ provides a posibility to discover the
very basics of networking in order to be able to solve 10 educational puzzles
of increasing difficulty.
Each puzzle presents a malfunctioning network that might contain different
devices that are connected locally to each other and potentially also to
the Internet. The task is to reconfigure the network to fix it,
i.e. to make both forward and backward communication in
all requested connections working properly.

# Instructions

Both the training phase and the evaluation happen via a locally installed
application accessed by an webinterface.

## Installation and starting of the NetPractice Application

*students* (or persons having access to the 42 intra) can install it as
follows:

1. **Log in** to the 42 intra and navigate to the NetPractice project page,
2. **Download the bundle** of files provided there
   (as of 26.11.2026 this is named `net_practice.1.10.tgz`),
3. **Unpack that bundle**.
4. Open the extracted folder, navigate to `run.sh` and run it from a terminal.

Then the default browser should open the starting interface of
NetPractice. In case that the script is not working try to run

```bash
python3 -m http.server 49242
```

(with a possible change the port number), then launch in your web
browser to the URL `http://localhost:49242` (with addoption of the port
if needed), cf. the subject sheet, pdf Version 6.3.

## Submission details and Practical hints

Remember to __enter your username__ at the _starting interface_ and be aware
of the subject requiring a copy of your solution to each of the 10 provided
puzzles. Before continuing to the next level it is therefore important to
__save the solution__ of the previous puzzle by clicking on the `Get my config`
button, exporting it to a configuration file. All these 10 configuration files
(one per level) must be placed at root of your submission repository.

For requirements on the `README.md` and further submission details,
cf. the subject pdf.

After finishing the 10 puzzles in _training mode_ it is strongly recommended
to practice in _evaluation_ mode.
Note that each run of level will challenge you with new (random) IP addresses!

# Resources

## Important notions in networking

The following concepts needs to be studied and understood to pass the project
confidently:

- TCP/IP addressing
- subnet masks
- default gateways
- routers and switches

Also worthwhile is to get an idea what
- OSI layers
exist.

### TCP/IP addressing



### subnet masks

- CIDR mask

### default gateways

### routers and switches

### OSI layers

## Some usefull links




## Acknowledgements

I would like to acknowledge all students of 42 Vienna helping in understanding
basic concepts of networks and offering tipps to solve the levels in the speed required in the evaluations. In particular I would like to thank Mária Kamilla Huszár,Kateryna Huk, Lukas Wittwer and Maria Arapovic.

## References



## Usage of AI

AI was partially used to get an idea about new notions like e.g.

- default gateway
