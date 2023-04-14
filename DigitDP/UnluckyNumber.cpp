#include <bits/stdc++.h>
#define ll long long
#define fast_io                       \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);                       \
    cout.tie(0);
#define mod 998244353
#define inf 1e9
#define F first
#define S second
#define pb push_back
#define mp make_pair

#define vi vector<int>
#define vl vector<ll>
#define vii vector<pair<int, int>>
#define vll vector<pair<ll, ll>>
#define all(a) a.begin(),a.end()
#define nl '\n'

using namespace std;

bool compare(pair<ll, ll> p1, pair<ll, ll> p2)
{
    return p1.second<p2.second;
}


/*

*/

string a,b;
int dif = 10;
string ans;
// dp[low][high][pos][bound1][bound2]
int dp[10][10][20][2][2];

void digit(int low,int high,int pos,int b1,int b2,string &num)
{
    if(pos >= a.size())
    {
        if(high -low < dif)
        {
            ans = num;
        }
        dif = min(dif,high-low);
        return;
    }

    if(dp[low][high][pos][b1][b2] != -1)
    {
        return;
    }

    if(b1 == 0 && b2 == 0)
    {
        for(int i =0;i<=9;i++)
        {
            num += (char)(i+'0');
            digit(min(low,i),max(high,i),pos+1,b1,b2,num);
            num.pop_back();
        }
    }
    else if(b1 == 1 && b2 == 0)
    {
        for(int i = (int)(a[pos]-'0');i<=9;i++)
        {
            num += (char)(i+'0');
            digit(min(low,i),max(high,i),pos+1,(i ==(int)(a[pos]-'0'))?1:0,b2,num);
            num.pop_back();
        }
    }
    else if(b1 == 0 && b2 == 1)
    {
        for(int i = 0;i<=(int)(b[pos]-'0');i++)
        {
            num += (char)(i+'0');
            digit(min(low,i),max(high,i),pos+1,b1,(i ==(int)(b[pos]-'0'))?1:0,num);
            num.pop_back();
        }
    }
    else
    {
        for(int i = (int)(a[pos]-'0');i<=(int)(b[pos]-'0');i++)
        {
            num += (char)(i+'0');
            digit(min(low,i),max(high,i),pos+1,(i ==(int)(a[pos]-'0'))?1:0,(i ==(int)(b[pos]-'0'))?1:0,num);
            num.pop_back();
        }
    }

    // found
    dp[low][high][pos][b1][b2] = 1;

    return;
}

void solve()
{
    ll l,r;
    cin>>l>>r;

    while(l>0)
    {
        a.pb((char)(l%10+'0'));
        l/=10;
    }
    while(r>0)
    {
        b.pb((char)(r%10+'0'));
        r/=10;
    }

    reverse(all(a));
    reverse(all(b));

    // cout <<"a:"<<a<<nl;
    // cout <<"b:"<<b<<nl;

    if(a.size()!=b.size())
    {
        for(int i =0;i<a.size();i++){
            cout <<'9';
        }
        cout <<nl;
        a.clear();
        b.clear();
        return;
    }

    // memset(dp,-1,sizeof(dp));

    for(int i =0;i<=9;i++)
    {
        for(int j =0;j<=9;j++)
        {
            for(int k = 0;k<20;k++)
            {
                for(int h = 0;h<2;h++)
                {
                    for(int l = 0;l<2;l++)
                    {
                        dp[i][j][k][h][l] = -1;
                    }
                }
            }
        }
    }

    string num = "";
    dif = 10;
    digit(9,0,0,1,1,num);


    cout <<ans<<nl;

    ans.clear();
    a.clear();
    b.clear();
    num.clear();


    
}


int main()
{
    fast_io;
    cout << fixed;
    cout << setprecision(10);


    ll t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}
