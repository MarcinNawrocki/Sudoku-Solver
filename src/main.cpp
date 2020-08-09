#include "SudokuHandler.h"

//more solved sudokus: https://www.kaggle.com/bryanpark/sudoku?select=sudoku.csv (50 was taken)
/*
TODO:
    - handling generated flag
    - move constructor and assignment operator for working cell struct
    - error handling
   
*/


//some sample sudoku - 0 is not known
one_dim_container sample1 = {0,0,0,0,0,0,2,0,0,
                            0,8,0,0,0,7,0,9,0,
                            6,0,2,0,0,0,5,0,0,
                            0,7,0,0,6,0,0,0,0,
                            0,0,0,9,0,1,0,0,0,
                            0,0,0,0,2,0,0,4,0,
                            0,0,5,0,0,0,6,0,3,
                            0,9,0,4,0,0,0,7,0,
                            0,0,6,0,0,0,0,0,0};

one_dim_container sample2 = {1,0,0,4,8,9,0,0,6,
                            7,3,0,0,0,0,0,4,0,
                            0,0,0,0,0,1,2,9,5,
                            0,0,7,1,2,0,6,0,0,
                            5,0,0,7,0,3,0,0,8,
                            0,0,6,0,9,5,7,0,0,
                            9,1,4,6,0,0,0,0,0,
                            0,2,0,0,0,0,0,3,7,
                            8,0,0,5,1,2,0,0,4};


int main()
{
    //generate new sudoku
    //one_dim_container sample = gen.generate();
    //create sudoku class
    SudokuHandler s (sample2);
    //SudokuHandler s;
    //s.Generate();
    //check that sudoku is solved
    std::cout<<"Solved: "<<s.Check()<<"\n";
    //print sudoku
    std::cout<<s;
    //solve sudoku
    s.Solve();
    //print sudoku again
    std::cout<<s;
    //check if sudoku is properly solved
    std::cout<<"Solved: "<<s.Check()<<"\n";
    return 0;
}


