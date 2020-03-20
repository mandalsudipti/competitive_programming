#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,q;
    cin>>n>>q;
    int matrix[3][n+10],ans=0;
    memset(matrix,0,sizeof(matrix));
    while(q--)
    {
        int x , y;
        cin>>x>>y;
        if(matrix[x][y])
        {
            matrix[x][y]=0;
            ans-=(matrix[3-x][y]+matrix[3-x][y-1]+matrix[3-x][y+1]);
        }
        else
        {
            matrix[x][y]=1;
            ans+=matrix[3-x][y]+matrix[3-x][y-1]+matrix[3-x][y+1];
        }
        if(ans)
            cout<<"NO\n";
        else
            cout<<"YES\n";
    }
    return 0;
}
