#include<bits/stdc++.h>
using namespace std;
char  str[202][202];
int visit[202][202];
bool flag= false;
void check(int r , int c, char b, char w,int n)
{
    int rw[]= {-1,-1,0,1,1,0};
    int rc[]= {-1,0,-1,0,1,1};

    if(r<0 || c<0 || r>=n || c>=n) return ;

    if(str[r][c]=='b') return ;

    if(c==n-1 && str[r][c]=='w')
    {

        flag=true;

        return ;
    }
    for(int i=0;i<6;i++)
    {
        int rr= r+rw[i];
        int cc= c+rc[i];
        if(rr<0 || cc<0 || rr>=n || cc>=n) continue ;
        if(!visit[rr][cc])
        {
            visit[rr][cc]=1;
            check(r+rw[i], c+rc[i], b, w, n);
        }
    }
}
int main()
{
    int n;
    //freopen("input.txt", "r", stdin);
    int t=1;
    while(cin>>n && n)
    {
        flag= false;
        string st;
        for(int i=0;i<n;i++)
        {
            cin>>st;
            for(int j=0;j<n;j++) str[i][j]= st[j];
        }

        for(int i=0;i<n && !flag;i++)
        {
            if(str[i][0]=='w')
            {
                memset(visit, 0,sizeof(visit));
                visit[i][0]=1;
                check(i, 0, 'b',  'w',n);
            }
        }
        if(flag)
            cout<<t<<" "<<"W"<<endl;
        else cout<<t<<" "<<"B"<<endl;
        t++;

    }
    return 0;
}
