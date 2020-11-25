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
        string A , B ;
        cin>>A;
        cin>>B;
        vector<int>freq_A(26,0);
        vector<int>freq_B(26,0);
        for(int i=0;i<n;i++)
        {
            freq_A[A[i] - 'a']++;
            freq_B[B[i] - 'a']++;
        }
        
        bool possible = true ;
        vector<int>cnt_A ;
        vector<int>cnt_B ;
        for(int i=0;i<26;i++)
        {
            int tmp = min(freq_A[i] , freq_B[i]);
            freq_A[i]-=tmp ;
            freq_B[i]-=tmp;
            if(freq_A[i]%k!=0 || freq_B[i]%k !=0)
                possible = false;
            else
            {
                int x = freq_A[i] / k ;
                for(int j=0;j<x;j++)
                    cnt_A.push_back(i);
                x = freq_B[i] / k ;
                for(int j=0;j<x;j++)
                    cnt_B.push_back(i);
            }
        }
        if(!possible || cnt_B.size()!=cnt_A.size())
        {
            cout<<"NO"<<endl;
            continue;
        }
        
        for(int i=0;i<cnt_B.size();i++)
        {
            if(cnt_A[i] > cnt_B[i])
            {
                possible = false;
                break;
            }
        }
        if(!possible)
            cout<<"NO"<<endl;
        else
            cout<<"YES"<<endl;
        
    }
    
    return 0;
}