#include<iostream>
#include<vector>


using namespace std;

void factor(int n)
{
    vector<pair<int,int>> v;
    for(int i = 2;i*i<=n;i++)
    {
        int count =0;
        if(n%i==0)
        {
            while(n%i==0)
            {
                count++;
                n = n/i;
            }
        }
        if(count!=0)
            v.push_back(make_pair(i,count));
    }

    if(n!=1)
        v.push_back(make_pair(n,1));

    for(auto it:v)
    {
        cout<< it.first<<"^"<<it.second<<" * " ;
    }
    cout << endl;
}

int main()
{
    int n;
    cin>>n;

    factor(n);
}