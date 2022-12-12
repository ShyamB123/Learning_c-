#include<iostream>
#include<unordered_map>

using namespace std;

int main()
{
    int a[] = {5,5,5,5,5};
    int n = sizeof(a)/sizeof(int);

    unordered_map<int,int> m;

    int cuml_sum[n+1];
    cuml_sum[0] = 0;

    for(int i = 1;i<=n;i++)
    {
        cuml_sum[i] = cuml_sum[i-1] + a[i-1];
       // m[i]++;
    }

    for(int i =0;i<=n;i++)
    {
        cuml_sum[i] = cuml_sum[i]%n;
        m[cuml_sum[i]]++;
    }
    int sum = 0;

    for(auto it = m.begin();it!=m.end();it++)
    {
        if(it->second>1)
        {
            sum += (it->second*(it->second-1))/2;
        }
    }
    cout << sum<<endl;



    
}