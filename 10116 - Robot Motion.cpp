#include<bits/stdc++.h>
using namespace std;
char str[11][11];
int cnt[11][11];
int main()
{
    int n, m, k;
     freopen("input.txt","r", stdin);
    while(cin>>n>>m>>k  )
    {
        if(n==0 && m==0 && k==0)break;
        string st;
        for(int i=1;i<=n;i++)
        {
            cin>>st;
            for(int j=1;j<=m;j++)
            {
                str[i][j]= st[j-1];
            }

        }
        memset(cnt, 0, sizeof(cnt));

        int r=1, c=k, lr,lc;
        int cc=0;
        bool flag=false;
        while(r>=1 && r<=n && c>=1 && c<=m)
        {


            if(cnt[r][c]==0)
            {
                cnt[r][c]=cc+1;
                cc++;
                lr=r;
                lc=c;

            }
            else
            {
                flag= true;
                lr=r;
                lc=c;

                break;
            }

            if(str[r][c]=='S') r++;
            else if(str[r][c]=='E')c++;
            else if(str[r][c]=='N') r--;
            else if(str[r][c]=='W') c--;
        }

        if(flag)
        {
            int tot=cnt[lr][lc]-1;
            int step = cc - cnt[lr][lc]+1;
            cout<< tot <<" step(s) before a loop of "<< step<<" step(s)\n" ;
        }
        else
            cout<< cc << " step(s) to exit\n" ;
    }
    return 0;
}
