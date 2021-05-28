#ifndef MATRIX_H_INCLUDED
#define MATRIX_H_INCLUDED
#include <vector>
#include <cstdlib>
#include <iostream>
using namespace std;


template <class T>
class Matrix
{
    private:
        unsigned int row;
        unsigned int column;
        vector<vector<T>> matrix;

    public:

         Matrix(int, int, T);
         Matrix(Matrix &x);
        ~Matrix();
        //operations
        Matrix operator+(Matrix &);
        Matrix operator-(Matrix &);
        Matrix operator*(Matrix &);
        Matrix transpose();

        //methods
        void MatrixElements();
        void display();

        int get_row();
        int get_col();


};

template <class T>
Matrix<T>::Matrix(int x, int y, T number){
    row= x;
    column=y;
    // vector<vector<T>> matrix (row, vector<T>(column));
     matrix.resize(row);

    for (int i=0; i<matrix.size(); i++){
    matrix[i].resize(column,number);
            }

}


// Copy Constructor
template<class T>
Matrix<T>::Matrix( Matrix & x) {
  matrix = x.matrix;
  row = x.get_row();
  column = x.get_col();
}


//dstr.
template<class T>
Matrix<T>::~Matrix() {}

//addition
template <class T>
Matrix<T> Matrix<T>:: operator +(Matrix &x){

    Matrix result(row, column, 0);
    for (int i=0; i<row ;i++){

        for (int j=0; j<column; j++){

            result.matrix[i][j] = this->matrix[i][j] + x.matrix[i][j];

        }
    }

    return result;
}

//subtraction
template <class T>
Matrix<T> Matrix<T>::operator-(Matrix & x){
    Matrix result(column, row, 0.0);

    for (int i = 0; i<row; i++)
    {
        for (int j=0; j<column; j++)
        {
            result.matrix[i][j] = this->matrix[i][j] - x.matrix[i][j];
        }
    }

    return result;
}

//multiplication
template<class T>
Matrix<T> Matrix<T>::operator *(Matrix &x) {

   int r = x.get_row();
   int c = x.get_col();
   Matrix result(row, c, 0);

        double product = 0.0;
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < c; j++)
            {
                product = 0.;
                for (int k = 0; k < column; k++)
                {
                    product += this->matrix[i][k] * x.matrix[k][j];
                }
                result.matrix[i][j] = product;
            }
        }
        return result;


}


template<class T>
Matrix<T> Matrix<T>:: transpose()
{
    int r= get_row();
    int c= get_col();

    Matrix Transpose(c,r,0);
    for (int i = 0; i < c; i++)
    {
        for (int j = 0; j < r; j++) {

          Transpose.matrix[i][j] = this->matrix[j][i];
        }
    }
    return Transpose;
}



//Filling matrix elements
template <class T>
void Matrix<T>::MatrixElements(){

    for(int i = 0; i<row; i++)
            {
                for(int j = 0; j<column; j++)
                    {
                cout<<"Enter Elements of Matrix :";
                cin>>matrix[i][j];
                    }
                }

}

//displaying elements
template <class T>
void Matrix<T>::display()
{
    cout << "Matrix: " << endl;
    for ( int i = 0; i < row; i++) {
        for ( int j = 0; j < column; j++) {
            cout << "[" << matrix[i][j] << "] ";
        }
        cout << endl;
    }
}


template <class T>
int Matrix<T>::get_row()
{
    return this->row;
}

template <class T>
int Matrix<T>::get_col()
{
    return this->column;
}


#endif // MATRIX_H_INCLUDED

