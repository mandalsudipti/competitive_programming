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
        vector<int>arr(n);
        vector<int>pos_one;
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
            if(arr[i]==1)
                pos_one.push_back(i);
        }
        
        if(pos_one.size()==0)
        {
            cout<<arr.size()<<endl;
            for(int i=0;i<n;i++)
                cout<<arr[i]<<" ";
            cout<<endl;
            continue;
        }
        
        vector<int>ans;
        for(int i=0;i<pos_one[0];i++)
            ans.push_back(0);
            
        for(int i=0;i<pos_one.size();i++)
        {
            if(i<pos_one.size()-1)
            {
                int zero = pos_one[i+1] - pos_one[i] - 1;
                if(zero%2==1)
                    zero--;
                ans.push_back(1);
                for(int j=0;j<zero;j++)
                    ans.push_back(0);
            }
            else
            {
                if(pos_one.size()%2==0)
                    ans.push_back(1);
                for(int j=pos_one.back()+1;j<n;j++)
                    ans.push_back(0);
            }
        }
            
        cout<<ans.size()<<endl;
        for(int i=0;i<ans.size();i++)
            cout<<ans[i]<<" ";
        cout<<endl;
    }
    
    return 0;
}
