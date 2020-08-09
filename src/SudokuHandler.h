#pragma once

#include <array>
#include <iostream>
#include "Structs.h"
#include "SudokuBoard.h"



class SudokuHandler{

private:

    SudokuBoard Board;                  //sudoku containers and get/set mothods to it

public:
    //constructors
    SudokuHandler() = default;
    SudokuHandler(one_dim_container& s)
        :Board(s) {}
    SudokuHandler(two_dim_container& s)
        :Board(s) {}

    //public fields
    bool solved{ false };                   
    bool checked{ false };
    bool generated{ false };

    //public methods 
    bool Solve();
    bool Check();
    bool Generate();

    //operator overload
    friend std::ostream& operator<<(std::ostream& os, const SudokuHandler& rhs);
};

