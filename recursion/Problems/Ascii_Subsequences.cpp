 #include<iostream>
#include<cstring>
#include<bits/stdc++.h>
#define mod 1000000007
 using namespace std;


 int k= 0 ;

 void subseq(string a , string out , int i )
 {
     if(a[i] ==  '\0')
     {
        // out = out + "\0";
        
         cout << out << " ";
         k++;

         return;
     }

        subseq(a,out,i+1);
        //out[j] = a[i];
        
        subseq(a,out + a[i],i+1);

        //out.erase(i);
      //  out  =  out + to_string(int(a[i]));
         subseq(a,out + to_string(int(a[i])),i+1);

 }

 int main()
 {
     
         string a ;
         cin>>a;


        string out ;
     

     subseq(a,out,0);

    

    
     cout << endl;
     cout << k <<endl;

 
 }