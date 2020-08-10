#include "SudokuHandler.h"

//more solved sudokus: https://www.kaggle.com/bryanpark/sudoku?select=sudoku.csv (50 was taken)
/*
TODO:
    -code repeat in sudoku handler
*/

int main()
{

    //SudokuHandler s (sample2);
    SudokuHandler s;
    s.Generate();
    //check whether sudoku is solved
    std::cout<<"Solved: "<<s.Check()<<"\n";
    //print sudoku
    std::cout<<s;
    //solve sudoku
    s.Solve();
    //print sudoku again
    if (s.solved)
    {
        std::cout << s;
        //check if sudoku is properly solved
        std::cout << "Solved: " << s.Check() << "\n";
    }
    s.Solve();

    return 0;
}


