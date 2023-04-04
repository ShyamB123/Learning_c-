#include<bits/stdc++.h>
#define ll long long
#define fast_io                       \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);                       \
    cout.tie(0);
#define mod 1000000007


using namespace std;

vector<vector<int>> adj(30001);

void bfs(int n,int t)
{
    vector<bool> vst(n+1,false);
 
    vst[1] = true;
 
    queue<int> q;
    q.push(1);
 
    while(!q.empty())
    {
        int node = q.front();
        q.pop();
        for(auto it:adj[node])
        {
            if(vst[it] == false)
            {
                q.push(it);
                vst[it] = true; 
            }
        }
    }
 
    if(vst[t] == true)
    {
        cout <<"YES"<<endl;
    }  
    else
    {
        cout<<"NO"<<endl;
    }
 
}