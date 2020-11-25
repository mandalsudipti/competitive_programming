#include<bits/stdc++.h>
using namespace std;

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int n , q ;
        cin>>n>>q;
        string S;
        cin>>S;
        vector<int>one;
        vector<int>zero;
        for(int i=0;i<n;i++)
        {
            S[i] =='0' ? zero.push_back(i) : one.push_back(i);
        }
        
        while(q--)
        {
            int left , right ;
            cin>>left>>right ;
            left-- ; 
            right--;
            int idx1 = -1, idx2 = -1 ; // idx1 -> 1 , idx2 -> 0
            bool flag = false ;
            for(int i=left;i<=right;i++)
            {
                if(S[i] == '1')
                {
                    idx1++;
                    while(idx2>-1 && one[idx1] <= zero[idx2] && idx1 < one.size())
                        idx1++;
                    if(idx1 == one.size())
                        break;
                    if( i-1>=left && S[i-1]=='0' && idx2 + 1 < zero.size() && zero[idx2 + 1] < one[idx1])
                        flag = true ;
                }
                else
                {
                    idx2++;
                    while(idx1>-1 && zero[idx2] <= one[idx1] && idx2 < zero.size())
                        idx2++;
                    if(idx2 == zero.size())
                        break;
                    if(i-1>=left && S[i-1] == '1' && idx1 + 1 < one.size() && one[idx1 + 1] < zero[idx2])
                        flag = true ;
                }
            }
            /*for(int i=0;i<one.size();i++)
                cout<<one[i]<<" ";
            cout<<endl;
            for(int i=0;i<zero.size();i++)
                cout<<zero[i]<<" ";
            cout<<endl;*/
            
            int end_ele ;
            if(idx1 == -1)
                end_ele = 0 ;
            else if(idx2 == -1)
                end_ele = 1 ;
            else
                one[idx1] > zero[idx2] ? end_ele = 1 : end_ele = 0 ;
                
            if(end_ele == 1 && idx1 < one.size() - 1)
                flag = true ;
            if(end_ele == 0 && idx2 < zero.size() - 1)
                flag =true;
            if(flag)
                cout<<"YES"<<endl;
            else
                cout<<"NO"<<endl;
        }
    }
    
    return 0;
}

