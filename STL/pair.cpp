#include<iostream>
#include<algorithm>

using namespace std;

int main()
{
    pair <int ,int > p1;

    p1.first = 10;
    p1.second = 20;

    cout<<p1.first<<endl;
    cout<<p1.second<<endl;

    pair <string,pair<float,int> > p2;

    p2.first = "Audi";
    p2.second.first = 20.23;
    p2.second.second = 24;

    cout<<p2.first<<endl;
    cout<<p2.second.first<<endl;
    cout<<p2.second.second<<endl;


}