#include<bits/stdc++.h>
using namespace std;

bool compare(const string& A , const string& B)
{
    long long int A_s = 0 , A_h=0,B_s = 0 , B_h = 0 ;
    for(int i=0;i<A.length();i++)
        A[i]=='s'?A_s++:A_h++;
        
    for(int i=0;i<B.length();i++)
        B[i]=='s'?B_s++:B_h++;
    
    return A_s*B_h > B_s*A_h ;
}
int main()
{
    int n ;
    cin>>n;
    vector<string>arr(n);
    for(int i=0;i<n;i++)
        cin>>arr[i];
    sort(arr.begin(),arr.end(),compare);
    
    string ans;
    for(int i=0;i<n;i++)
        ans+=arr[i];
        
    long long int cnt_subsequence = 0 , cnt_s = 0 ;
    
    for(int i=0;i<ans.length();i++)
    {
        ans[i]=='s'?cnt_s++:cnt_subsequence+=cnt_s;
    }
    cout<<cnt_subsequence<<endl;
    
    return 0;
}
