#include<bits/stdc++.h>
using namespace std;

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int n , p , k ;
        cin>>n>>p>>k;
        p--;
        string S;
        long long int add , erase ;
        cin>>S;
        cin>>add>>erase;
        
        int end = min(n-1,p+k-1);
        vector<vector<long long int>>op_required(end - p + 1) ;
        for(int i=p;i<=end;i++)
        {
            int start = i ;
            for(int j=start;j<n;j+=k)
            {
                if(S[j] == '0')
                    op_required[start - p].push_back(add);
                else
                    op_required[start - p].push_back(0);
                    
                int x = op_required[start - p].size();
                if(x > 1)
                    op_required[start - p][x-1]+=op_required[start - p][x-2] ;
            }
        }
        
        long long int min_cost = LONG_MAX ;
        for(int i=0;i<op_required.size();i++)
        {
            int start = i + p ;
            long long int pre_cost = erase * i ;
            for(int j=0;j<op_required[i].size();j++)
            {
                if( j > 0)
                {
                    pre_cost+=(erase * k);
                    min_cost = min( min_cost , pre_cost + op_required[i].back() - op_required[i][j-1]);
                }
                else
                    min_cost = min( min_cost , pre_cost + op_required[i].back());
            }
        }
        
        cout<<min_cost<<endl;
    }
    
    return 0;
}