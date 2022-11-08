#include<bits/stdc++.h>
using namespace std;
#define mx  20000

struct
{
    int num[10004];
    int cnt ;
}st[10];

int length(int x)
{
    int cnt=0;
    while(x)
    {
        cnt++;
        x/=10;
    }
    return cnt;
}
int check(int x, int n)
{
    int digit= n/2;

    int  c=1;
     for(int i=1;i<=digit;i++)
     {
         c=c*10;
     }
    int  a= x/c;
     int b= x%c;
     if((a+b)*(a+b)==x)return 1;
   else
    return 0;
}

string getstring(int x, int n)
{
    string str;
    while(x)
    {
        str+= (x%10)+'0';
        x/=10;
    }
    reverse(str.begin(), str.end());
    if(str.length()==n) return str;
    while(str.length()<n)
    {
        str= "0"+str;
    }
    return str;
}
int main()
{
    int temp;
    st[2].cnt = st[4].cnt=st[6].cnt=st[8].cnt=0;
    for(int i=0;i<=mx;i++)
    {
        temp= i*i;

        if(temp<100)
        {
            st[2].num[st[2].cnt]= temp;
            st[2].cnt++;
        }
        if(temp<=9999)
        {
             st[4].num[st[4].cnt]= temp;
            st[4].cnt++;
        }

         if( temp<=999999)
        {
             st[6].num[st[6].cnt]= temp;
            st[6].cnt++;
        }
         if( temp<=99999999)
        {
             st[8].num[st[8].cnt]= temp;
             st[8].cnt++;
        }
    }
        int n;
        while(cin>>n)
        {
            for(int i=0;i<st[n].cnt;i++)
            {
                if(check(st[n].num[i], n))
                {
                    int dt =1;
                    for(int ii=1;ii<=n/2;ii++) dt*=10;

                    cout<<getstring(st[n].num[i]/dt, n/2)+getstring(st[n].num[i]%dt, n/2)<<endl;
                }
            }

        }

    return 0;
}
