#include<iostream>
#include<bits/stdc++.h>

using namespace std;

void decimal_to_binary(int n)
{
    int p = 1;
    int ans = 0;

    while(n>0)
    {
        ans +=(n&1)*p;
        n=n/2;
        p *=10;
    }
    cout << ans<<endl;
}

void decimal_to_binary_bits(int n)
{
    int p = 1;
    int ans = 0;

    while(n>0){

        ans += (n&1)*p;
        p *= 10;

        n= n>>1;
    }
    cout<<ans<<endl;
}

void dc_2_bnry_str(int n)
{

    string s;

    while(n>0)
    {
        s.push_back('0'+(n&1));  // using ASCII values '0' + 1 == '1'
        n= n>>1;
    }
    reverse(s.begin(),s.end());   // reversing string as the binary no was reverse
    cout<<s<<endl;
}


void optimised_bnry2dc(int n)
{

    bool check = false;
    int mask = 1<<30; // setting the '1' on the most significant bit

    while(mask>0)
    {
        if((mask&n)!=0) // only printing after the most significant bit in the number
        {
            check = true;
        }
        if(check != false)
        {
            if((n&mask)>0) // the bit we are checking is '1'
            {
                cout<<1;

            }
            else{           // the bit is not '1' hence --> '0'
                cout<<0;
            }
       }
        mask = mask>>1;     // updating the bit to be checked next by right shifting
    }
    cout<<endl;
}

int main()
{
    decimal_to_binary(31241234);
    decimal_to_binary_bits(31241234);
    dc_2_bnry_str(31241234);
    optimised_bnry2dc(31241234);

}
