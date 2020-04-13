#include<bits/stdc++.h>
using namespace std;

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        long long  n , x, val  ;
        cin>>n>>x;
        long long sum =0 ,idx =0 ;
        vector<long long > negetive;
        for(int i=0;i<n;i++)
        {
            cin>>val;
            if(val<x)
                negetive.push_back(val);
            else
            {
                sum+=val;
                idx++;
            }
        }
        
        sort(negetive.begin(),negetive.end());
        for(int i=negetive.size()-1;i>=0;i--)
        {
            if(sum+negetive[i]>=(idx+1)*x)
            {
                idx++;
                sum+=negetive[i];
            }
            else
                break;
        }
        cout<<idx<<endl;
    }
    return 0;
}