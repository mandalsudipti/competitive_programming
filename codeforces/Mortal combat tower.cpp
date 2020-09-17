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
        vector<int>arr(n);
        for(int i=0;i<n;i++)
            cin>>arr[i];
            
        if(n<=2)
        {
            arr[0]==1 ? cout<<"1"<<endl : cout<<"0"<<endl;
            continue;
        }
        
        vector<pair<int,int>>end1(n);
        vector<pair<int,int>>end2(n);
        
        arr[0]==1 ? end1[0] = make_pair(1,1) :  end1[0] = make_pair(0,0);
        if(arr[1]==1)
        {
            end1[1] = make_pair(1+end1[0].first , 1+end1[0].first);
            end2[1] = end1[0];
        }
        else
        {
            end1[1] = end1[0];
            end2[1] = end1[0];
        }
        
        for(int i=2;i<n;i++)
        {
            end1[i] = make_pair(end1[i-1].second , min(end2[i-1].first,end2[i-1].second));
            end2[i] = make_pair(min(end1[i-1].first ,end1[i-1].second) , end2[i-1].first);
            
            if(arr[i]==1)
            {
                end1[i].first++;
                end1[i].second++;
            }
        }
        
        /*for(int i=0;i<n;i++)
        {
            cout<<end1[i].first<<" "<<end1[i].second<<"------"<<end2[i].first<<" "<<end2[i].second<<endl;
        }*/
        cout<<min( min(end1[n-1].first,end1[n-1].second) , min(end2[n-1].first,end2[n-1].second))<<endl;
    }
    
    return 0;
}