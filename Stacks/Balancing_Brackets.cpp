#include <iostream>
#include<stack>
#include<string.h>

using namespace std;

int main()
{
    char strn[100];
    cout<<"enter brackets:";
    cin>>strn;

    stack<char> s;

    for(int i=0;i<strlen(strn);i++)
    {
        if(strn[i]=='('||strn[i]=='{'||strn[i]=='[')
            {
                s.push(strn[i]);
            }
        else if(strn[i]==')')
        {
            if(s.empty()||strn[i]!=s.top()+1){
                cout<<"wrong";
                return 0;
            }

            else{
                s.pop();
            }
        }
        else if(strn[i]=='}'||strn[i]==']')
        {
            if(s.empty()||strn[i]!=s.top()+2){
                cout<<"wrong";
                return 0;
            }

            else{
                s.pop();
            }
        }
    }
    cout<<"correct";
}