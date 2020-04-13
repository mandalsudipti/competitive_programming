#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    string S,T;
    cin>>S>>T;
    vector<int>a_b ;
    vector<int>b_a;
    vector<int>a_a;
    vector<int>b_b;
    for(int i=0;i<n;i++)
    {
        if(S[i]=='a' && T[i]=='a')
            a_a.push_back(i+1);
        else if(S[i]=='b'&&T[i]=='b')
            b_b.push_back(i+1);
        else if(S[i]=='a' && T[i]=='b')
            a_b.push_back(i+1);
        else if(S[i]=='b' && T[i]=='a')
            b_a.push_back(i+1);
    }
    if(a_b.size()%2!=b_a.size()%2)
    {
        cout<<"-1";
        return 0;
    }
    
    int step = (a_b.size()/2)+(b_a.size()/2) + (a_b.size()%2==1?2:0) ;
    cout<<step<<endl;
    for(int i=0;i+1<a_b.size();i+=2)
    {
        cout<<a_b[i]<<" "<<a_b[i+1]<<endl;
    }
    for(int i=0;i+1<b_a.size();i+=2)
    {
        cout<<b_a[i]<<" "<<b_a[i+1]<<endl;
    }
    if(a_b.size()%2==1)
    {
        cout<<a_b.back()<<" "<<a_b.back()<<endl;
        cout<<a_b.back()<<" "<<b_a.back()<<endl;
    }
    return 0;
}