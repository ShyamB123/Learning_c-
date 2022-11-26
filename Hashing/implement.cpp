#include <bits/stdc++.h>

using namespace std;

template <typename T>
class node
{
public:
    string key;
    T data;
    node<T> *next;

    node(string key, T d)
    {
        this->key = key;
        data = d;
        next = NULL;
    }
    ~node()
    {
        if (next != NULL)
        {
            delete next;
        }
    }
};

template <typename T>
class hashtable
{
private:
    node<T> **table;
    int current_size;
    int table_size;

    int hashfn(string key)
    {

        int val = 0;
        int p = 1;
        for (int i = 0; i < key.length(); i++)
        {
            val = (val + (key[i] * p)) % table_size;
            val = val % table_size;
            p = (p * 27) % table_size;
        }

        return val;
    }

public:
    hashtable(int ts = 7)
    {
        table_size = ts;
        table = new node<T> *[table_size];
        current_size = 0;
        for (int i = 0; i < table_size; i++)
        {
            table[i] = NULL;
        }
    }

    void insert(string key, T value)
    {
        int index = hashfn(key);
        node<T> *n = new node(key, value);

        n->next = table[index];
        table[index] = n;
        current_size++;

        // rehash

        float load = current_size / (1.0 * table_size);

        if (load > 0.7)
        {
            node<T> **oldtable = table;
            int oldtable_size = table_size;
            table_size = table_size * 2;
            table = new node<T> *[table_size];

            for (int i = 0; i < table_size; i++)
            {
                table[i] = NULL;
            }
            current_size = 0;


            for (int i = 0; i < oldtable_size; i++)
            {
                node<T> *temp = oldtable[i];

                while (temp != NULL)
                {
                    insert(temp->key, temp->data);
                    temp = temp->next;
                }

                delete oldtable[i];
            }
            delete oldtable;
        }
    }
    void print()
    {
        node<T> *temp;
        for (int i = 0; i < table_size; i++)
        {
            temp = table[i];
            cout << "Bucket:" << i << "--->";
            while (temp)
            {
                cout << temp->key << "->";
                temp = temp->next;
            }
            cout << endl;
        }
    }

    T * search(string s)
    {
        int index = hashfn(s);
        node<T> * temp  = table[index];
        while(temp!=NULL)
        {
            if(temp->key == s)
            {
                return &temp->data;
            }
            temp = temp->next;
        }
        return NULL;
      
    }

    // void erase(string s)
    // {
    //     int index = hashfn(s);
    //     node<T> *temp = table[index];

    //     node<T> *temp2 =table[index];

    //     while((temp2->key)!= s )
    //     {
    //         temp2 = temp2->next;
    //     }
    //     while(temp->next != temp2)
    //     {
    //         temp  = temp->next;
    //     }
        
    //     temp->next = temp2->next;
    //     delete temp2;
    // }

    T & operator[](string key)
    {
        T * n = search(key);
        if(n == NULL)
        {
            T garbage;
            insert(key,garbage);
            n = search(key);
        }

        return *n;

    }
};

int main()
{
    hashtable<int> ht;
    ht.insert("burger", 100);
    ht.insert("burgerPizza", 100);
    ht.insert("noodles", 100);

    ht.insert("Pepsi", 90);
    ht.insert("Coke", 10);
    ht.print();
    int* x = ht.search("Peps");
    if(x)
         cout << * x<<endl;
    else 
        cout << "Not Found"<<endl;

    //ht.erase("burger");
    ht.print();

    // insert
    ht["dosa"] = 60;
    //update
    ht["dosa"] += 10;
    //search
    cout <<"prince of dosa is :" <<ht["dosa"] << endl;
}