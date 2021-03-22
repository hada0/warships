The purpose of this README is to track the changes and decisions made during development of warships.

Initial:

Struct "SHIP" and ENUM types for each state.

Update: Change the struct SHIP to a node struct which can also be a

BUG - Sometimes out of range vector occurs when computer generates random coordinates. The rate at which coordinates
are found varies. If this happens, re-run the program.

BUG - Replacement of ships: autoplace doesn't re-randomise.

BUG - Flakiness in runs. Terminates with error: libc++abi.dylib: terminating with uncaught exception of type std::out_of_range: vector.
If this happens, re-run the program.