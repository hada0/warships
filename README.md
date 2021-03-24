Ada Warships - by Hongann Dao
---
####Contents
 1. Challenge Outline
 
 2. Development
 
 3. Evaluation
    
#### 1. Challenge Outline
 
 The objective of this project was to create a game system that has the same baseline rules as Battleships. The aim of
 game is to sink your opponent's placed battleships by targeting coordinates. In addition to this the game was implemented
 with the following additional requirements:
 - Players must be able to visualise their ship board and target board in order to make informed decisions on their
 target.
 - Players must be able to see the status of their own ships including a ship's health points.
 - Players must be able to auto-fire at valid coordinates.
 - Players must be able to auto-place their ships when setting up the board.
 - All inputs and configuration settings must be validated.
 - Players are able to choose from 2 game modes:
    - Player vs Computer (1 player game)
    - Player 1 vs Player 2 (2 player game)
    - Quit game.
 - Players are able to quit and reset the game.
 
 Based on these requirements and the time constraints of the project, a combination of approaches were used;
 agile and iterative software development was first where each component was built and unit tested, and often iterated
 over to improve efficiency or identify bugs.With each complete
 component integration tests were carried out to ensure classes and units were communicated as expected. Due to the agile
 nature, the design of the project was initially very abstract. The project was compartmentalised into these four 
 classes: configuration, player board, utilities which were the key categories in which methods and attributes was split.
 This prioritised the requirements of the product. Layering the iterative approach on top of this meant that areas that
 could be refactored to improve efficiency or re-usable code could be addressed once the minimum requirements were achieved.
 In the iterative stage, the code would be refactored to increase abstraction.
 
 The design initially started by breaking it down into 3 epics: the board, the players and the game setup. These would need
 to communicate with one other using the C++ pointers and references, which also meant there is a reduction code
 duplication. In addition to this, each ship was planned to be hardcoded in a map that would represent the ship types
 mapped to their characteristics. This would provide access to the ships. A UML diagram is shown below with demonstrating
 each class' dependencies.
 
 ![alt text](https://github.com/hada0/warships/blob/main/img/uml.png "abstract uml")
 
 The project was decomposed into the following steps:
 1) Define the key components of the game: board, player, setup, ship structure.
 2) Categorise relevant actions (methods) into each class.
 3) Set up a default configuration object that will be used for testing across the project.
 4) Implement `board`.
 5) Implement `player` and create boards for the player.
 6) Integrate the config settings into `player` to be passed into `board` so they are using the same data.
 7) Test each new integration.
 
 #### 2. Development
 From the initial planning process, it was decided to create a utilities class which would contain all the static methods
 that would be used and re-used across the game. This contains constants that will be used across files, the use of constants
 means there are fewer bugs when there is no intention of mutating the values for example, REGEX comparators. Methods are also
 added here when it doesn't depend on an object and may also be re-used across difference packages. Not only is this a
 good programming practice, it also reduces clutter in other classes that might use it. This has encouraged encapsulation,
 where each class is organised in it's own directory / package to maintain it's organisation for future scalability. New
 files can be added to each package depending on relevance, and only methods that apply to the attributes of that class
 are included in that package. This also helps readability of the program for example, to clearly identify when methods are changing
 the state of the player or the state of the board. 
 
 The methods included in the `utils` class as also encouraged abstraction of code for example in method `utils::parseCoordinates(std::string coordinates)`:
 ```
std::vector<int> utils::parseCoordinates(std::string str) {
        std::string tmp;
        std::vector<int> items;
        int x = 0, y = 0;
        std::smatch match;
        if (std::regex_search(str, match, coordinates)) {
            x = convertAlphaToInt(match.str(1));
            y = std::stoi(match.str(2)) - 1;
        }
        items.push_back(x);
        items.push_back(y);
        return items;
    }
```
The caller of this method only needs to be aware that this method will provide a vector of x and y coordinates based on the 
string version of those coordinates. This is a method that is used across many files and improves readability greatly by
removing clutter. This design principle is used across the codebase particularly with duplicated code. In this case,
modularisation is used to clearly indicate independent classes, methods and constants. With maximum abstraction and modularisation,
a class can be easily and quickly debugged, especially as the workspace becomes larger with more files.

More general good coding practices were also considered during implementation for building separate validators for each input
and providing informed and relevant error responses to guide the players to the solution. Helper methods are used in all
classes, which may also be re-used. For example `player::placeNode` and `player::fire` are both used `player::autoplace`
and `player::autofire` respectively. Not only are these methods usable independently, they are also re-used as helpers in the mentioned methods.
Additionally, naming of methods are also carefully thought out to provide enough context on what the method does.

