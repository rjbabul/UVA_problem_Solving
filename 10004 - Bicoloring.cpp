#include<bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    struct Node *child;
};

int bicolor[204];


Node* push(Node* head, int data)
{
    Node * newnode = NULL;
    newnode = (struct Node*) malloc(sizeof(struct Node));
    newnode->data= data;
    newnode->child= NULL;

    if(head==NULL) return newnode;

    Node *temp = head;
    while(temp->child!=NULL) temp = temp->child;

    temp->child=newnode;
    return head;
}

int dfs(Node*node[], int s)
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
    freopen("input.txt", "r", stdin);
    int n, m;
    int u, v;

    while(cin>>n && n)
    {
        cin>>m;
        Node *node[202] ={NULL};

        for(int i=0;i<m;i++)
        {
            cin>>u>>v;
            node[u]= push (node[u], v);
            node[v]= push (node[v], u);
        }

        memset(bicolor, -1, sizeof(bicolor));
        bicolor[0]=0;
        if(dfs(node, 0))
            cout<<"BICOLORABLE."<<endl;
        else
            cout<<"NOT BICOLORABLE."<<endl;



    }
    return 0;
}
