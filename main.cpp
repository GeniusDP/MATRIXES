#include <iostream>
#include "Variants.h"
#include "Interactive.h"

using namespace std;

//declared as extern in "Interactive.cpp"
const string sep="*****************************************************\n";

int main(){
    int rows, cols;
    int** matr;
    input(&rows, &cols, &matr);

    START_WORKING(rows, cols, matr);

    CLEAN(rows, cols, matr);
    return 0;
}
