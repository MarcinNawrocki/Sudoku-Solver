#include "Solver.h"
#include "Sudoku.h"

bool Solver::Solve_backtracking(){
//find first empty location

    ModifiedCell workingCell;
    int empty_Row {0};
    int valueToInsert {1};
    while(1)
    {
        if (workingCell.searchNew)
        {
            workingCell = this->findEmptyCell(empty_Row);
            //chechk if Cell out of range -> sudoku is done
            if (workingCell.row == 9)
            {
                return true;
            }
        }

        //determine first valid number in this cell
        valueToInsert = 1;
        if (!workingCell.triedValues.empty())
        {
            //max value is the same as size
            if (workingCell.triedValues.size() < 9)
                valueToInsert = workingCell.triedValues.size() + 1;
            else
            {
                valueToInsert = 10;
                backToPreviousCell(workingCell, empty_Row);
            }
        }

        for (valueToInsert; valueToInsert<10; ++valueToInsert)
        {
            workingCell.triedValues.insert(valueToInsert);
            if (digitValidationInCell(workingCell, valueToInsert))
            {
                ptr_toSudoku->modifyElement(valueToInsert, workingCell.row,  workingCell.col);
                workingCell.searchNew = true;
                modifiedCells.push(workingCell);
                break;
            }
            else
            {
                 //workingCell.triedValues.insert(valueToInsert);
                 //backtracking
                 if (valueToInsert == 9)
                 {
                     //backtracking
                     //actualize row
                    if(modifiedCells.empty())
                    {
                        return false;
                    }
                    else
                    {
                        backToPreviousCell(workingCell, empty_Row);
                        break;
                    }
                }
            }
        }
    }
}

//check if number can be added given Cell
bool Solver::digitValidationInCell(const ModifiedCell &mCell, int number){

    bool rows_validation = digitValidationInContainer(ptr_toSudoku->rows.at(mCell.row), number);
    bool col_validation = digitValidationInContainer(ptr_toSudoku->columns.at(mCell.col), number);
    bool sqaure_validation = digitValidationInContainer(ptr_toSudoku->squares.at(mCell.square), number);

    return rows_validation && col_validation && sqaure_validation;
}

bool Solver::digitValidationInContainer(const std::array <int,9> &arr, int number){
    auto it = std::find(std::begin(arr), std::end(arr), number);
    if (it == std::end(arr))
        return true;
    else
        return false;
}


ModifiedCell Solver::findEmptyCell (short start_Row){
    int empty_Col {0};
    for (start_Row; start_Row<9; ++start_Row)
    {
        auto it = std::find(std::begin(ptr_toSudoku->rows.at(start_Row)), std::end(ptr_toSudoku->rows.at(start_Row)), 0);
        if (it != std::end(ptr_toSudoku->rows.at(start_Row)))
        {
            empty_Col = std::distance(std::begin(ptr_toSudoku->rows.at(start_Row)), it);
            return ModifiedCell(start_Row, empty_Col);
            break;
        }
        else if (it == std::end(ptr_toSudoku->rows.at(start_Row)) && start_Row == 8)
            //return cell out of range -> sudoku is done
            return ModifiedCell(9,9);
    }

    //handle for possible error
}

void Solver::backToPreviousCell(ModifiedCell &workingCell, int &empty_Row){

    ptr_toSudoku->modifyElement(0,modifiedCells.top().row, modifiedCells.top().col);
    workingCell = modifiedCells.top();
    modifiedCells.pop();
    workingCell.searchNew = false;
    empty_Row = workingCell.row;
}



