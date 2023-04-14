#include<bits/stdc++.h>
using namespace std;
struct node
{
    int data;
    struct node *left ;
    struct node *right;
};
node * get_node( node* head, int data)
{
    if(head->left==NULL && head->right==NULL) return head;
    if(head->left && head->data > data) return get_node(head->left, data);
    else if(head->right && head->data<data) return get_node(head->right, data);
    return head;
}
node * push( node * head, int data)
{
    node * newnode= NULL;
    newnode= (struct node*) malloc( sizeof(struct node));
    newnode->data= data;
    newnode->left= NULL;
    newnode->right= NULL;
    if( head ==NULL) return newnode;
    node * temp = get_node(head, data);
    if(temp->data>data) temp->left= newnode;
    else if(temp->data <data)temp->right= newnode;

    return head;

}
void postorder(node *head)
{
    if(head==NULL) return ;
    postorder(head->left);
    postorder(head->right);
    cout<<head->data<<endl;
}

int main()
{
    int n ;
    freopen("input.txt", "r", stdin);
    node * tree=NULL;
    while(cin>>n)
    {
        tree = push( tree, n);
    }
    postorder(tree);
}
