#include <iostream>
#include <math.h>
#include <conio.h>
#include <fstream>
#include<windows.h>
using namespace std;
  HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);


int row, col;

void displayofmatrix();
void printmatrix();
void printmatrix2();
void printmatrix3();
void identifyingmatrixforsquare();
int userchoice();
void typeofmatrix();
void determinenttype();
void determinent1();
void transposeofmatrix();
void orderofmatrix();
void addtwomatrices();

int matrix[3][5]; // Dummy value for 2d array of matix
int matrix3[3][3];
int matrix2[2][2];
int sumofmatrices[2][3];


main()
{
 SetConsoleTextAttribute(hConsole, 6);

cout<<"##     ##    ###    ######## ########  #### ##     ##     ######     ###    ##        ######  ##     ## ##           ##     ########  ####### ########  "<<endl;
cout<<"###   ###   ## ##      ##    ##     ##  ##   ##   ##     ##    ##   ## ##   ##       ##    ## ##     ## ##         ## ##      ##    ##     ## ##     ## "<<endl;
cout<<"#### ####  ##   ##     ##    ##     ##  ##    ## ##      ##        ##   ##  ##       ##       ##     ## ##        ##   ##     ##    ##     ## ##     ## "<<endl;
cout<<"## ### ## ##     ##    ##    ########   ##     ###       ##       ##     ## ##       ##       ##     ## ##       ##     ##    ##    ##     ## ########  "<<endl;
cout<<"##     ## #########    ##    ##   ##    ##    ## ##      ##       ######### ##       ##       ##     ## ##       #########    ##    ##     ## ##   ##   "<<endl;
cout<<"##     ## ##     ##    ##    ##    ##   ##   ##   ##     ##    ## ##     ## ##       ##    ## ##     ## ##       ##     ##    ##    ##     ## ##    ##  "<<endl;
cout<<"##     ## ##     ##    ##    ##     ## #### ##     ##     ######  ##     ## ########  ######   #######  ######## ##     ##    ##     #######  ##     ##"<<endl;
  
 SetConsoleTextAttribute(hConsole, 13);
  
    int choice = userchoice();
    if (choice == 1)
    {
        orderofmatrix();
    }
    if (choice == 2)
    {
        typeofmatrix();
    }
    if (choice == 3)
    {
        transposeofmatrix();
    }
    if (choice == 4)
    {
        determinenttype();
    }
    if (choice == 5)
    {
        addtwomatrices();
    }
}
int userchoice()
{
    int choice;
    cout << "1. Find order of matrix." << endl;
    cout << "2. Type of matrix." << endl;
    cout << "3. Find transpose of matrix." << endl;
    cout << "4. Find determinent." << endl;
    cout << "5. Add two matrices." << endl;
    cout << "4. Subtract two matrices." << endl;
    cin >> choice;
    return choice;
}
void displayofmatrix()
{
    cout << "Enter the row size: ";
    cin >> row;
    cout << "Enter the column size: ";
    cin >> col;
}
void printmatrix()
{
    int matrix[row][col];
    for (int i = 0; i < row; i++)
    {
        for (int f = 0; f < col; f++)
        {
            cout << "Enter entity: ";
            cin >> matrix[i][f];
        }
    }
    cout << "Your matrix is: " << endl;
    for (int i = 0; i < row; i++)
    {
        for (int f = 0; f < col; f++)
        {
            cout << matrix[i][f] << "  ";
        }
        cout << endl;
    }
}
void printmatrix2()
{

    for (int i = 0; i < 2; i++)
    {
        for (int f = 0; f < 2; f++)
        {
            cout << "Enter entity: ";
            cin >> matrix2[i][f];
        }
    }
    cout << "Your matrix is: " << endl;
    for (int i = 0; i < 2; i++)
    {
        for (int f = 0; f < 2; f++)
        {
            cout << matrix2[i][f] << "  ";
        }
        cout << endl;
    }
}
void printmatrix3()
{

    for (int i = 0; i < 3; i++)
    {
        for (int f = 0; f < 3; f++)
        {
            cout << "Enter entity: ";
            cin >> matrix3[i][f];
        }
    }
    cout << "Your matrix is: " << endl;
    for (int i = 0; i < 3; i++)
    {
        for (int f = 0; f < 3; f++)
        {
            cout << matrix3[i][f] << "  ";
        }
        cout << endl;
    }
}

