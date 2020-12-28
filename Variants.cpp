//#####################################################################
//#####################################################################


void makeBuffer(int rows, int cols, int** matr);
void invert(int rows, int cols, int** matr);
void toZeroIndex(int rows,int cols,int** matr);
void Variant3Zaranik(int rows, int cols, int** matr);
void Variant2(int a, int b, int** arr);
void Variant1(int a, int b, int **arr);
void Variant5_6(int rows, int cols, int** matr);
void Variant10(int n, int **matrix);//for sqaure
void Variant7(int **matrix, int n);//for sqaure, 2k+1
void Variant13(int **Matrix,int n);//for square
void Variant8(int **matrix, int n);//square
void Variant9(int **matrix, int n);//square
void Variant11(int** matrix, int rows, int cols);
void Variant12(int** matrix, int rows, int cols);
void Variant4(int** matrix, int n);//square
void Variant13_Second(int **Matrix,int num_row, int num_col);
//is used in func Variant13_Second()
void fill_Part(int **Matrix,int line,int border1,int border2, int way, int num_row, int num_col);  // Заповнення верхньої(нижньої частини матриці)
void Variant14(int** arr, int a);


void Variant14(int** arr, int a) {
    //Zelenskii A
    for (int i = 0; i < a; i++) {
        for (int j = 0; j < a; j++) {
            if ((i+j)%2) {
                arr[i][j] = 0;
            }
            else {
                arr[i][j] = 1;
            }
        }
    }
}



//#####################################################################
//#####################################################################

void Variant4(int** matrix, int n){
    //Kornienko V
     int index = 1;
            int currX = -1;
            int currY = -1;
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n - i; j++)
                {
                    if (i%3==0)
                    {
                        currX++;
                        currY++;
                    }
                    else if(i%3==1)
                    { currX--;}
                    else { currY--;}

                    matrix[currX][currY] = index;
                    matrix[currY][currX] = index;
                    index++;
                }
            }
}

//#####################################################################
//#####################################################################

void Variant12(int** matrix, int rowsCount, int columnsCount){
    //Kovalenko N
    int currentNumber = 1;

            bool directionUp = true;

            for (int j = 0; j <= columnsCount / 2; j++)
            {
                if (directionUp)
                {
                    for (int i = rowsCount - 1; i >= 0; i--)
                    {
                        matrix[i][j] = currentNumber++;
                    }
                }
                else
                {
                    for (int i = 0; i < rowsCount; i++)
                    {
                        matrix[i][j] = currentNumber++;
                    }
                }

                directionUp = !directionUp;
            }

            currentNumber = 1;
            directionUp = true;

            for (int j = columnsCount - 1; j >= columnsCount / 2; j--)
            {
                if (directionUp)
                {
                    for (int i = rowsCount - 1; i >= 0; i--)
                    {
                        matrix[i][j] = currentNumber++;
                    }
                }
                else
                {
                    for (int i = 0; i < rowsCount; i++)
                    {
                        matrix[i][j] = currentNumber++;
                    }
                }

                directionUp = !directionUp;
            }



}

//#####################################################################
//#####################################################################

void Variant11(int** matrix, int rows, int cols){
    //Kovalenko N
    int currentNumber = 1;
        bool directionUp = true;
        for (int j = 0; j <= cols / 2; j++)
        {
            if (directionUp)
            {
                for (int i = rows - 1; i >= 0; i--)
                {
                    matrix[i][j] = currentNumber++;
                }
            }
            else
            {
                for (int i = 0; i < rows; i++)
                {
                    matrix[i][j] = currentNumber++;
                }
            }

            directionUp = !directionUp;
        }

        currentNumber = 1;
        directionUp = false;

        for (int j = cols - 1; j >= cols / 2; j--)
        {
            if (directionUp)
            {
                for (int i = rows - 1; i >= 0; i--)
                {
                    matrix[i][j] = currentNumber++;
                }
            }
            else
            {
                for (int i = 0; i < rows; i++)
                {
                    matrix[i][j] = currentNumber++;
                }
            }

            directionUp = !directionUp;
        }
}

