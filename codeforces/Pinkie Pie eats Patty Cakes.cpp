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
        vector<int>freq(n+1,0);
        for(int i=0;i<n;i++)
        {
            int val;
            cin>>val;
            freq[val]++;
        }
        sort(freq.begin(),freq.end(),greater<int>());
        int x = freq[0]-1 , sum = 0 ;
        for(int i=1;i<freq.size();i++)
        {
            if(freq[i]==freq[0])
                freq[i]--;
            sum+=freq[i];
        }
        cout<<sum/x<<endl;
    }
    return 0;
}