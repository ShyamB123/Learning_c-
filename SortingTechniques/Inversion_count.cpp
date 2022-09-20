#include<bits/stdc++.h>

using namespace std;
int merge(int * a , int s, int e)
{
    int mid = (s+e)/2;
    int i = s;
    int k = s;
    int j = mid +1;

    int temp[100];

    int count = 0;

    while( i <= mid && j<=e)
    {
        if(a[i]>=a[j])
        {
            temp[k++] = a[j++];
            count += mid - i + 1;
        }
        else
        {
            temp[k++] = a[i++];
        }
    }

    while(j<=e){
        temp[k++] = a[j++];
    }
    while(i<=mid)
    {
        temp[k++] = a[i++];
    }

    for(int  i = 0 ;i<= e ;i++)
    {
        a[i] = temp[i];
    }
    
    return count;
}

int invrsn(int * a, int s, int e)
{
    //base case
    if(s>=e)
    {
        return 0;
    }

    //recursive call

    int mid = (s+e)/2;
    int x = invrsn(a,s,mid);
    int y = invrsn(a,mid+1,e);
    int cross_invrsn = merge(a,s,e);

    return x + y + cross_invrsn ;


}

int main()
{
    int arr[] = {1,5,2,6,3,0};
    int n = sizeof(arr)/sizeof(int);

    cout << invrsn(arr,0,n-1) <<endl;

}