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
        vector<int>distance;
        distance.push_back(0);
        for(int i=0;i<S.length();i++)
        {
            if(S[i]=='R')
            {
                distance.push_back(i+1);
            }
        }
        distance.push_back(S.length()+1);
        int differ[distance.size()];
        differ[0]=distance[0];
        for(int i=1;i<distance.size();i++)
            differ[i]= distance[i]-distance[i-1];
        int maximum=differ[0];
        for(int i=0;i<distance.size();i++)
        {
            if(differ[i]>maximum)
                maximum=differ[i];
        }
        cout<<maximum<<endl;
    }
    return 0;
}
