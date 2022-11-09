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

node *lca(node *root, int a, int b)
{
    if (root == NULL)
    {
        return NULL;
    }
    if (root->data == a or root->data == b)
    {
        return root; // address of target
    }

    node *left_subtree = lca(root->left, a, b);   // left subtree
    node *right_subtree = lca(root->right, a, b); // right subtree

    if (left_subtree != NULL and right_subtree != NULL)
    {
        return root; // if both left and right have some non null value it is lca
    }

    if (left_subtree != NULL)
    {
        return left_subtree; // else we return the non null value if present in left subtree
    }
    return right_subtree; // or we return the null or non-null value of right subtree
}

int levelsearch(node *lca, int target, int level)
{
    if (lca == NULL)
    {
        return -1;
    }
    if (lca->data == target)
    {
        return level;
    }
    int ls = levelsearch(lca->left, target, level + 1);

    if (ls != -1)
    {
        return ls;
    }
    int rs = levelsearch(lca->right, target, level + 1);
    return rs;
}

int shortestPath(node *root, int targetA, int targetB)
{
    node *least_com_ansestor = lca(root, targetA, targetB);

    return levelsearch(least_com_ansestor, targetA, 0) + levelsearch(least_com_ansestor, targetB, 0);
}
int main()
{
    node *root = buildTree();

    bfs(root);

    node *temp = lca(root, 9, 13);
    cout << temp->data << endl;
    int shortest = shortestPath(temp, 9, 8);

    cout << "shortest path:" << shortest << endl;
}