#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n , h;
    cin>>n>>h;
    int arr[n],i,cnt=0;
    vector<int>bottle;
    for(i=0;i<n;i++)
        cin>>arr[i];
    for(i=0;i<n;i++)
    {
        bottle.push_back(arr[i]);
        sort(bottle.begin(),bottle.end());
        int height =h ,j=bottle.size()-1;
        while(height>0 && j>=0)
        {
            if(j-1>=0)
            {
                height= height- max(bottle[j],bottle[j-1]);
                j-=2;
            }
            else
            {
                height-=bottle[j];
                j--;
            }
        }
        if(height>=0 && j==-1)
            cnt=bottle.size();
        else
            break;
        
    }
    cout<<cnt;
    return 0;
}