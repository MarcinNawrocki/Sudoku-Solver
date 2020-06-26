#include "Sudoku.h"
#include "Solver.h"

void  Sudoku::print(){
    print(Sudoku::rows);
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
    return obj_Solver.Solve_backtracking();
}
