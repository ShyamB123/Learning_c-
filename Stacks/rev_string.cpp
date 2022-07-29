#include <iostream>
#include<stack>
#include<string.h>

using namespace std;

char * Reverse(char * c,int n)
{
    stack<char> S;
    for(int i=0;i<n;i++){
        S.push(c[i]);
    }
    for(int i=0;i<n;i++)
    {
        c[i]=S.top();
        S.pop();
    }
}

int main()
{
    char c[50];
    cout<< "enter a string:";
    cin>>c;
    Reverse(c,strlen(c));
    cout<<"reversed : "<<c;

}