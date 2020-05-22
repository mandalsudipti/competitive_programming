#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,  op ;
    cin>>n;
    vector<int>arr(n+1);
    for(int i=1;i<=n;i++)
        cin>>arr[i];
    cin>>op;
    vector<int>pos(n+1,0);
    vector<int>donation;
    vector<int>donation_pos;
    for(int i=1;i<=op;i++)
    {
        int type;
        cin>>type;
        if(type==1)
        {
            int idx , amount ;
            cin>>idx>>amount;
            arr[idx]=amount;
            pos[idx]=i;
        }
        else
        {
            int amount;
            cin>>amount;
            donation.push_back(amount);
            donation_pos.push_back(i);
        }
    }
    int max_donation=0;
    if(donation.size()>=1)
        max_donation=donation.back();
    for(int i=donation.size()-1;i>=0;i--)
    {
        max_donation = max(max_donation,donation[i]);
        donation[i]=max_donation;
    }
    for(int i=1;i<=n;i++)
    {
        int x = upper_bound(donation_pos.begin(),donation_pos.end(),pos[i]) - donation_pos.begin();
        if(x<donation_pos.size())
            arr[i]=max(donation[x],arr[i]);
    }
    for(int i=1;i<=n;i++)
        cout<<arr[i]<<" ";
    return 0;
}




