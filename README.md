# Trabalho Intermediário 1 - Conceitos Básicos de POO
Universidade Federal de Minas Gerais, abril de 2018
Ariel de Souza Ribeiro - http://github.com/arieldsr
João Pedro Temponi de Andrade - 

## Tarefa
  Crie uma classe Matriz que permita que sejam feitas operações matemáticas similares às do Matlab para matrizes do double. O seguinte código é um exemplo de programa cliente para a sua classe:
  ```cpp
  Matriz X(3,1), A(3,3), C(3,3);
  A.unit(); // inicializa A como uma matriz identidade
  A(2,1)=10; // altera o valor de uma posição de A
  C.zeros(); // inicializa C com zeros
  C=A+A; // Soma
  C-=A; // Subtração
  A=C-A; // Subtração
  A+=A; // Soma
  A=~C; // A é igual a transposta de C
  X.ones(); // inicializa X com 1s
  X*=2; // multiplicação por uma constante
  C=A*X; // multiplicação de matrizes
  C*=X; // multiplicação de matrizes
  cout << C << endl; // Impressão de matrizes
  int numerolinhas = A.getRows();
  numerocolunas= A.getCols()
  ```
