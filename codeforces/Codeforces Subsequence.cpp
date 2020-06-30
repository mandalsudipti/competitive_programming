#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long int k;
    cin>>k;
    vector<int>freq(10,1);
    long long int subsequence = 1 , idx=-1 ;
    while(subsequence<k)
    {
        idx = (idx+1)%10;
        subsequence = (subsequence*(freq[idx]+1))/freq[idx];
        freq[idx]++;
    }
    string S="codeforces";
    for(int i=0;i<S.length();i++)
    {
        for(int j=0;j<freq[i];j++)
            cout<<S[i];
    }
    return 0;
}

