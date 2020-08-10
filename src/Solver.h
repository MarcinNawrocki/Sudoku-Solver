#pragma once

#include <memory>

#include "SudokuHandler.h"

class Solver: public I_OneTaskClass
{
    //private fields
    std::stack <WorkingCell> modifiedCells;                     //saving modified cells in order to perfrom backtracking
    SudokuBoard *ptr_sudoku_board;                              //sudoku board to solve

    //private methods
    int next_value_to_insert(WorkingCell& wc);
    bool digit_validation_in_cell(const WorkingCell& mCell, int number);
    bool digit_validation_in_container(const unique_cointainer &arr, int number);
    WorkingCell find_empty_cell (short start_Row);
    void back_to_previous_cell(WorkingCell&workingCell, int &empty_Row);


public:
    //constructors and destructors
    Solver() = default;
    Solver(SudokuBoard* ptr_s)
        : ptr_sudoku_board(ptr_s) {};

    //public method
    bool Proceed_operation() override;
};

