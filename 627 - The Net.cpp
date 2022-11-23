#include<bits/stdc++.h>
using namespace std;

int visit[303], parent[303];

struct Node
{
    int data;
    struct Node* child;
};

Node *push(Node* head, int data)
{
    Node *newnode = NULL;
    newnode= (struct Node*) malloc(sizeof(struct Node));

    newnode->data= data;
    newnode->child= NULL;

    if(head==NULL) return newnode;

    Node* temp = head;

    while(temp->child) temp= temp->child;
    temp->child= newnode;

    return head;
}

void bfs(Node*node[], int s, int d)
{
    Node*qu =NULL;

    qu =(struct Node*) malloc(sizeof(struct Node));

    qu = push(qu , s);

    visit[s]=1;
    parent[s]=s;

    while(qu)
    {
        s = qu->data;

        for(Node* edge = node[s] ; edge; edge= edge->child)
        {
            if(edge==NULL) continue;
            int  v = edge->data;

            if(!visit[v])
            {
                visit[v]=1;
                parent[v]=s;
                qu= push(qu, v);
            }
        }

        qu = qu->child;
    }
}

void call(int n)
{
    if(parent[n]==n)return ;
    call(parent[n]);
    cout<<" "<<n;
}

int main()
{
    //freopen("input.txt", "r", stdin);
    int n;
    string str;
    while(cin>>n)
    {
        while(getchar() != '\n');
        Node* node[305] ;
        for(int i=0;i<305;i++) node[i]=NULL;
        int u, v=-1;
        static char ch ;
        for(int i=0;i<n;i++)
        {

            getline(cin,str);
            istringstream is(str);
            is>>u>>ch;
           v=-1;
            while(is>>v>>ch)
            {

                node[u]= push(node[u], v);
                if(ch!=',')break;
            }
            if(v!=-1)
            node[u]= push(node[u], v);
        }
        int m;
        cout<<"-----"<<endl;
        cin>>m;
        while(m-- && cin>>u>>v)
        {
            memset(visit, 0, sizeof(visit));
            memset(parent, 0,sizeof(parent));
            visit[u]=1;
             if(node[u]!=NULL)
            bfs(node, u, v);

            if(!visit[v])
            {
                cout<<"connection impossible"<<endl;
            }
            else{
               cout<<u;
               if(v!=u)
               call(v);
               cout<<endl;
            }
        }

    }

    return 0;
}
