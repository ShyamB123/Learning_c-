#include <iostream>
#include<bits/stdc++.h>
#include<string.h>

using namespace std;
void binsearch(int * arr,int first,int last,int srch);


int main()
{
    int n;
    cout<< "enter the length of the array:";
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    sort(arr,arr+n);
    int srch;
    cout<< "enter the number to search:";
    cin>>srch;
    for(int i=0;i<n;i++)
    {
        cout << arr[i] << " ";
    }
    cout<<'\n';
    binsearch(arr,0,n-1,srch);


}



 void binsearch(int * arr,int first,int last,int srch)
{
    int middle;
    middle = (first + last)/2;
    if(arr[middle]== srch){
        cout<<srch<<" is at the "<<middle+1<<" position"<<endl;
        return;
    }
    else if(arr[middle]<srch)
    {
        first = middle + 1;
        binsearch(arr,first,last,srch);
    }
    else
    {
        last = middle-1;
        binsearch(arr,first,last,srch);
    }

}
