#include<bits/stdc++.h>

using namespace std;

int main()
{
    int arr [] = {6,-1,2,-1,2,-1,-7};
    int n = sizeof(arr)/sizeof(int);

    unordered_map<int,int> m;

    int sum =0;
    int a = -1;
    for(int i=0;i<n;i++)
    {
        sum += arr[i];
        if(sum == 0)
        {
            cout << "the subarray is from "<<1<<" to "<<i+1<<endl;
            a = max(a,i+1);
            //m.insert(make_pair(sum,i));
           
        }
        auto it =  m.find(sum);

        if(it==m.end())
        {
            m.insert(make_pair(sum,i));
        }
        else
        {
            
            cout << "the subarray is from "<<it->second+1<<" to "<<i<<endl;
            a = max(a, i - it->second - 1 );
        
           // break;
        }
    }
    cout << a << endl;
}