# Flight Simulator - Part One
### Credit:  Inbar Avital and Noam Yakov
## Description:
This is a C++ project that execute FlightGear commands that are given from a file.
The compiler we created supports the following commands:
* OpenDataServer
* ConnectControlClient
* If Conditions
* While Loops
* Sleep
* Print
* Functions
* Variables (Optional - Binding the simulator's variables)
## Installation and Running
Install the files clicking the green "***clone or download***" button, and choose the preffered option.

#### Compile the program using this command:
> g++ -std=c++14 */*.cpp *.cpp -Wall -Wextra -Wshadow -Wnon-virtual-dtor -pedantic -o a.out -pthread

#### and then run it with:
> ./a.out fly.txt
```(change the fly.txt file to match your file name)```
