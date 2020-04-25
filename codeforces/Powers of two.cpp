#include<bits/stdc++.h>
using namespace std;

void check_bit(int n,vector<int>&set_bit)
{
    unsigned i;
    for(i=0;i<32;i++)
    {
        if(n &(1<<i))
            set_bit.push_back(1<<i);
    }
    /*for(int i=0;i<set_bit.size();i++)
        cout<<set_bit[i]<<" ";
    cout<<endl;*/
}

void get_ans(vector<int>&set_bit,vector<int>&ans , int k)
{
    int tmp = k-set_bit.size();
    for(int i=0;i<set_bit.size();i++)
    {
        if(tmp==0 || set_bit[i]==1)
            ans.push_back(set_bit[i]);
        else
        {
            vector<int>cur;
            int num = set_bit[i];
            cur.push_back(num/2);
            cur.push_back(num/2);
            tmp--;
            int idx=0;
            while(idx<cur.size() && tmp>0)
            {
                if(cur[idx]<=1)
                    idx++;
                else
                {
                    cur[idx] = cur[idx]/2;
                    cur.push_back(cur[idx]);
                    tmp--;
                }
            }
            for(int j=0;j<cur.size();j++)
                ans.push_back(cur[j]);
        }
    }
}

int main()
{
    int n , k ;
    cin>>n>>k;
    vector<int>set_bit;
    check_bit(n,set_bit);
    if(k<set_bit.size() || k>n)
        cout<<"NO";
    else
    {
        vector<int>ans;
        get_ans(set_bit,ans,k);
        if(ans.size()!=k)
            cout<<"NO";
        else
        {
            cout<<"YES\n";
            for(int i=0;i<ans.size();i++)
                cout<<ans[i]<<" ";
        }
    }
    return 0;
}