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

void serialize(Node * node,vector<int> &v)
{
    if(node->children.size() == 0)
    {
        v.push_back(-1);
        return ;
    }

    v.push_back(node->data);
    for(int i = 0 ; i < node->children.size() ; i++)
    {
        serialize(node->children[i]);
    }
}


Node * deserialize(vector<int> &v)
{

}
int main()
{

}