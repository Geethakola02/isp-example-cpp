#include<iostream>
#include<queue>
using namespace std;
struct node{
    int val;
    node* left;
    node* right;
    node(int data):val(data),left(nullptr),right(nullptr){}

};
void preorder(node*root)
{
    if(root==nullptr)
    {
        return ;
    }
    cout<<root->val<<"->";
    preorder(root->left);
     preorder(root->right);
}
void Inorder(node*root)
{
    if(root==nullptr)
    {
        return ;
    }
    Inorder(root->left);
    cout<<root->val<<"->";
    Inorder(root->right);
}
void postorder(node*root)
{
    if(root==nullptr)
    {
        return ;
    }
    postorder(root->left);
     postorder(root->right);
     cout<<root->val<<"->";
}
void levelOrder(node* root) {
    if (root == nullptr) return;
    queue<node*> q;
    q.push(root);
    while (!q.empty()) {
        node* current = q.front();
        q.pop();
        cout << current->val<< " ";
        if (current->left) q.push(current->left);
        if (current->right) q.push(current->right);
    }
}

int main()
{
    node* root=new node(1);
    root->left=new node(2);
    root->right=new node(3);
    root->left->left=new node(4);
    root->right->right=new node(5);
    root->left->right=new node(6);
    root->right->left=new node(7);
    root->left->left->left=new node(8);
    root->right->right->right=new node(9);
    cout<<"preorder:";
    preorder(root);
    cout<<endl;
    cout<<"inorder:"<<endl;
    Inorder(root);
 cout<<endl;
    
    cout<<"postorder:"<<endl;
    postorder(root);
    
 cout<<endl;
    
    cout<<"lowlevelorder:"<<endl;
    levelOrder(root);


}