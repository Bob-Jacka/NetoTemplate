#ifndef TABLE_H
#define TABLE_H

#include <stdexcept>

import Libio;

template <typename T>
class Table {
    T** inner_representation_array;
    int rows;
    int cols;

public:

    Table() = delete;

    Table(const int r, const int c) : rows(r), cols(c) {
        if (rows < 0 || cols < 0) {
            throw std::invalid_argument("Size cannot be negative value");
        }
        inner_representation_array = new T*[rows];
        for (int i = 0; i < rows; ++i) {
            inner_representation_array[i] = new T[cols]();
        }
    }

    Table(const Table& other) : rows(other.rows), cols(other.cols) {
        inner_representation_array = new T*[rows];
        for (int i = 0; i < rows; ++i) {
            inner_representation_array[i] = new T[cols];
            for (int j = 0; j < cols; ++j) {
                inner_representation_array[i][j] = other.inner_representation_array[i][j];
            }
        }
    }

    Table& operator=(const Table& other) {
        if (this != &other) {
            for (int i = 0; i < rows; ++i) {
                delete[] inner_representation_array[i];
            }
            delete[] inner_representation_array;

            rows = other.rows;
            cols = other.cols;
            inner_representation_array = new T*[rows];
            for (int i = 0; i < rows; ++i) {
                inner_representation_array[i] = new T[cols];
                for (int j = 0; j < cols; ++j) {
                    inner_representation_array[i][j] = other.inner_representation_array[i][j];
                }
            }
        }
        return *this;
    }

    ~Table() {
        libio::array::deleteDynamicArray(inner_representation_array, this->rows);
    }

    Table(Table&&) = delete;
    Table& operator=(Table&&) = delete;

    T* operator[](int index) {
        if (index < 0 || index >= rows) {
            throw std::out_of_range("Index out of bound");
        }
        return inner_representation_array[index];
    }

    const T* operator[](int index) const {
        if (index < 0 || index >= rows) {
            throw std::out_of_range("Index out of bound");
        }
        return inner_representation_array[index];
    }

    [[nodiscard]] int size() const {
        return rows * cols;
    }
};

#endif  // TABLE_H