//#####################################################################
//#####################################################################

void Variant8(int **matrix, int n){//square
    //Kapshuk M
  for (int i=0; i<n; i++){
    for (int j=0; j<i; j++){
      matrix[i][j]=1;
    }
    for (int j=i; j<n; j++){
      matrix[i][j]=0;
    }
  }
}

//#####################################################################
//#####################################################################

void Variant9(int **matrix, int n){//square
  //Kapshuk M ?
  //This code is written in her own style
  for (int i=0; i<n; i++){
    for (int j=0; j<n-i; j++){
      matrix[i][j]=1;
    }
    for (int j=n-i; j<n; j++){
      matrix[i][j]=0;
    }
  }
}

//#####################################################################
//#####################################################################

void Variant5_6(int rows, int cols, int** matr){
    //Zaranik
    makeBuffer(rows, cols, matr);
    //making the slime TO center
    int cur=0;
    int x=1, y=0, dx=0, dy=1;
    while(cur<rows*cols){
        if( matr[x+dx][y+dy]!=0){//not 0, so we have to change the direction
            if(dx==0 && dy==1){
                dx=1; dy=0;
            }
            else if(dx==1 && dy==0){
                dx=0; dy=-1;
            }
            else if(dx==0 && dy==-1){
                dx=-1; dy=0;
            }
            else if(dx==-1 && dy==0){
                dx=0; dy=1;
            }
        }
        else{
            x+=dx; y+=dy;
            matr[x][y]=++cur;
        }

    }
    toZeroIndex(rows, cols, matr);

    /*
        //inversing to "slime from the center"
        invert(rows, cols, matr);
    */
}


//#####################################################################
//#####################################################################

void Variant13(int **Matrix,int n)//for square
{
    //Adamchuk Illya
    for (int i=0;i<n;i++)
    {
        if (i<(n/2))
        {
            for (int j=0;j<n;j++)
            {
                if((j>i)&&(j<n-1-i))
                {
                    Matrix[i][j]=1;
                }
                else
                    Matrix[i][j]=0;
            }
        }
        if (i==(n/2))
        {
            for (int j=0;j<n;j++)
            {
                Matrix[i][j]=0;
            }
        }
        if (i>(n/2))
        {
            for (int j=0;j<n;j++)
            {
                if((j>n-1-i)&&(j<i))
                {
                    Matrix[i][j]=1;
                }
                else
                    Matrix[i][j]=0;
            }
        }
        Matrix[i][i]=5;
        Matrix[i][n-1-i]=5;
    }
}

//#####################################################################
//#####################################################################

void Variant10(int n, int **matrix){//for sqaure
    //Kapshuk M
  for (int i=0; i<n; i++){
    for (int j=0; j<n; j++){
      matrix[i][j] = 0;
    }
    for (int j=0; j<=i-(2*i/n); j++){
      matrix[i][j] = (matrix[i][j]+1)%2;
      matrix[i][n-1-j] = (matrix[i][n-1-j]+1)%2;
    }
  }
  matrix[n/2][n/2]=1;
}

//#####################################################################
//#####################################################################

void Variant1(int a, int b, int **arr) {
    //Zelenskii
    for (int i = 0; i < a; i++) {
        for (int j = 0; j < b; j++) {
            if (i % 2 == 0) {
                arr[i][j] = i * b + (j + 1);
            }
            else {
                arr[i][j] = i * b + (b - j);
            }
        }
    }
}

//#####################################################################
//#####################################################################

void Variant2(int a, int b, int** arr) {
    //Zelenskii
    for (int i = 0; i < b; i++) {
        for (int j = 0; j < a; j++) {
            if (i % 2 == 0) {
                arr[j][i] = i * a + (j + 1);
            }
            else {
                arr[j][i] = i * a + (a - j);
            }
        }
    }
}


