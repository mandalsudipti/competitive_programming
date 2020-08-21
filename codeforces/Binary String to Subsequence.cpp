#include<bits/stdc++.h>
using namespace std;

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int n ;
        cin>>n;
        string S;
        cin>>S;
        vector<int>arr(n);
        vector<set<int>>end_with(2);
        int idx = 1;
        for(int i=0;i<n;i++)
        {
            if(S[i]=='0')
            {
                if(end_with[1].size()==0)
                {
                    arr[i] = idx ;
                    end_with[0].insert(idx);
                    idx++;
                }
                else
                {
                    int val = *(end_with[1].begin());
                    end_with[1].erase(end_with[1].begin());
                    arr[i]=val;
                    end_with[0].insert(val);
                    
                }
            }
            else
            {
                if(end_with[0].size()==0)
                {
                    arr[i] = idx;
                    end_with[1].insert(idx);
                    idx++;
                }
                else
                {
                    int val = *(end_with[0].begin());
                    end_with[0].erase(end_with[0].begin());
                    end_with[1].insert(val);
                    arr[i]=val;
                }
            }
        }
        int maximum = 0;
        for(int i=0;i<n;i++)
        {
            if(arr[i]>maximum)
                maximum=arr[i];
        }
        cout<<maximum<<endl;
        for(int i=0;i<n;i++)
            cout<<arr[i]<<" ";
        cout<<endl;
    }
    return 0;
}