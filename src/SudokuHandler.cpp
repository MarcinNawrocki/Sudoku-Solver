#include "SudokuHandler.h"
#include "Solver.h"
#include "Checker.h"
#include "Generator.h"

#include<iostream>

//Creates Solver object to solve sudoku in Board object
bool SudokuHandler::Solve() {
    //if board is empty or solved, doesn't solve it
    if (this->empty_board || this->solved)
    {
        std::cout << "Sudoku is solved or board is empty";
        return false;
    }
        

    Solver* ptr_solver = new Solver(&Board);
    return this->Call_one_task_class(ptr_solver);
}

//Creates Checker object to check sudoku in Board object
bool SudokuHandler::Check(){

    Checker* ptr_checker = new Checker(&Board);
    return this->Call_one_task_class(ptr_checker);
}
//Creates Generator object to generate new sudoku in Board object
bool SudokuHandler::Generate()
{
    Generator* ptr_generator = new Generator(&Board);
    return this->Call_one_task_class(ptr_generator);

}

//Call task function from one task class (Generator, Checker, Solver), based on pointer type
bool SudokuHandler::Call_one_task_class(I_OneTaskClass* ptr)
{
    if (ptr->Proceed_operation())
    {
        //set attributes depending of class type
        if (Solver* s = dynamic_cast<Solver*>(ptr))
        {
            this->solved = true;
        }
        else if (Generator* g = dynamic_cast<Generator*>(ptr))
        {
            this->solved = false;
            this->empty_board = false;
        }
        return true;
    }
    else
    {
        this->Clear_board();
        return false;
    }
}

//Fill with zeros (empty value) entire sudoku board.
void SudokuHandler::Clear_board()
{
    for (size_t row = 0; row < 9; ++row)
    {
        for (size_t col = 0; col < 9; ++col)
        {
            Board.modify_element(0, row, col);
        }
    }
    this->solved = false;
}

//Overloaded operator<<, based on SudokuBoard overloading
std::ostream& operator<<(std::ostream& os, const SudokuHandler& rhs)
{
    return os << rhs.Board;
}
