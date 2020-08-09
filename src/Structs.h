#pragma once
//declaring alias for unique containers
using two_dim_container = std::array<std::array<int, 9>, 9>;
using unique_cointainer = std::array<int, 9>;
using one_dim_container = std::array<int, 81>;

struct WorkingCell {

    int max_tried_value{ 0 };       //in order to get next value to insert in this cell
    int actual_Value{ 0 };          //actual value in cell
    int row{ 0 };                   //number of row
    int col{ 0 };                   //number of column
    int square{ 0 };                //number of square
    bool searchNew;                 //flags which specified that we end work with this cell and should look for another to fill with value

    WorkingCell() : searchNew{ true } {};
    WorkingCell(int row, int col) : row{ row }, col{ col }, searchNew{ true } {
        square = (3 * (row / 3)) + col / 3;
    }
    ~WorkingCell() = default;
};

//For returning two values from functions and methods
struct Coordinates {
    int row;        
    int col;      

    Coordinates() = default;
    Coordinates(int row, int col) : row{ row }, col{ col } {};
    void change_coordinates(int number)
    {
        row = number / 9;
        col = number % 9;
    }
};