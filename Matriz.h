//AS FUNÇÕES QUE NÃO ESTÃO COMENTADAS SÃO AS QUE JÁ ESTÃO IMPLEMENTADAS

#ifndef MATRIZ_H 
#define MATRIZ_H

#include <iostream>

class Matriz{
    private:
    int rows;
    int cols;
    double **vetor;
    void alocaVetor();

    public:
    Matriz(int rows, int cols); //Função construtora
    Matriz(const Matriz& original);//Construtor de cópia
    ~Matriz(); //Função destrutora
    
    double& operator()(unsigned int x, unsigned int y); //A(x, y) = k;
    Matriz& operator=(const Matriz &A); //Operador de atribuição
    Matriz& operator+=(const Matriz &A); //Soma de matrizes
    Matriz& operator-=(const Matriz &A); //Subtração de matrizes
    Matriz& operator*=(const Matriz &A); //Multiplicação de matrizes
    Matriz& operator~(); // A é igual a transposta de C
    Matriz & operator*=(double x); //Multiplicação por uma constante
    friend std::ostream & operator<<(std::ostream & os, const Matriz &A);

    void unit(); //Inicializa uma matriz identidade
    void zeros(); //Inicializa a matriz com zeros
    void ones(); //Inicializa a matriz com 1s
    int getRows(); //Retorna número de linhas
    int getCols(); //Retorna número de colunas
};

Matriz operator+(const Matriz &A, const Matriz &B); //Soma de matrizes
Matriz operator-(const Matriz &A, const Matriz &B);//Subtração de matrizes
Matriz operator*(const Matriz &A, const Matriz &B);//Multiplicação de matrizes

#endif