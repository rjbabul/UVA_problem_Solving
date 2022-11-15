#include<bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("input.txt", "r" , stdin);
    vector<int > vt;
    int l, h, r;
    int a[10005];
    int mn = INT_MAX;
    int mx=0;
    memset(a, 0,sizeof(a));
    while(cin>>l>>h>>r)
    {
        mn=min(mn, l);
        mx= max(mx, r);
        for(int i=l;i<r;i++)
        {
            a[i]=max(a[i], h);
        }
    }
     int m;

    for(int i=mn;i<=mx;)
    {
        int j;

        cout<<i<<" "<<a[i];
        m = a[i];

        for(  j=i+1;j<=mx;j++)
            if(m>a[j])
            {

                break;
            }
            else if(m<a[j])break;
        i=j;
        if(i>mx)break;
        cout<<" ";
    }
    cout<<endl;

    return 0;
}

