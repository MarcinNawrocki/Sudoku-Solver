#include "SudokuBoard.h"
#include<iostream>

//overloaded << operator for SudokuBoard structure
std::ostream& operator<<(std::ostream& os, const SudokuBoard& rhs) {

    for (int i = 0; i < 9; ++i)
    {
        for (int j = 0; j < 9; ++j)
        {
            os << rhs.rows.at(i).at(j) << " ";
        }
        os << "\n";
    }
    os << "\n";
    return os;
}

//generate 9x9 array from 81x1 array
void SudokuBoard::one_dim_to_two_dim(one_dim_container& s) {

    for (int i = 0; i < 81; ++i)
    {
        int row = i / 9;
        int col = i % 9;
        this->modify_element(s.at(i), row, col);
    }
}

//generate columns and squares containers fromr rows
void SudokuBoard::make_two_dim_containers(two_dim_container& s) {
    for (int row = 0; row < 9; ++row)
    {
        for (int col = 0; col < 9; ++col)
        {
            this->modify_element(s.at(row).at(col), row, col);
        }
    }

}

//Modified element in specified coordinates in all three sudoku containers (row, columns and squares)
void SudokuBoard::modify_element(int elem, int row, int col) {
    //insert in rows
    this->rows.at(row).at(col) = elem;
    //insert in cols
    this->columns.at(col).at(row) = elem;
    //insert in squares
    Coordinates sqCoord;

    sqCoord = get_square_coordinates(row, col);
    //std::cout<<"Row "<<row<<", Col "<<col<<" ...... Box "<<(3*(row/3)) + col/3 <<" \n"; //<<", Col "<<sq_col<<" \n";
    this->squares.at(sqCoord.row).at(sqCoord.col) = elem;
}

Coordinates SudokuBoard::get_square_coordinates(int row, int col) {
    Coordinates coord;
    coord.row = ((row / 3) * 3) + (col / 3);
    coord.col = ((row % 3) * 3) + col % 3;

    return coord;
}

//Single row getter from SudokuBoard
unique_cointainer& SudokuBoard::get_row(int row_number)
{
    return this->rows.at(row_number);
}

//Single column getter from SudokuBoard
unique_cointainer& SudokuBoard::get_column(int col_number)
{
    return this->columns.at(col_number);
}

//Single square getter from SudokuBoard
unique_cointainer& SudokuBoard::get_square(int sq_number)
{
    return this->squares.at(sq_number);
}

//Single element getter from SudokuBoard
int& SudokuBoard::get_element(int row, int col)
{
    return this->rows.at(row).at(col);
}
