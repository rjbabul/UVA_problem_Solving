#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    //freopen("input.txt","r", stdin);
    while(cin>>n && n)
    {
        int a[n+1];
        int i;
        for(  i=1;i<=100;i+=1)
        {
            memset(a, 0 , sizeof(a));
            a[1]=1;
            int cnt=1,k=0;

            for(int j=1;cnt<n-1;j++)
            {
                if(j%(n+1)==0)continue;

                if(a[j%(n+1)]==0)k++;

               if(k==i) {
                    cnt++;
                    a[j%(n+1)]=1;
                    k=0;

                }
            }
            if(a[13]==0)break;

        }

        cout<<i<<endl;
    }
    return 0;
}
