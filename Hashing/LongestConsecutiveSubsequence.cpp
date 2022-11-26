#include<bits/stdc++.h>

using namespace std;

int LCS1 (int * arr,int n)
{
    unordered_map<int,bool> m;

    int minimum = INT_MAX;
    int maximum = INT_MIN;

    for(int i =0;i<n;i++)
    {
        //m.insert(make_pair(arr[i],true));
        m[arr[i]] = true;

        minimum = min(minimum , arr[i]);
        maximum = max(maximum , arr[i]);
    }
    int ans = 1;
    int count = 1;
    for(int i = minimum;i<=maximum;i++)
    {
        if(m.find(i+1)!=m.end())
        {
            count++;
        }
        else
        {
            ans = max(ans,count);
            count = 1;
        }
    }
    return ans;
}

int LCS2(int * arr ,int n)
{
    unordered_map<int,int> m;
    
    for(int i = 0 ;i<n;i++)
    {
        int num = arr[i];

        if(m.count(num-1)==0 and m.count(num+1)==0)
        {
            m[num] = 1;
        } 
        else if(m.count(num-1) and m.count(num+1))
        {
            int left = m[num-1];
            int right = m[num+1];

            int total = left + 1 + right;

            m[num - left] = total;
            m[num + right] = total;
        }
        else if(m.count(num-1) and m.count(num+1)== 0)
        {
            int left = m[num-1];
            m[num-left] = left + 1;
            m[num] = left +1;
        }
        else
        {
            int right = m[num+1];
            m[num+right] = right + 1;
            m[num] = right +1;
        }
    }
    int maximum =INT_MIN;

    for(auto it:m)
    {
        maximum = max(maximum,it.second);
    }
    return maximum;
}

int main()
{
    int arr [] = {10,4,20,1,3,5,2,19};
    int n = sizeof(arr)/sizeof(int);

    int ans1 = LCS1(arr,n);
    cout << ans1 << endl;

    int ans2 = LCS2(arr,n);
    cout << ans2 <<endl;
}