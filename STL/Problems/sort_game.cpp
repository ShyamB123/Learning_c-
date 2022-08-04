 #include<iostream>
 #include<algorithm>
 #include<bits/stdc++.h>

 using namespace std;

 bool check(pair<string,int>& a,pair<string,int>& b)
 {
     if(a.second>b.second){
        return true;
     }
     else if (a.second == b.second)
     {
         return a.first.length()>b.first.length();
     }
     else{
        return false;
     }
 }

 int main()
 {
     int x;
     cin>>x;
     int n;
     cin>>n;

     pair <string,int> p[n];

     for(int i =0;i<n;i++)
     {

         cin>>p[i].first>>p[i].second;

     }

     sort(p,p+n,check);
     for(int i=0;i<n;i++){
        if(p[i].second<x){
            break;
        }
        cout<<p[i].first<<" "<<p[i].second<<endl;
     }
 }
