#include<bits/stdc++.h>
using namespace std;

int main()
{
    string S;
    cin>>S;
    long long int i=0,j=0,cnt , sum=0 , cursum , x=0;
    vector<pair<long long int,long long int>>location_v ;
    while(i<S.length())
    {
        if(S[i]=='v')
        {
            cnt=0;
            while(S[i]=='v' && i<S.length())
            {
                cnt++;
                i++;
            }
            if(cnt>1)
                 {
                     location_v.push_back(make_pair(i-1,cnt-1));
                     x+=cnt-1;
                 }
        }
        else
            i++;
    }
    sort(location_v.begin(),location_v.end());
    vector<long long int> location_o;
    for(i=0;i<S.length();i++)
    {
        if(S[i]=='o')
        {
            cursum=0;
            while(j<location_v.size())
            {
                if(location_v[j].first<i)
                {
                    cursum+=location_v[j].second;
                    j++;
                }
                else
                    break;
            }
            if(location_o.size()>0)
                cursum+=location_o[location_o.size()-1];
            location_o.push_back(cursum);
        }
    }
    
    for(i=0;i<location_o.size();i++)
    {
        sum+=location_o[i]*(x-location_o[i]);
    }
    //for(i=0;i<location_o.size();i++)
    //cout<<location_o[i]<<endl;
    //for(i=0;i<location_v.size();i++)
        //cout<<location_v[i].first<<" -> "<<location_v[i].second<<endl;
    cout<<sum<<endl;
    return 0;
}