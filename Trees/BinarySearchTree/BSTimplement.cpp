#include <iostream>
#include <queue>

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

bool search(node *root, int key)
{
    if (root == NULL)
        return false;

    if (root->data == key)
        return true;

    if (root->data < key)
    {
        return search(root->right, key);
    }
    else
    {
        return search(root->left, key);
    }
}
node *build()
{

    node *root = NULL;
    int d;
    cin >> d;
    while (d != -1)
    {
        root = insertInBST(root, d);
        cin >> d;
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

void inorder(node *root)
{
    if (root == NULL)
        return;

    inorder(root->left);
    cout << root->data << ",";
    inorder(root->right);
}

node *deletion(node *root, int key)
{
    if (root == NULL)
    {
        return NULL;
    }
    if (root->data < key)
    {
        root->right = deletion(root->right, key);
        return root;
    }
    else if (root->data > key)
    {
        root->left = deletion(root->left, key);
        return root;
    }
    else
    {
        // if node has 0 children
        if (root->left == NULL && root->right == NULL)
        {
            delete root;
            return NULL;
        }
        // if node has one children

        if (root->left!=NULL && root->right ==NULL)
        {
            node * temp = root->left;
            delete root;
            return temp;
        }
        if (root->left==NULL && root->right!=NULL)
        {
            node * temp = root->right;
            delete root;
            return temp;
        }
        //case where node has 2 children
        if(root->left!=NULL && root->right!=NULL)
        {
            node * replace = root->right;
            while(replace->left!=NULL)
            {
                replace = replace->left;
            }
            root->data = replace->data;

            root->right = deletion(root->right,replace->data);

            return root;
        }
    }
    return NULL;
}


bool isBST(node * root,int minv = INT_MIN,int maxv= INT_MAX)
{

    if(root==NULL)
    {
        return true;
    }
    if(root->data<=maxv && root->data >= minv && isBST(root->left,minv,root->data) && isBST(root->right,root->data,maxv))
    {
        return true;
    }
    else
    {
        return false;
    }
}

class linkedlist
{
    public:

    node * head;
    node * tail;
};

linkedlist flatten(node * root)
{
    linkedlist l;
    if(root == NULL)
    {
        l.head = l.tail = NULL;
        return l;
    }
    //if it is leaf node
    if(root->left==NULL && root->right == NULL)
    {
        l.head = l.tail = root;
        return l;
    }
    // if the node has only left subtree
    if(root->left!=NULL && root->right == NULL)
    {
        linkedlist leftLL = flatten(root->left);
        leftLL.tail->right = root;
        
        l.head = leftLL.head;
        l.tail = root;
        return l;
    }
    // if the node has only right subtree
    if(root->left == NULL && root->right!= NULL)
    {
        linkedlist rightLL = flatten(root->right);
        root->right = rightLL.head;
        
        l.head = root;
        l.tail = rightLL.tail;

        return l;
    }
    //if both subtrees are present

    linkedlist leftLL = flatten(root->left);
    linkedlist rightLL = flatten(root->right);

    leftLL.tail->right = root;
    root->right = rightLL.head;

    l.head = leftLL.head;
    l.tail = rightLL.tail;

    return l;
}

int main()
{
    node *root = build();

    bfs(root);

    inorder(root);
    cout <<endl;

    //root = deletion(root,5);

   // bfs(root);

    // inorder(root);
    // cout << endl;

    // if (isBST(root))
    // {
    //     cout << "It is BST" << endl;
    // }

    linkedlist l ;

    l = flatten(root);
    node * temp = l.head;
    while(temp!=NULL)
    {
        cout << temp->data<<"-->";
        temp = temp->right;
    }
    cout << endl;
}