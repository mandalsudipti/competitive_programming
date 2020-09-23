#include<bits/stdc++.h>
using namespace std;

int get_max(vector<int>&A , vector<int>&B , int idx1 , int idx2 , int cnt)
{
    long long int ans = 0 ;
    while(cnt>0)
    {
        if(idx1<A.size() && idx2<B.size())
        {
            if(A[idx1]>B[idx2])
            {
                ans+=A[idx1];
                idx1++;
                cnt--;
            }
            else
            {
                ans+=B[idx2];
                idx2++;
                cnt--;
            }
        }
        else if(idx1<A.size())
        {
            ans+=A[idx1];
            idx1++;
            cnt--;
        }
        else if(idx2<B.size())
        {
            ans+=B[idx2];
            idx2++;
            cnt--;
        }
        else
            break;
    }
    
    return ans;
}

int main()
{
    int n ;
    cin>>n;
    vector<int>zero_one;
    vector<int>one_zero;
    vector<int>zero_zero;
    int cnt = 0 ;
    long long int ans = 0 ;
    string S;
    int power ;
    
    for(int i=0;i<n;i++)
    {
        cin>>S>>power;
        if(S=="00")
            zero_zero.push_back(power);
        else if(S=="11")
        {
            ans+=power;
            cnt++;
        }
        else if(S=="01")
            zero_one.push_back(power);
        else
            one_zero.push_back(power);
    }
    
    sort(zero_one.begin(),zero_one.end(),greater<int>());
    sort(one_zero.begin(),one_zero.end(),greater<int>());
    sort(zero_zero.begin(),zero_zero.end(),greater<int>());
    
    int x = min(zero_one.size(),one_zero.size());
    
    for(int i=0;i<x;i++)
        ans+=(zero_one[i]+one_zero[i]);
        
    //cout<<ans<<" "<<cnt<<endl;
    if(zero_one.size()>x)
        ans+=get_max(zero_one,zero_zero,x,0,cnt);
    else if(one_zero.size()>x)
        ans+=get_max(one_zero,zero_zero,x,0,cnt);
    else
    {
        for(int i=0;i<min(cnt , (int)(zero_zero.size() ));i++)
            ans+=zero_zero[i];
    }
    
    cout<<ans<<endl;
    return 0;
}
