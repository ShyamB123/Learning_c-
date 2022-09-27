#include <bits/stdc++.h>

using namespace std;

class car
{
    public:
    string name;
    int x;
    int y;

    car()
    {

    }
    car(string n ,int a,int b)
    {
        name = n;
        x= a;
        y = b;
    
    }

    int dist()
    {
        return x*x + y*y;
    }
};



bool compare(car A, car B)
{
    int d1 = A.dist();
    int d2 = B.dist();

    if(d1==d2)
    {
        return A.name < B.name;
    }

    return d1 < d2;
    
}

int main()
{
    int n;
    cin>>n;

    vector<car> v;

    for(int i = 0; i<n;i++)
    {
        car temp;
        int x,y;
        string n;
        cin >> temp.name >> temp.x >>temp.y;

        v.push_back(temp);
    }

    sort(v.begin(),v.end(),compare);

    for(int i = 0;i<n;i++)
    {
        cout <<"Car:"<< v[i].name<<" distance:"<<v[i].dist()<<" location:"<< v[i].x<<" "<<v[i].y << endl;
    }
}