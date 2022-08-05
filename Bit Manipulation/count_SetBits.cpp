  #include<iostream>

 using namespace std;

int main()
{
    int n;
    cin>>n;

    int find_bits;

    while(n!=0)
    {
        if(n&1){         // checking if last bit is 0 or 1
                         // if 1 --> True
            find_bits++; // update our total bits
        }
        n=n>>1;          // right shifting the number

    }
    cout<<"The number of SET bits is :"<<find_bits<<endl;
}
