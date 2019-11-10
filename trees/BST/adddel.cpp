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
    display(root);
}