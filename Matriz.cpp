#include "Matriz.h"

 using namespace std;

Matriz::Matriz(int rows, int cols){
    this->rows = rows;
    this->cols = cols;
    this->vetor = (double**) malloc(rows*sizeof(double*));
    for (int i = 0; i < rows; i++) this->vetor[i] = (double*) malloc(cols*sizeof(double));
}

Matriz::~Matriz(){
    int rows = getRows();
    for (int i = 0; i < rows; i++) free(this->vetor[i]);
    free(this->vetor);
}

double & Matriz::operator()(unsigned int x, unsigned int y){
    if ((x > this->getRows())&&(y > this->getCols())) throw "Índice fora da Matriz.";
    else return vetor[x][y];
}

Matriz& Matriz::operator+=(const Matriz &A){
    for(int i = 0; i < A.rows; i++){
        for(int j = 0; j < A.cols; j++){
             this->vetor[i][j] += A.vetor[i][j];
        }    
    }
    return *this;
}

int Matriz::getRows(){
    return this->rows;
}

int Matriz::getCols(){
    return this->cols;
}

void Matriz::zeros(){
    int rows = this->getRows(), cols = this->getCols();

    for (int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            this->vetor[i][j] = 0;
        }
    }
}

void Matriz::ones(){
    int rows = this->getRows(), cols = this->getCols();

    for (int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            this->vetor[i][j] = 1;
        }
    }
}

void Matriz::unit(){
    int rows = this->getRows(), cols = this->getCols();
    int minimo;

    if (rows < cols) minimo = rows;
    else minimo = cols;

    this->zeros();
    for (int i = 0; i < minimo; i++){
        this->vetor[i][i] = 1;
    }
}

ostream & operator<<(ostream & os, const Matriz &A){
    for (int i = 0; i < A.rows; i++){
        os << A.vetor[i][0];
        for(int j = 1; j < A.cols; j++){
            os << " " << A.vetor[i][j];
        }
        os << endl;
    }
    return os;
}
