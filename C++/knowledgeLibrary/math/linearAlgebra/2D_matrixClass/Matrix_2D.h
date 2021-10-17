#ifndef MATRIX_H
#define MATRIX_H


template<class T>
class Matrix_2D{
public:
    Matrix_2D();
    Matrix_2D(unsigned int rows, unsigned int columnns);
    Matrix_2D(unsigned int rows, unsigned int columnns, const T* inputData);
    Matrix_2D(const Matrix_2D<T>& inputMatrix);     // Copy constructor
    Matrix_2D(Matrix_2D<T>&& inputMatrix);          // Move constructor
    ~Matrix_2D();

    // Configurations methods
    bool resize(unsigned int rows, unsigned int columns);

    // Element access methods
    bool get_element(unsigned int rows, unsigned int columns);
    unsigned int get_rowCount(unsigned int rows, unsigned int columns);
    unsigned int get_columnCount(unsigned int rows, unsigned int columns);

    // Overload == operator
    bool operator== (const Matrix_2D<T>& otherMatrix);


private:
unsigned int m_rowsCount;
unsigned int m_columnsCount;
unsigned int m_elementCount;


};

#endif