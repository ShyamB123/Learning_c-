 #include<bits\stdc++.h>

using namespace std;


string b[] = {"zero","one","two","three","four","five","six","seven","eight","nine"};

void print_num(int n)
{
    if(n==0)
    {
        return;
    }
    print_num(n/10);

    cout << b[n%10]<<" ";
}
int main()
{
    int a[]  = {1,4,5,6,9};
    int n  =  sizeof(a)/sizeof(int);
    int srch = 9;

    //int indx = binary_search(a,a + n - 1 ,srch,0 );
    //cout << indx << endl;
        print_num(3242131);
}