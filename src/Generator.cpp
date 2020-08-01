#include "Generator.h"
#include<fstream>
#include<ctime>
#include<string>
#define path "./solved.in"
#define solved_sudokus 50

one_dim_container Generator::generate() {

    //generate random number to get one of previosly solved sudokus
    int line = generate_random_number(solved_sudokus);

    int act_line{ 0 };
    std::string readLine;
    this->open_file();

    //read sudoku with drawn number
    while (act_line != line && getline(this->file_solved, readLine))
    {
        act_line++;
    }
    getline(this->file_solved, readLine);


    for (int i = 0; i < 81; ++i)
    {
        generated_sudoku.at(i) = std::stoi(readLine.substr(i, 1));
    }
    return generated_sudoku;
}

bool Generator::open_file(){
    this->file_solved.open(path);
    if (file_solved.good())
        return true;
    else
    //error handling
        return false;
}

int Generator::generate_random_number(int max){
    srand((int) time (0));
    return rand()%max;
}


