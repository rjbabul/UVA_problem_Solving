#include<bits/stdc++.h>
using namespace std;

struct
{
    int n, x, y;
}arr[10004];

int main()
{

    freopen("input.txt","r", stdin);
    int n;
    while(cin>>n)
    {
        int cnt=0;
        for(int i=n+1; i<=2*n;i++)
        {
            int temp  = i*n;
            if(temp%(i-n)==0)
            {
                arr[cnt].n=n;
                arr[cnt].x=temp/(i-n);
                arr[cnt].y= i;
                cnt++;
            }
        }
        cout<<cnt<<endl;
            for(int i=0;i<cnt;i++)
            {
                ///1/2  =  1/6  +  1/3
                cout<<"1/"<<arr[i].n<<" = 1/"<<arr[i].x<<" + 1/"<<arr[i].y<<endl;
            }
    }
    return 0;
}
