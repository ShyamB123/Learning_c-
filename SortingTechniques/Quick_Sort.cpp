#include<bits/stdc++.h>

using namespace std;

int partition(int *a ,int s,int e)
{
    int i = s-1;

    

    for(int j =s;j<e;j++)
    {
        if(a[j]<=a[e])
        {
            // upadating partitons
            i++;
            swap(a[j],a[i]);
        }

    }
    // putting the random pivot int the middle of 2 segments

    swap(a[i+1],a[e]);
    return i+1;
    
}

void quicksort(int * a ,int s , int e,int n)
{
    // base case

    if(s>= e)
    {
        return;
    }

    // recursive case

    int indx = partition(a,s,e);
    /*for(int i =0 ;i <n;i++)
    {
        cout <<a[i]<< " ";
    }
    cout<<endl;*/

    quicksort(a,s,indx-1,n);
    quicksort(a,indx+1,e,n);


}

int main()
{
    int n;
    cin>>n;

    int a[n];
    for(int i =0 ; i<n;i++)
    {
        cin>>a[i];
    }

    quicksort(a,0,n-1,n);
    for(int i= 0;i<n;i++)
    {
        cout << a[i] <<" ";
    }
}