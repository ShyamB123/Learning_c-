#include <iostream>

using namespace std;

bool safetoput(int a[][100], int n, int i, int j)
{
    // horizontal

    for (int k = 0; k < n; k++)
    {
        if (a[i][k] == 1)
        {
            return false;
        }
    }

    // vertical

    for (int k = 0; k < n; k++)
    {
        if (a[k][j] == 1)
        {
            return false;
        }
    }

    // diagonal;

    int x = i;
    int y = j;

    while (x >= 0 && y < n)
    {
        if (a[x][y] == 1)
        {
            return false;
        }
        x--;
        y++;
    }
    x = i;
    y = i;
    while (x >= 0 && y >= 0)
    {
        if (a[x][y] == 1)
        {
            return false;
        }
        x--;
        y--;
    }

    return true;
}

bool n_queen(int a[][100], int n, int i)
{
    // base case
    if (i == n)
    {
        for (int x = 0; x < n; x++)
        {
            for (int y = 0; y < n; y++)
            {
                cout << a[x][y] << " ";
            }
            cout << endl;
        }
        cout << endl;
        return false;
    }
    int j;
    for (j = 0; j < n; j++)
    {
        if (safetoput(a, n, i, j))
        {
            a[i][j] = 1;
            int ans = n_queen(a, n, i + 1);
            if (ans)
            {
                return true;
            }

            a[i][j] = 0; // back track
        }
    }
    return false;
}

int main()
{
    int a[100][100] = {0};
    int n;
    cin >> n;

    n_queen(a, n, 0);
}