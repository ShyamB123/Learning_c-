#include<iostream>
#include<bits\stdc++.h>

using namespace std;

void permute(char in[],int i)
{
    //base case
    if(in[i]=='\0')
    {
        cout << in<<endl;
    }

    for(int j=i;in[j]!='\0';j++)
    {
        swap(in[i],in[j]);
        permute(in,i+1);

        //back track
        swap(in[i],in[j]);
    }
}

int main()
{
    char s[] = "abc";
    permute(s,0);
}