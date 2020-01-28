#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n ,i , j, len , val;
    cin>>n;
    vector< vector <int> > arr(n);
    for(i=0;i<n;i++)
    {
        cin>>len;
        for(j=0;j<len;j++)
        {
            cin>>val;
            arr[i].push_back(val);
        }
    }
    
    long long int ascent=0 , non_ascent=0;
    bool flag;
    
    vector<int> min_val;
    int max_val_freq[1000005]={0};

    for(i=0;i<n;i++)
    {
        flag=false;
        if(arr[i].size()>1)
        {
            for(j=1;j<arr[i].size();j++)
            {
                if(arr[i][j-1]<arr[i][j])
                {
                    ascent++;
                    flag=true;
                    break;
                }
            }
        }
        if(!flag)
        {
            min_val.push_back(arr[i][ arr[i].size()-1]);
            max_val_freq[ arr[i][0] ]++;
            non_ascent++;
        }
    }
    for(i=1000000;i>=0;i--)
        max_val_freq[i]+=max_val_freq[i+1];
        
    long long int ascent_pair = (ascent*ascent) + (2 * ascent* non_ascent);
    //cout<<ascent_pair<<endl;
    for(i=0;i<min_val.size();i++)
        ascent_pair+=max_val_freq[min_val[i]+1];
        
    cout<<ascent_pair;
    
    return 0;
}
