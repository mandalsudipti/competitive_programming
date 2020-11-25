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
        vector<int>arr(n);
        int freq = 1 ;
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
            if(i>0 && arr[i]==arr[0])
                freq++;
        }
        if(freq==n)
        {
            cout<<"NO"<<endl;
            continue;
        }
        else
            cout<<"YES"<<endl;
            
        vector<int>tmp;
        int diff = -1 ;
        
        for(int i=1;i<n;i++)
        {
            if(arr[i]==arr[0])
                tmp.push_back(i);
            else
            {
                cout<<1<<" "<<(i+1)<<endl;
                diff = i ;
            }
        }
        
        for(int i=0;i<tmp.size();i++)
            cout<<diff + 1 <<" "<< tmp[i]+1<<endl;
        
    }
    
    return 0;
}