##### Phase 1 Development: Board
The implementation started with defining the board and decided what attributes and methods should be stored. Attributes in a board are:
- width
- height
- grid (representation of the player's boards)
   
Functionalities implemented here generally change the state of the class. These include:
- creating an empty board: ready to be populated with ships.
- displaying the board: printing the grid in a readable formate
    
Initially ships were planned to be added into a map but to encourage object oriented design, a `ship` struct was created instead. This would store all 
the relevant attributes and also enable construction of new ships whenever needed. Additionally, any changes to the ship's state can also be
accessed by passing a reference to the object. This `ship` struct lives inside the `board` class it is used most often in assigning each ship to a board cell.
It was soon realised that there would need to be an additional structure to be used to populate the board's grid. Struct `ship` could not be used for this
because of the possibility of a node being of state `MISS` and `HIT` as well as the ship. To handle this, an enum was initially created to represent a `node`
where different possibilities were `HIT`, `MISS`, `CARRIER`, `BATTLESHIP`, `SUBMARINE`, `DESTROYER`, `PATROL`, and `EMPTY`. An enum was chosen due to it's 
compatibility with switch cases. However this was quickly replaced with another struct in order to set other attributes that would affect placing nodes on the board
such as the length of the ship.

Multiple helper methods are also included here e.g. `getNodeStateAtCoordinates` and `printCellValue`. A big challenge of this part was formatting the grid to display.
An open source library called `Tabulate` was used which set up borders according to the size of the grid. This made the graph much easier read. In
later iterations, the `displayBoard` method was updated to handle formatting of larger boards.

##### Phase 2 Development: Setup
The next part of the implementation involved creating a configuration class that reads an .ini file. It was first attempted by importing an open source .ini file
parser but this was unsuccessful due to compatability issues with mac OS. Instead a default configuration setting was used in order to continue to implement and test
the system. The `player` class was designed to take a configuration object as an argument in it's constructor. It's then able to set it's characteristics e.g. height
and width for that player. During the set up, a target board and ship board is also created using the height and width in the configuration. Once an end-to-end flow was working,
this stage was revisited to implement an .ini parser by using std::ifstream. 

##### Phase 3 Development: Player
At this stage, the majority of the backbone had been set up. The actions that would change the state of the game all live in the `player` class. The player has attributes:
- config (for setup)
- target board: used to records shots fired
- ships board: used to display the player's ships
- ship library: contains all ships that are in play

Functionalities include:
- setup (configuration)
- displaying player libraries
- resetting the player ship boards to place new coordinates for ship placement.
- placing ships from the library.
- autoplace all the ships that have not been placed (including all of them)

In this class, these were the first functions implemented and tested. It had been decided early on to take advantage of the C++ common use of references to
improve code efficiency. At any given time where action would change the state of a ship (e.g. ship placement will set "deploy" to , the reference to that object was
used to make any updates 'globally'.

To autoplace a ship, a random coordinate is generated (from `utils` class) and the value is validated to ensure that there is no existing
ship in that cell or any other cells it might use up. In this section of the code, there was a consistent flakiness for
approximately 50% of the program runs being made. This was due to the `utils::randomCoordinatesGenerator` where there was lack of randomness, possibly because to the seeding technique
being based on `time(NULL)`). To resolve this, an instance of the Mersenne Twister `std::mt19937`, a psuedorandom number generator, was use to get as close to true randomness
as possible. With the addition of this, flakiness was reduced significantly. The biggest challenge was familiarising myself with pointers and references and learning
to use them to my advantage rather than make copies of objects for analysis. Similarly to the previous phases, there were iterations
to tidy, fix and improvement readability.

Continuing on to the remaining methods to complete, the auto-fire method introduced many new challenges as I was now using a reference
to another player class to check if a `fire` was successful. This became very complicated to track and a significantly bug had been identified - there was no way to track the ship's that had been "sunk" so 
a counter was introduced to keep track of the number of ships the player had sunk.

Another unresolved bug was the technique used to reference a `node` and reduce the health of the node which would be reflected on all
points where that node is stored on the grid. However, the logic for this became very complicated because of reference sharing. Because of the limited time,
a brute force approach was taken and a much simpler, but less efficient design was implemented. This would then be revisited when the agile 
cycle was complete. The program now iterates through a list of coordinates that each ship owns. The coordinates represent all the
cells that the said ship is placed at. If there is a coordinate that matches during this iteration, the health of that ship is reduced by 1 via a reference to it in 
the library.

##### Phase 4 Development: End to End Testing
As previously mentioned, the each method built was unit tested and as the program expanded, integration tests were often carried out
with different pathways and walkthroughs. It was during these times, many bugs presented themselves, and edge cases that were not yet accounted for. These were all logged in a `BUGLOG.txt`
to make sure they were addressed if not at the moment.
For the first mode of the game (Player vs Computer)
I first implement one player menu, validation and game process. Once that was working successfully and as intended, similar logic was set in place for the computer and further on, similarly 
for the two player game.

When first testing with larger boards, the alignment of the axis and header was offset significantly because of the values of the headers
going from a single-letter and single-number types e.g. 'A6' and 'F4' to double-letters and double-digits e.g. 'AD2' and 'D16'. Through many iterations, 
the correct padding was set for the y-axis. The alphabet headers provided a more difficult task because there had to be a way to write 'AD'
in one space. The solution for this was to split the double-letter up and align them in a column so that both values only appeared in one space. See below
for the result.

 ![alt text](https://github.com/hada0/warships/blob/main/img/alpha_headers.png "headers on larger boards.")

 #### 3. Evaluation
 Although refactorings were made continuously throughout, `main.cpp` has a lot of duplicate code which could be condensed to
 re-use sections of code. For example Player 1 logic:
 ```
player1Turn:
                std::cout << "*********************************** P L A Y E R  1 ***********************************" << std::endl;
                std::cout << "It's Player 1's turn. Enter coordinates to target, enter A to autofire or enter Q to quit the game."
                          << std::endl;
                std::cin >> targetCoordinates;
                targetCoordinates = utils::coordinatesToUpper(targetCoordinates);
                if (targetCoordinates == "A") {
                    p1.autoFire(*p2.getShipsBoard(), p2.shipLibrary);
                    p2.displayPlayerBoards("PLAYER 1");
                    goto endPlayer1Turn;
                } else if (targetCoordinates == "Q") {
                    std::cout << "GAME QUIT." << std::endl;
                    return 0;
                }
                if (!utils::validateCoordinatesFormat(targetCoordinates)) {
                    std::cout << "Invalid coordinates format. Please try again." << std::endl;
                    goto player1Turn;
                }
                if (!p1.validateFire(targetCoordinates)) {
                    std::cout << "Invalid target. Coordinates has been hit previously." << std::endl;
                    goto player1Turn;
                }
                p1.fire(*p2.getShipsBoard(), p2.shipLibrary, targetCoordinates);
                p1.displayPlayerBoards("PLAYER 1");

            endPlayer1Turn:
                if (p1.remainingOpponentShips == 0) {
                    victor = "PLAYER 1";
                    goto end2PlayerGame;
                }
                std::cout << "Enter X to end your turn." << std::endl;
                std::cin >> endTurn;
                if (!(endTurn == "X" || endTurn == "x")) {
                    goto endPlayer1Turn;
                }
```
is almost identical to player 2 logic apart from the objects being called. There are two improvements that would've been made here:
1) Use polymorphism to create an abstract class for `player`. The methods could be overridden to behave differently for a "computer" player.
This would reduce the duplication of code.
2) Refactor into a method e.g. `PlayerTurn(player player1, player opponent)` which would improve the readability of the `main.cpp` file. I definitely
think it could be tidier with more abstraction.
In hindsight, it would've been much more efficient and time-saving to start with an abstract class for player which could be used to implement 
`COMPUTER` functionality as well as `PLAYER` functionality.

