#pragma once

// N by M matrix representation. Not for linear transformations, just for storing level data (as of now).

#include <vector>
#include <iostream>

// Kill me idc.
using namespace std;

template<class T = char>
class Matrix {
  private:
    vector<T> entries;
    size_t rows;
    size_t cols;
  
  public:
    Matrix(size_t rows_, size_t cols_, const T& val) : 
      rows{rows_}, 
      cols{cols_}, 
      entries{vector<T>(rows_ * cols_, val)} {}

    Matrix(size_t rows_, size_t cols_, const vector<T>& entries_) {
      if (rows_ * cols_ != entries_.size()) {
        throw invalid_argument("Dimensions must match.");
      }
      rows = rows_;
      cols = cols_;
      entries = entries_;
    }
    
    Matrix(size_t rows_, size_t cols_, const initializer_list<T>& entries_) {
      if (rows_ * cols_ != entries_.size()) {
        throw invalid_argument("Dimensions must match.");
      }
      rows = rows_;
      cols = cols_;
      entries = vector<T>(entries_);
    } 
    
    ~Matrix() = default;
    
    vector<T>& get_entries() {
      return entries;
    }
    
    size_t& get_rows() {
      return rows;
    }
    
    size_t& get_cols() {
      return cols;
    }

    void set_entry(size_t i, size_t j, T& val) {
      entries.at(rows * i + j) = val;
    }

    T& operator()(size_t i, size_t j) {
      return entries.at(rows * i + j);
    }
    
    const T& operator()(size_t i, size_t j) const {
      return entries.at(rows * i + j);
    }

    friend ostream& operator<<(ostream& out, const Matrix<T>& mat) {
      for (size_t i = 0; i < mat.rows; ++i) {
        out << "{";
        for (size_t j = 0; j < mat.cols; ++j) {
          if (j == mat.cols - 1) {
            out << mat(i, j);
            continue;
          }
          out << mat(i, j) << ", ";
        }
        out << "}\n";
      }

      return out;
    }
};



