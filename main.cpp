#include "Sudoku.h"

/*
TODO:
    - refactor existing code
    - new class solver which inherit from Sudoku
    - implementing sample sudoku generator (maybe with difficulty levels)
    - user friendly menu, maybe some interfaces
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

    Sudoku s (sample1);
    s.print();
    std::cout<<s.Solve()<<" \n";
    s.print();
    return 0;
}





