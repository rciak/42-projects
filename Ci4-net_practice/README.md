_This project has been created as part of the 42 curriculum by reciak._

# Description

The project __NetPractice__ provides a posibility to discover the
very __basics of networking__ in order to be able to solve 10 educational
network puzzles of increasing difficulty.
Each puzzle presents a malfunctioning network that might contain different
devices that are connected locally to each other and potentially also to
the Internet. The task is to reconfigure the network to fix it,
i.e. to make both forward and backward communication in
all requested connections working properly.

# Instructions

Both the training phase and the evaluation happen via a locally installed
application accessed by an webinterface.

## Installation and starting of the NetPractice application

_students_ (or persons having access to the 42 intra) can install the
NetPractice application as
follows:

1. __Log in__ to the 42 intra and navigate to the NetPractice project page,
2. __Download the bundle__ of files provided there
   (as of 26.11.2026 this is named `net_practice.1.10.tgz`),
3. __Unpack that bundle__.

To start the application open the extracted folder,
navigate to `run.sh` and run it from a terminal.
Then the default browser should open the starting interface of
NetPractice. In case that the script is not working try to run

```bash
python3 -m http.server 49242
```

(with a possible change the port number), then launch in your web
browser to the URL `http://localhost:49242` (with addoption of the port
if needed), cf. the subject sheet, pdf Version 6.3.

## Submission details and practical hints

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
Note that in evaluation mode each run of level will provide a kind of new
challenge in from of new (random) IP addresses!

# Resources

## Important notions in networking

The following concepts needs to be studied and understood to do the
puzzles and pass the project
confidently:

- TCP/IP addressing (*)
- subneting and subnet masks
- default gateways
- routers and switches

Also worthwhile is to get an idea what
__OSI layers__ are and how they are grouped to __TCP/IP Layers__.

__Annotations to (*):__
The abbreviation __TCP__ is short for _Transmission ControlProtocol_,
whereas __IP__ stands for _Internet Protocol_.

## Usage of AI

AI was partially used to get an idea about new notions like
 e.g. default gateway.

## References

Some useful videos include the following ones by Thuggonaut and Network Chuck

- [NetPractice: An Intro to IP Addresses and Subnets](https://www.youtube.com/watch?v=HQUw0CfQWAM)

- [You Suck at Subnetting](https://youtube.com/playlist?list=PLIhvC56v63IKrRHh3gvZZBAGvsvOhwrRF&si=0ORxK-Ww8yYSrYGn)

Further I would like to mention an English and two German wiki pages

- [List of reserved IP addresses](https://en.wikipedia.org/w/index.php?title=List_of_network_protocols_(OSI_model)&oldid=1381424795)

- [OSI-Modell](https://de.wikipedia.org/wiki/OSI-Modell](https://de.wikipedia.org/w/index.php?title=Internetprotokollfamilie&oldid=259582030))

- [Internetprotokollfamilie und TCP/IP-Referenzmodell](https://de.wikipedia.org/w/index.php?title=Internetprotokollfamilie&oldid=259582030)

The latter contains a nice table that visualizes which ISO layers are grouped
into one TCP/IP layer.

# Acknowledgements

I would like to acknowledge all students of 42 Vienna helping in understanding
basic concepts of networks and offering tipps to solve the levels in the speed
required in the evaluations. In particular I would like to thank
Mária Kamilla Huszár,Kateryna Huk, Lukas Wittwer and Maria Arapovic.
