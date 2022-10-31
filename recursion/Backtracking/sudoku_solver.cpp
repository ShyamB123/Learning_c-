#include <iostream>
#include <cmath>

using namespace std;

bool check(int arr[9][9], int n, int i, int j, int num)
{

    for (int k = 0; k < n; k++)
    {
        if (arr[i][k] == num || arr[k][j] == num)
        {
            // cout << arr[i][j]<<endl;
            return false;
        }
    }

    int rt = 3;
    int x = (i / 3) * 3;
    int y = (j / 3) * 3;

    for (int m = x; m < x + 3; m++)
    {
        for (int n = y; n < y + 3; n++)
        {
            if (arr[m][n] == num)
            {
                // cout << arr[m][y]<<endl;
                return false;
            }
        }
    }
    return true;
}

bool sudoku(int arr[9][9], int n, int i, int j)
{
    // base
    //cout << "shyam" << endl;
    if (i == n)
    {
        //cout << "final" << endl;
        for (int w = 0; w < n; w++)
        {
            for (int l = 0; l < n; l++)
            {
                cout << arr[w][l] << " ";
            }
            cout << endl;
        }
        cout << endl;
        return true;
    }

    if (j == n)
    {
        return sudoku(arr, n, i + 1, 0);
        // j = 0;
        // i++;
    }
    // skip prefilled cells
    if (arr[i][j] != 0)
    {
        return sudoku(arr, n, i, j + 1);
    }
    for (int num = 1; num <= 9; num++)
    {
        if (check(arr, n, i, j, num) == true)
        {
            arr[i][j] = num;
            bool satisfy = sudoku(arr, n, i, j + 1);
            if (satisfy)
            {
                return true;
            }
        }
        // backtrack
        arr[i][j] = 0;
    }

    return false;
}

int main()
{
    int board[9][9] = { { 3, 0, 6, 5, 0, 8, 4, 0, 0 },
                       { 5, 2, 0, 0, 0, 0, 0, 0, 0 },
                       { 0, 8, 7, 0, 0, 0, 0, 3, 1 },
                       { 0, 0, 3, 0, 1, 0, 0, 8, 0 },
                       { 9, 0, 0, 8, 6, 3, 0, 0, 5 },
                       { 0, 5, 0, 0, 9, 0, 6, 0, 0 },
                       { 1, 3, 0, 0, 0, 0, 2, 5, 0 },
                       { 0, 0, 0, 0, 0, 0, 0, 7, 4 },
                       { 0, 0, 5, 2, 0, 6, 3, 0, 0 } };
    sudoku(board, 9, 0, 0);
}