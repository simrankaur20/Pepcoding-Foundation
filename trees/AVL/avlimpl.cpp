#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node * left, * right;
    int height;
    int balance;   // value should be -1 0 or 1

    Node(int d)
    {
        data = d;
        left = NULL;
        right = NULL;
        height = -1;
        balance = 0;
    }
};


int getHeight(Node * n)
{
    if(n == NULL)
    {
        return -1;
    }
    int lh = -1 ,rh = -1;
    
    if(n->left)
      lh = n->left->height;

    if(n->right)
      rh = n->right->height;

    return max(lh,rh) + 1;

}

int getBalance(Node * n)
{
     if(n == NULL)
    {
        return 0;
    }
    int lh = -1 ,rh = -1;
    
    if(n->left)
      lh = n->left->height;

    if(n->right)
      rh = n->right->height;

    return lh - rh;
}

void getfactors(Node * n)
{
    n->height = getHeight(n);
    n->balance = getBalance(n); 
}


Node * create(vector<int> &arr,int si,int ei)
{
    if(si > ei)
    {
        return NULL;
    }

    int mid = (si + ei)/2;

    Node * n = new Node(arr[mid]);
    n->left = create(arr,si,mid-1);
    n->right = create(arr,mid+1,ei);

    //postorder mei getfactors

    getfactors(n);
    return n;
}
Node * construct(vector<int> &arr,int n)
{
    return create(arr,0,n-1);
}

void display(Node * root)
{
    if(root == NULL)
    {
        return ;
    }
    root->left == NULL ? cout<<" -1 ->" : cout<<root->left->data<<" -> ";
    cout<<root->data<<" ";
    root->right == NULL ? cout<<" <- -1 " : cout<<" <- "<<root->right->data;
    cout<<endl;
    display(root->left);
    display(root->right);
}



Node * rightrotate(Node * node)
{
    Node * n = node->left;
    Node * a = n->right;
    n->right = node;
    node->left = a;
    getfactors(n);
    getfactors(node);
    return n;
}

Node* leftrotate(Node * node)
{
    Node * n = node->right;
    Node * a = n->left;
    n->left = node;
    node->right = a;
    getfactors(n);
    getfactors(node);
    return n;
}

Node * updatefactors(Node * n)
{
   if(getBalance(n) > 1)
   {
       //lr ll
       if(getBalance(n->left) > 0) //ll
       {
           n = rightrotate(n);
       }
       else
       {
           //lr 
           n->left = leftrotate(n->left);
           n = rightrotate(n);
       }
   } 
   else if(getBalance(n) < -1 )
   {
       if(getBalance(n->right) < 0)
       {
           //rr
           n = leftrotate(n);
       }
       else
       {
          n->right = rightrotate(n->right);
          n = leftrotate(n); 
       }
   }
   return n;
}

Node* adddata(Node * node, int data)
{
    if(node == NULL)
    {
         Node* node1= new Node(data);
         getfactors(node1);
         return node1;
    }
    if(node->data < data)
    {
        node->right = adddata(node->right, data);
    }
    else 
    {
        node->left = adddata(node->left, data);
    }

    getfactors(node);
   node= updatefactors(node);
    return node;
}



Node* lkarm(Node * r)
{
    Node * p = r;
    r = r->left;
    while(r->right != NULL)
    {
        p = r;
        r = r->right;
    }
   // p->right = NULL;
    return r;
}

Node * deletenode(Node * root, int data)
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
            Node* n = lkarm(root);
            root->data = n->data;
            root->left = deletenode(root->left, n->data);
            
            getfactors(root);
          root=  updatefactors(root);
            
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
int main()
{
    vector<int> arr{1,2,3,4,5,9,10,11,12,13,14,15};
    Node * r = construct(arr,arr.size());
    display(r);
    cout<<"Add 7 "<<endl<<endl;
    r = adddata(r,7);
    display(r);
    cout<<"Add 8 "<<endl<<endl;
   // display(r);
    r = adddata(r,8);
  //  r == NULL ? cout<<"null" : cout<<r->data;
    display(r);
    cout<<" Remove 8" <<endl<<endl;
    r = deletenode(r,8);
    display(r);

    cout<<" Remove 7" <<endl<<endl;
    r = deletenode(r,7);
    display(r);
}