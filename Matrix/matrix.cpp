#include<iostream>
#include<cassert>
#include<vector>
#include<cmath>
#include"matrix.h"

/*          Vector class methods        */

int vector::size() {
    return elements.size();
}

double& vector::operator[](int index) {
    return elements[index];
}

/*          rowVector class methods           */

rowVector rowVector::operator+(const rowVector& other) const {
    assert(elements.size() == other.elements.size()); 
    std::vector<double> result(elements.size());
    for (size_t i = 0; i < elements.size(); ++i) {
            result[i] = elements[i] + other.elements[i];
        }
    return rowVector(result);
}

rowVector rowVector::operator-(const rowVector& other) const {
    assert(elements.size() == other.elements.size());
    std::vector<double> result(elements.size());
    for (size_t i = 0; i < elements.size(); ++i) {
            result[i] = elements[i] - other.elements[i];
        }
    return rowVector(result);
}

rowVector rowVector::operator/(const double& num) const {
    assert(num != 0);
    std::vector<double> result(elements.size());
    for (size_t i = 0; i < elements.size(); ++i) {
            result[i] = elements[i]/num;
    }
    return rowVector(result);
}

void rowVector::print() {
    for (size_t i = 0; i < elements.size(); i++) {
        std::cout << elements[i] << " ";
    }
    std::cout << "\n";
}

bool compare(vector a, vector b, double acc) {
    assert(a.size() == b.size());
    
    for (int i = 0; i < a.size(); i++) {
        if (abs(a[i] - b[i]) > acc) {
            return false;
        }
    }
    return true;
}


/*          rowVector class methods           */

colVector colVector::operator+(const colVector& other) const {
    assert(elements.size() == other.elements.size()); 
    std::vector<double> result(elements.size());
    for (size_t i = 0; i < elements.size(); ++i) {
            result[i] = elements[i] + other.elements[i];
        }
    return colVector(result);
}

colVector colVector::operator-(const colVector& other) const {
    assert(elements.size() == other.elements.size());
    std::vector<double> result(elements.size());
    for (size_t i = 0; i < elements.size(); ++i) {
            result[i] = elements[i] - other.elements[i];
        }
    return colVector(result);
}

colVector colVector::operator/(const double& num) const {
    assert(num != 0);
    std::vector<double> result(elements.size());
    for (size_t i = 0; i < elements.size(); ++i) {
            result[i] = elements[i]/num;
    }
    return colVector(result);
}

void colVector::print() {
    for (size_t i = 0; i < elements.size(); i++) {
        std::cout << elements[i] << "\n";
    }
}


/*              Matrix class                */

int matrix::cols() {
    return elements.size();
}
/* Returns number of rows.*/
int matrix::rows() {
    /* Returns number of rows.*/
    return elements[0].size();
}

double& matrix::operator()(int row, int col) {
    assert(row >= 0);
    assert(col >= 0);
    assert(row < rows());
    assert(col < cols());

    colVector& v = elements[col];

    return v[row];
}

void matrix::print() {
    for (int i = 0; i < rows(); i++) {
        for(int j = 0; j < cols(); j++) {
            std::cout << elements[j][i] << " ";
        }
        std::cout << "\n";
    }
}

matrix matrix::operator+(matrix& other) {
    assert(rows() == other.rows());
    assert(cols() == other.cols());

    matrix A(rows(), cols());

    for (int i = 0; i < cols(); i++) {
        for (int j = 0; j < rows(); j++) {
            A(j,i) = elements[i][j] + other(j,i);
        }
    }
    return A;
}

matrix matrix::operator-(matrix& other) {
    assert(rows() == other.rows());
    assert(cols() == other.cols());

    matrix A(rows(), cols());

    for (int i = 0; i < cols(); i++) {
        for (int j = 0; j < rows(); j++) {
            A(j,i) = elements[i][j] - other(j,i);
        }
    }
    return A;
}


matrix matrix::operator/(const double& num) {
    assert(num != 0);
    matrix A(rows(),cols());

    for (int i = 0; i < rows(); i++) {
        for (int j = 0; j < cols(); j++) {
            A(i,j) = elements[j][i]/num;
        }
    }
    return A;
}

colVector& matrix::col(const int& index) {
    return elements[index];
}


/*      vector operations         */

double operator*(rowVector v, colVector u) {
    assert(v.size() == u.size());
    double result = 0;

    for (int i = 0; i < v.size(); i++) {
        result += v[i] * u[i];
    } 
    return result;
}

