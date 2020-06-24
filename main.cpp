#include <iostream>
#include <array>
#include<algorithm>
#include<stack>
#include<set>
#include<memory>


//declaring alias for unique containers
using uniqueContainer = std::array<std::array<int,9>,9>;
using sampleContainer = std::array<int,81>;
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

struct ModifiedCell{
    std::set <int> triedValues;
    int actual_Value;
    int row;
    int col;
    int square;
    bool searchNew;
    ModifiedCell() : searchNew{true} {};
    ModifiedCell(int row, int col) : row{row}, col{col}, searchNew{true} {
        square = (3*(row/3)) + col/3;
     }
    ~ModifiedCell(){
    //std::cout<<"Delete modified cell \n";
    }
};
class Sudoku{

private:
    //unique containers - storing arrays with unique data
    uniqueContainer rows = {0};
    uniqueContainer columns = {0};
    uniqueContainer squares = {0};

    void sampleToSudoku(sampleContainer &s){
        for (int i=0; i<81; ++i)
        {
            int row = i/9;
            int col = i%9;
            insertElement(s.at(i), row, col);
        }

    }

    void insertElement(int elem, int row, int col){
        //insert in rows
        this->rows.at(row).at(col) = elem;
        //insert in cols
        this->columns.at(col).at(row) = elem;
        //insert in squares
        int sq_row = ((row/3)*3) + (col/3);
        int sq_col = ((row%3)*3) + col%3;
        //std::cout<<"Row "<<row<<", Col "<<col<<" ...... Box "<<(3*(row/3)) + col/3 <<" \n"; //<<", Col "<<sq_col<<" \n";
        this->squares.at(sq_row).at(sq_col) = elem;
    }

    void eraseElement(int row, int col){
        this->rows.at(row).at(col) = 0;
        //insert in cols
        this->columns.at(col).at(row) = 0;
        //insert in squares
        int sq_row = ((row/3)*3) + (col/3);
        int sq_col = ((row%3)*3) + col%3;
        //std::cout<<"Row "<<row<<", Col "<<col<<" ...... Box "<<(3*(row/3)) + col/3 <<" \n"; //<<", Col "<<sq_col<<" \n";
        this->squares.at(sq_row).at(sq_col) = 0;
    }

    bool digitValidation(const ModifiedCell &mCell, int number){

        bool rows_validation = digitValidationInContainer(rows.at(mCell.row), number);
        bool col_validation = digitValidationInContainer(columns.at(mCell.col), number);
        bool sqaure_validation = digitValidationInContainer(squares.at(mCell.square), number);

        return rows_validation && col_validation && sqaure_validation;
    }

    bool digitValidationInContainer(const std::array <int,9> &arr, int number){
        auto it = std::find(std::begin(arr), std::end(arr), number);
        if (it == std::end(arr))
            return true;
        else
            return false;
    }

public:

    bool Solve(){
        //find first empty location
        std::stack <ModifiedCell> modifiedCells;
        ModifiedCell workingCell;
        int empty_Row {0}, empty_Col {0};
        int valueToInsert {1};
        while(1)
        {
            //this->print();
            if (workingCell.searchNew)
            {
                for (empty_Row; empty_Row<9; ++empty_Row)
                {
                    auto it = std::find(std::begin(rows.at(empty_Row)), std::end(rows.at(empty_Row)), 0);
                    if (it != std::end(rows.at(empty_Row)))
                    {
                        empty_Col = std::distance(std::begin(rows.at(empty_Row)), it);
                        //std::cout<<"Row "<<empty_Row<<", Col "<<empty_Col;
                        //later check for copy/move
                        //modifiedCells.push(ModifiedCell(empty_Row,empty_Col));
                        workingCell = ModifiedCell(empty_Row, empty_Col);
                        break;
                    }
                    else if (it == std::end(rows.at(empty_Row)) && empty_Row == 8)
                        //nothing to find in last row -> sudoku is done
                        return true;
                }
            }

            //determine first valid number in this cell
            valueToInsert = 1;
            if (!workingCell.triedValues.empty())
                //max value is the same as size
                if (workingCell.triedValues.size() < 9)
                    valueToInsert = workingCell.triedValues.size() + 1;
                else
                {
                    //duplicate with else in for
                    //avoid loop
                    valueToInsert = 10;
                    eraseElement(modifiedCells.top().row, modifiedCells.top().col);
                    workingCell = modifiedCells.top();
                    modifiedCells.pop();
                    workingCell.searchNew = false;
                    empty_Row = workingCell.row;


                }

            for (valueToInsert; valueToInsert<10; ++valueToInsert)
            {
                workingCell.triedValues.insert(valueToInsert);
                if (digitValidation(workingCell, valueToInsert))
                {
                    insertElement(valueToInsert, workingCell.row,  workingCell.col);
                    workingCell.searchNew = true;
                    modifiedCells.push(workingCell);
                    break;
                }
                else
                {
                     //workingCell.triedValues.insert(valueToInsert);
                     //backtracking
                     if (valueToInsert == 9)
                     {
                         //backtracking
                         //actualize row
                        if(modifiedCells.empty())
                            return false;
                        else
                        {
                            eraseElement(modifiedCells.top().row, modifiedCells.top().col);
                            workingCell = modifiedCells.top();
                            modifiedCells.pop();
                            workingCell.searchNew = false;
                            empty_Row = workingCell.row;
                            break;
                        }
                    }
                }
            }
        }
    }


    Sudoku(sampleContainer &s){
        this->sampleToSudoku(s);
    }
    //uniqueContainer sudoku = {0};
    void print();



};

int main()
{

    Sudoku s (sample2);
    std::cout<<s.Solve()<<" \n";
    s.print();
    return 0;
}


void  Sudoku::print(){
    for (int i=0; i<9; ++i)
    {
        for (int j=0; j<9; ++j)
        {
            std::cout<<rows.at(i).at(j)<<" ";
        }
        std::cout<<"\n";
    }
    std::cout<<"--------------------------------\n";
}


