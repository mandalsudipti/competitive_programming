#include<bits/stdc++.h>
using namespace std;

bool has_zero(vector<int>&num)
{
    for(int i=0;i<num.size();i++)
    {
        if(num[i]==0)
            return true;
    }
    return false;
}

int main()
{
    int n ;
    cin>>n;
    vector<int>left(n);
    vector<int>right(n);
    
    for(int i=0;i<n;i++)
        cin>>left[i];
    for(int i=0;i<n;i++)
        cin>>right[i];
        
    vector<int>num(n,0);
    int val = n ;
    bool possible = true ;
    for(int pass=0;pass<n;pass++)
    {
        vector<int>tmp;
        for(int i=0;i<n;i++)
        {
            if(left[i]+right[i]==0)
            {
                num[i] = val;
                tmp.push_back(i);
                left[i] = right[i] = -1 ;
            }
        }
        val--;
        for(int j=0;j<tmp.size();j++)
        {
            int idx = tmp[j];
            for(int i=0;i<idx;i++)
            {
                if(right[i]>0)
                    right[i]--;
                else if(right[i]==0)
                {
                    possible = false;
                    break;
                }
            }
            for(int i=idx+1;i<n;i++)
            {
                if(left[i]>0)
                    left[i]--;
                else if(left[i]==0)
                {
                    possible = false;
                    break;
                }
            }
        }
        if(tmp.size()==0)
            break;
    }
    
    if(has_zero(num) || possible==false)
    {
        cout<<"NO";
    }
    else
    {
        cout<<"YES"<<endl;
        for(int i=0;i<n;i++)
            cout<<num[i]<<" ";
    }
    
    return 0;
}

