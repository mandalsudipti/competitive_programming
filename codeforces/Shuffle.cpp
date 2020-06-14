#include<bits/stdc++.h>
using namespace std;

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int n , x ,m ;
        cin>>n>>x>>m;
        int left = 0  , right = 0 ;
        while(m--)
        {
            int l ,r ;
            cin>>l>>r;
            if(left ==0 && right == 0)
            {
                if(x>=l && x<=r)
                {
                    left = l ;
                    right = r ;
                }
                continue;
            }
            if(l<=right && r>=left)
            {
                left = min(left,l);
                right = max(right , r);
            }
        }
        cout<<right-left+1<<endl;
    }
    return 0;
}