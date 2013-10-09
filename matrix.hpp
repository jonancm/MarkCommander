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

#ifndef MATRIX_HPP_8BSA1YFN
#define MATRIX_HPP_8BSA1YFN

#include "exception.hpp"

typedef unsigned int uint;
typedef long double real;

class Matrix {
    uint     _rows;
    uint     _cols;
    real    **array;
    
public:
                Matrix(uint rows, uint cols);
               ~Matrix();
    uint        rows() const;
    uint        cols() const;
    real        at(uint row, uint col) const;
    real &      at(uint row, uint col);
    Matrix &    operator=(const Matrix &matrix);
    Matrix      operator+(const Matrix &matrix) const;
    Matrix      operator-(const Matrix &matrix) const;
    Matrix      operator*(const Matrix &matrix) const;
    void        print();
};

class OutOfRange : Exception
{
public:
    OutOfRange();
};

class IncompatibleDimensions : Exception
{
public:
    IncompatibleDimensions();
};

#endif /* end of include guard: MATRIX_HPP_8BSA1YFN */
