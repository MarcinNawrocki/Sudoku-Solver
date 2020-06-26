#ifndef SOLVER_H
#define SOLVER_H

#include "Sudoku.h"
#include <memory>

class Solver
{

private:
   // sampleContainer *ptr_parentBoard;

    std::stack <ModifiedCell> modifiedCells;
    Sudoku *ptr_toSudoku;

    bool digitValidation(const ModifiedCell &mCell, int number);
    bool digitValidationInContainer(const std::array <int,9> &arr, int number);
    ModifiedCell findEmptyCell (short start_Row);
    void backToPreviousCell(ModifiedCell &workingCell, int &empty_Row);


public:

    Solver() = default;
    Solver(Sudoku *ptr_s): ptr_toSudoku(ptr_s) {};
    bool Solve_backtracking();
};



#endif // SOLVER_H
