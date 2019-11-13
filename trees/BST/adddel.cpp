#include<bits/stdc++.h>
using namespace std;
class TreeNode{

    public:
    int data;
    TreeNode* left, *right;
    TreeNode(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};

TreeNode* addnode(TreeNode * root , int data)
{
    if(root == NULL)
    {
        return new TreeNode(data);
    }
    if(root->data > data)
    {
        root->left = addnode(root->left,data);
    }
    else
    {
        root->right = addnode(root->right,data);
    }
    return root;
}

//Parent Method
void add(TreeNode * node, TreeNode * par, int data , bool isleft)
{
    if(node == NULL)
    {
        if(isleft)
        {
            par->left = new TreeNode(data);
        }
        else
        {
            par->right = new TreeNode(data);
        }
        return ;  
    }

    if(node->data < data)
    {
        add(node->right , node, data, false);
    }
    else
    {
        add(node->left , node, data , true);   
    }
}
void display(TreeNode * root)
{
    if(!root)
    {
        return ;
    }

    cout<<root->data<<" ";
    root->left !=NULL ? cout<< root->left->data<<" " : cout<<  " -1 ";
    root-> right !=NULL ? cout<< root->right->data <<" ": cout<<  " -1 ";
    cout<<endl;
    display(root->left);
    display(root->right);
}

TreeNode* lkarm(TreeNode * r)
{
    TreeNode * p = r;
    r = r->left;
    while(r->right != NULL)
    {
        p = r;
        r = r->right;
    }
   // p->right = NULL;
    return r;
}

TreeNode * deletenode(TreeNode * root, int data)
{
    if(root == NULL)
    {
        return NULL;
    }
    if(root->data == data){
        if( !root->left  && !root->right)
        {
            delete root;
            return NULL;
        }

        if((root->left && !root->right) || (!root->left && root->right))
        {
            return root->left == NULL ? root->right : root->left;
        }

        else
        {
            TreeNode* n = lkarm(root);
            root->data = n->data;
            root->left = deletenode(root->left, n->data);
            return root;
        }
    }
    else if(root->data < data)
    {
        root->right = deletenode(root->right , data);
    }
    else
    {
        root->left = deletenode(root->left, data);
    }
    return root;
    
}
bool find(TreeNode * r,int data)
{
    if(!r) return false;

    if(data < r->data)
    {
        return find( r->left, data);
    }
    else if(data > r->data)
    {
        return find( r->right, data);
    }
    else
    {
        return r->data == data ? true : false;
    }
    
}
bool targetsum(TreeNode * root, int tar)
{
    if(root == NULL)
    {
        return false;
    }
    int comp = tar - root->data;
    if(find(root , comp))
    {
        return true;
    } 
    return false;
}
int main()
{
    TreeNode * root = new TreeNode (5);
    // root = addnode(root , 5);
    // root = addnode(root , 4);
    // root = addnode(root , 6);
    // root = addnode(root , 3);
  //  add(root,NULL,5,false);
    add(root,NULL,4,false);
    add(root,NULL,6,false);
    add(root,NULL,2,false);
    add(root,NULL,1,false);
    add(root,NULL,10,false);
    add(root,NULL,8,false);
    add(root,NULL,9,false);
    display(root);
    cout<<"delete"<<endl;
    root = deletenode(root ,10);
    display(root);
}