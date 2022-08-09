#include<bits\stdc++.h>

using namespace std;

int frst_ocrnc(int * a,int n,int srch)
{
    if(n==0)
    {
        return -1;

    }

    if(a[0]== srch)
    {
        return 0;
    }

    int i  = frst_ocrnc(a+1,n-1,srch);

    if(i==-1)
    {
        //cout << "value not found"<<endl;
        return -1;
    }
    else{
        return i+1;
    }
}

int frst_ocrnc_itrtr(int * a ,int n,int srch , int i)
{
    if(i==n)
        return -1;
    


    if(a[i]== srch)
        return  i ;
    
    if(frst_ocrnc_itrtr(a , n ,srch ,i+1)==-1)
        return -1;

    return frst_ocrnc_itrtr(a , n ,srch ,i+1);
    
}
int main()
{
    int a[] =  {1,2,2, 4,5, 2 };
    int n = sizeof(a)/sizeof(int);

    int srch = 5;
     
    int x = frst_ocrnc(a,n,srch);
    int y = frst_ocrnc_itrtr(a,n,srch,0);

    cout <<x<<endl;
    cout << y << endl;

}