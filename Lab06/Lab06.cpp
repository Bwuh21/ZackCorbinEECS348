#include <iostream>
#include <fstream>

const int MAX_SIZE = 100;


void readMatrix(std::ifstream& file, int matrix[MAX_SIZE][MAX_SIZE], int& size) {
    if (file >> size) { 
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                file >> matrix[i][j];
            }
        }
    } else {
        std::cerr << "Error: Unable to read size from the file." << std::endl;
        exit(1);
    }
}


void printMatrix(const int matrix[MAX_SIZE][MAX_SIZE], int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
}


void addMatrices(const int matrixA[MAX_SIZE][MAX_SIZE], const int matrixB[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            result[i][j] = matrixA[i][j] + matrixB[i][j];
        }
    }
}


void subtractMatrices(const int matrixA[MAX_SIZE][MAX_SIZE], const int matrixB[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            result[i][j] = matrixA[i][j] - matrixB[i][j];
        }
    }
}


void multiplyMatrices(const int matrixA[MAX_SIZE][MAX_SIZE], const int matrixB[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            result[i][j] = 0;
            for (int k = 0; k < size; k++) {
                result[i][j] += matrixA[i][k] * matrixB[k][j];
            }
        }
    }
}

void updateMatrixElement(int matrix[MAX_SIZE][MAX_SIZE], int size, int row, int col, int newValue) {
    if (row >= 0 && row < size && col >= 0 && col < size) {
        matrix[row][col] = newValue;
    } else {
        std::cout << "Error: Row or column is out of bounds." << std::endl;
    }
}

int getMaxValue(const int matrix[MAX_SIZE][MAX_SIZE], int size) {
    int maxValue = matrix[0][0]; 
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (matrix[i][j] > maxValue) {
                maxValue = matrix[i][j];
            }
        }
    }
    return maxValue;
}

void transposeMatrix(int matrix[MAX_SIZE][MAX_SIZE], int size) {
    for (int i = 0; i < size; i++) {
        for (int j = i + 1; j < size; j++) { 
            std::swap(matrix[i][j], matrix[j][i]);
        }
    }
}

int main() {
    int sizeA, sizeB;
    int matrixA[MAX_SIZE][MAX_SIZE];
    int matrixB[MAX_SIZE][MAX_SIZE];
    int result[MAX_SIZE][MAX_SIZE];

    std::ifstream file("matrix_input.txt"); // Open file stream once
    if (!file) {
        std::cerr << "Error: Unable to open the file." << std::endl;
        return 1; // Exit if file cannot be opened
    }

    readMatrix(file, matrixA, sizeA);
    readMatrix(file, matrixB, sizeB);

    std::cout << "Matrix A:" << std::endl;
    printMatrix(matrixA, sizeA);

    std::cout << "Matrix B:" << std::endl;
    printMatrix(matrixB, sizeB);

    // Check if matrices are compatible for addition, subtraction, and multiplication
     if (sizeA == sizeB && sizeA > 0) {
        // Add matrices
        addMatrices(matrixA, matrixB, result, sizeA);
        std::cout << "Matrix Sum (A + B):" << std::endl;
        printMatrix(result, sizeA);

        // Subtract matrices
        subtractMatrices(matrixA, matrixB, result, sizeA);
        std::cout << "Matrix Difference (A - B):" << std::endl;
        printMatrix(result, sizeA);

        // Multiply matrices
        multiplyMatrices(matrixA, matrixB, result, sizeA);
        std::cout << "Matrix Product (A * B):" << std::endl;
        printMatrix(result, sizeA);


        updateMatrixElement(matrixA, sizeA, 0, 1, 10); 
        std::cout << "Matrix after update:" << std::endl;
        printMatrix(matrixA, sizeA);

        int maxValue = getMaxValue(matrixA, sizeA);
        std::cout << "Max value in the matrix: " << maxValue << std::endl;

        transposeMatrix(matrixA, sizeA);
        std::cout << "Transposed matrix:" << std::endl;
        printMatrix(matrixA, sizeA);

    }
    file.close(); 
    return 0;
}