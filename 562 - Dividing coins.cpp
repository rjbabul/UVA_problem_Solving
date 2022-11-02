#include<bits/stdc++.h>
using namespace std;

int call(int a[], int n, int sum,int ans){

  bool dp[n+3][sum+3];
   memset(dp, 0, sizeof(dp));
   dp[0][0]=1;
  for(int i=1;i<=n;i++){
    for(int j=0;j<=sum;j++){
         dp[i][j]|= dp[i-1][j];
       if(a[i]<=j)  dp[i][j]|= dp[i-1][j-a[i]];
    }
  }

  for(int i=sum;i>=0;i--){
    if(dp[n][i]) return ans-(2*i);
  }
}
int main()
{
    int n, m;
    cin>>n;
    while(n-- && cin>>m){
            int a[200];
            int sum =0;
            a[0]=0;
        for(int i=1;i<=m;i++){
            cin>>a[i];
            sum+=a[i];
        }
        int ans = sum;
        sum = (sum)/2;
      cout<<call(a, m, sum, ans)<<endl;
    }

    return 0;
}
