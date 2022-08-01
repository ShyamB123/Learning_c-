#include<iostream>
#include<algorithm>

using namespace std;

int main()
{
    int arr[] = {2,4,5,40,40,40,50,200};
    int n = sizeof(arr)/sizeof(int);

    int * lowlim = lower_bound(arr,arr+n,40); // return first value that is >= key

    cout<< "the value"<<*lowlim<<"is located at "<<lowlim - arr<<" index"<<endl;

    int * upplim = upper_bound(arr,arr+n,40); // return first value that is > key
    cout<< "the value"<<*upplim<<"is located at "<<upplim - arr<<" index"<<endl;
        cout<< "the value"<<*(upplim-1)<<"is located at "<<upplim - arr-1<<" index"<<endl;

    cout<<"the numbers of occurences of 40 is :"<<upplim- lowlim<<endl;



}