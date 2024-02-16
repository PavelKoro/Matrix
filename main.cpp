#include <iostream>
#include "Equation.h"

using namespace std;

void output(char* arr, Matrix2D *ptr);

int main(int argc, char **argv) {
  Matrix2D* ptr = nullptr;
  int size = 0;
  char* arr;

  if(argc == 2) {
    arr = argv[1];
    size = ptr->size_fail(arr);
    if(size > 0) {
      Equation* C = new Equation(size);
      Gauss* B = new Gauss(size);
      Matrix2D* A = new Matrix2D(size);
      output(arr, A);
      output(arr, B);
      output(arr, C);
      delete C;
      delete B;
      delete A;
      ptr = nullptr;
    } else {
      printf("Не удвлось открыть файл: %s\n", arr);
    }
  } else if(argc > 2) {
      for(int i=1; i<argc; i++) {
        arr = argv[i];
        size = ptr->size_fail(arr);
        if(size > 0) {
          Equation* C = new Equation(size);
          Gauss* B = new Gauss(size);
          Matrix2D* A = new Matrix2D(size);  
          output(arr, A);
          output(arr, B);
          output(arr, C);
          delete C;
          delete B;
          delete A;
          ptr = nullptr;
          
          if(i < argc-1) {
            printf("----------------------------------------------------------------------\n");
          }
        } else {
          printf("Не удвлось открыть файл: %s\n", arr);
        }
      }
  } else {
    double num;
    int k=0, j=0;
    printf("Ведите размер матрицы (n*n): ");
    scanf("%d", &size);
    Equation* C = new Equation(size);
    Gauss* B = new Gauss(size);
    Matrix2D* A = new Matrix2D(size);
    Matrix2D* ptr = nullptr;
    for(int i=0; i<size*size; i++) {
      printf("A[%d, %d] = ", k, j);
      scanf("%lf", &num);
      A->fill(i, num);
      B->fill(i, num);
      C->fill(i, num);
      j++;
      if(j > (size-1)) {
        k++;
        j=0;
      }
      if(i == size*size-1) {
        printf("\n");
      }
    }
    ptr = A;
    ptr->print();
    ptr = B;
    ptr->print();
    ptr = C;
    ptr->print();
    delete C;
    delete B;
    delete A;
    ptr = nullptr;
  }
  return 0;
}

void output(char* arr, Matrix2D *ptr) {
  ptr->fill_fail(arr, ptr->size_fail(arr));
  ptr->print();
}