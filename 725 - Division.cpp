#include<bits/stdc++.h>
using namespace std;
int cnt;
int check(int a , int b)
{
    int flag[10];
    memset(flag, 0,sizeof(flag));
    while(a){
        flag[a%10]++;
        if(flag[a%10]>1) return 0;
        a/=10;
    }
     while(b){
        flag[b%10]++;
        if(flag[b%10]>1) return 0;
        b/=10;
        cnt++;
    }
    int sum=0;
    for(int i=0;i<10;i++) sum+= flag[i];
    if(sum<9) return 0;
    if(cnt<5 && flag[0])return 0;
    return 1;
}
int main()
{
    int n;

    int chck=0;
    while(cin>>n && n!=0)
    {
        if(chck>0) cout<<endl;
        int flag=0;
        for(int i=1234; i<=98765/n;i++)
        {
            if(i*n<=98765)
            {
                cnt=0;
                if(check(i*n, i))
                {
                    if(cnt==5)
                       cout<<i*n<<" / "<<i<<" = "<<n<<endl;
                    else
                    {

                        cout<<i*n<<" / 0"<<i<<" = "<<n<<endl;
                    }

                    flag=1;

                }
            }

        }
        if(!flag)
        cout<<"There are no solutions for "<<n<<"."<<endl;
        chck++;
    }
    return 0;
}
