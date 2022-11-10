#include<bits/stdc++.h>
using namespace std;
int ans =0;
char str[16][16];
int row[150], dia1[160], dia2[160];
void Nqueen(int col, int n)
{
    if(col == n) ans++;

    for(int i=0;i<n;i++)
    {
        if(str[i][col]=='*' || row[i]>0 || dia1[col+i]>0 || dia2[n+i -col]>0)continue;


        row[i]= dia1[col+i]= dia2[n+i-col]=1;

        Nqueen(col+1, n);
        row[i]= dia1[col+i]= dia2[n+i-col]=0;
    }

}

int main()
{
    int n;
    int t=1;
    while(cin>>n && n!=0)
    {
         memset(row, 0, sizeof(row));
         memset(dia1, 0, sizeof(dia1));
         memset(dia2, 0, sizeof(dia2));

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++) cin>>str[i][j];
        }
          ans=0;
        Nqueen(0, n);
        cout<<"Case "<<t<<": "<<ans<<endl;
        t++;
    }
    return 0;
}
