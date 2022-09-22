#include<bits/stdc++.h>


using namespace std;

void counting_sort(int * a , int n)
{

    int max  =0 ;
    for(int i =0 ;i<n;i++)
    {
        if(a[i]>max)
        {
            max= a[i];
        }
    }
    max++;
    int arr[max]= {0};
    for(int i = 0 ; i < n ;i++)
    {
        arr[a[i]]++;
    }
    int k = 0;
    

    for(int j = 0 ; j <max ;j++)
    {
        while(arr[j]!=0)
        {
            a[k++] = j ;
            arr[j] = arr[j] - 1;

        }
    }
    
}

int main()
{
    int a[] = {1,31,53,97,45,13,79,4,44,36};
    int n= sizeof(a)/sizeof(int);

    counting_sort(a,n);

    for(int i = 0 ;i< n;i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;

}