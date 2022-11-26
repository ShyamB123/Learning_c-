#include <iostream>
#include <map>

using namespace std;

int main()
{
    map<string, int> m;

    // insert

    // 1
    m["banana"] = 60;

    // 2
    pair<string, int> p;
    p.first = "apple";
    p.second = 120;
    m.insert(p);

    // 3
    m.insert(make_pair("grape", 80));

    // search

    string key;
    cin >> key;

    auto it = m.find(key);
    if (it != m.end())
    {
        cout << "the fruit " << key << " is of price :" << m[key] << endl;
    }
    else
    {
        cout << "not found" << endl;
    }
    m["apple"] += 35;

    // erase
    m.erase("apple");

    if (m.count(key))
    {
        cout << "the fruit " << key << " is of price :" << m[key] << endl;
    }
    else
    {
        cout << "not found" << endl;
    }

    m["litchi"] = 90;

    m["orange"] = 20;

    m["watermelon"] = 150;

    // iterate over all the key value pairs

    for (auto it = m.begin(); it != m.end(); it++)
    {
        cout << "the fruit " << it->first << " is of price :" << it->second << endl;
    }

    cout<<endl;
    for (auto e : m)
    {
        cout << "the fruit " << e.first << " is of price :" << e.second << endl;
    }
}