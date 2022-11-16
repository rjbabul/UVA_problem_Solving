#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,t;
    cin>>t;
    while(t-- && cin>>n)
    {
        int a[n+1];
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
        }
        int ans=0;
        for(int i=n-1;i>=1;i--)
        {
            for(int j=i-1;j>=0;j--)
                ans+= a[i]>=a[j];
        }
        cout<<ans<<endl;
    }

    return 0;
}