//#####################################################################
//#####################################################################



void Variant7(int **matrix, int n){//for sqaure, 2k+1
    //Kapshuk
  for (int i=0; i<=n/2; i++){
    for (int j=0; j<n/2-i; j++){
      matrix[i][j]=0;
      matrix[n-i-1][j]=0;
      matrix[i][n-1-j]=0;
      matrix[n-i-1][n-1-j]=0;
    }
    for (int j=n/2-i; j<=n/2+i; j++){
      matrix[i][j]=1;
      matrix[n-i-1][j]=1;
    }
  }
}


//#####################################################################
//#####################################################################




void Variant3Zaranik(int rows, int cols, int** matr) {
    //Zaranik
    int cnt = 0, di, dj, i, j;


    makeBuffer(rows, cols, matr);//making buffer of -1


    matr[1][1] = 1;
    i = 1;//current pos
    j = 1;//current pos
    cnt = 1;
    di = 1, dj = -1;//direction
    while (cnt < rows * cols) {
        if (matr[i + di][j + dj] == 0) {
            i += di;
            j += dj;
            matr[i][j] = ++cnt;
        }
        else {
            di = -di;
            dj = -dj;
            //********************
            if (j == 1) {
                //left boarder
                if (matr[i + 1][j] == 0) {//down
                    i++;
                    matr[i][j] = ++cnt;
                }
                else {//right
                    j++;
                    matr[i][j] = ++cnt;
                }
            }
            else if (i == rows) {
                //bottom boarder
                j++;
                matr[i][j] = ++cnt;
            }
            //********************
            else if (j == cols) {
                //right boarder
                i++;
                matr[i][j] = ++cnt;
            }
            //********************
            else if (i == 1) {
                //left boarder
                if (matr[i][j + 1] == 0) {//down
                    j++;
                    matr[i][j] = ++cnt;
                }
                else {//right
                    i++;
                    matr[i][j] = ++cnt;
                }
            }
            //********************
        }
    }
    toZeroIndex(rows, cols, matr);
}

//#####################################################################
//#####################################################################

void makeBuffer(int rows, int cols, int** matr){
    for(int i=0; i<2+rows; i++)
        for(int j=0; j<2+cols; j++)
            matr[i][j]=-1;
     for(int i=1; i<1+rows; i++)
        for(int j=1; j<1+cols; j++)
            matr[i][j]=0;
}

//#####################################################################
//#####################################################################

void invert(int rows, int cols, int** matr){
    //inversing to "slime from the center"
    for(int i=0; i<rows; i++)
        for(int j=0; j<cols; j++)
            matr[i][j]=rows*cols-matr[i][j]+1;
}

//#####################################################################
//#####################################################################

void toZeroIndex(int rows,int cols,int** matr){
    for(int i=1; i<=rows; i++)
        for(int j=1; j<=cols; j++)
            matr[i-1][j-1]=matr[i][j];
}

//#####################################################################
//#####################################################################

