#ifndef SUDOKU_H
#define SUDOKU_H

#include<iostream>
#include <array>
#include<set>
#include<algorithm>
#include<stack>
//declaring alias for unique containers
using uniqueContainer = std::array<std::array<int,9>,9>;
using sampleContainer = std::array<int,81>;

struct ModifiedCell{
    std::set <int> triedValues;
    int actual_Value;
    int row;
    int col;
    int square;
    bool searchNew;

    ModifiedCell() : searchNew{true} {};
    ModifiedCell(int row, int col) : row{row}, col{col}, searchNew{true} {
        square = (3*(row/3)) + col/3;
     }
    ~ModifiedCell() = default;
};

struct Coordinates{
    int row;
    int col;

    Coordinates() = default;
    Coordinates(int row, int col): row {row}, col {col} {};
};
class Sudoku{

friend class Solver;
friend class Checker;

friend std::ostream &operator<<(std::ostream &os, const Sudoku &rhs);

private:
    //unique containers - storing arrays with unique data

    uniqueContainer rows = {0};
    uniqueContainer columns = {0};
    uniqueContainer squares = {0};

    void sampleToUniques(sampleContainer &s);
    void uniqueTouniques(uniqueContainer &s);
    void modifyElement(int elem, int row, int col);
    Coordinates getSquareCoordinates (int row, int col);
    bool uniqueContainerValidation(uniqueContainer s);

public:

    bool solved{false};
    bool checked{false};

    Sudoku(sampleContainer &s){
        this->sampleToUniques(s);
    };


    Sudoku(uniqueContainer &s){
        this->uniqueTouniques(s);
    };

    Sudoku() = default;


    void print ();
    void print(const uniqueContainer &s);

    //add method to change sudoku
    bool Solve();
    bool Check();
};



#endif // SUDOKU_H
