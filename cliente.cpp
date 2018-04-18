#include <iostream>
#include <string>
#include "matriz.h"

 using namespace std;

 int main(){
    Matriz X(3,3), A(3,3), C(3,3);

    A.unit();
    cout << "Matriz identidade:" << endl << A << endl;
    
    A(2,1)=10;
    cout << "A(2,1)=10" << endl << A << endl;
    
    C.zeros();
    cout << "Matriz de zeros:" << endl << C << endl;

    //C=A+A; // Soma
    //cout << "C=A+A:" << endl << C << endl;

    C-=A; // Subtração
    cout << "C-=A" << endl << C << endl;

    //A=C-A; // Subtração
    //cout << "C=C-A" << endl << C << endl;

    A+=A; // Soma
    cout << "A+=A" << endl << A << endl;

    //A=~C; // A é igual a transposta de C
    
    X.ones(); // inicializa X com 1s
    cout << "Matriz de 1s:" << endl << X << endl;
    
    //X*=2; // multiplicação por uma constante
    
    //C=A*X; // multiplicação de matrizes
    
    //C*=X; // multiplicação de matrizes
    //cout << "C=C*X:" << endl << C << endl;
    
    cout << C << endl; // Impressão de matrizes
    
    int numerolinhas = A.getRows();
    int numerocolunas= A.getCols();
    cout << numerolinhas << " " << numerocolunas << endl;

    delete &A, &C, &X;

    return 1;
 }

