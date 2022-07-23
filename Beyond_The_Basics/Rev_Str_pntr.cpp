#include <iostream>
#include <string.h>

using namespace std;

char*  Rev_Str(char* pStr);

int main()
{
    char s[] = "Hello my name is Shyam!";
    char* ch = s;
     
    for(int i=0;i<strlen(s);i++)
    {
        cout<< *ch;
        ch++;
    }

    

    cout << endl << Rev_Str(s) << endl;
}

char*  Rev_Str( char* pStr)
{
    int len = strlen(pStr); // length of string
 

    char*  p1 = &(pStr[0]); // p1->start of string
    char* p2 = &(pStr[len-1]); // p2->last element of string
    char temp;
   
    while(p1<p2) // comparing the addresses of p1 and p2
    {
        // swap syntax
        temp = *p1;
        *p1 = *p2;
        *p2 = temp;
        
        p1++; // incrementing p1
        p2--; // decrementing p2 
     

    }
  
    return pStr;


}