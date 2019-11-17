#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    vector<Node*>children;

    Node(int d)
    {
        this->data = d;
    }
};
Node * root = NULL;

Node* constructor(vector<int> &v)
{
    list<Node*> ll;
    for(int i = 0 ; i < v.size()-1;i++)
    {
        if(v[i] != -1)
        {
            Node * nn = new Node(v[i]);
            ll.push_front(nn);
        }
        else
        {
            Node * rchild = ll.front();
            ll.pop_front();
            Node * t = ll.front();
            t->children.push_back(rchild);
        }
        
    }
    return ll.front();
}


void display(Node * r)
{
    string  s = "";
    s += to_string(r->data);
    s += " [ ";
    for(Node *x : r->children )
    {
        s = s +  to_string(x->data) + " ";
    }
    s += " ] ";
    
    cout<<s<<endl;

    for(Node * x : r->children)
    {
        display(x);
    }
}
// void serialize(Node * node,vector<int> &v)
// {
//     if(node->children.size() == 0)
//     {
//         v.push_back(-1);
//         return ;
//     }

//     v.push_back(node->data);
//     for(int i = 0 ; i < node->children.size() ; i++)
//     {
//         serialize(node->children[i]);
//     }
// }


// Node * deserialize(vector<int> &v)
// {

// }

int size(Node * root)
{
    int s = 0;
    for(int i =0; i<root->children.size() ; i++)
    {
        s += size(root->children[i]);
    }
    return s + 1;
}

int height(Node * root)
{
    int ht = 0;
    for(int i =0; i<root->children.size() ; i++)
    {
        ht = max( ht , height(root->children[i]));
    }
    return ht + 1;
}

int find(Node * root , int data)
{
    
    if(root->data == data)
    {
        return true;
    }
    bool res = false;
    for(int i =0; i<root->children.size() ; i++)
    {
        res = res || find(root->children[i] , data);
    }
    return res;
}

bool isfoldable(Node * n1, Node * n2)
{
    if((n1 != NULL && n2 == NULL) || (n1 == NULL && n2 != NULL))
    {
        return false;

    }
    if(n1->children.size() != n2->children.size())
    {
        return false;

    }

    if(n1->data != n2->data)
    {
        return false;
    }

    for(int i = 0 , j = n1->children.size() - 1 ;  i < n1->children.size() ; i++ , j--)
    {
        bool res = isfoldable(n1->children[i] , n2->children[j]);
        if(!res) return res;
    }
    return true;

}

void removeleaf(Node * root)
{
    for(int i = root->children.size() - 1 ; i >=0 ; i--)
    {
        Node * x = root->children[i];
        if(x->children.size() == 0)
        {
            // cout<<root->children.size();
             root->children.erase(root->children.begin() + i);
            // cout<<root->children.size();  
            continue;
        }
        removeleaf(x);
    }
    
}
int main()
{
    vector<int> v{10,30,-1,50,120,-1,40,-1,80,-1,-1,20,-1,-1};
    Node * root = constructor(v);
//     Node * n1 = new Node(10);
//     Node * n2 = new Node(20);
//     Node * n3 = new Node(30);
//     Node * n4 = new Node(20);
//     Node * n5 = new Node(30);
//     Node * n6 = new Node(40);
//     Node * n7 = new Node(60);
//     Node * n8 = new Node(90);
//     Node * n9 = new Node(60);
//     Node * n10 = new Node(40);
//     Node * n11 = new Node(30);
   //  Node * n10 = new Node(40);
//     n1->children.push_back(n5);
//     n1->children.push_back(n6);
//     n2->children.push_back(n7);
//     n2->children.push_back(n8);
//     n2->children.push_back(n9);
//     n3->children.push_back(n10);
//     n3->children.push_back(n11);
    
//     root->children.push_back(n1);
//     root->children.push_back(n2);
//     root->children.push_back(n3);
    display(root);
    removeleaf(root);
    // cout<<endl;
    cout<<"remove leaf"<<endl;
     display(root);
}