#include<bits/stdc++.h>
using namespace std;

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        string S;
        cin>>S;
        vector<pair<int,int>>segment;
        int idx=0;
        for(int i=1;i<S.length();i++)
        {
            if(S[i]!=S[idx])
            {
                segment.push_back(make_pair(idx,i-1));
                idx=i;
            }
        }
        segment.push_back(make_pair(idx,S.length()-1));
        
        int cnt=0 , pre=0;
        char pre_ele = '*';
        
        for(int i=0;i<segment.size();i++)
        {
            if(pre_ele == S[segment[i].first])
                pre+=(segment[i].second - segment[i].first + 1);
                
            else if(pre_ele=='*')
            {
                pre_ele = S[segment[i].first];
                pre+=(segment[i].second - segment[i].first + 1);
            }
            
            else 
            {
                int seg_len = segment[i].second - segment[i].first  + 1 ;
                
                cnt+= min(pre,seg_len);
                
                if(seg_len>pre)
                    pre_ele = S[segment[i].first];
                else if(seg_len == pre)
                    pre_ele='*';
                    
                seg_len>=pre ? pre = seg_len-pre : pre-=seg_len ;
            }
        }
        
        cnt%2==1 ? cout<<"DA"<<endl : cout<<"NET"<<endl;
    }
    return 0;
}
