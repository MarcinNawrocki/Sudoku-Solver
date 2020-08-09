#include "Checker.h"
#include<numeric>

//Function check if sudoku is correctly solved
//It validates sudoku from pointer to Sudoku Board struct- ptr_to_sudoku, which is class member
bool Checker::CheckSudoku(){

    bool rowValidation, columnValidation, squareValidation;
    //we validate each uniqueContainer (row, column and square)
    for (int i=0; i<9;++i)
    {
        rowValidation = unique_container_validation(ptr_sudoku_board->get_row(i));
        columnValidation = unique_container_validation(ptr_sudoku_board->get_column(i));
        squareValidation = unique_container_validation(ptr_sudoku_board->get_square(i));

        if (rowValidation != true || columnValidation != true || squareValidation != true )
            return false;
    }
    return true;
}
//Check if given unique container is valid in terms of sudoku
//All numbers from 0-9 appears once
bool Checker::unique_container_validation(unique_cointainer s){
    //s not passing by reference because will be sorted so copy is necessary
    std::sort(s.begin(), s.end());
    const auto double_pos = std::adjacent_find(s.begin(), s.end());            //no duplicates
    const auto [min_pos, max_pos] = std::minmax_element(s.begin(), s.end());   //check min/max values
    int sum = std::accumulate(s.begin(),s.end(),0);                            //check sum

    if (double_pos == s.end() && *min_pos==1 && *max_pos==9 && sum == 45)
        return true;
    else
        return false;
}

