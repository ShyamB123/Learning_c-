#include<iostream>
#include<algorithm>

using namespace std;

int main()
{
    int n;cin>>n;
    int arr[n];
    int srch;
    int a[n];

    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    cin>>srch;
    int j;
    for(int i =0 ; i<n;i++)
    {
        if(arr[i]>arr[i+1]){
            j=i+1;
            break;
        }
    }
    for(int i =j;i<n;i++){
            
        a[i-j] = arr[i];
    }
  
        for(int i=0;i<n-j;i++){
       
        a[i+n-j]=arr[i];
    }
   
    int first = 0;
    int last = n;
    int middle = (first+last)/2;

    while(middle!=first&&middle!=last){
        if(middle<srch){
            first = middle;
            middle = (first+last)/2;
        }
        else{
            last= middle;
            middle = (first + last)/2;
        }
            

    }
    cout<<middle + j<<endl;
}
