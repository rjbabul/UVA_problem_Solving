#include<bits/stdc++.h>
using namespace std;
int main()
{
    int f, r;
     //freopen("input.txt", "r", stdin);
    while(cin>>f && f)
    {
        cin>>r;
        double fa[f+1], ra[r+1];

        for(int i=0;i<f;i++) cin>>fa[i];
        for(int i=0;i<r;i++) cin>>ra[i];

        double mat[r*f+2];
        int index=0;
        for(int i=0;i<f;i++)
        {
            for(int j=0;j<r;j++)
            {
                mat[index]= ra[j]/fa[i];
                index++;
            }

        }
        sort(mat, mat+index);
        double mx =-1.0;
        for(int i=0;i<r*f-1;i++)
        {
            if(mat[i+1]/mat[i]>mx)mx= mat[i+1]/mat[i];
        }
        printf("%0.2lf\n", mx);
      //  cout<<setprecision(3)<<mx<<endl;
    }
    return 0;
}
