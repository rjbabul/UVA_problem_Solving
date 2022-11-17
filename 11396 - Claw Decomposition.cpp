#include<bits/stdc++.h>
using namespace std;

int bicolor[303];

struct Node
{
    int data;
    struct Node* child;
};

Node* push(Node* head, int data)
{
    Node* newnode = NULL;
    newnode= (struct Node*)malloc(sizeof(struct Node));
    newnode->data= data;
    newnode->child=NULL;
    if(head==NULL) return newnode;

    Node* temp = head;
    while(temp->child !=NULL)
        temp= temp->child;

    temp->child=newnode;

    return head;
}
int dfs(Node* node[], int s)
{
    for(Node* edge = node[s]; edge; edge= edge->child)
    {
        int v= edge->data;
        if(bicolor[v]==-1)
        {
            bicolor[v]= bicolor[s]^1;
            dfs(node, v);
        }
        else if(bicolor[v]==bicolor[s]) return 0;
    }
    return 1;
}
int main()
{
    int n;
    while(cin>>n && n)
    {
        int u, v;
        Node *node[303]={NULL};
        while(cin>>u>>v && (u>0 && v>0))
        {
             node[u]= push(node[u], v);
             node[v]= push(node[v], u);
        }
        memset(bicolor, -1, sizeof(bicolor));
        bicolor[1]=0;
        if(dfs(node, 1))
            cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}
