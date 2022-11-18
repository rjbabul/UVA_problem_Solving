#include<bits/stdc++.h>
using namespace std;
int visit[55][55];
int main()
{
    int n,m;
    cin>>n>>m;

        string str;
        char ch ;
        int r, c;
        memset(visit, 0, sizeof(visit));
        while(cin>>r>>c>>ch>>str)
        {

            bool flag= true;

            for(int i=0;i<str.length() && flag ;i++)
            {
                if(str[i]=='L')
                {
                    if(ch=='E') ch='N';
                    else if(ch=='N') ch='W';
                    else if(ch=='W') ch='S';
                    else if(ch=='S') ch='E';
                }
                if(str[i]=='R')
                {
                    if(ch=='E') ch='S';
                    else if(ch=='S') ch='W';
                    else if(ch=='W') ch='N';
                    else if(ch=='N') ch='E';

                }

                 if(str[i]=='F')
                {
                    if(ch=='E'){
                        if(r+1>n)
                        {
                            if(!visit[r][c])
                            {
                                visit[r][c]=1;
                                flag=false;
                                break;
                            }
                        }
                        else r++;
                    }

                    else if(ch=='S')
                    {
                        if(c-1<0)
                        {
                             if(!visit[r][c])
                            {
                                visit[r][c]=1;
                                flag=false;
                                break;
                            }
                        }
                        else c--;

                    }

                    else if(ch=='W')
                    {
                        if(r-1<0)
                        {
                             if(!visit[r][c])
                            {
                                visit[r][c]=1;
                                flag=false;
                                break;
                            }
                        }
                        else r--;
                    }
                    else if(ch=='N')
                    {
                         if(c+1>m)
                        {
                            if(!visit[r][c])
                            {
                                visit[r][c]=1;
                                flag=false;
                                break;
                            }
                        }
                        else c++;
                    }

                }

            }
             cout<<r<<" "<<c<<" "<<ch;
             if(!flag)
                cout<<" LOST";
             cout<<endl;
        }



    return 0;
}
