#include<bits/stdc++.h>

using namespace std;

int main()
{
    vector<int> v{1,2,3,4,5};

    // push back 
    v.push_back(14); // 1 2 3 4 5 16

    // pop back

    v.pop_back(); // 1 2 3 4 5

    //insert in the middle

    v.insert(v.begin()+3,4,100); // v.insert(starting address,frequency of the number,number to be inserted)
    // 1 2 3 100 100 100 100 4 5

    for(int c:v)
    {
        cout << c << " ";
    }
    cout << endl;

    // Erase

    v.erase(v.begin()+2); // 1 2 100 100 100 100 4 5
    v.erase(v.begin()+2,v.begin()+5); // 1 2 100 4 5 

    for(int c:v)
    {
        cout << c << " ";
    }
    cout << endl;

    //Size

    cout << "size:"<<v.size() << endl; // size ie. number of elements in the vector
    cout << "capacity " << v.capacity() << endl; // total space of the vector

    // Resize

    v.resize(18); // changes capacity to 8 . Only can increase size!
    cout << "capacity " << v.capacity() << endl;

    // Clear 
    // capacity remains same but size is 0
    v.clear(); // Clears all the elements in the vector

    // Empty

    if(v.empty())
    {
        cout << "the vector is empty!" << endl;
    }


    v.push_back(10);
    v.push_back(20);
    v.push_back(30);

    //Front and Back

    cout << v.front() << endl; // returns the first element
    cout << v.back() << endl; // returns the last element
    


    for(int c:v)
    {
        cout << c << " ";
    }
    cout << endl;

    // reserve


    //some cases we know that there will be atleast 100 cases then we can set the capacity as 100
    // to save the time as the vector does not have to double its capacity as much

    vector<int> s;


    s.reserve(100);

    int n;
    cin>>n;

    for(int i = 0 ; i < n ;i++)
    {
        int no;
        cin>>no;
        s.push_back(no);

        cout << "capcity:" << s.capacity() << endl;
    }
    

    for(int x : s)
    {
        cout << x<<  " ";
    }
    cout << endl;
}