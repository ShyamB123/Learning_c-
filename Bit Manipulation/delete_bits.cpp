#include<iostream>

using namespace std;

void clear_i_bits(int& n,int i)
{
    int mask = ~0; // setting all bits as 1
    mask = mask<<i;
    n= n&mask;
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
    cout<<"enter a number:";
    cin>>n;

    clear_range(n,4,2);

    cout<<n;
}
