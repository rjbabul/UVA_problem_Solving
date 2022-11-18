///N, S, L, 0 =(N , S, E, W }
/// D,E,F = { R, L, F}
#include<bits/stdc++.h>
using namespace std;
char grid[102][102];
int main()
{
    int n, m, k;
     //freopen("input.txt", "r", stdin);
    while(cin>>n>>m>>k )
    {
        if(n==0 && m==0 && k==0) break;
        string str;
        getchar();
        char ch;
        int c,r;
        for(int i=1;i<=n;i++)
        {
            getline(cin, str);

            for(int j=1;j<=m;j++)
            {
                if(str[j-1]>='A' && str[j-1]<='Z')
                {
                    ch= str[j-1];
                    r=i;
                    c=j;
                }
                grid[i][j]= str[j-1];
            }
        }
        cin>>str;
        int cnt=0;

        for(int i=0;i<str.length();i++)
        {
            if(str[i]=='E')
            {
                if(ch=='N') ch= 'O';
                else if(ch=='O') ch= 'S';
                else if(ch=='S') ch= 'L';
                else if(ch=='L') ch= 'N';
            }

            else  if(str[i]=='D')
            {
                if(ch=='N') ch= 'L';
                else if(ch=='L') ch= 'S';
                else if(ch=='S') ch= 'O';
                else if(ch=='O') ch= 'N';
            }
          else  if(str[i]=='F')
            {
                if(ch=='N')
                {
                    if(r-1>=1 && grid[r-1][c]!='#')r--;
                }
                else if(ch=='O')
                {
                    if(c-1>=1 && grid[r][c-1]!='#')c--;
                }
                else if(ch=='S')
                {
                    if(r+1<=n && grid[r+1][c]!='#'){
                        r++;
                    }
                }
                else if(ch=='L')
                {
                    if(c+1<=m && grid[r][c+1]!='#'){
                        c++;
                    }
                }
                if(grid[r][c]=='*')
                {
                    cnt++;
                    grid[r][c]='.';
                }
            }
        }
         cout<<cnt<<endl;
    }
    return 0;
}
