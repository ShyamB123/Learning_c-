#include<iostream>
#include<vector>

using namespace std;

int main()
{
    vector<int> a;

    vector<int> b(5,10); // vector has 5 elements and value is 10
    vector<int> c(b.begin(),b.end()); // copying vector b to c
    vector<int> d{1,2,3,4,5}; // intializing 5 elements to d

    // to iterate through the vector

    for(int i =  0 ; i<b.size();i++)
    {
        cout << b[i] << " ";
    }
    cout << endl;


    for(auto it = b.begin();it!=b.end();it++)
    {
        cout << *it << " ";
    }
    cout << endl;

    for(int i:d)
    {
        cout << i << " ";

    }
    cout << endl;

    vector <int> v;
    int n;
    cin>>n;
    for(int i = 0; i < n ; i++)
    {
        int no;
        cin>>no;

        v.push_back(no);
    }

    for(int x:v)
    {
        cout << x << " ";

    }
    cout << endl;
    

    cout << v.size() << endl; // size of vector
    cout << v.capacity()<< endl; // capacity of the vector
    cout << v.max_size() << endl; // highest space the vector can achieve

    cout << d.size() << endl;
    cout << d.capacity() << endl;
    cout << d.max_size() << endl;


}