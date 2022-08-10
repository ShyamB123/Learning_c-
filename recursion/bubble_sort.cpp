 #include<bits/stdc++.h>

 using namespace std;

 void bubble_sort(int* a , int n)
 {
     if(n==1){
         return;
     }
     int i ;

     for(i=0;i<n-1;i++)
     {
         if(a[i]>a[i+1])
         {
             swap(a[i],a[i+1]);

         }

     }

     bubble_sort(a,n-1);

     
 }

 int main()
 {
     int a[] = {4,3,2,4,7,1,5};
     int n = sizeof(a)/sizeof(int);

     for(int i =0 ;i<n;i++)
     {
         cout << a[i] << " ";
     }
     cout << endl;

     bubble_sort(a,n);
     for(int i =0 ;i<n;i++)
     {
         cout << a[i] << " ";
     }
     cout << endl;
 }