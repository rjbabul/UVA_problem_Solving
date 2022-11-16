#include<bits/stdc++.h>
using namespace std;
bool binary(int a[], int l , int r, int x)
{
    if(l<r)
    {
        int mid = (l+r)/2;
        if(a[mid]==x)return true;
        else if(a[mid]<x)
            return binary(a, l, mid, x);
        else
            return binary(a, mid+1, r, x);
    }
    return false;
}
string check(int a[],int n)
{
    for(int i=0;i<n-2;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(binary(a, j+1, n, a[j]+ (a[j]-a[i])))
                return "no";
        }
    }
    return "yes";
}
int main()
{
    int n ;
    string str;
   // freopen("input.txt","r", stdin);
    while(cin>>n>>str && n)
    {
        int a[n];
        for(int i=0;i<n;i++)cin>>a[i];
        cout<< check(a,n)<<endl;
    }
    return 0;
}
