#include <iostream>
#include<bits/stdc++.h>
#include<string.h>
#include <stdbool.h>

using namespace std;

bool isPallindrome(string s);


int main()
{
    char s[100];
    cout<< "Enter a string:";
    cin>>s;

    bool rev= false;
    rev =isPallindrome(s);
    //cout<<s<<endl;
  //  cout<<rev<<endl;
  if(rev== true){
    cout<<"yes "<<s<<" is a pallindrome\n";
  }
    else{
        cout<<"no "<<s<<" is not a pallindrome\n";
    }
}

bool isPallindrome(string s)
{
    if(s.length()<2){
        return true;
    }
    else{
        if(s[0]!=s[s.length()-1])
        {
            return false;
        }

    }
    isPallindrome(s.substr(1,s.length()-2));




}