matrix operator*(colVector v, rowVector u) {
    assert(v.size() == u.size());

    matrix M(v.size(),u.size());

    for (int i = 0; i < v.size(); i++) {
        for (int j = 0; j < u.size(); j++) {
            M(j,i) = v[i] * u[j];
        }
    }
    return M;
}

matrix operator*(matrix A, matrix B) {
    assert(A.cols() == B.rows());

    matrix product(A.rows(),B.cols());

    for (int i = 0; i < A.rows();i++) {
        for (int j = 0; j < B.cols(); j++) {
            double sum = 0;
            for (int k = 0; k < A.cols(); k++) {
                sum += A(i,k) * B(k,j);
            }
            product(i,j) = sum;
        }
    }
    return product;
}

double dot(colVector v, colVector u) {
    assert(v.size() == u.size());
    double result = 0;

    for (int i = 0; i < v.size(); i++) {
        result += v[i] * u[i];
    }
    return result;
}

double dot(rowVector v, rowVector u) {
    assert(v.size() == u.size());
    double result = 0;

    for (int i = 0; i < v.size(); i++) {
        result += v[i] * u[i];
    }
    return result;
}

colVector operator*(colVector v, double num) {

    for (int i = 0; i < v.size(); i++) {
        v[i] *= num;
    } 
    return v;
}
colVector operator*(double num, colVector v) {

    for (int i = 0; i < v.size(); i++) {
        v[i] *= num;
    } 
    return v;
}

rowVector operator*(rowVector v, double num) {
    for (int i = 0; i < v.size(); i++) {
        v[i] *= num;
    } 
    return v;
}

rowVector operator*(double num, rowVector v) {
    for (int i = 0; i < v.size(); i++) {
        v[i] *= num;
    } 
    return v;
}

rowVector transpose(colVector v) {

    std::vector<double> elements(v.size());

    for (int i = 0; i < v.size(); i++) {
        elements[i] = v[i];
    }

    return rowVector(elements);
}

colVector transpose(rowVector v) {

    std::vector<double> elements(v.size());

    for (int i = 0; i < v.size(); i++) {
        elements[i] = v[i];
    }

    return colVector(elements);
}

colVector unitVector(int size, int index) {
    colVector e(size);
    e[index] = 1;
    return e;
}

double norm(vector v) {
    double result = 0;

    for (int i = 0; i < v.size(); i++) {
        result += v[i] * v[i];
    }
    return std::sqrt(result);
}


/*      matrix operations       */

matrix operator*(matrix A, double num) {

    matrix M(A.rows(), A.cols());

    for (int i = 0; i < A.rows(); i++) {
        for (int j = 0; j < A.cols(); j++) {
            M(i,j) = A(i,j) * num;
        }
    }
    return M;
}

matrix operator*(double num, matrix A) {

    matrix M(A.rows(), A.cols());

    for (int i = 0; i < A.rows(); i++) {
        for (int j = 0; j < A.cols(); j++) {
            M(i,j) = A(i,j) * num;
        }
    }
    return M;
}

colVector operator*(matrix A, colVector b) {
    assert(A.cols() == b.size());

    colVector x(A.rows());

    for (int i = 0; i < A.rows();i++) {
        for (int j = 0; j < A.cols(); j++) {
            x[i] += A(i,j) * b[j];
        }
    }
    return x;
}

rowVector operator*(rowVector b, matrix A) {
    assert(b.size() == A.rows());

    rowVector x(A.cols());

    for (int i = 0; i < A.cols();i++) {
        for (int j = 0; j < A.rows(); j++) {
            x[i] += A(j,i) * b[j];
        }
    }
    return x;
}

matrix transpose(matrix A) {
    int m = A.rows();
    int n = A.cols();
    matrix T(n,m);

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            T(j,i) = A(i,j);
        }
    }
    return T;
}  

bool compare(matrix A, matrix B, double acc) {
    
    assert(A.cols() == B.cols());
    assert(A.rows() == B.rows());
    

    for (int i = 0; i < A.rows(); i++) {
        for (int j = 0; j < A.cols(); j++) {
            if (A(i,j) - B(i,j) > acc) {
                return false;
            }
        }
    }
    return true;
}


matrix id(int size) {
    matrix I(size,size);

    for (int i = 0; i < size; i++) {
        I(i,i) = 1;
    }
    return I;
}