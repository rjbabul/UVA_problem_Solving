#include<bits/stdc++.h>
using namespace std;
int mat[2000006];
void heapify(int a[], int n , int at)
{
    int mn = at;
    int l = at*2+1;
    int r = at*2+2;
    if(l<n && a[l]>a[mn])mn= l;
    if(r<n && a[r]>a[mn])mn= r;
    if(mn!=at)
    {
        swap(a[mn], a[at]);
        heapify(a, n, mn);
    }
}
void heap(int a[], int n)
{

    for(int i= n/2-1; i>=0;i--) heapify(a, n, i);

    for(int i=n-1;i>0;i--)
    {
        swap(a[i], a[0]);
        heapify(a, i, 0);
    }
}

int main()
{
    int n;
    int t =1;
    freopen("input.txt","r", stdin);
    while(cin>>n && n)
    {
        int a[n+1], x;
        memset(mat, 0, sizeof(mat));

        for(int i = 0; i<n;i++) cin>>a[i];

        int index=0;
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                mat[index]= a[i]+a[j];
                index++;
            }
        }
        heap(mat, index);
        cin>>n;
        int nn = n;
        cout<<"Case "<<t<<":"<<endl;
        while(n--)
        {
            cin>>x;
             int ans =mat[0];

            for(int i=1;i<index; i++)
            {
                if(abs(x-mat[i])< abs(x- ans)) ans= mat[i];
            }
            cout<<"Closest sum to "<<x<<" is ";
            cout<<ans<<".\n";
        }
        t++;

    }
    return 0;
}
