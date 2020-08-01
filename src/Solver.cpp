#include "Solver.h"
#include "Sudoku.h"

bool Solver::Solve_backtracking(){

    //find first empty location
    WorkingCell workingCell;
    int empty_Row {0};
    int value_to_insert {1};
    while(1)
    {
        if (workingCell.searchNew)
        {
            workingCell = this->find_empty_cell(empty_Row);
            //chechk if Cell out of range -> sudoku is done
            if (workingCell.row == 9)
            {
                return true;
            }
        }

        value_to_insert = next_value_to_insert(workingCell);

        //value_to_insert out of range
        if (value_to_insert > 9)
            back_to_previous_cell(workingCell, empty_Row);

        for (value_to_insert; value_to_insert <10; ++value_to_insert)
        {
            workingCell.max_tried_value++;
            //we can insert actual value
            if (digit_validation_in_cell(workingCell, value_to_insert))
            {
                ptr_to_sudoku->modify_element(value_to_insert, workingCell.row,  workingCell.col);
                workingCell.searchNew = true;
                modifiedCells.push(workingCell);
                break;
            }
            else
            {
                 //no value is valid for this cell
                 if (value_to_insert == 9)
                 {
                     //sudoku is unsolvable
                    if(modifiedCells.empty())
                        return false;
                    //backtracking
                    else
                    {
                        back_to_previous_cell(workingCell, empty_Row);
                        break;
                    }
                }
            }
        }
    }
}


int Solver::next_value_to_insert(WorkingCell& wc){
    //get value to insert
    int next_value{ 1 };

    //if (!workingCell.triedValues.empty())
    if (wc.max_tried_value > 0)
    {
        //max value is the same as size
        if (wc.max_tried_value < 9)
            next_value = wc.max_tried_value + 1;
        //we try all values so we must come back to previous cell
        else
            next_value = 10;
    }

    return next_value;
}

//check if number can be added given Cell
bool Solver::digit_validation_in_cell(const WorkingCell& mCell, int number){

    bool rows_validation = digit_validation_in_container(ptr_to_sudoku->get_row(mCell.row), number);
    bool col_validation = digit_validation_in_container(ptr_to_sudoku->get_column(mCell.col), number);
    bool sqaure_validation = digit_validation_in_container(ptr_to_sudoku->get_square(mCell.square), number);

    return rows_validation && col_validation && sqaure_validation;
}

bool Solver::digit_validation_in_container(const unique_cointainer &arr, int number){
    auto it = std::find(std::begin(arr), std::end(arr), number);
    if (it == std::end(arr))
        return true;
    else
        return false;
}


WorkingCell Solver::find_empty_cell(short start_row){
    int empty_Col {0};
    for (start_row; start_row<9; ++start_row)
    {
        //try to find free cell in row
        auto it = std::find(std::begin(ptr_to_sudoku->get_row(start_row)), std::end(ptr_to_sudoku->get_row(start_row)), 0);
        //if is free cell in the row return it
        if (it != std::end(ptr_to_sudoku->get_row(start_row)))
        {
            empty_Col = std::distance(std::begin(ptr_to_sudoku->get_row(start_row)), it);
            return WorkingCell(start_row, empty_Col);
        }
    }
    //didn't find value->sudoku is done -> return value out of range
    return WorkingCell(9, 9);

}

void Solver::back_to_previous_cell(WorkingCell&workingCell, int &empty_Row){

    ptr_to_sudoku->modify_element(0,modifiedCells.top().row, modifiedCells.top().col);
    workingCell = modifiedCells.top();
    modifiedCells.pop();
    workingCell.searchNew = false;
    empty_Row = workingCell.row;
}



