#include <iostream>
#include "Gauss.h"

Gauss::Gauss(int n): Matrix2D(n) {
    arr = new double[n*n];
    for(int i=0; i<n*n; i++) arr[i]=i;
}

Gauss::Gauss(Gauss &other): Matrix2D(other) {
    arr = new double[n*n];
    for(int i=0; i<n*n; i++) arr[i]=other.arr[i];
}

Gauss::~Gauss() {
    delete[] arr;
}

void Gauss::gauss_method() {
    int max = 0;
    sign = 1;
    for(int i=0; i<n; i++) {
        max = max_column(i);
        if(i != max) {
            sign *= -1;
            swap_line(i, max);
        }
    }
    for(int i=0; i<n; i++) {
        for(int j=i; j<n; j++) {
            arithmetic(i,j);
        }
    }
}

double Gauss::det() {
    double value = 1;
    Gauss copy = (*this);
    copy.gauss_method();
    for(int i=0; i<n; i++) {
        value *= copy[i][i];
    }
    return (copy.sign*value);
}

int Gauss::max_column(int num_column) {
    int max = num_column;
    for(int i=num_column; i<n; i++) {
      if(abs((*this)[max][num_column]) < abs((*this)[i][num_column])) {
        max = i;
      }
    }
    return max;
}

void Gauss::swap_line(int line_1, int line_2) {
    int tmp;
    for(int j=0; j<n; j++) {
        tmp = (*this)[line_1][j];
        (*this)[line_1][j] = (*this)[line_2][j];
        (*this)[line_2][j] = tmp;
    }
}

void Gauss::arithmetic(int line_1, int line_2) {
    if(line_1 != line_2) {
        if((*this)[line_1][line_1] != 0) {
            double k = (*this)[line_2][line_1]/(*this)[line_1][line_1];
            for(int j=line_1; j<n; j++) {
                (*this)[line_2][j] = (*this)[line_2][j] - ((*this)[line_1][j]*k);
            }
        }
    }
}

void Gauss::print() {
    printf("det() = %f\n", (*this).det());
}