#include "Generator.h"
#include<fstream>
#include<ctime>
#include<string>
#define path "./solved.in"
#define solved_sudokus 50


bool Generator::openFile(){
    this->file_solved.open(path);
    if (file_solved.good())
        return true;
    else
    //error handling
        return false;
}

int Generator::generateRandomNumber(int max){

    srand((int) time (0));
    return rand()%max;
}

sampleContainer Generator::Generate(){
    int line = generateRandomNumber(solved_sudokus);
    //std::cout<<line<<"\n";
    int act_line {0};
    std::string readLine;


    this->openFile();
    while(act_line != line && getline(this->file_solved,readLine))
    {
        act_line++;
    }

    if(act_line == line)
    {
        //final read
        getline(this->file_solved,readLine);
        for (int i = 0; i<81; ++i)
        {
            generatedSudoku.at(i) = std::stoi(readLine.substr(i,1));
        }
        return generatedSudoku;
    }
    else
    {
            //error handling
    }
}
