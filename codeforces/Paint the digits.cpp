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
        string S;
        cin>>S;
        vector<int>freq(10,0);
        for(int i=0;i<n;i++)
            freq[S[i]-48]++;
        
        vector<int>color(n);
        int idx=0;
        for(int i=0;i<n;i++)
        {
            while(idx<=10 && freq[idx]==0)
                idx++;
                
            if(S[i]==idx+48)
            {
                color[i]=1;
                freq[idx]--;
            }
            else
                color[i]=2;
        }
        vector<int>color_2;
        bool possible =true;
        for(int i=0;i<n;i++)
        {
            if(color[i]==2)
                color_2.push_back(i);
        }
        for(int i=1;i<color_2.size();i++)
        {
            int pre = color_2[i-1] , cur = color_2[i] ;
            if(S[pre]>S[cur])
            {
                possible=false;
                break;
            }
        }
        if(!possible)
            cout<<"-"<<endl;
        else
        {
            for(int i=0;i<color.size();i++)
                cout<<color[i];
            cout<<endl;
        }
    }
    return 0;
}