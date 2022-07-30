#include<iostream>
#include<algorithm>


using namespace std;

int main()
{
    int arr[] = {1,2,4,5,9,32,3};
    int n = sizeof(arr)/sizeof(int);

    int srch;
    cout<< "enter the value to search:";
    cin>>srch;

    int* psrch = find(arr,arr+n,srch);

    int index = psrch - arr;

    if(index== n)
    {
        cout<< "The value "<<srch << " is not present in the array"<<endl;

    }
    else{
        cout<<" the index of the value "<<srch <<" is "<<index <<endl;
    }


}