#include<bits/stdc++.h>
using namespace std;
int main()
{
   /// freopen("input.txt", "r", stdin);
    int t, n;
    cin>>t;
    while(t-- && cin>>n)
    {
        int x;
        cin>>x;
        int mx = INT_MIN;
        int fst=x;
        int sum =0;

        for(int i=1;i<n;i++)
        {
            cin>>x;
            sum+= (fst-x);

            mx=max(mx, sum);
            sum = max(sum, 0);
            fst=x;
        }
        cout<<mx<<endl;

    }
    return 0;
}
