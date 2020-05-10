#include<bits/stdc++.h>
using namespace std;

vector<long long int>height;
const long long int maximum = 1000000000;
void card_required()
{
    height.push_back(0);
    height.push_back(2);
    long long int total_card=2,idx;
    while(total_card<=maximum)
    {
        idx=height.size();
        height.push_back((idx*2ll) + (idx-1ll)+height[idx-1]);
        total_card=height.back();
    }
}

int main()
{
    card_required();
    int T;
    cin>>T;
    while(T--)
    {
        long long int n , total_pyramid=0;
        cin>>n;
        while(n>=2)
        {
            int idx = upper_bound(height.begin(),height.end(),n) - height.begin();
            total_pyramid++;
            n = n- height[idx-1];
        }
        cout<<total_pyramid<<endl;
    }
    return 0;
}


