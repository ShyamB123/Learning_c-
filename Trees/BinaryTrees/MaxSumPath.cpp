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

class Pair
{
public:
    int branchSum;
    int maxSum;

    Pair()
    {
        branchSum = 0;
        maxSum = 0;
    }
};

Pair MaxSumPath(node *root)
{
    Pair p;
    // base case
    if (root == NULL)
        return p;

    Pair l = MaxSumPath(root->left);
    Pair r = MaxSumPath(root->right);

    int op1, op2, op3, op4;

    op1 = root->data;                             // only root
    op2 = root->data + l.branchSum;               // root + left branch
    op3 = root->data + r.branchSum;               // root + right branch
    op4 = root->data + l.branchSum + r.branchSum; // root + left branch + right branch

    int max_sum_through_root = max(op1, max(op2, max(op3, op4)));

    p.branchSum = max(op1, max(op2, op3));
    p.maxSum = max(l.maxSum, max(r.maxSum, max_sum_through_root));

    return p;
}
int main()
{
    node *root = buildTree();

    bfs(root);

    Pair p;

    p = MaxSumPath(root);
    cout << "max path :" << p.maxSum << endl;
    cout << "Branch path :" << p.branchSum << endl;
}