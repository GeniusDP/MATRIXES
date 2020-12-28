/*
                PREIMAGES OF "INTERACTIVE" FUNCTIONS
//#####################################################################
//#####################################################################
    THESE FUNCTIONS ARE USED TO OUTPUT MATRIXES
    OR COOSE THE VARIANT OF FILLING
*/

//to delete matrix from heap
void CLEAN(int rows, int cols, int** matr);

//  creates matrix of (2+rows) x (2+cols) elements
//  (2+...) is used in functions, created by
//  Zaranik. It allows us to use "buffer".
//  see function makeBuffer(int rows, int cols, int** matr);
//  in "Variants.h".
void input(int* rows, int* cols, int*** matr);

//start working
void START_WORKING(int rows, int cols, int** matr);

//menu of fillings
int MENU(int rows, int cols, int** matr);

//printing matrix
void printMatrix(int rows, int cols, int** matr);

void ChooseVarOfFilling(int choice, int rows, int cols, int** matr);
