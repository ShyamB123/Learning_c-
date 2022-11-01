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

void print_preorder(node *pntr)
{
    if (pntr == NULL)
    {
        return;
    }

    cout << pntr->data << " ";
    print_preorder(pntr->left);
    print_preorder(pntr->right);
}
void print_postorder(node *pntr)
{
    if (pntr == NULL)
    {
        return;
    }

    print_postorder(pntr->left);
    print_postorder(pntr->right);
    cout << pntr->data << " ";
}
void print_inorder(node *pntr)
{
    if (pntr == NULL)
    {
        return;
    }
    print_inorder(pntr->left);
    cout << pntr->data << " ";

    print_inorder(pntr->right);
}

int height(node *pntr)
{
    if (pntr == NULL)
    {
        return 0;
    }

    int lh = height(pntr->left);
    int rh = height(pntr->right);
    return max(lh, rh) + 1;
}

void printKthLevel(node *pntr, int k)
{
    if (pntr == NULL)
    {
        return;
    }
    if (k == 1)
    {
        cout << pntr->data << " ";
        return;
    }
    printKthLevel(pntr->left, k - 1);
    printKthLevel(pntr->right, k - 1);
    return;
}

void printAllLevels(node *root)
{
    int h = height(root);
    for (int i = 1; i <= h; i++)
    {
        printKthLevel(root, i);
        cout << endl;
    }
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

int count(node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    int x = count(root->left);
    int y = count(root->right);

    return 1 + x + y;
}

int sum(node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    int x = sum(root->left);
    int y = sum(root->right);

    return root->data + x + y;
}

// longest path
int diameter(node *root)
{
    // base case
    if (root == NULL)
    {
        return 0;
    }

    int lh = height(root->left);  // height of left subtree
    int rh = height(root->right); // height of right subtree

    int h = lh + rh;               // path when path goes through root
    int x = diameter(root->left);  // when path goes only in left subtree
    int y = diameter(root->right); // when path goes only in right subtree
    return max(h, max(x, y));      // take the max path
}

pair<int, int> fast_diameter(node *head)
{
    pair<int, int> p;
    if (head == NULL)
    {
        p.first = 0;
        p.second = 0;
        return p;
    }

    pair<int, int> left, right;

    left = fast_diameter(head->left);
    right = fast_diameter(head->right);

    p.first = max(left.first, right.first) + 1;                               // height
    p.second = max(left.first + right.first, max(left.second, right.second)); // diameter
    return p;
}

int sum_replacement(node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    if ((root->left == NULL) && (root->right == NULL))
    {
        return root->data;
    }

    int left_sum = sum_replacement(root->left);
    int right_sum = sum_replacement(root->right);

    int temp = root->data;
    root->data = left_sum + right_sum;
    return root->data + temp;
}

class hbpair
{
public:
    int height;
    bool balance;
};

hbpair isHeightBalanced(node *root)
{
    hbpair p;
    if (root == NULL)
    {
        p.balance = true;
        p.height = 0;
        return p;
    }

    // recursive

    hbpair l = isHeightBalanced(root->left);
    hbpair r = isHeightBalanced(root->right);

    if (abs(l.height - r.height) <= 1 && l.balance && r.balance)
    {
        p.balance = true;
    }
    else
    {
        p.balance = false;
    }

    p.height = max(l.height, r.height) + 1;
    return p;
}
int main()
{
    node *root = buildTree();
    // print_preorder(root);
    // cout << endl;
    // print_inorder(root);
    // cout << endl;
    // print_postorder(root);
    // cout << endl;
    // cout << height(root) << endl;
    // printKthLevel(root, 3);
    // cout << endl;
    printAllLevels(root);
    // bfs(root);

    // cout << count(root) << endl;
    // cout << sum(root) << endl;
    // cout << diameter(root) << endl;

    // pair<int, int> p;
    // p = fast_diameter(root);
    // cout << "height:" << p.first << endl;
    // cout << "diameter:" << p.second << endl;

    // sum_replacement(root);
    // bfs(root);

    hbpair p = isHeightBalanced(root);
    if (p.balance)
    {
        cout << " the tree is balanced:" << endl;
    }
    else
    {
        cout << " the tree is not balanced" << endl;
    }
}