void fill_Part(int **Matrix,int line,int border1,int border2,int way, int num_row, int num_col)  // Заповнення верхньої(нижньої частини матриці)
{
    //Adamchuk Anton
    //This func is used in function Variant13_Second.


    /*
        way==0 - Up
        way==1 - Down

    */

    if (way==0)           // Якщо заповнення іде доверху
    {
        while(line!=-1)      // Доки номер рядка, якого ми будемо заповняти не виходить за межі матриці зверху
        {
        if (border1>=0)      // Якщо border1 у межах матриці то на "діагоналі" з центра ставимо 5
        {
            Matrix[line][border1]=5;
        }
        if (border2<num_col) // Якщо border2 у межах матриці то на "діагоналі" з центра ставимо 5
        {
            Matrix[line][border2]=5;
        }
        if (border1<0)      // Якщо border1 поза межами матриці, надаємо йому значення(індекс стовця) найближчого до цієї матриці елеметна
        {
            border1=-1;
        }
          if (border2>num_col) // Якщо border2 поза межами матриці, надаємо йому значення(індекс стовця) найближчого до цієї матриці елеметна
        {
            border2=num_col;
        }
        for(int k=border1+1; k<border2;k++) // Заповнюємо матрицю одиничками у межах border1 < i < border2
        {
            Matrix[line][k]=1;
        }
        line-=1;            // Переміщуємося на одиницю вверх по рядках матриці
        border1-=1;         // Розширюємо межу вліво на один для збереження діагоналі
        border2+=1;         // Розширюємо межу вправо на один для збереження діагоналі
        }


    }
     // Цей самий алгоритм роботи і для заповнення вниз, але з рухом донизу
    if (way==1)
    {
        while(line!=num_row)
        {
            if (border2>=0)
            {
                Matrix[line][border2]=5;
            }
            if (border1<num_col)
            {
                Matrix[line][border1]=5;
            }
            if (border2<0)
            {
                border2=-1;
            }
              if (border1>num_col)
            {
                border1=num_col;
            }


            for(int k=border2+1; k<border1;k++)
            {
                 Matrix[line][k]=1;
            }
            line+=1;
            border1+=1;
            border2-=1;
        }


    }
}

//#####################################################################
//#####################################################################

void Variant13_Second(int **Matrix,int num_row, int num_col)
{
    //Adamchuk Anton
    for(int i=0;i<num_row;i++)
    {
        for(int j=0;j<num_col;j++)
        {
            Matrix[i][j]=0;             // Заповнення матриці нулями
        }
    }
    if((num_row%2!=0)&&(num_col%2!=0))  // К-сть рядків і стовпців непарна
    {
        int center_row=(num_row/2);     // Пошук центрального рядка матриці
        int center_col=(num_col/2);     // Пошук центрального стовпчика матриці
        fill_Part(Matrix, center_row,center_col,center_col,0, num_row, num_col);   // Точка відліку для заповнення - центр матриці.
        fill_Part(Matrix, center_row,center_col,center_col,1, num_row, num_col);
    }
    if((num_row%2!=0)&&(num_col%2==0))  // К-сть рядків непарна, стовпців парна
    {
        int center_row=(num_row/2);     // Центральний рядок матриці
        // У стовпцях буде 2 центри бо їх к-сть парна
        int center_col1=(num_col/2)-1;  // Перший центральний елемент стовпців
        int center_col2=(num_col/2);    // Другий центральний елемент стовпців
        fill_Part(Matrix, center_row,center_col1,center_col2,0, num_row, num_col);     // Заповнення відносно центрального рядка доверху межа зліва- перший центр стовпців, зправа-другий
        fill_Part(Matrix, center_row,center_col2,center_col1,1, num_row, num_col);   // Заповнення відносно центрального рядка донизу,тому тут змінюємо межі місцями межа зліва- другий центр стовпців, зправа-перший
    }
    // Для наступних випадків логіка така ж, як для двох вище описаних, якщо к-сть стовпців(рядків) парна - два центри, непарна- один
    if((num_row%2==0)&&(num_col%2!=0))
    {
        int center_row1=(num_row/2)-1;
        int center_row2=(num_row/2);
        int center_col=(num_col/2);
        fill_Part(Matrix, center_row1,center_col,center_col,0, num_row, num_col);
        fill_Part(Matrix, center_row2,center_col,center_col,1, num_row, num_col);
    }
        if((num_row%2==0)&&(num_col%2==0))
    {
        int center_row=(num_row/2)-1;
        int center_col1=(num_col/2)-1;
        int center_col2=(num_col/2);
        fill_Part(Matrix, center_row,center_col1,center_col2,0, num_row, num_col);
        fill_Part(Matrix, center_row,center_col1,center_col2,1, num_row, num_col);
    }
}


