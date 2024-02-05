#include <iostream>

void addRow(int**& m,int& rows,int columns) {
    int** m2 = new int* [rows + 1];
    for (int i = 0; i < rows; i++) {
        m2[i] = new int[columns];
        for (int j = 0; j < columns; j++)
            m2[i][j] = m[i][j];
    }
    m2[rows] = new int[columns];
    for (int j = 0; j < columns; j++)
        m2[rows][j] = rows + j;

    for (int i = 0; i < rows; i++) {
        delete[] m[i];
    }
    delete[] m;
    m = new int* [rows + 1];
    for (int i = 0; i < rows + 1; i++) {
        m[i] = new int[columns];
        for (int j = 0; j < columns; j++)
            m[i][j] = m2[i][j];
    }
    rows++;
}

void addColumn(int**& m, int rows, int& columns) {
    int** m3 = new int* [rows];
    for (int i = 0; i < rows; i++) {
        m3[i] = new int[columns + 1];
        for (int j = 0; j < columns; j++)
            m3[i][j] = m[i][j];
        m3[i][columns] = columns + i;
    }

    for (int i = 0; i < rows; i++) {
        delete[] m[i];
    }
    delete[] m;
    m = new int* [rows];
    for (int i = 0; i < rows; i++) {
        m[i] = new int[columns + 1];
        for (int j = 0; j < columns + 1; j++)
            m[i][j] = m3[i][j];
    }
    columns++;
}

int main()
{
    int rows = 5;
    int columns = 3;

    int** m = new int* [rows];
    for (int i = 0; i < rows; i++) {
        m[i] = new int[columns];
        for (int j = 0; j < columns; j++)
            m[i][j] = i + j;
    }

    addRow(m, rows, columns);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++)
            std::cout << m[i][j] << " ";
        std::cout << std::endl;
    }

    addColumn(m, rows, columns);

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++)
            std::cout << m[i][j] << " ";
        std::cout << std::endl;
    }
}