#include<bits/stdc++.h>
using namespace std;
int mn=INT_MAX;
int a[1000][1000];
int visit[1000][1000];

struct Edge
{
    int r, c;
    struct Edge *child;
};

struct Node
{
    int w;
    struct Node* left;
    struct Node*right;

    Edge *ed=NULL;
};

Edge *push_edge(Edge *head, int r, int c)
{
    Edge *newnode =NULL;
    newnode= (struct Edge*)malloc(sizeof(struct Edge));
    newnode->r= r;
    newnode->c= c;
    newnode->child=NULL;

    if(head==NULL) return newnode;

    newnode->child = head;
    head= newnode;

    return head;
}

/// Search Tree with minimum value

Node* get(Node* head, int w)
{
     if(head->left!=NULL  && head->w>w)
    {
        return get(head->left, w);
    }
    else if(head->right!=NULL  && head->w<w)
    {
        return get(head->right, w);
    }
    return head;
}

/// Add Node on Tree
Node *push(Node *head , int w, int r, int c)
{
    Node *newnode = NULL;
    newnode= (struct Node*)malloc(sizeof(struct Node));
    newnode->w= w;
    newnode->left=NULL;
    newnode->right=NULL;

    newnode->ed= NULL;
    newnode->ed= push_edge(newnode->ed, r, c);

    if(head==NULL)
    {
        return newnode;
    }
     Node* temp = get(head,w);

    if(temp->w==w)
    {
     temp->ed = push_edge(temp->ed, r,c);
    }
    else if(temp->w<w) temp->right= newnode;
    else temp->left= newnode;
    return head;
}

void Dijkstra(int r , int c, int n,int m)
{
    int rw[]={-1, 0, 1, 0};
    int cw[]={0, 1, 0, -1};

    Node *qu=NULL;

    visit[0][0]=a[0][0];
    qu = push(qu,a[0][0], 0, 0);

    while(qu)
    {
        int w;
        Node *temp= qu;
        Node *cur= qu;
        Edge *edge;

          if(qu->left==NULL)
        {
            edge= qu->ed;
            w= qu->w;
            qu= qu->right;
        }
        else
        {
            while(cur->left->left) cur =cur->left;
            while(temp->left) temp = temp->left;
            edge= temp->ed;
            w= temp->w;
            cur->left= temp->right;
        }
        while(edge)
        {
            r= edge->r;
            c= edge->c;
            for(int i=0;i<4;i++)
            {
                int rr= r+rw[i];
                int cc= c+cw[i];

                if(rr>=0 && rr<n && cc>=0 && cc<m)
                {
                    if(a[rr][cc]+w<visit[rr][cc])
                    {
                         visit[rr][cc]=a[rr][cc]+w;
                         qu= push(qu,visit[rr][cc], rr, cc);
                    }
                }
            }
            edge= edge->child;
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
   freopen("input.txt","r", stdin);
    int n, m, t;
    cin>>t;
    while(t-- && cin>>n>>m)
    {
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                  visit[i][j]=INT_MAX;
                  cin>>a[i][j];
            }
        }
        Dijkstra(0,0,n,m);
        cout<<visit[n-1][m-1]<<endl;
    }
    return 0;
}
