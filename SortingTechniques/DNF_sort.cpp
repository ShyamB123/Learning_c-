#include<bits/stdc++.h>

using namespace std;

void dnf_sort(int * a ,int n)
{
    int low = -1;
    int mid = 0;
    int high = n;

    while(mid<high)
    {
        if(a[mid]==0){
            low++;
            swap(a[low],a[mid]);
            
        }
        else if(a[mid]==2)
        {
            high--;
            swap(a[high],a[mid]);
            mid--;

        }
        mid++;
    }
}

int main()
{
    int a[] = {1,2,0,0,0,1,2,2,2,0,1,0,2,0,2,1,1,1,1,2,2};
    int n = sizeof(a)/sizeof(int);

        dnf_sort(a,n);

    for(int i = 0 ; i<n;i++)
    {
        cout << a[i]<<" ";
    }
}