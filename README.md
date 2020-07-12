# Sudoku-Solver
## General info
The goal of the project was to handle Sudoku problem. Only classic boards with nine rows, nine columns and nine 3x3 squares were considered. 
For more info about Sudoku check [wikipedia page](https://en.wikipedia.org/wiki/Sudoku).

## Project structure
In the whole project there are four classes:
* Sudoku,
* Checker,
* Solver,
* Generator.

The basic class is **"Sudoku"**, which stores board as three different "uniqueContainers". "Unique container" is **std::array** of nine **std::arrays**,
which should have unique values from 1 to 9 (in this project 0 value was considered as an empty cell). There were three "uniqueContainer", because values must be different in arows, columns
and squares. "Sudoku '' class has methods to solve board and check if the board is properly solved. They were realized by classes **"Solver"** and **"Checker"**, which takes a pointer to 
"Sudoku" class as a constructor parameter. They are also defined as friends of "Sudoku" class, so they can access and modify (checker can only access, because have pointer to const object)
all three "uniqueContainers" and avoid unnecessary copying. The fourth class is **"Generator"**, which provides new sudoku's boards.

## Solving algorithm
In this project simple backtracking (brute force) algorithm was used. For more details check [wikipedia page](https://en.wikipedia.org/wiki/Sudoku_solving_algorithms#Backtracking).

## Generating algorithm
Generating algorithm is not finished yet. Actually it only read randomly choosing, solved Sudoku boards from the file. 
**TODO list:**
* columns and rows permutation after reading board from file (columns and rows with numbers 1-3, 4-6,7-9 can be shuffled with each other),
* randomly clear cells to get board with specified number of filled cells,
* based on a backtracking algorithm create functionality that checks the number of Sudoku possible solutions (generated board should have one solution),
* try to relate generating operation more with level of difficulty than number of cells.
