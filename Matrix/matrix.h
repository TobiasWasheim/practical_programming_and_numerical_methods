#ifndef HAVE_MATRIX_H
#define HAVE_MATRIX_H

#include<cassert>
#include<vector>
#include<functional>

class vector {
protected:
    std::vector<double> elements;
    bool is_null = false;

public:
    vector() : is_null(true) {}
    vector(int size) : elements(size), is_null(false) {
        assert(size >= 0);
    }
    vector(std::initializer_list<double> list) : elements(list), is_null(false) {} 
    vector(std::vector<double> list) : elements(list), is_null(false) {} 
    bool isNull() const { return is_null; }
    /*Return size of vector*/
    int size();
    double& operator[](int index);
    void print();
};

class rowVector : public vector {
public:

    using vector::vector;


    rowVector operator+(const rowVector& other) const;
    rowVector operator-(const rowVector& other) const;
    rowVector operator/(const double& num) const;

    void print();
};

class colVector : public vector {
public:    
    using vector::vector;

    colVector operator+(const colVector& other) const;
    colVector operator-(const colVector& other) const;
    colVector operator/(const double& num) const;

    colVector map(std::function<double(double)> f);

    void print();
};


class matrix {
private:
    std::vector<colVector> elements = {{0}};

public:
    matrix() = default;
    matrix(int rows, int cols) : elements(cols) {
        assert(rows >= 0);
        assert(cols >= 0);

        for (int i = 0; i < cols; i++) {
            colVector v(rows);
            for (int j = 0; j < rows; j++) {
                v[j] = 0;
            }
            elements[i] = v;
        }
    }
    matrix(std::vector<colVector> values) : elements(values) {
        double col_0 = values[0].size();
        for (int i = 0; i < values.size();i++) {
            assert(col_0 == values[i].size() && "All columns must have the same length");
        }
    }
    matrix(std::initializer_list<colVector> values) : elements(values) {}
    /**
     * Returns number of rows
     * 
     */
    int rows();
    /* Returns number of columns.*/
    int cols();
    void print();
    colVector& col(const int& index);
    rowVector& row(const int& index);
    colVector& operator[](const int& index);
    double& operator()(int row, int col);
    matrix operator+(matrix& other);
    matrix operator-(matrix& other);
    matrix operator/(const double& num);
    


};

/*      Vector operations       */
double operator*(rowVector v, colVector u);
matrix operator*(colVector v, rowVector u);
double dot(colVector v, colVector u);
double dot(rowVector v, rowVector u);

colVector operator*(colVector v, double num);
colVector operator*(double num, colVector v);
rowVector operator*(rowVector v, double num);
rowVector operator*(double num, rowVector v);

rowVector transpose(colVector v);
colVector transpose(rowVector v);
colVector unitVector(int size, int index);
double norm(vector v);
bool compare(vector a, vector b, double acc = 1e-4);



/*      Matrix operations       */

matrix operator*(matrix A, double num);
matrix operator*(double num, matrix A);
matrix operator*(matrix A, matrix B);
matrix transpose(matrix A);
colVector operator*(matrix A, colVector b);
rowVector operator*(rowVector b, matrix A);
bool compare(matrix A, matrix B, double acc = 1e-4);

matrix id(int size);


// In the future I might add a method that inverses the matrix or pseudo inverses. 
#endif