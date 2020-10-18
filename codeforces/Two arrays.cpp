#include<bits/stdc++.h>
using namespace std;

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int n , k ;
        cin>>n>>k;
        
        vector<int>color(n);
        multiset<int>A;
        multiset<int>B;
        
        int mid_cnt = 0 , val;
        for(int i=0;i<n;i++)
        {
            cin>>val;
            if(k%2==0 && k/2==val)
            {
                color[i] = -1 ;
                mid_cnt++;
                continue;
            }
            
            if(A.find(k-val)==A.end())
            {
                A.insert(val);
                color[i] = 0 ;
            }
            else
            {
                B.insert(val);
                color[i] = 1 ;
            }
        }
        
        int cnt = 0 ;
        for(int i=0;i<n;i++)
        {
            if(color[i]==-1)
            {
                cnt++;
                cnt>mid_cnt/2 ? color[i] = 1 : color[i] = 0;
            }
        }
        
        for(int i=0;i<n;i++)
            cout<<color[i]<<" ";
        cout<<endl;
        
    }
    
    return 0;
}