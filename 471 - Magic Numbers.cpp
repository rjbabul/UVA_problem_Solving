#include<bits/stdc++.h>
using namespace std;
bool check(long long int n)
{
    int a[10];
    memset(a, 0, sizeof(a));
    while(n)
    {
        if(a[n%10])return 0;
         a[n%10]++;
         n= n/10;
    }
    return 1;
}
int main()
{
    long long int mx= 9876543210;
    long long int n,m;
    int t;
    cin>>t;
    while(t-- && cin>>n)
    {
        for(long long int i =1; i*n<=mx;i++)
        {
            m= i*n;
            if(check(m) && check(i))
            {

                cout<<m<<" / "<<i<<" = "<<n<<endl;
            }
        }
        if(t)cout<<endl;
    }
    return 0;
}
