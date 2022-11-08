#include<bits/stdc++.h>
using namespace std;
int a, b;
int col[100] , dia1[100], dia2[100];
int q[100];
int cnt =1;
bool check(int r, int c)
{
    for(int i=0;i<c;i++)
    {
        if(q[i]==r || abs(i-c)== abs(q[i]-r)) return false;
    }
    return true;
}
void backtrack(int c, int n )
{
    if(c== n && q[b]==a)
    {
        cout<<setw(2)<<cnt<<"     ";
        for(int i=0;i<8;i++) cout<<" "<<q[i]+1;
        cout<<endl;
        cnt++;

    }
    for(int i=0;i<n;i++)
    {
       if(check(i, c))
       {
            q[c]=i;

        backtrack(c+1, n);

       }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("input.txt","r", stdin);
    int t;
    cin>>t;
    while(t-- )
    {
        memset(col, 0,sizeof(col));
        memset(dia1,0,sizeof(dia1));
        memset(dia2, 0, sizeof(dia2));
        memset(q,0,sizeof(q));

        cin>>a>>b;
        a--, b--;
        cout<<"SOLN       COLUMN"<<endl;
        cout<<" #      1 2 3 4 5 6 7 8"<<endl;
        cout<<endl;
        cnt=1;

       backtrack(0, 8);
       if(t>0)cout<<endl;
    }

    return 0;
}
