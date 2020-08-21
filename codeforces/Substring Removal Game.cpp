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
        vector<int>segment ;
        int start=-1 ,  end=-1 ;
        for(int i=0;i<S.length();i++)
        {
            if(S[i]=='1' && start==-1)
            {
                start = end = i ;
            }
            else if(S[i]=='1')
                    end++;
                    
            if((S[i]=='0' || i==S.length()-1) && start!=-1)
            {
                segment.push_back(end-start+1);
                start = end = -1 ;
            }
        }
        sort(segment.begin(),segment.end(),greater<long long int>());
        long long int sum = 0 ;
        for(int i=0;i<segment.size();i++)
            if(i%2==0)
                sum+=segment[i];
                
        cout<<sum<<endl;
    }
    return 0;
}