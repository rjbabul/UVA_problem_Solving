#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    freopen("input.txt", "r", stdin);
    cin>>t;
    while(t--)
    {
        string str[10005];
        int i=0;
        string st;
        while(cin>>st)
        {
            if(st=="*")break;
            str[i]=st;
            i++;
        }

        getchar();
        string s, ts;

        while(getline(cin, st))
        {
            if(st.length()==0)break;
            istringstream is(st);
            is>>s>>ts;

            int ss=0, tt=0;
            for(int j = 0; j<i;j++)
            {
                if(str[j]==s) ss= j;
                if(str[j]==ts) tt= j;
            }
            cout<<s<<" "<<ts<<" "<<abs(ss-tt)<<endl;
        }

        if(t>0) cout<<endl;
    }
    return 0;
}
