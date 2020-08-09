#pragma once
#include"SudokuHandler.h"

#include<fstream>
#include <unordered_set>
class Generator
{
    //private fields
    std::ifstream file_solved;                      //file with saved, solved sudokus          
    SudokuBoard* ptr_sudoku_board;                  //pointer to board, where we store readed sudoku
    std::unordered_set<int> unique_randoms;         //vector with number indexes, which stay in unsolved sudoku

    //private methods
    int generate_random_number(int max);
    void unique_random_numbers(int);
    bool open_file();

    public:
    
    //constructors
    Generator() = default;
    Generator(SudokuBoard* ptr_s)
        : ptr_sudoku_board(ptr_s) {};

    //public methods
    bool Generate();
    

};


