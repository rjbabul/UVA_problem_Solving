#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a, b, c;
    int n;
    cin>>n;
    while(n-- && cin>>a>>b>>c)
    {
        int flag = 0;
        int x, y,z;
        for(x=-21; x<=21 && !flag; x++)
        {
            for( y=-100; y<=100 && !flag; y++)
            {
                for(z=-100; z<=100 && !flag; z++)
                {
                    if(x!=y && z!=x && y!=z)
                        if(x+y+z==a && x*y*z==b && (x*x+y*y+z*z)==c)
                        {
                            flag =1;
                            goto solution;
                        }
                }
            }
        }
solution:
        if(flag)
            cout<<x<<" "<<y<<" "<<z<<endl;
        else
            cout<<"No solution."<<endl;
    }
    return 0;

}
