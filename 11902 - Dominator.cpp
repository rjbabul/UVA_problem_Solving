#include<bits/stdc++.h>
using namespace std;

int visit0[105], visit[105];

struct Node
{
    int data;
    struct Node *child;
};

Node* push(Node* head, int data)
{
    Node *newNode = NULL;

    newNode = (struct Node*)malloc(sizeof(struct Node));

    newNode->data = data;
    newNode->child= NULL;

    Node* temp= head;
    if(head==NULL) return newNode;

    while(temp->child!=NULL) temp= temp->child;
    temp->child= newNode;

    return head;
}

void bfs0(Node *node[], int s)
{
    Node *qu=NULL;
    qu = (struct Node*) malloc(sizeof(struct Node));
    qu = push(qu, s);
    visit0[s]=1;
    while(qu)
    {
        Node* temp = qu;
        qu= qu->child;
          s = temp->data;
        for(Node* edge = node[s]; edge; edge = edge->child)
        {
            int  u= edge->data;
            if(!visit0[u])
            {
                visit0[u]=1;
                qu = push(qu, u);
            }
        }

    }
}

void bfs(Node *node[], int s,int skip)
{
    Node *qu=NULL;
    qu = (struct Node*) malloc(sizeof(struct Node));
    qu = push(qu, s);
    visit[s]=1;
     while(qu)
    {
        Node* temp = qu;

           int u= qu->data;
           visit[u]=1;
        for(Node* edge = node[u]; edge; edge = edge->child)
        {
            int  v= edge->data;

            if(visit[v]==0 && v!=skip)
            {
                visit[v]=1;
                qu = push(qu, v);
            }
        }
        qu= qu->child;
    }
}

int main()
{
    int t, n;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);

    cin>>t;
    for(int case_ =1; case_<=t; case_++)
    {
        Node *node[1005];
        memset(visit0, 0, sizeof(visit0));
        memset(visit, 0, sizeof(visit));

        cin>>n;
        int x;
        for(int i=0;i<n;i++) node[i]=NULL;

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cin>>x;
                if(x==1)
                {

                     node[i]= push(node[i], j);
                }
            }
        }

      bfs0(node, 0);
      char str[n+1][n+1];

      cout<<"Case "<<case_<<":"<<endl;

      for(int i=0;i<n;i++) if(visit0[i]) str[0][i]='Y'; else str[0][i]='N';

      for(int i=1;i<n;i++)
      {


           memset(visit, 0,sizeof(visit));
           bfs(node, 0, i);

           for(int j=0;j<n;j++)
           {
               if(visit0[j] && !visit[j]) str[i][j]='Y';
               else str[i][j]='N';
           }
      }
      for(int i=0;i<n;i++)
      {
           for(int j=1; j<=n*2+1;j++)
              {
                if(j==1 || j== n*2+1)cout<<"+";else cout<<"-";
              }
              cout<<endl;
              cout<<"|";
          for(int j=0;j<n;j++)
          {
              cout<<str[i][j]<<"|";

          }
          cout<<endl;
      }
       for(int j=1; j<=n*2+1;j++)
              {
                if(j==1 || j== n*2+1)cout<<"+";else cout<<"-";
              }
              cout<<endl;

    }
    return 0;
}