void identifyingmatrixforsquare()
{
    bool is_identity = true;
    bool is_diagonal = true;

    // check if matrix is diagonal
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (i != j && matrix[i][j] != 0)
            {
                is_diagonal = false;
                break;
            }
        }
        // if (!is_diagonal)
        // {
        //     break;
        // }
    }

    // check if matrix is identity
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (i == j && matrix[i][j] != 1)
            {
                is_identity = false;
                break;
            }
            else if (i != j && matrix[i][j] != 0)
            {
                is_identity = false;
                break;
            }
        }
        // if (!is_identity)
        // {
        //     break;
        // }
    }

    // output the result
    if (is_identity)
    {
        cout << "The matrix is an identity matrix." << endl;
    }
    else if (is_diagonal)
    {
        cout << "The matrix is a diagonal matrix." << endl;
    }
    else
    {
        cout << "It's a Square Matrix";
    }
}

void orderofmatrix()
{
    cout << "The order of matrix is: " << row * col;
}
void typeofmatrix()
{
    if (row == col) // identifying for diagonal,square or identity.
    {
        identifyingmatrixforsquare();
    }
    if (row != col) // identifying a rectangular matix.
    {
        cout << "It's a Rectangle matrix.";
    }
}
void determinenttype()
{
    int otype;
    cout << "1. 2x2 matrix" << endl;
    cout << "2. 3x3 matrix" << endl;
    cin >> otype;
    if (otype == 1)
    {
        printmatrix2();
        determinent1();
    }
    if (otype == 2) // Pending
    {
        printmatrix3();
    }
}
void determinent1()
{
    int determinentans1, c1, c2;
    c1 = matrix2[0][0] * matrix2[1][1];
    c2 = matrix2[0][1] * matrix2[1][0];
    determinentans1 = c1 - c2;
    cout << "The Determinent of your matris is: " << determinentans1;
}

void transposeofmatrix()
{
    int rows, cols;
    cout << "Enter the number of rows and columns of the matrix: ";
    cin >> rows >> cols;

    int matrix[rows][cols];
    cout << "Enter the elements of the matrix: " << endl;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
            cin >> matrix[i][j];
    }

    cout << "The transpose of the matrix is: " << endl;
    for (int i = 0; i < cols; i++)
    {
        for (int j = 0; j < rows; j++)
            cout << matrix[j][i] << " ";
        cout << endl;
    }
}

void addtwomatrices()
{
    row = 0, col = 0;
    int n_matrix[row][col];
    sumofmatrices[row][col];
    for (int q = 0; q < row; q++)
    {
        for (int t = 0; t < col; t++)
        {
            sumofmatrices[q][t] = 0;
            matrix[q][t] = 0;
            n_matrix[q][t] = 0;
        }
    }

    cout << "Enter number of rows: " << endl;
    cin >> row;
    cout << "Enter number of columns: " << endl;
    cin >> col;
    cout << "Enter the first Matrix: " << endl;
    int matrix[row][col];
    for (int i = 0; i < row; i++)
    {
        for (int f = 0; f < col; f++)
        {
            cout << "Enter entity: ";
            cin >> matrix[i][f];
        }
    }
    cout << "Enter the second Matrix: " << endl;
    for (int q = 0; q < row; q++)
    {
        for (int t = 0; t < col; t++)
        {
            cout << "Enter entity: ";
            cin >> matrix[q][t];
        }
    }

    for (int v = 0; v < row; v++)
    {
        for (int g = 0; g < col; g++)
        {
            sumofmatrices[v][g] = matrix[v][g] + n_matrix[v][g];
        }
    }
    cout << "The sum of matrices is: " << endl;
    for (int z = 0; z < row; z++)
    {
        for (int m = 0; m < col; m++)
        {
            cout << sumofmatrices[z][m] << "\t";
        }
        cout << endl;
    }
}
