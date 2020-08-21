#include<bits/stdc++.h>
using namespace std;

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int n;
        cin>>n;
        vector<long long int>candy(n);
        vector<long long int>orange(n);
        for(int i=0;i<n;i++)
            cin>>candy[i];
        for(int i=0;i<n;i++)
            cin>>orange[i];
        
        long long int min_candy = candy[0] , min_orange = orange[0] , total_move = 0 ;
        for(int i=0;i<n;i++)
        {
            min_orange = min(min_orange,orange[i]);
            min_candy = min(min_candy,candy[i]);
        }
        for(int i=0;i<n;i++)
        {
            long long int x = candy[i]- min_candy , y = orange[i] - min_orange ;
            total_move+=max(x,y);
        }
        cout<<total_move<<endl;
    }
    return 0;
}