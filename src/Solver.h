#ifndef SOLVER_H
#define SOLVER_H

#include "Sudoku.h"
#include <memory>

class Solver
{
    //private fields
    std::stack <WorkingCell> modifiedCells;
    Sudoku *ptr_to_sudoku;

    //private methods
    int next_value_to_insert(WorkingCell& wc);
    bool digit_validation_in_cell(const WorkingCell& mCell, int number);
    bool digit_validation_in_container(const unique_cointainer &arr, int number);
    WorkingCell find_empty_cell (short start_Row);
    void back_to_previous_cell(WorkingCell&workingCell, int &empty_Row);


public:
    //constructors and destructors
    Solver() = default;
    Solver(Sudoku *ptr_s): ptr_to_sudoku(ptr_s) {};
    virtual ~Solver()
    {
        ptr_to_sudoku = nullptr;
        delete ptr_to_sudoku;
    }

    //public method
    bool Solve_backtracking();
};



#endif // SOLVER_H
