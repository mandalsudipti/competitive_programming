#include<bits/stdc++.h>
using namespace std;

int main()
{
    string A , B ;
    cin>>A>>B;
    
    vector<int>cnt_zero(B.length(),0);
    for(int i=0;i<B.length();i++)
    {
        if(B[i]=='0')
            cnt_zero[i]++;
        if(i>0)
            cnt_zero[i]+=cnt_zero[i-1];
    }
    
    long long int cnt = 0 ;
    for(int i=0;i<A.length();i++)
    {
        int last_idx = B.length() - A.length() + i;
        int first_idx = i ;
        int zero = cnt_zero[last_idx] - (first_idx>0 ? cnt_zero[first_idx-1] : 0) ;
        int one = (last_idx - first_idx + 1) - zero ;
        
        if(A[i]=='0')
            cnt+=one;
        else
            cnt+=zero;
    }
    
    cout<<cnt<<endl;
    
    return 0;
}