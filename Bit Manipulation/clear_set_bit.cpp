 #include<iostream>
 #include<algorithm>
 #include<bits/stdc++.h>

 using namespace std;

 void ClearBit(int &a,int i)
 {

     int mask=1<<i; // setting 1 at the bit we want to clear

     mask = ~mask;  // making only the ith position 0 , rest are 1
     a= a&mask; //changing only the ith bit to 0

 }
 void SetBit(int& a , int v,int i )
 {
     ClearBit(a,i); // first clear the ith bit
     int mask = v<<i; // only make the ith bit the value of v
     a= a|mask; // makes the ith bit of a = v
 }

int main()
{
    int a = 10 ;
    ClearBit(a,3);
    cout<<a<<endl;
    SetBit(a,1,2);
    cout<<a<<endl;
}
