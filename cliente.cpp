#include <iostream>
#include <string>
#include "matriz.h"

 using namespace std;

 int main(){

    Matriz X(3,3), A(3,3), C(3,3);
    A.unit();
    cout << A << endl;
    A(2,1)=10;
    cout << A << endl;
    C.zeros();
    cout << C << endl;
    //C=A+A; // Soma
    //C-=A; // Subtração
    //A=C-A; // Subtração
    //A+=A; // Soma
    //A=~C; // A é igual a transposta de C
    X.ones(); // inicializa X com 1s
    cout << X << endl;
    //X*=2; // multiplicação por uma constante
    //C=A*X; // multiplicação de matrizes
    //C*=X; // multiplicação de matrizes
    cout << C << endl; // Impressão de matrizes
    int numerolinhas = A.getRows();
    int numerocolunas= A.getCols();
    cout << numerolinhas << " " << numerocolunas << endl;

    return 1;
 }

