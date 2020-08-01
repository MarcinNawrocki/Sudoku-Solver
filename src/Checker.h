#ifndef CHECKER_H
#define CHECKER_H
#include "Sudoku.h"

class Checker
{
    //private methods and fields
    bool unique_container_validation(unique_cointainer s);
    Sudoku* ptr_to_sudoku;

public:
    //constructors and destructos
    Checker()=default;
    Checker(Sudoku *ptr_s): ptr_to_sudoku(ptr_s) {};
    virtual ~Checker()
    {
        ptr_to_sudoku = nullptr;
        delete ptr_to_sudoku;
    }
    //public method
    bool CheckSudoku();
};

#endif // CHECKER_H
