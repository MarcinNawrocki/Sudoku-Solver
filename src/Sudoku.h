#ifndef SUDOKU_H
#define SUDOKU_H

#include<iostream>
#include <array>
#include<set>
#include<algorithm>
#include<stack>
//declaring alias for unique containers
using two_dim_container = std::array<std::array<int,9>,9>;
using unique_cointainer = std::array<int, 9>;
using one_dim_container = std::array<int,81>;

struct WorkingCell{
    //std::set <int> triedValues;
    int max_tried_value{ 0 };
    int actual_Value;
    int row;
    int col;
    int square;
    bool searchNew;

    WorkingCell() : searchNew{true} {};
    WorkingCell(int row, int col) : row{row}, col{col}, searchNew{true} {
        square = (3*(row/3)) + col/3;
     }
    ~WorkingCell() = default;
};

struct Coordinates{
    int row;
    int col;

    Coordinates() = default;
    Coordinates(int row, int col): row {row}, col {col} {};
    void change_coordinates(int number)
    {
        row = number / 9;
        col = number % 9;
    }
};

class Sudoku{

    //unique containers - storing arrays with unique data
    two_dim_container rows;
    two_dim_container columns ;
    two_dim_container squares;

    void one_dim_to_two_dim(one_dim_container &s);
    void make_two_dim_containers(two_dim_container&s);
    Coordinates get_square_coordinates (int row, int col);
   // bool uniqueContainerValidation(uniqueContainer s);

public:
    //public fields
    bool solved{ false };
    bool checked{ false };

    //constructors
    Sudoku() = default;
    Sudoku(one_dim_container& s) {
        this->one_dim_to_two_dim(s);
    }
    Sudoku(two_dim_container& s) {
        this->make_two_dim_containers(s);
    }

    //getters
    int& get_element(int row, int col);
    unique_cointainer& get_row(int row_number);
    unique_cointainer& get_column(int col_number);
    unique_cointainer& get_square(int sq_number);

    //setter
    void modify_element(int elem, int row, int col);

    //public methods 
    bool Solve();
    bool Check();

    //overloaded operators
    friend std::ostream& operator<<(std::ostream& os, const Sudoku& rhs);
};

#endif // SUDOKU_H
