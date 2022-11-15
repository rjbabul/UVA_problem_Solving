#include<bits/stdc++.h>
using namespace std;

int main()
{
    double  v, v0;
    double length[60004];
    while(cin>>v>>v0  && (v || v0))
    {
        double d = 0.3;
        if(v<=v0)
        {
            cout<<0<<endl;
            continue;
        }

        double mx=0.0,s,dd;
        int i,ans;
        for( i=1;i<v ;i++)
        {
             s= v/(double)(i);
             if(v0>=s) break;
            dd= (s - v0);
            dd= sqrt(dd) *d;
            dd= dd*(double)(i);
            if(mx<dd)
            {
                 mx=dd;
                 ans=i;
            }
            length[i]= dd;
        }

        for(int j=1;j<i;j++)
        {
           if(abs(length[j]- mx)<0.00000001 && ans!=j) ans=0;

        }

        cout<<ans<<endl;
    }
    return 0;
}
