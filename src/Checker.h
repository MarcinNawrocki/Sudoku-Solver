#pragma once
#include "SudokuHandler.h"

class Checker
{
    //private methods and fields
    bool unique_container_validation(unique_cointainer s);      
    SudokuBoard* ptr_sudoku_board;                                 
 
public:
    //constructors and destructos
    Checker()=default;
    Checker(SudokuBoard* ptr_s): ptr_sudoku_board(ptr_s) {};

    //public method
    bool CheckSudoku();
};


