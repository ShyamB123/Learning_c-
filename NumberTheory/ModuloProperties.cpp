#include<bits/stdc++.h>
#define mod 10000007
using namespace std;

int main()
{
    int a,b;
    cin>>a>>b;

    // 1. (a+b)%mod = (a%mod + b%mod)%mod
    if((a+b)%mod == (a%mod + b%mod)%mod)
        cout << "same"<<endl;
     
    // 2. (a-b)%mod = (a%mod - b%mod + mod)%mod
    if((a-b)%mod == (a%mod - b%mod + mod)%mod)
    {
        cout << "Same!"<<endl;
    }
    // 3. (a*b)%mod = ((a%mod)*(b%mod))%mod
    if((a*b)%mod == ((a%mod)*(b%mod))%mod)
    {
        cout << "Same!"<<endl;
    }




}