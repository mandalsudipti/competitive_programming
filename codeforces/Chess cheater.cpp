#include<bits/stdc++.h>
using namespace std;

bool sortfunc(const pair<int,int>&A , const pair<int,int>&B)
{
    int x = A.second - A.first + 1 , y = B.second - B.first + 1 ;
    
    if(x<y)
        return true;
    else
        return false;
}

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int n , k ;
        cin>>n>>k;
        string S;
        cin>>S;
        
        vector<pair<int,int>>segment;
        int start = -1 , end = -1 ;
        for(int i=0;i<n;i++)
        {
            if(S[i]=='L')
            {
                if(start==-1)
                    start = end = i ;
                else
                    end = i ;
            }
            if(i==n-1||S[i]=='W')
            {
                if(start!=-1)
                {
                    segment.push_back(make_pair(start,end));
                    start = end = -1 ;
                }
            }
        }
        
        sort(segment.begin(),segment.end(),sortfunc);
        //for(int i=0;i<segment.size();i++)
            //cout<<segment[i].first<<" "<<segment[i].second<<endl;
            
        for(int i=0;i<segment.size();i++)
        {
            if(segment[i].first==0 || segment[i].second==n-1)
                continue;
            for(int j=segment[i].first;j<=segment[i].second;j++)
            {
                if(k<=0)
                    break;
                S[j]='W';
                k--;
            }
        }
        
        if(k>0)
        {
            for(int i=0;i<n;i++)
            {
                if(S[i]=='W')
                {
                    for(int j=i-1;j>=0;j--)
                    {
                        if(k<=0)
                            break;
                        S[j]='W';
                        k--;
                    }
                    break;
                }
            }
        }
        if(k>0)
        {
           for(int i=n-1;i>=0;i--)
           {
               if(S[i]=='W')
               {
                   for(int j=i+1;j<n;j++)
                   {
                        if(k<=0)
                            break;
                        S[j]='W';
                        k--;
                   }
                   break;
               }
           }
        }
        
        for(int i=0;i<n;i++)
        {
            if(k>0 && S[i]=='L')
            {
                S[i] = 'W';
                k--;
            }
        }
        
        int cnt = 0 ;
        for(int i=0;i<n;i++)
        {
            if(S[i]=='W' && i>0 && S[i-1]=='W')
                cnt+=2;
            else if(S[i]=='W')
                cnt++;
        }
        
        cout<<cnt<<endl;
    }
    
    return 0;
}



