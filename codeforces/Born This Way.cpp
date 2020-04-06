#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long int len1 , len2 , k , ta , tb ;
    cin>>len1>>len2>>ta>>tb>>k;
    vector<long long int>A(len1);
    vector<long long int>B(len2);
    long long int maximum =0 ;
    for(int i=0;i<len1;i++)
    {
        cin>>A[i];
        A[i]+=ta;
    }
    for(int i=0;i<len2;i++)
    {
        cin>>B[i];
    }
    if(k>=A.size())
    {
        cout<<"-1";
        return 0;
    }
    for(int i=0;i<=k;i++)
    {
        int idx = upper_bound(B.begin(),B.end(),A[i]) - B.begin();
        int removed = k-i ;
        if(B[idx-1]==A[i])
            removed--;
        if(removed<0)
        {
            idx--;
        }
        else
        {
            idx+=removed ;
        }
        if(idx>=B.size())
        {
            cout<<"-1";
            return 0;
        }
        else
            maximum= max (maximum,B[idx]);
    }
    cout<<maximum+tb;
    return 0;
}
