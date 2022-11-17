#include<bits/stdc++.h>
using namespace std;
static char str1[100];

char stt[100][100];
char st[100][100];

int get(int r, int c,int n, int m, char old, char nw)
{
    int dw[]= {0,-1,1,0,-1,1,-1,1};
    int dc[]= {1,0,0,-1,-1,-1,1,1};
    int ans =1;


    if(r<0 || c<0 || r>=n || c>=m )
        return 0;

    if(stt[r][c] == nw)
        return 0;
    stt[r][c] = nw;

    for(int i=0; i<8; i++)
    {
        ans+= get(r+dw[i], c+dc[i], n, m, old, nw);

    }

    return ans;
}
int main()
{
    //freopen("input.txt", "r", stdin);
    string str;
    int t;
    cin>>t;
    int n,m;
    getline(cin,str);
    getline(cin,str);
    while(t--)
    {
        n=0;
        int r, c;
        while(1)
        {
            getline(cin, str);
            istringstream is(str);
            is>>r>>c;

            if(str[0]!='W' && str[0]!='L')
                break;
            m= str.length();
            for(int i =0; i<m; i++)
            {
                st[n][i]= str[i];
            }
            n++;

        }


        for(int i=0; i<n; i++)
            for(int j=0; j<m; j++)
                stt[i][j]=st[i][j];

        cout<<get(r-1, c-1,n,m, 'W', 'L')<<endl;


        while(gets(str1) && strlen(str1))
        {
            istringstream is(str1);
            is>>r>>c;
            for(int i=0; i<n; i++)
                for(int j=0; j<m; j++)
                    stt[i][j]=st[i][j];

            cout<<get(r-1, c-1,n,m, 'W', 'L')<<endl;
        }
        if(t)
            cout<<endl;

    }

    return 0;
}
