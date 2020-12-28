
/*
                PREIMAGES OF PARTS OF FILLING FUNCTIONS
                (Specially for Zaranik`s functions)
//#####################################################################
//#####################################################################

*/

//to make buffer of -1
void makeBuffer(int rows, int cols, int** matr);


//specially for Variant5
//to make slime "left top boarder- center" and "center - left top boarder"
void invert(int rows, int cols, int** matr);

//some of fillings use 1-index.
//This is function to convert into 0-index
void toZeroIndex(int rows,int cols,int** matr);

/*
                            PREIMAGES OF FILLING FUNCTIONS
//#####################################################################
//#####################################################################

*/

void Variant1(int a, int b, int **arr);

void Variant2(int a, int b, int** arr);

void Variant3Zaranik(int rows, int cols, int** matr);

void Variant4(int** matrix, int n);//square

void Variant5_6(int rows, int cols, int** matr);

void Variant7(int **matrix, int n);//for square, 2k+1

void Variant8(int **matrix, int n);//square

void Variant9(int **matrix, int n);//square

void Variant10(int n, int **matrix);//for square

void Variant11(int** matrix, int rows, int cols);//square 2k

void Variant12(int** matrix, int rows, int cols);

void Variant12_Second(int **Matrix, int num_row, int num_col);

void Variant13(int **Matrix,int n);//for square

void Variant13_Second(int **Matrix,int num_row, int num_col);

void fill_Part(int **Matrix,int line,int border1,int border2, int way, int num_row, int num_col);  // Заповнення верхньої(нижньої частини матриці)

void Variant14(int** arr, int a);//for square, but can be extended to rectangle
