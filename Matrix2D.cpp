#include <iostream>
#include "Matrix2D.h"

Matrix2D::Matrix2D(int n) {
    this->n = n;
    data = new double[n*n];
    for(int i=0; i<n*n; i++) data[i]=i;
}

Matrix2D::Matrix2D(Matrix2D &other) {
    this->n = other.n;
    data = new double[n*n];
    for(int i=0; i<n*n; i++) data[i]=other.data[i];
}

Matrix2D::~Matrix2D() {
    delete[] data;
}


int Matrix2D::err() { return ERROR; }

int Matrix2D::get_N() { return n; }

double Matrix2D::matrix_num(int i) { return data[i]; }

void Matrix2D::fill(int i, double num) {data[i] = num;}

void Matrix2D::fill_fail(char* arr, int n) {
  double num = 0;
  FILE* file = fopen(arr, "rb");
  if (file) {
    ERROR = 1;
    for(int i=0; i<n*n; i++) {
      fscanf(file, "%lf", &num);
      (*this).fill(i, num);    
    }
    fclose (file);
  } else{
    ERROR = -1;
  }
}

int Matrix2D::size_fail(char* arr) {
    int size = 0;
    double num = 0;
    FILE* file = fopen(arr, "rb");
    if (file) {
        while (!feof(file)) {
        fscanf(file, "%lf", &num);    
        size++;
        }
        fclose (file);
        size = sqrt(size);
    } else{
        size = -1;
    }
    return size;
}   

void Matrix2D::print() {
    printf("Matrix2D:\n");
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            printf("%9f ", (*this)[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

double* Matrix2D::operator[](int i) {
    return &(data[n*i]); // data + n*i
}