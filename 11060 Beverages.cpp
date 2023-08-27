#include<bits/stdc++.h>
using namespace std;
map<string , int > mp ;
int hasParent[101];
int isvisit[101];
void dfs(int s,vector<int> vt[], vector<int>& tempAns )
{


    isvisit[s]=1;
    for(int i = 0; i<vt[s].size();i++)
    {
        int v = vt[s][i];
        if(!isvisit[v])
        {

            isvisit[v]=1;
            dfs(v, vt, tempAns);
        }
    }
    tempAns.push_back(s);
}
int main()
{
    freopen("input.txt", "r", stdin);
    int n ;
    int test=1;
    while(cin>>n)
    {
        memset(isvisit, 0, sizeof(isvisit));
        memset(hasParent, 0, sizeof(hasParent));
        mp.clear();
        vector<int> vt[n+1];

        map<int , string> trackName;

         string str;
        for(int i=0;i<n;i++)
        {
            cin>>str;
            mp[str]=i;
            trackName[i]=str;
        }
        int m ;
        string u, v;
        cin>>m;
        while(m--)
        {
            cin>>u>>v;
            vt[mp[u]].push_back(mp[v]);
            hasParent[mp[v]]=1;
        }




  vector<int> tempAns;
      for(int i = 0; i<n ;i++)
      {
          if(!isvisit[i] && !hasParent[i])
          {

               dfs(i,vt,tempAns);

          }
      }

      cout<<"Case #"<<test++<<": Dilbert should drink beverages in this order:";

     reverse(tempAns.begin(), tempAns.end());
          for(int i = 0;i<tempAns.size();i++)
          {

              cout<<" "<<trackName[tempAns[i]];
          }

      cout<<".\n";
    }
    cout<<endl;
    return 0;
}