A significant portion of the time on this project was focused on displaying the graph and tables. As someone who values user experience,
it was important to ensure the players had an aesthetic display that was easy to read and understand. The image below shows a player's 
boards and ship library status.

![alt text](https://github.com/hada0/warships/blob/main/img/player_boards.png "player boards")

This is not only true for the display,
methods and helper methods throughout the code was written with the user in mind - questions such as "Will the user understand the purpose of this method
without having to delve into the lower levels of abstraction?" and "Is this simplified as much as possible for the user to use easily?". A simple example of this
is the Menu functionality.

![alt text](https://github.com/hada0/warships/blob/main/img/warships_menu.png "user menu snippet")

The options here have been limited to single character entries to keep it as simple as possible and avoid human errors such as spelling.
It also accepts both lowercase and uppercase values, again, to reduce the likelihood of human errors.

There were many iterations that involved moving methods between classes, particularly between `player` and `board`. The aim of this was to 
maximise cohesion and communication within each module. This was initially a very indecisive process as many methods depend on attributes of both `player` and `board`.

Although low coupling is ideal, the relationship between `configuration` and `player` and `board` could be minimised. In this 
version, `configuration` data is being passed to `board` through `player`. An alternative solution to this would be to create
a singleton and use the instance in both `player` and `board` classes. Another negative noticed is using computation in `while` loops when
defining the conditions. Generally this should be separated i.e. create a `bool` variable to represent a validation test to avoid potential infinite loops.

There are still many improvements to be made within the code design. In summary, the key potential improvements would be:
1) Use polymorphism to construct players instead of duplicating very similar code.
2) 'Hiding' code in abstracted methods and helper functions to present a cleaner, more readable `main.cpp` file that will clearly indicate the code flow.
3) Reducing coupling between classes.

#### 1. Running in replit.