#include<bits/stdc++.h>

using namespace std;

void wave_sort(int * a,int n)
{
    int i = 0;
    int j = 1;

    while(j<=n)
    {
        if(a[i]<a[j])
        {
            swap(a[i],a[j]);
        }
        if(a[j]>a[j+1])
        {
            swap(a[j],a[j+1]);
        }
        i += 2;
        j += 2;

    }
}

int main()
{
    int a[] = {1,4,2,42,1,3,21,4,0,234,432,9,1,100};
    int n  = sizeof(a)/sizeof(int);

    wave_sort(a,n);
    
    for(int i = 0 ; i<n;i++)
    {
        cout << a[i] << " ";

    }
}