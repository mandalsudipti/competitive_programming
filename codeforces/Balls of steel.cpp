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
        vector<vector<int>>points(n,vector<int>(2));
        for(int i=0;i<n;i++)
            cin>>points[i][0]>>points[i][1];
            
        int cnt = 0 ;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]) > k)
                    break;
                else
                    cnt++;
            }
            if(cnt == n)
                break;
            else
                cnt = 0 ;
        }
        
        if(cnt == n)
            cout<<"1"<<endl;
        else
            cout<<"-1"<<endl;
    }
    
    return 0;
}