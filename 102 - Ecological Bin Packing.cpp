#include<bits/stdc++.h>
using namespace std;
void pre_calculation(string str,vector<string> & vt)
{
    sort(str.begin(), str.end());
    do
    {
        vt.push_back(str);
    }
    while(next_permutation(str.begin(), str.end()));

}
int main()
{
    string str= "BCG";
    vector<string > vt;
    pre_calculation(str, vt);
    long long  int b[3], g[3], c[3];
   while(cin>>b[0]>>g[0]>>c[0])
   {

    long long int sum =0;
    sum= sum+ b[0]+g[0]+c[0];
    for(int i=1; i<3; i++)
    {
        cin>>b[i]>>g[i]>>c[i];
        sum= sum+ b[i]+g[i]+c[i];

    }
    long long int mn= 2e31+1,temp=0;
    string ans;
    sort(vt.begin(), vt.end());
    for(int i=0; i<vt.size(); i++)
    {

        temp=0;
        for(int j=0; j<3; j++)
        {
            if(vt[i][j]=='B')
                temp+= b[j];
            else if(vt[i][j]=='G')
                temp+= g[j];
            else if(vt[i][j]=='C')
                temp+= c[j];
        }

        if(sum-temp<mn)
        {
            ans= vt[i];
            mn=sum-temp;

        }

    }
    cout<<ans<<" "<<mn<<endl;

   }

    return 0;
}
