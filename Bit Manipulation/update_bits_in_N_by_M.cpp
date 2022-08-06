#include<iostream>

using namespace std;

void clear_range(int& n ,int i ,int j);

void  update_bits(int& n,int m,int i,int j)
{
    m=m<<(j-1);  // moving the parts to be updated in that range

    clear_range(n,i,j-1); //clearing the parts to be changed in n

    n= n|m; //updating n int (j,i) range using m
}

void clear_range(int&n , int i,int j)
{
    int mask_a = ~0;
    mask_a = mask_a<<i;

    int mask_b= (1<<j) -1; // 2^n - 1

    int mask = (mask_a|mask_b);

    n = n&mask;
}

int main()
{
    int n;
    cin>>n;



    update_bits(n,2,4,2);

    cout<<n;
}
