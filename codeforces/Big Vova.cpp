#include<bits/stdc++.h>
using namespace std;


int find_multiple(multiset<int,greater<int>>&arr, int num)
{
    for(auto itr=arr.begin();itr!=arr.end();++itr)
    {
        if((*itr)>=num && (*itr)%num==0)
            return (*itr);
    }
    
    return 0;
}

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int n ;
        cin>>n;
        multiset<int,greater<int>>arr;
        for(int i=0;i<n;i++)
        {
            int val;
            cin>>val;
            arr.insert(val);
        }
        vector<int>ans;
        ans.push_back((*arr.begin()));
        arr.erase(arr.begin());
        
        int gcd = ans[0] ;
        while(true)
        {
            bool find = false;
            int x = find_multiple(arr,gcd);
            if(x)
            {
               ans.push_back(x);
               arr.erase(arr.find(x));
               continue;
            }
            
            for(int i=2;i<=sqrt(gcd);i++)
            {
                if(gcd%i==0 && find_multiple(arr,gcd/i))
                {
                    int x = find_multiple(arr,gcd/i);
                    ans.push_back(x);
                    arr.erase(arr.find(x));
                    gcd = gcd/i;
                    find = true;
                    break;
                }
            }
            if(find)
                continue;
            for(int i=sqrt(gcd);i>=2;i--)
            {
                if(gcd%i==0 && find_multiple(arr,i))
                {
                    int x = find_multiple(arr,i);
                    ans.push_back(x);
                    arr.erase(arr.find(x));
                    gcd = i ;
                    find = true ;
                    break;
                }
            }
            if(!find)
                break;
        }
        
        for(auto itr=arr.begin();itr!=arr.end();++itr)
            ans.push_back(*itr);
        for(int i=0;i<ans.size();i++)
            cout<<ans[i]<<" ";
        cout<<endl;
    }
    
    return 0;
}



