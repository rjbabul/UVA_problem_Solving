#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    int cnt=0;
    while(cin>>n && n!=0)
    {
        if(cnt>0)cout<<endl;
        int a[n+1];
        for(int i=0;i<n;i++) cin>>a[i];
        for(int i=0;i<n-5;i++)
        {
             for(int j=i+1;j<n-4;j++)
             {
                 for(int k=j+1;k<n-3;k++)
                 {
                     for(int l=k+1; l<n-2;l++)
                     {
                         for(int m=l+1;m<n-1;m++)
                         {
                             for(int o=m+1; o<n;o++)
                             {
                                 cout<<a[i]<<" "<<a[j]<<" "<<a[k]<<" "<<a[l]<<" "<<a[m]<<" "<<a[o]<<endl;
                             }
                         }
                     }
                 }
             }
        }
        cnt++;
    }
    return 0;
}
