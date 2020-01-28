#include<bits/stdc++.h>
using namespace std;

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        long long int N,i,ele,diff=0,min_diff=1e6,one=1;
        cin>>N;
        vector<pair<long long int ,long long int >>arr;
        for(i=0;i<N;i++)
        {
            cin>>ele;
            arr.push_back(make_pair(ele,i));
        }
        sort(arr.begin(),arr.end());
        for(i=1;i<N;i++)
        {
            if(arr[i-1].first==arr[i].first)
            {
                diff=abs(arr[i-1].second-arr[i].second);
                if(diff<min_diff)
                    min_diff=diff;
            }
        }
        if(min_diff>N)
            cout<<"-1"<<endl;
        else
            cout<<min_diff+one<<endl;
        
    }
}