#include<bits/stdc++.h>
using namespace std;
char grid[61][61];

int main()
{
    //freopen("input.txt", "r", stdin);
    int t,n,m;
    string str;
    cin>>t;

    getchar();
    while(t-- )
    {
        cin>>n>>m;
        getchar();
        for(int i=1;i<=n;i++)
        {
            getline(cin, str);

            for(int j=1;j<=m;j++)
            {
                grid[i][j]=str[j-1];
            }
        }
        int c, r;
        cin>>r>>c;
        char ch ='N';
        bool flag=true;
        while(getline(cin, str))
        {

            for(int i=0;i<str.length();i++)
            {
                if(str[i]=='L'){
                    if(ch=='N') ch= 'W';
                    else if(ch=='W') ch= 'S';
                    else if(ch=='S') ch= 'E';
                    else if(ch=='E') ch= 'N';
                }
                else if(str[i]=='R'){
                    if(ch=='N') ch= 'E';
                    else if(ch=='E') ch= 'S';
                    else if(ch=='S') ch= 'W';
                    else if(ch=='W') ch= 'N';
                }

                else if(str[i]=='F'){
                    if(ch=='N')
                    {
                        if(grid[r-1][c]==' ')r--;
                    }
                    else if(ch=='W') {
                        if(grid[r][c-1]==' ')c--;
                    }
                    else if(ch=='S') {
                        if(grid[r+1][c]==' ')r++;
                    }
                    else if(ch=='E') {
                        if(grid[r][c+1]==' ')c++;
                    }
                }
                else if(str[i]=='Q')
                {
                    flag=false;
                    break;
                }
            }
            if(!flag)break;
        }

        cout<<r<<" "<<c<<" "<<ch<<endl;
        if(t)cout<<endl;
    }
    return 0;
}
