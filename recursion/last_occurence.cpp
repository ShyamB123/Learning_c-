#include<bits\stdc++.h>

using namespace std;

int last_ocrnc(int * a,int * l,int n,int srch)
{
    if(n==0)
    {
        return -1;

    }

    if(*(l)== srch)
    {
        return 0;
    }

    int i  = last_ocrnc(a,l-1,n-1,srch);

    if(i==-1)
    {
        //cout << "value not found"<<endl;
        return -1;
    }
    else{
        return i+1;
    }
}

int last_ocrnc_itrtr(int * a ,int n,int srch , int i)
{
    if(i==0)
        return -1;
    


    if(a[i]== srch)
        return  i ;
    
    if(last_ocrnc_itrtr(a , n ,srch ,i-1)==-1)
        return -1;

    return last_ocrnc_itrtr(a , n ,srch ,i-1);
    
}


int last_occurance_from_first(int* a,int n,int i,int srch)
{
    if(i==n){
        return -1;
    }
    if(a[i]==srch)
    {
        int bi = last_occurance_from_first(a,n,i+1,srch);

        if(bi!=-1)
        {
            return bi;
        }
        else
        {
            return i;
        }
    }
    return last_occurance_from_first(a,n,i+1,srch);

}
int main()
{
    int a[] =  {1,2,2, 4,5, 2 ,2,10,10};
    int n = sizeof(a)/sizeof(int);

    int srch = 10;
     
    int x = last_ocrnc(a,a+n-1,n,srch);
    int y = last_ocrnc_itrtr(a,n,srch,n-1);
    int z = last_occurance_from_first(a,n,0,srch);

    cout <<n-1-x<<endl;
    cout << y << endl;
    cout << z << endl;

}