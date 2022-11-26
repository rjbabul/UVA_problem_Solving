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

    newnode->child=NULL;


    if(head==NULL) return newnode;
    Edge *temp= head;
    while(temp->child) temp= temp->child;

    temp->child= newnode;

    return head;

}

Node* get(Node* head, int data)
{
     if(head->left!=NULL  && head->w>data)
    {

        return get(head->left, data);
    }
    else if(head->right!=NULL  && head->w<data)
    {
        return get(head->right, data);
    }
    return head;
}
Node* push(Node *head , int w, int r, int c)
{
    Node*newnode =NULL;
    newnode= (struct Node*) malloc(sizeof(struct Node));
    newnode->w= w;
    newnode->left= NULL;
    newnode->right=NULL;
    newnode->ed = NULL;

    if(head ==  NULL) return newnode;
    Node *temp = head;

    temp = get(head, w);

    if(temp->w>w) temp->left=newnode;
    else if(temp->w<w) temp->right=newnode;
    else{
        temp->ed = push_edge(temp->ed, r,c);
    }

    return head;
}

void diastra(int r , int c, int n,int m)
{
    int rw[]={1,-1,0,0};
    int cw[]={0,0,1,-1};

    Node *qu=NULL;
    qu= (struct Node*)malloc(sizeof(struct Node));
    if(r==n-1 && c==m-1) mn=max(mn, a[r][c]);
    visit[0][0]=0;
    qu = push(qu,0, r, c);

    while(qu)
    {

        int w;
        Node *temp= qu;
        Node *cur= qu;
        Edge *edge =NULL;
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
            if(temp->w!=cur->w) cur->left= temp->right;
        }
        while(edge)
        {
            r= edge->r;
            c= edge->c;

            for(int i=0;i<4;i++)
            {

                if((rw[i]+r)>=0 && (rw[i]+r)<n && (c+cw[i])>=0 && (c+cw[i])<m)
                {  cout<<r+rw[i]<<"  "<<(c+cw[i])<<"  "<<a[r+rw[i]][cw[i]+c]<<" "<<visit[r+rw[i]][cw[i]+c]<<endl;

                    if(a[r+rw[i]][cw[i]+c]+w<visit[r+rw[i]][c+cw[i]])
                    {

                         visit[r+rw[i]][c+cw[i]]=a[r][c]+w;
                         qu= push(qu,visit[r+rw[i]][c+cw[i]], r+rw[i], c+cw[i]);cout<<"a"<<endl;
                    }
                }
            }
            edge= edge->child;
        }


    }

}
int main()
{
    freopen("input.txt", "r", stdin);
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
         mn=INT_MAX;

        diastra(0,0,n,m);
        cout<<"b"<<endl;
        cout<<mn<<endl;

    }
    return 0;
}
