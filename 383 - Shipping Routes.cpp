#include<bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    struct Node * child;
};


int get(string str)
{
    int ans =0;
    for(int i=0;i<str.length();i++)
    {
        ans= ans * 100+ (int)(str[i]);
    }
    return ans;
}

Node *push(Node * head, int data)
{
    Node *newnode = NULL;
    newnode= (struct Node*)malloc(sizeof(struct Node));
    newnode->data= data;
    newnode->child= NULL;

    if(head == NULL) return newnode;

    Node* temp = head;

    while(temp->child) temp = temp->child;
    temp->child = newnode;

    return head;
}

int visit[9999];
int level[9999];
int ms=0;

void bfs(Node *node[], int s, int d)
{

    Node *qu= NULL;
    qu = (struct Node*)malloc(sizeof(struct Node));

    qu= push(qu, s);
    level[s]=0;
    visit[s]=1;
    while(qu)
    {

        s= qu->data;
        for(Node* edge = node[s]; edge; edge= edge->child)
        {
            int v= edge->data;

            if(!visit[v])
            {

                visit[v]=1;
                level[v]= level[s]+1;

                qu= push(qu, v);
            }
        }
        qu= qu->child;
    }
}
int main()
{
    int t;
    //freopen("input.txt", "r", stdin);
    int n, m, q;
    cout<<"SHIPPING ROUTES OUTPUT"<<endl<<endl;
    cin>>t;
    int test =1;

    while(t-- && cin>>n>>m>>q)
    {
        string str[100];
        string st;
        Node* node[9999] ={NULL};

        for(int i=0;i<n;i++)
        {
            cin>>str[i];
        }

        string s, d;
        for(int i=0;i<m;i++)
        {
            cin>>s>>d;
            int ss = get(s);
            int dd= get(d);

            node[ss]= push(node[ss], dd);
            node[dd]= push(node[dd], ss);
        }
        int ans;

        cout<<"DATA SET  "<<test<<endl<<endl; ;
        for(int i=0;i<q;i++)
        {
            cin>>ans>>s>>d;
            int ss = get(s);
            int dd = get(d);
            memset(visit, 0, sizeof(visit));
            memset(level, -1, sizeof(level));
            ms=0;

            bfs(node, ss, dd);

            if(level[dd]!=-1)
              cout<<"$"<<level[dd]*ans*100<<endl;
            else
                cout<<"NO SHIPMENT POSSIBLE"<<endl;

        }
        if(t)cout<<endl;
       test++;
    }
 cout<<"\nEND OF OUTPUT"<<endl;
    return 0;
}
