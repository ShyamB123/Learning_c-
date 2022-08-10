 #include<bits/stdc++.h>

 using namespace std;

void merge ( int * a , int* b,int* c , int s,int e)
{
    int i = s;      // pointer for arr b
    int k = s;      // pointer for arr a
    int mid =  (s + e) /2;
    int j = mid + 1;       // pointer for arr c

    while(i<=mid && j<= e)
    {
        if(b[i]>c[j]){
            a[k]= c[j]; 
            k++;
            j++;
        }
        else{
            a[k] = b[i];
            k++;
            i++;
        }
    }
    while(i<=mid) // adding the extra values of b to a
    {
        a[k] = b[i];
        k++;
        i++;
    }
    while(j<=e) // adding the extra values of c to a
    {
        a[k] = c[j];
        k++;
        j++;
    }
}

void merge_sort (int* a , int s , int e)
{

    int b[100];
    int c[100];
    //1. Base case
    if(s>=e)
    {
        return;
    }

    // 2 .recursive case 
    int mid = (s+e)/2;

    
    // dividing in to 2 arrays

    for(int i = 0;i<=mid;i++)
    {
        b[i] = a[i];
    }
    for(int i = mid+1;i<=e;i++)
    {
        c[i] = a[i];
    }
    

    merge_sort(b,s,mid );
    merge_sort(c,mid + 1,e);

    //3.merge

    merge(a,b,c,s,e);


}

 

 int main()
 {
     int a[] = {4,3,2,4,7,1,22,52,20,5,5};
     int n = sizeof(a)/sizeof(int);

     for(int i =0 ;i<n;i++)
     {
         cout << a[i] << " ";
     }
     cout << endl;

     merge_sort(a,0,n-1);
     for(int i =0 ;i<n;i++)
     {
         cout << a[i] << " ";
     }
     cout << endl;
 }