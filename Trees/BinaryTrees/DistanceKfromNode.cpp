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

void PrintKthLevel(node * root,int k)
{
    if(root == NULL)
    {
        return;
    }
    if(k==0)
    {
        cout << root->data << " ";
        return;
    }

    PrintKthLevel(root->left,k-1);
    PrintKthLevel(root->right,k-1);
    return;

}

int printAtDistanceK(node * root,node * target ,int k)
{
    if(root == NULL)
    {
        return -1;
    }
    if(root == target)
    {
        PrintKthLevel(root,k);
        return 0; // distance of node from target
    }

    int dl = printAtDistanceK(root->left,target,k);

    if(dl!=-1)
    {
        if(dl+1==k)
        {
            cout << root->data << " ";
        }
        else{
            PrintKthLevel(root->right,k-2-dl);
        }
        return dl +1;

    }

    int dr = printAtDistanceK(root->right,target,k);

    if(dr!=-1)
    {
        if(dr+1==k)
        {
            cout << root->data << " ";
        }
        else
        {
            PrintKthLevel(root->left,k-2-dr);
        }
        return dr +1;
    }
    return -1;
}

int main()
{
    node * root = buildTree();

   node * target = root->left;
   bfs(root);

   printAtDistanceK(root,target,2);


}