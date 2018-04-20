#include "Matriz.h"

 using namespace std;

void Matriz::alocaVetor(){
    this->vetor = (double**) malloc(this->rows*sizeof(double*));
    if (this->vetor == NULL){
        cerr << "Erro ao alocar matriz." << endl;
        exit(0);
    }
    for (int i = 0; i < this->rows; i++){
        this->vetor[i] = (double*) malloc(this->cols*sizeof(double));
        if (this->vetor[i] == NULL){
            cout << "Erro ao alocar matriz." << endl;
            exit(0);
        }   
    } 
}

Matriz::Matriz(int rows, int cols){
    this->rows = rows;
    this->cols = cols;
    this->alocaVetor();
    this->zeros();
}

Matriz::Matriz(const Matriz& original){
    this->rows = original.rows;
    this->cols = original.cols;
    this->alocaVetor();
    for (int i = 0; i < this->rows; i++){
        for (int j = 0; j < this->cols; j++){
            this->vetor[i][j] = original.vetor[i][j];
        }
    }  
}

Matriz::~Matriz(){
    for (int i = 0; i < this->rows; i++) delete [] this->vetor[i];
    delete [] this->vetor;
}

double& Matriz::operator()(unsigned int x, unsigned int y){
    if ((x > this->getRows())&&(y > this->getCols())) throw "Índice fora da Matriz.";
    else return vetor[x][y];
}

Matriz& Matriz::operator=(const Matriz &A){
    if (this == &A) return *this;
    if ((this->rows != A.rows)||(this->cols != A.cols)){
        for (int i = 0; i < rows; i++) delete [] this->vetor[i];
        delete [] this->vetor;
        this->rows = A.rows;
        this->cols = A.cols;
        this->alocaVetor();
    }
    for (int i = 0; i < this->rows; i++){
        for (int j = 0; j < this->cols; j++){
            this->vetor[i][j] = A.vetor[i][j];
        }
    }
}

Matriz& Matriz::operator+=(const Matriz &A){
    if ((A.cols != this->cols)||(A.rows != this->rows)){
        cerr << "Matrizes de ordem diferentes. Não foi possível realizar a soma." << endl;
    }
    else{
        for(int i = 0; i < A.rows; i++){
            for(int j = 0; j < A.cols; j++){
                this->vetor[i][j] += A.vetor[i][j];
            }    
        }
    }
    return *this;
}

Matriz& Matriz::operator-=(const Matriz &A){
    if ((A.cols != this->cols)||(A.rows != this->rows)){
        cerr << "Matrizes de ordem diferentes. Não foi possível realizar a subtração." << endl;
    }
    else{
        for(int i = 0; i < A.rows; i++){
            for(int j = 0; j < A.cols; j++){
                this->vetor[i][j] -= A.vetor[i][j];
            }    
        }
    }
    return *this;
}

Matriz& Matriz::operator*=(const Matriz &A){
    if (this->cols != A.rows) throw "Ordem incompatível. Não foi possível realizar a multiplicação.";

    Matriz Resultado(this->rows, A.cols);
    Resultado.zeros();

    for(int i = 0; i < Resultado.rows; i++){
        for(int j = 0; j < Resultado.cols; j++){
            for(int k = 0; k < this->cols; k++){
                Resultado.vetor[i][j] += (this->vetor[i][k])*(A.vetor[k][j]);
            }
        }    
    }
    
    return (*this = Resultado);
}

int Matriz::getRows(){
    return this->rows;
}

int Matriz::getCols(){
    return this->cols;
}

void Matriz::zeros(){
    for (int i = 0; i < this->rows; i++){
        for(int j = 0; j < this->cols; j++){
            this->vetor[i][j] = 0;
        }
    }
}

void Matriz::ones(){
    for (int i = 0; i < this->rows; i++){
        for(int j = 0; j < this->cols; j++){
            this->vetor[i][j] = 1;
        }
    }
}

void Matriz::unit(){
    int minimo;

    if (this->rows < this->cols) minimo = this->rows;
    else minimo = this->cols;

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

Matriz operator+(const Matriz &A, const Matriz &B){
    Matriz Resultado(A);
    return (Resultado += B);
}

Matriz operator-(const Matriz &A, const Matriz &B){
    Matriz Resultado(A);
    return (Resultado -= B);
}

/*Matriz operator*(const Matriz &A, const Matriz &B){
    Matriz Resultado(A);
    return (Resultado *= B);
}*/