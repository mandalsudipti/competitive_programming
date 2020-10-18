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
        string S;
        cin>>S;
        if(S.length()==1)
        {
            cout<<"1"<<endl;
            continue;
        }
        
        vector<int>segment_len;
        set<int>del_from;
        int start = 0 ,end = 0 ;
        for(int i=1;i<n;i++)
        {
            if(S[i]==S[start])
                end = i ;
            if(S[i]!=S[start] || i==n-1)
            {
                int len = end - start + 1 ;
                segment_len.push_back(len);
                
                start = end = i ;
                if(i==n-1 && S[i]!=S[i-1])
                    segment_len.push_back(1);
            }
        }
        
        for(int i=0;i<segment_len.size();i++)
        {
            if(segment_len[i]>1)
                del_from.insert(i);
        }
        
        int op = 0 , idx = 0 ;
        while(idx<segment_len.size())
        {
            op++;
            if(segment_len[idx]>1)
            {
                del_from.erase(del_from.find(idx));
                idx++;
            }
            else
            {
                if(del_from.size()==0)
                {
                    idx+=2;
                    continue;
                }
                idx++;
                int i = (*del_from.begin());
                segment_len[i]--;
                if(segment_len[i]==1)
                    del_from.erase(del_from.begin());
            }
        }
        
        cout<<op<<endl;
    }
    
    return 0;
}

