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
        vector<vector<int>>grid(n,vector<int>(n,0));
        int start = 0 ;
        for(int i=0;i<n;i++)
        {
            int ele = (k/n) + (i<k%n) ;
            while(ele>0)
            {
                start = start % n ;
                grid[i][start] = 1 ;
                start++;
                ele--;
            }
        }
        
        k%n==0 ? cout<<"0"<<endl : cout<<"2"<<endl;
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
                cout<<grid[i][j];
            cout<<endl;
        }
    }
    return 0;
}