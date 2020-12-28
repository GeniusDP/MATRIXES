#include <iostream>
#include <iomanip>
#include "Variants.h"
using namespace std;
/*
                    PREIMAGES OF "INTERACTIVE" FUNCTIONS
//#####################################################################
//#####################################################################

*/

extern const string sep="*****************************************************\n";

//to delete matrix from heap
void CLEAN(int rows, int cols, int** matr);

//creates matrix of (2+rows) x (2+cols) elements
void input(int* rows, int* cols, int*** matr);

//start working
void START_WORKING(int rows, int cols, int** matr);

//menu of fillings
int MENU(int rows, int cols, int** matr);

//printing matrix
void printMatrix(int rows, int cols, int** matr);

void ChooseVarOfFilling(int choice, int rows, int cols, int** matr);


//#####################################################################
//#####################################################################

int MENU(int rows, int cols, int** matr){
    int type=1;
    cout << "Allowed fillings:" << endl;
    if(rows==cols){//square
        if(rows%2==0)cout << "1-14. But not 7!!!";
            else cout << "1-14. But not 11!!!";
    }
    else{
        if(cols%2==0)cout << "1, 2, 3, 5, 6, 11, 12.";
            else cout << "1, 2, 3, 5, 6, 12.";//without variant 11.
    }
    cout << endl << "Input please type of filling: ";
    cin >> type;
    return type;
}

//#####################################################################
//#####################################################################


//MAIN WORK FUNCTION
void START_WORKING(int rows, int cols, int** matr){
    int choice;
    int willContinue=1;
    do{
        cout << sep << sep;
        choice = MENU(rows, cols,  matr);
        //cout << "choise is : " << choice << endl;

        ChooseVarOfFilling(choice, rows, cols, matr);
        printMatrix(rows, cols, matr);

        cout << "CONTINUE - 1 \nSTOP - 0\nYOUR ANSWER: ";
        cin >> willContinue;
    }while(willContinue);
}

//#####################################################################
//#####################################################################

void input(int* rows, int* cols, int*** matr){
    cout << "Input rows and cols of matrix:" << endl;
    cin >> *rows >> *cols;

    //making dynamic matrix

    (*matr) = new int* [2+*rows];
    for(register int i=0; i<2+*rows; i++)
        (*matr)[i] = new int [2+*cols];
}

//#####################################################################
//#####################################################################

void CLEAN(int rows, int cols, int** matr) {
    for (int i = 0; i < 2 + rows; i++)
        delete[] matr[i];
    delete[] matr;
}

//#####################################################################
//#####################################################################

void printMatrix(int rows, int cols, int** matr) {
    cout << "\nThis is matrix:" << endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++)
            cout << setw(5) << matr[i][j];
        cout << endl;
    }
}

//#####################################################################
//#####################################################################


void ChooseVarOfFilling(int choice, int rows, int cols, int** matr){
    switch(choice){
        case 1: Variant1(rows, cols, matr); break;
        case 2: Variant2(rows, cols, matr); break;
        case 3: Variant3Zaranik(rows, cols, matr); break;
        case 4: Variant4(matr, rows); break;
        case 5: Variant5_6(rows, cols, matr); break;
        case 6: Variant5_6(rows, cols, matr); invert(rows, cols, matr); break;
        case 7: Variant7(matr, rows); break;//for square only 2k+1
        case 8: Variant8(matr, rows); break;//for square only
        case 9: Variant9(matr, rows); break;//for square only
        case 10: Variant10(rows, matr); break;//for square only
        case 11: Variant11(matr, rows, cols); break;
        case 12: Variant12(matr, rows, cols); break;
        case 13: Variant13(matr, rows); break;//for square only
        case 14: Variant14(matr, rows); break;
    }
}

//#####################################################################
//#####################################################################
