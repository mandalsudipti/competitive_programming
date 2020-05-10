#include<bits/stdc++.h>
using namespace std;

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int n ;
        cin>>n;
        vector<int>ans;
        int left = (n%2==0)?n:(n-1);
        while(left>=6)
        {
            ans.push_back(left);
            left-=2;
        }
        ans.push_back(3);
        ans.push_back(1);
        ans.push_back(4);
        ans.push_back(2);
        int right = (n%2==1)?n:(n-1);
        for(int i=5;i<=right;i+=2)
            ans.push_back(i);
        if(n<4)
            cout<<"-1"<<endl;
        else
        {
            for(int i=0;i<ans.size();i++)
                cout<<ans[i]<<" ";
            cout<<endl;
        }
    }
    return 0;
}