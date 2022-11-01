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

node * BuildTreeFromInPre(int * in,int * pre,int s,int e)
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
    int pre[] = {1,2,3,4,8,5,6,7};
    int in[] = {3,2,8,4,1,6,7,5};

    int n = sizeof(in)/sizeof(int);

    node * root = BuildTreeFromInPre(in,pre,0,n-1);
    bfs(root);
}