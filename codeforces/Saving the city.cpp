#include<bits/stdc++.h>
using namespace std;
const int activate = 1 , place = 0 ;
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int a , b ;
        cin>>a>>b;
        
        string S;
        cin>>S;
        vector<pair<int,int>>segment;
        int left = -1 , right = -1 ;
        
        for(int i=0;i<S.length();i++)
        {
            if(S[i]=='1')
            {
                if(left==-1)
                    left = right = i;
                else
                    right = i ;
            }
            
            if(S[i]=='0' || i==S.length()-1)
            {
                if(left!=-1)
                {
                    segment.push_back(make_pair(left,right));
                    left = right = -1;
                }
            }
        }
        
        long long int total_cost = 0 ;
        for(int i=0;i<segment.size();i++)
        {
            if(i==segment.size()-1 || a<=(segment[i+1].first - segment[i].second - 1)*b)
                total_cost+=a;
            else
                total_cost+=(segment[i+1].first - segment[i].second - 1)*b ;
        }
        cout<<total_cost<<endl;
    }
    
    return 0;
}
