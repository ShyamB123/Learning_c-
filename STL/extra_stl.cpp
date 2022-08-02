#include<iostream>
#include<algorithm>

using namespace std;

void print(int *arr,int n)
{
    for(int i=0;i<n;i++)
    {
        cout<< arr[i] << " ";

    }
    cout<<endl;
}

int main()
{
    int a [] = {1,3,5,6,9,0,3};
    int n = sizeof(a)/sizeof(int);

    print(a,n);
    rotate(a,a+3,a+n);
    print(a,n);

    reverse(a,a+n);
    print(a,n);

    int b,c,d;

    b=10;
    c=20;
    d=40;

    swap(c,b);

    cout<<"B:"<<b<<endl;
    cout<<"C:"<<c<<endl;

    cout<<max(b,max(c,d))<<endl;
    cout<<min(b,min(c,d))<<endl;


}