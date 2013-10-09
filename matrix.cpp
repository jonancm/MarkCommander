// Copyright 2011 Jonán C. Martín
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//   http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#include "matrix.hpp"

#include <iostream>
using namespace std;

Matrix::Matrix(uint rows, uint cols)
{
    _rows = rows;
    _cols = cols;
    
    array = new real*[rows];
    for (uint i = 0; i < rows; i++)
    {
        array[i] = new real[cols];
        for (uint j = 0; j < cols; j++)
            array[i][j] = 0;
    }
}

Matrix::~Matrix()
{
    for (uint i = 0; i < rows(); i++)
        delete[] array[i];
    delete[] array;
}

uint Matrix::rows() const
{
    return _rows;
}

uint Matrix::cols() const
{
    return _cols;
}

real Matrix::at(uint row, uint col) const
{
    if (row < 1 || row > rows() || col < 1 || col > cols())
        throw new OutOfRange();
    return array[row - 1][col - 1];
}

real & Matrix::at(uint row, uint col)
{
    if (row < 1 || row > rows() || col < 1 || col > cols())
        throw new OutOfRange();
    return array[row - 1][col - 1];
}

/*
 * http://en.wikipedia.org/wiki/Assignment_operator_in_C%2B%2B
 */
Matrix & Matrix::operator=(const Matrix &matrix)
{
    if (this != &matrix) // protect against self-assignment 
    {
        real **new_array = new real*[matrix.rows()];
        for (uint i = 0; i < matrix.rows(); i++)
        {
            new_array[i] = new real[matrix.cols()];
            for (uint j = 0; j < matrix.cols(); j++)
                new_array[i][j] = matrix.at(i+1, j+1);
            delete[] array[i];
        }
        delete[] array;
        array = new_array;
        _rows = matrix.rows();
        _cols = matrix.cols();
    }
    return *this;
}

Matrix Matrix::operator+(const Matrix &matrix) const
{
    if (rows() != matrix.rows() || cols() != matrix.cols())
        throw new IncompatibleDimensions();
    
    Matrix new_matrix(rows(), cols());
    for (uint i = 0; i < rows(); i++)
    {
        for (uint j = 0; j < cols(); j++)
            new_matrix.at(i+1, j+1) = array[i][j] + matrix.at(i+1, j+1);
    }
    return new_matrix;
}

Matrix Matrix::operator-(const Matrix &matrix) const
{
    if (rows() != matrix.rows() || cols() != matrix.cols())
        throw new IncompatibleDimensions();
    
    Matrix new_matrix(rows(), cols());
    for (uint i = 0; i < rows(); i++)
    {
        for (uint j = 0; j < cols(); j++)
            new_matrix.at(i+1, j+1) = array[i][j] - matrix.at(i+1, j+1);
    }
    return new_matrix;
}

Matrix Matrix::operator*(const Matrix &matrix) const
{
    if (cols() != matrix.rows())
        throw new IncompatibleDimensions();
    
    Matrix new_matrix(rows(), matrix.cols());
    for (uint i = 0; i < rows(); i++)
    {
        for (uint j = 0; j < matrix.cols(); j++)
        {
            for (uint k = 0; k < cols(); k++)
                new_matrix.at(i+1, j+1) +=  array[i][k] * matrix.at(k+1, j+1);
        }
    }
    return new_matrix;
}

void Matrix::print()
{
    cout << endl;
    for (uint i = 1; i <= rows(); i++)
    {
        for (uint j = 1;  j <= cols();  j++)
            cout << at(i, j) << "\t";
        cout << endl;
    }
    cout << endl;
}

OutOfRange::OutOfRange()
{
    _description = "Index out of range";
    setMessage("Index out of range");
}

IncompatibleDimensions::IncompatibleDimensions()
{
    _description = "Incompatible dimensions";
    setMessage("Incompatible dimensions");
}
