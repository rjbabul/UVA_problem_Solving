#include<bits/stdc++.h>
using namespace std;

int visit[9092], parent[9092];
struct Node
{
    int data;
    struct Node *child;
};


int get(string str)
{
    return  (int)str[0]*100+ (int)str[1];
}

Node *push(Node *head, int data)
{
    Node *newnode = NULL;
    newnode = (struct Node*)malloc(sizeof(struct Node));
    newnode->data = data;
    newnode->child= NULL;

    if(head ==NULL) return newnode;

    Node* temp = head;
    while(temp->child)temp= temp->child;
    temp->child= newnode;

    return head;
}

void bfs(Node* node[], int s)
{
    Node * qu = NULL;
    qu= (struct Node*)malloc(sizeof(struct Node));
    parent[s]=s;
    visit[s]=1;
    qu =push(qu, s);
    while(qu)
    {
        s = qu->data;
        for(Node *edge =node[s]; edge ; edge= edge->child)
        {
            int v= edge->data;
            if(!visit[v])
            {
                visit[v]=1;
                parent[v]=s;
                qu= push(qu, v);
            }
        }
        qu= qu->child;
    }
}

int main()
{
    //freopen("input.txt", "r", stdin);
    int n;
    bool flag =false;

    while(cin>>n)
    {
        if(flag)cout<<endl;
        flag=true;
        string str[9092];
        string v, u;
        Node *node[9092]={NULL};

        int vv, uu;
        int path[9092];
        for(int i=0;i<n;i++)
        {
            cin>>u>>v;
            uu= get(u);
            vv= get(v);
            node[uu]= push(node[uu],vv);
            node[vv]= push(node[vv],uu);
            str[uu]=u;
            str[vv]=v;
        }

        cin>>u>>v;
        uu= get(u);
        vv= get(v);
        memset(visit , 0, sizeof(visit));
        memset(parent , 0, sizeof(parent));

        bfs(node, uu);

        if(!visit[vv])
        {
            cout<<"No route"<<endl;
        }
        else
        {
            int j=0;

            while(parent[vv]!=vv)
            {
                path[j++]=vv;
                vv=parent[vv];

            }
            path[j++]=vv;

            for(int i=j-1;i>0;i--)
            {
                cout<<str[path[i]]<<" "<<str[path[i-1]]<<endl;
            }
        }

    }
    return 0;
}
