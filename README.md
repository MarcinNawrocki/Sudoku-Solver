# Sudoku-Solver
## General info
The goal of the project was to handle the Sudoku problem. Only classic boards with nine rows, nine columns and nine 3x3 squares were considered. 
For more info about Sudoku check [wikipedia page](https://en.wikipedia.org/wiki/Sudoku).

## Project structure
In the whole project there are five main structs/classes and one interface:
* SudokuHandler,
* I_OneTaskClass,
* Checker,
* Solver,
* Generator.

The base of the project is the SudokuBoard structure. It contains three  "uniqueContainers". "Unique container" is **std::array** of nine **std::arrays <int,9>**,
which should have unique values from 1 to 9 (in this project 0 value was considered as an empty cell). There were three "uniqueContainer", because values must be different in a rows, columns and squares. This structure also provides apropriate method to set and get values.
The main class is **"SudokuHandler"**, which stores SudokuBoard object and pass it as pointer to one of the "OneTaskClasses"(Checker, Solver, Generator) in order to perform specified operation on the board. All "OneTaskClasses" inherit from OneTaskClass interface virtual function Proceed_operation().

## Solving algorithm
In this project a simple backtracking (brute force) algorithm was used. For more details check [wikipedia page](https://en.wikipedia.org/wiki/Sudoku_solving_algorithms#Backtracking).

## Generating algorithm
Generating algorithm read randomly choosed, solved Sudoku boards from the file. 
