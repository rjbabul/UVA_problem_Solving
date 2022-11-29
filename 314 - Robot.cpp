#include<bits/stdc++.h>
using namespace std;

int dxr[4]={-1, 0, 1, 0};
int dyr[4]={0, 1, 0, -1};
int obs[51][51];
int visit[51][51][5];
int n, m;

struct Node
{
    int x, y, t, d;
    struct Node* child;
};
bool valid( int x, int y)
{
    if(x<=0 || y<=0 || x>=n || y>=m) return false;
    if(obs[x-1][y-1]) return false;
    if(obs[x-1][y]) return false;
    if(obs[x][y-1]) return false;
    if(obs[x][y]) return false;
    return true;
}

Node *push(Node *head, int sx, int sy , int dir, int t)
{
   Node *newnode = NULL;
   newnode= (struct Node*)malloc(sizeof(struct Node));

   newnode->x= sx;
   newnode->y= sy;
   newnode->d= dir;
   newnode->t= t;
   newnode->child= NULL;

   if(head== NULL) return newnode;

   Node* temp = head;
   while(temp->child) temp = temp->child;
   temp->child= newnode;
   return head;
}

int dijkstra(int sx, int sy,int dx, int dy, int dir)
{
    Node *qu =NULL;

    if(valid(sx,sy))
    {
        visit[sx][sy][dir]=1;
        qu = push(qu , sx, sy , dir, 0);
    }

    while(qu)
    {
        Node * temp = qu;
        qu = qu->child;

        int x= temp->x;
        int y = temp->y;
        int t= temp->t;
        dir= temp->d;

        if(x==dx && y==dy) return t;

        int dir1= visit[x][y][(dir+1)%4];

        if(!dir1)
        {
            visit[x][y][(dir+1)%4] =1;
            qu = push(qu , x, y ,(dir+1)%4,t+1);
        }

        if(!visit[x][y][(dir+3)%4])
        {
            visit[x][y][(dir+3)%4] =1;
            qu = push(qu , x, y ,(dir+3)%4,t+1);
        }

        for(int i=1;i<=3;i++)
        {
            if(valid(x+dxr[dir]*i, y+ dyr[dir]*i))
            {
                if(!visit[x+dxr[dir]*i][y+ dyr[dir]*i][dir])
                {
                    visit[x+dxr[dir]*i][y+ dyr[dir]*i][dir] =1;
                    qu = push(qu,x+dxr[dir]*i, y+ dyr[dir]*i, dir, t+1);
                }
            }
            else break;
        }
    }
    return -1;
}
int main()
{

    //freopen("input.txt", "r", stdin);
    while(cin>>n>>m && (n|m))
    {
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
                cin>>obs[i][j];
        }

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
                for(int k=0;k<4;k++) visit[i][j][k]=0;
        }
        int sx,sy,dx,dy;
        string str;
        cin>>sx>>sy>>dx>>dy>>str;
        int dr;
        if(str[0]=='n') dr =0;
        else if(str[0]=='e') dr =1;
        else if(str[0]=='s') dr=2;
        else if(str[0]=='w') dr=3;

        cout<<dijkstra(sx, sy,dx, dy,dr)<<endl;
    }
    return 0;
}
