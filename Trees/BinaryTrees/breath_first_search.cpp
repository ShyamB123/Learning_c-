#include <iostream>
#include <queue>
#include <bits\stdc++.h>

using namespace std;

class node
{
public:
    int data;
    node *left;
    node *right;

    node(int d)
    {
        data = d;
        left = NULL;
        right = NULL;
    }
};

node *buildTree()
{
    int d;
    cin >> d;
    if (d == -1)
    {

        return NULL;
    }

    node *tree_pntr = new node(d); // creates node

    tree_pntr->left = buildTree();  // call to build left side of this node
    tree_pntr->right = buildTree(); // call to build right side of this node

    // return;
    return tree_pntr;
}

void bfs(node *root)
{
    queue<node *> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {
        node *temp = q.front();

        if (temp == NULL)
        {
            cout << endl;
            q.pop();
            if (!q.empty())
            {
                q.push(NULL);
            }
        }
        else
        {
            cout << temp->data << " ";

            q.pop();
            if (temp->left) // if temp->left is NULL it wont go inside
            {
                q.push(temp->left);
            }
            if (temp->right)
            {
                q.push(temp->right);
            }
        }
    }
    return;
}

int main()
{
    node *root = buildTree();
    bfs(root);
}
