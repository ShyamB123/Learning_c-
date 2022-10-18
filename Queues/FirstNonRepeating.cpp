#include <iostream>
#include <queue>

using namespace std;

int main()
{
    char ch;
    int freq[27] = {0};
    cin >> ch;
    queue<char> q;

    while (ch != '.')
    {
        q.push(ch);
        int num = ch - 'a';
        freq[num]++;

        while (!q.empty())
        {
            int indx = q.front() - 'a';
            if (freq[indx] > 1)
            {
                q.pop();
            }
            else
            {
                cout << q.front() << " ";
                break;
            }
        }
        if (q.empty())
        {
            cout << -1 << " ";
        }
        cin >> ch;
    }
}