#include "Sudoku.h"
#include "Generator.h"
//more solved sudokus: https://www.kaggle.com/bryanpark/sudoku?select=sudoku.csv (50 was taken)
/*
TODO:
    - finish generator (add column and row permutation)
    - error handling
    - use solver to calculate number of possible sudoku solutions
*/


//some sample sudoku - 0 is not known
sampleContainer sample1 = {0,0,0,0,0,0,2,0,0,
                           0,8,0,0,0,7,0,9,0,
                           6,0,2,0,0,0,5,0,0,
                           0,7,0,0,6,0,0,0,0,
                           0,0,0,9,0,1,0,0,0,
                           0,0,0,0,2,0,0,4,0,
                           0,0,5,0,0,0,6,0,3,
                           0,9,0,4,0,0,0,7,0,
                           0,0,6,0,0,0,0,0,0};

sampleContainer sample2 = {1,0,0,4,8,9,0,0,6,
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
    Generator gen;
    sampleContainer sample = gen.Generate();
    //create sudoku class
    Sudoku s (sample1);
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


