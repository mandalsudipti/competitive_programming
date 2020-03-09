#include<bits/stdc++.h>
using namespace std;
const long long int mod =1e9+7;
int main()
{
    long long int len ;
    string S;
    cin>>len;
    cin>>S;
    long long int i,cnt_one=0;
    vector<pair<long long int,long long int>> one ;
    for(i=0;i<len;i++)
    {
        if(S[i]=='1')
            cnt_one++;
    }
    if(cnt_one%2==1)
    {
        cout<<"-1";
        return 0;
    }
    int start=-1 , end=-1 ;
    cnt_one=0;
    for(i=0;i<len;i++)
    {
        if(S[i]=='1')
        {
            if(cnt_one==0)
            {
                start=i;
                cnt_one++;
            }
            else
            {
                end=i;
                cnt_one=0;
                one.push_back(make_pair(start,end));
            }
        }
    }
    //for(i=0;i<one.size();i++)
        //cout<<one[i].first<<" "<<one[i].second<<endl;
    long long int combination =1 ;
    
    for(i=1;i<one.size();i++)
    {
        if(one[i].first-one[i-1].second>1)
            combination = (combination * (one[i].first-one[i-1].second)%mod)%mod;
    }
    cout<<combination%mod;
    
    return 0;
}