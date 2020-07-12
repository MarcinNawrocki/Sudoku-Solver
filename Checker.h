#ifndef CHECKER_H
#define CHECKER_H
#include "Sudoku.h"

class Checker
{
    public:
        Checker()=default;
        Checker(const Sudoku *ptr_s): ptr_toSudoku(ptr_s) {};
        bool CheckSudoku();

    private:

        bool uniqueContainerValidation(std::array<int,9> s);
        const Sudoku *ptr_toSudoku;
};

#endif // CHECKER_H
