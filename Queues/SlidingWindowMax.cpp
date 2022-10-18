#include <iostream>
#include <deque>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int a[n];

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int k;
    cin >> k;

    deque<int> q;
    // max of first k elements

    int i;
    for (i = 0; i < k; i++)
    {
        while (!q.empty() && a[i] > a[q.back()])
        {

            q.pop_back();
        }
        q.push_back(i);
    }
    cout << a[q.front()] << " ";

    for (; i < n; i++)
    {
        // remove all elements that are not in the window
        while (!q.empty() && a[q.back()] < i - k)
        {
            q.pop_back();
        }
        // removing all smaller elements to the left int the array
        while (!q.empty() && a[i] > a[q.back()])
        {
            q.pop_back();
        }
        // adding the element
        q.push_back(i);

        cout << a[q.front()] << " ";
    }
}
