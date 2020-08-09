#include "SudokuHandler.h"
#include "Solver.h"
#include "Checker.h"
#include "Generator.h"

#include<iostream>

//Creates Solver object to solve sudoku in Board object
bool SudokuHandler::Solve(){

    Solver obj_Solver (&Board);
    if (obj_Solver.Solve_backtracking())
    {
        this->solved = true;
        return true;
    }
    else
    {
        this->solved = false;
        return false;
    }
}

//Creates Checker object to check sudoku in Board object
bool SudokuHandler::Check(){

    Checker obj_checker (&Board);
    if (obj_checker.CheckSudoku())
    {
        this->checked = true;
        return true;
    }
    else
    {
        this->checked = false;
        return false;
    }
}
//Creates Generator object to generate new sudoku in Board object
bool SudokuHandler::Generate()
{
    Generator obj_generator(&Board);
    return obj_generator.Generate();
}

//Overloaded operator<<, based on SudokuBoard overloading
std::ostream& operator<<(std::ostream& os, const SudokuHandler& rhs)
{
    return os << rhs.Board;
}
