#include "Checker.h"
#include<numeric>

bool Checker::CheckSudoku(){

    bool rowValidation, columnValidation, squareValidation;
    for (int i=0; i<9;++i)
    {
        rowValidation = unique_container_validation(ptr_to_sudoku->get_row(i));
        columnValidation = unique_container_validation(ptr_to_sudoku->get_column(i));
        squareValidation = unique_container_validation(ptr_to_sudoku->get_square(i));

        if (rowValidation != true || columnValidation != true || squareValidation != true )
            return false;
    }
    return true;
}
bool Checker::unique_container_validation(unique_cointainer s){
    //s not passing by reference because will be sorted so copy is necessary
    std::sort(s.begin(), s.end());
    const auto double_pos = std::adjacent_find(s.begin(), s.end());
    const auto [min_pos, max_pos] = std::minmax_element(s.begin(), s.end());
    int sum = std::accumulate(s.begin(),s.end(),0);

    if (double_pos == s.end() && *min_pos==1 && *max_pos==9 && sum == 45)
        return true;
    else
        return false;
}

