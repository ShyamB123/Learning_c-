#include <iostream>

using namespace std;

int sol[4][4] = {0};
bool RatInMaze(char a[][100], int i, int j, int n, int m)
{
    // base case
    if(i==n-1 && j==m-1)
    {
        sol[i][j]=1;
        for(int k=0;k<n;k++)
        {
            for(int l=0;l<n;l++)
            {
                cout << sol[k][l]<< " ";
            }
            cout << endl;
        }
        cout << endl;
        //return true;
        sol[i][j]=0;
        return false;
    }

    //recersive case
    sol[i][j]=1; //assume part of solution

    if( j+1<m && a[i][j+1]!='X')
    {
        bool right = RatInMaze(a,i,j+1,n,m);
        if(right==true)
        {
            return true;
        }
    }
    if(i+1<n && a[i+1][j]!='X')
    {
        bool down = RatInMaze(a,i+1,j,n,m);
        if(down==true)
        {
            return true;
        }
    }
    sol[i][j]=0;
    return false;


}

int main()
{
    char arr[][100] = { "0000",
                        "00XX",
                        "0000",
                        "XX00" };
    
    RatInMaze(arr,0,0,4,4);
}