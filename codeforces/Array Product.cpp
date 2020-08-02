#include<bits/stdc++.h>
using namespace std;

bool sortbyval(const pair<long long int,int>&A , const pair<long long int,int>&B)
{
    return A.first > B.first ;
}
int main()
{
    int n ;
    cin>>n;
    vector<long long int>zero;
    vector<pair<long long int,int>>positive;
    vector<pair<long long int,int>>negetive;
    long long int val;
    
    for(int i=0;i<n;i++)
    {
        cin>>val;
        if(val==0)
            zero.push_back(i);
        else
            val>0 ? positive.push_back(make_pair(val,i)) : negetive.push_back(make_pair(val,i));
    }
    
    sort(positive.begin(),positive.end(),sortbyval);
    sort(negetive.begin(),negetive.end());
    
    for(int i=1;i<positive.size();i++)
    {
        cout<<"1 "<<positive[i].second+1<<" "<<positive[0].second+1<<endl;
    }
    for(int i=1;i<zero.size();i++)
        cout<<"1 "<<zero[i]+1<<" "<<zero[0]+1<<endl;
        
    int idx = negetive.size() - 1 ;
    if(idx%2==0)
        idx--;
    for(int i=1;i<=idx;i++)
        cout<<"1 "<<negetive[i].second+1<<" "<<negetive[0].second+1<<endl;
        
    if(negetive.size()>1 && positive.size()>=1)
        cout<<"1 "<<negetive[0].second+1<<" "<<positive[0].second+1<<endl;
        
    
    if(zero.size()>=1)
    {
        if(negetive.size()>=1 && (negetive.size()-1)%2==0)
        {
            cout<<"1 "<<negetive.back().second+1<<" "<<zero[0]+1<<endl;
        }
        if(positive.size()>=1 || negetive.size()>1)
            cout<<"2 "<<zero[0]+1<<endl;
    }
    else if(negetive.size()>=1 && (negetive.size()-1)%2==0)
        cout<<"2 "<<negetive.back().second+1<<endl;
        
    return 0;
}
