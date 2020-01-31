#include<bits/stdc++.h>
using namespace std;

int main()
{
    string S,T;
    cin>>S>>T;
    const int LETTER=26;
    vector<vector<long long int>>location(LETTER);
    for(int i=0;i<S.length();i++)
    {
        location[S[i]-'a'].push_back(i);
    }
    long long int cnt=1 , last_loc=-1;
    for(int i=0;i<T.length();i++)
    {
        if(location[T[i]-'a'].size()==0)
        {
            cout<<"-1";
            return 0;
        }
        auto itr=upper_bound(location[T[i]-'a'].begin(),location[T[i]-'a'].end(),last_loc);
        if(itr==location[T[i]-'a'].end())
        {
            cnt++;
            last_loc=location[T[i]-'a'][0];
        }
        else
        {
            last_loc=*itr;
        }
    }
    long long total_length=(cnt-1)*(S.length()*1LL)+(last_loc+1);
    cout<<total_length<<endl;
    return 0;
}



