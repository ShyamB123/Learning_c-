#include<iostream>

using namespace std;


// Order of O(N*log(log(n)))
void prime_sieve(int * arr)
{
    //base cases
    arr[0] = arr[1] = 0;
    arr[2] = 1;

    // skipping all multiples of 2
    for(int i = 3;i<10000;i += 2)
    {
        arr[i] = 1;
    }

    for(int i = 3;i<10000;i += 2)
    {
        if(arr[i]==0)
            continue;

        // we can directly start from i^2 because if num is less than i^2
        // is has a factor that is less than i which is already taken care of
        for(int j = i*i;j<10000;j += i) 
        {
            arr[j] = 0;
        }
    }
}

int main()
{
    int n;
    cin>>n;

    int arr[10005] = {0};

    prime_sieve(arr);

    for(int i = 0;i<n;i++)
    {
        if(arr[i]==1)
        {
            cout << i<< " ";
        }
    }
}