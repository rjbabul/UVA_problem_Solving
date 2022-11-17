#include<bits/stdc++.h>
using namespace std;
int visit[27];
static char str[2];
struct Node
{
    int data;
    struct Node *child;
};

Node * push(Node *head, int data)
{
    Node *newnode = NULL;
    newnode = (struct Node*)malloc(sizeof(struct Node));

    newnode->data= data;
    newnode->child= NULL;

    if(head==NULL) return newnode;

    Node* temp = head;

    while(temp->child!= NULL) temp = temp->child;
    temp->child = newnode;

    return head;
}
void bfs(Node* node[], int s)
{
    visit[s]=1;

    for(Node *edge = node[s]; edge; edge= edge->child)
    {
        int v= edge->data;
        if(!visit[v])
        {
            bfs(node, v);
        }
    }
}
int main()
{
    int t;
     freopen("input.txt", "r", stdin);
    cin>>t;
    getchar();
    getchar();
    for(int test=1; test<=t; test++)
    {
        char ch=getchar();
        getchar();
        int n = ch-64;
        Node *node[28] ={NULL};
       // for(int i=0;i<28;i++) node[i]=NULL;
        while(gets(str)  && strlen(str))
        {

            int u = str[0]-64;
            int v = str[1]-64;
            node[u] = push(node[u], v);
            node[v] = push(node[v], u);
        }
        memset(visit, 0 , sizeof(visit));
        int cnt =0;
        for(int i=1;i<=n;i++)
        {
            if(!visit[i])
            {
                cnt++;
                bfs(node,i);
            }
        }
        cout<<cnt<<endl;
        if(test<t) cout<<endl;
    }
    return 0;
}
