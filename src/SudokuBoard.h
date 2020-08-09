#pragma once

#include <array>
#include <iostream>
#include <memory>
#include<algorithm>
#include<stack>

#include "Structs.h"




class SudokuBoard {

//private:
public:
    //unique containers - storing arrays with unique data
    two_dim_container rows;             //array of sudoku rows
    two_dim_container columns;          //array of sudoku columns
    two_dim_container squares;          //array of sudoku squares

    //container modifiers
    void one_dim_to_two_dim(one_dim_container& s);
    void make_two_dim_containers(two_dim_container& s);

    Coordinates get_square_coordinates(int row, int col);

public:

    //ctors
    SudokuBoard() = default;
    SudokuBoard(one_dim_container& s) {
        this->one_dim_to_two_dim(s);
    }
    SudokuBoard(two_dim_container& s) {
        this->make_two_dim_containers(s);
    }

    //getters
    int& get_element(int row, int col);
    unique_cointainer& get_row(int row_number);
    unique_cointainer& get_column(int col_number);
    unique_cointainer& get_square(int sq_number);

    //setter
    void modify_element(int elem, int row, int col);

    //operator overloads
    friend std::ostream& operator<<(std::ostream& os, const SudokuBoard& rhs);
};


