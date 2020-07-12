#include "Sudoku.h"
#include "Solver.h"
#include "Checker.h"
#include<iostream>
void  Sudoku::print(){
    print(Sudoku::rows);
}

std::ostream &operator<<(std::ostream &os, const Sudoku &rhs){

    for (int i=0; i<9; ++i)
    {
        for (int j=0; j<9; ++j)
        {
            os<<rhs.rows.at(i).at(j)<<" ";
        }
        os<<"\n";
    }
    os<<"\n";
    return os;
}
void  Sudoku::print(const uniqueContainer &s){

    for (int i=0; i<9; ++i)
    {
        for (int j=0; j<9; ++j)
        {
            std::cout<<s.at(i).at(j)<<" ";
        }
        std::cout<<"\n";
    }

    std::cout<<"------------------------------\n";

}

void Sudoku::sampleToUniques(sampleContainer &s){

        for (int i=0; i<81; ++i)
        {
            int row = i/9;
            int col = i%9;
            this->modifyElement(s.at(i),row,col);
        }
}

void Sudoku::uniqueTouniques(uniqueContainer &s){
    for (int row=0; row<9; ++row)
    {
        for (int col=0; col<9; ++col)
        {
            this->modifyElement(s.at(row).at(col), row,col);
        }
    }

}
void Sudoku::modifyElement(int elem, int row, int col){
    //insert in rows
    this->rows.at(row).at(col) = elem;
    //insert in cols
    this->columns.at(col).at(row) = elem;
    //insert in squares
    Coordinates sqCoord;

    sqCoord = getSquareCoordinates(row, col);
    //std::cout<<"Row "<<row<<", Col "<<col<<" ...... Box "<<(3*(row/3)) + col/3 <<" \n"; //<<", Col "<<sq_col<<" \n";
    this->squares.at(sqCoord.row).at(sqCoord.col) = elem;
}

Coordinates Sudoku::getSquareCoordinates (int row, int col){
    Coordinates coord;
    coord.row = ((row/3)*3) + (col/3);
    coord.col = ((row%3)*3) + col%3;

    return coord;
}


bool Sudoku::Solve(){

    Solver obj_Solver (this);
    if (obj_Solver.Solve_backtracking())
    {
        this->solved = true;
        return true;
    }
    else
    {
        this->solved = false;
        return false;
    }
}

bool Sudoku::Check(){

    Checker obj_checker (this);
    if (obj_checker.CheckSudoku())
    {
        this->checked = true;
        return true;
    }
    else
    {
        this->checked = false;
        return false;
    }
}
