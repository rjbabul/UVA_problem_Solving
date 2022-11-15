#include<bits/stdc++.h>
using namespace std;

struct database
{
    int l, h;
    string name;
};
int main()
{
    int t, n;
    freopen("input.txt", "r", stdin);
    database  lst[10005];
    cin>>t;
    while(t-- && cin>>n)
    {

        for(int i=0;i<n;i++)
        {
            cin>>lst[i].name>>lst[i].l>>lst[i].h;

        }
        int q,x;
        cin>>q;
        while(q--)
        {
            cin>>x;
            int cnt=0,pos;
            for(int i=0;i<n;i++)
                if(lst[i].l<= x && lst[i].h>=x)
                {
                    pos=i;
                    cnt++;
                }
                if(cnt==1)
                    cout<<lst[pos].name<<endl;
                else cout<<"UNDETERMINED"<<endl;


        }
        if(t)cout<<endl;

    }
    return 0;
}
