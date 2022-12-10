#include<iostream>
#include<set>

using namespace std;

int main()
{
    int a[] = {1,1,5,1,6,9,7,6,6,4,3,2,6,3};
    int n = sizeof(a)/sizeof(int);

    set<int> s;

    //insert

    for(int i =0;i<n;i++){
        s.insert(a[i]);
    }

    // traverse through the set
    for(auto it = s.begin();it!=s.end();it++)
    {
        cout << *it<<" ";
    }
    cout << endl;

    //erase

    s.erase(5);

    auto it = s.find(4);
    s.erase(it);


    for(auto it = s.begin();it!=s.end();it++)
    {
        cout << *it<<" ";
    }
    cout << endl;

    cout << *s.upper_bound(3)<<endl; // upperbound returns the address of the element > than that
    cout << *s.lower_bound(3)<<endl; // lowerbound returns the address of the element >= than that

    
}