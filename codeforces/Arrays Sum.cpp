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
        set<int>arr;
        int num;
        for(int i=0;i<n;i++)
        {
            cin>>num;
            arr.insert(num);
        }
        
        int len = arr.size()-1;
        if(k==1)
        {
            if(arr.size()==1)
                cout<<"1"<<endl;
            else
                cout<<"-1"<<endl;
        }
        else
        {
            int ans = (len/(k-1)) + (len%(k-1)!=0);
            cout<<max(ans,1)<<endl;
        }
    }
    
    return 0;
}
