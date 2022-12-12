#include<iostream>

using namespace std;

int gcd(int a,int b)
{
    //base case
    if(b==0)
    {
        return a;
    }

    //recursive 
    int ans = gcd(b,a%b) ;  // gcd(a,b) = gcd(b,a%b) Euclids algo
    return ans;
}

int lcm(int a,int b,int gcd_ans)
{
    // gcd * lcm = a*b

    return (a*b)/gcd_ans;
}

int main()
{
    int a,b;
    cin>>a>>b;

    int ans =  gcd(a,b);
    cout << "GCD:"<<ans<<endl;
    int lcmans = lcm(a,b,ans);
    cout << "LCM:"<< lcmans<<endl;
}