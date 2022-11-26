#include <bits/stdc++.h>

using namespace std;

int LCS1(int *arr, int n)
{
    unordered_map<int, bool> m;

    int minimum = INT_MAX;
    int maximum = INT_MIN;

    for (int i = 0; i < n; i++)
    {
        // m.insert(make_pair(arr[i],true));
        m[arr[i]] = true;

        minimum = min(minimum, arr[i]);
        maximum = max(maximum, arr[i]);
    }
    int ans = 1;
    int count = 1;
    for (int i = minimum; i <= maximum; i++)
    {
        if (m[i] == true)
        {
            if (m.find(i + 1) != m.end())
            {
                count++;
            }
            else
            {
                ans = max(ans, count);
                count = 1;
            }
        }
    }
    return ans;
}

int LCS2(int *arr, int n)
{
    unordered_map<int, int> m;

    for (int i = 0; i < n; i++)
    {
        int num = arr[i];

        if (m.count(num - 1) == 0 and m.count(num + 1) == 0)
        {
            m[num] = 1;
        }
        else if (m.count(num - 1) and m.count(num + 1))
        {
            int left = m[num - 1];
            int right = m[num + 1];

            int total = left + 1 + right;

            m[num - left] = total;
            m[num + right] = total;
        }
        else if (m.count(num - 1) and m.count(num + 1) == 0)
        {
            int left = m[num - 1];
            m[num - left] = left + 1;
            m[num] = left + 1;
        }
        else
        {
            int right = m[num + 1];
            m[num + right] = right + 1;
            m[num] = right + 1;
        }
    }
    int maximum = INT_MIN;

    for (auto it : m)
    {
        maximum = max(maximum, it.second);
    }
    return maximum;
}

int LCS3(int *a, int n)
{
    unordered_set<int> s;

    for (int i = 0; i < n; i++)
    {
        s.insert(a[i]);
    }
    int max_streak = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        if (s.find(a[i] - 1) == s.end())
        {
            int j = a[i] + 1;
            int cur_streak = 1;
            // int max_streak = 1;
            while (s.find(j) != s.end())
            {
                cur_streak++;
                j++;
            }
            max_streak = max(max_streak, cur_streak);
        }
    }
    return max_streak;
}
int main()
{
    int arr[] = {14, 5, 1, 2, 6, 3, 7, 8, 9, 13, 15, 11, 12, 13, 17,10};
    int n = sizeof(arr) / sizeof(int);

    int ans1 = LCS1(arr, n);
    cout << ans1 << endl;

    int ans2 = LCS2(arr, n);
    cout << ans2 << endl;

    int ans3 = LCS3(arr, n);
    cout << ans3 << endl;
}