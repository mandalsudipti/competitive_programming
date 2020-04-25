#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n , k;
    cin>>n>>k;
    map<vector<int>,int>freq;
    for(int i=0;i<n;i++)
    {
        vector<int>arr(k);
        for(int j=0;j<k;j++)
            cin>>arr[j];
        freq[arr]++;
    }
    
    for(auto itr=freq.begin();itr!=freq.end();++itr)
    {
        vector<int>arr=itr->first;
        vector<int>pos_one;
        for(int i=0;i<k;i++)
        {
            if(arr[i]==1)
                pos_one.push_back(i);
        }
        for(auto i=freq.begin();i!=freq.end();++i)
        {
            vector<int>arr=i->first;
            int j;
            for(j=0;j<pos_one.size();j++)
            {
                if(arr[pos_one[j]]==1)
                    break;
            }
            if(j==pos_one.size())
            {
                cout<<"YES";
                return 0;
            }
            
        }
    }
    cout<<"NO";
    return 0;
}


