#include <iostream>
#include <queue>
#include<bits/stdc++.h>

using namespace std;

class node
{
public:
    int data;
    node *right;
    node *left;

    node(int d)
    {
        data = d;
        left = NULL;
        right = NULL;
    }
};

node *insertInBST(node *root, int d)
{
    // base case
    if (root == NULL)
    {
        node *temp = new node(d);
        return temp;
    }

    if (d <= root->data)
    {
        root->left = insertInBST(root->left, d);
    }
    else
    {
        root->right = insertInBST(root->right, d);
    }
    return root;
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

node * BuildTreeFromInPre(int * pre,int * in,int s,int e)
{
    static int i =0;
    //base case
    if(s>e)
    {
        return NULL;
    }

    int index = -1;

    for(int j=s;j<=e;j++)
    {
        if(in[j]==pre[i])
        {
            index = j;
            break;
        }
    }

    node * root = new node(pre[i]);
    i++;
     
    root->left = BuildTreeFromInPre(in,pre,s,index-1);
    root->right = BuildTreeFromInPre(in,pre,index +1,e);

    return root;

    


}

int main()
{
    int pre[] = {5,3,1,6,7,8};
    int n = sizeof(pre)/sizeof(int);

    int in[n]; // 1 3 5 6 7 8
    for(int i=0;i<n;i++)
    {
        in[i]= pre[i];
    }
    sort(in,in+n);



    node * root = BuildTreeFromInPre(pre ,in,0,n-1);

    bfs(root);

    
}