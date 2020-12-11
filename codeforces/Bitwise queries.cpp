#include<bits/stdc++.h>
using namespace std;
long long int ask(string op , long long int a , long long int b)
{
    string query = op + " " + to_string(a) + " " + to_string(b)+"\n";
    cout<<query;
    cout.flush();
    long long int ans;
    cin>>ans;
    return ans;
}

int main()
{
    long long int n;
    cin>>n;
    
    vector<long long int>XOR(n+1,0);
    for(int i=2;i<=n;i++)
    {
        long long int ans = ask("XOR",1,i);
        XOR[i] = ans;
    }
    
    map<long long int , int>xor_last_occur ;
    long long int a ;
    for(int i=1;i<=n;i++)
    {
        if(XOR[i] == n-1) // complement of first element
        {
            long long int S1 = XOR[i] ;
            long long int S2 , S3 ;
            if(i == 2)
            {
                S2 = XOR[3] + 2ll*ask("AND",1,3);
                S3 = (XOR[3] ^ XOR[i]) + 2ll*ask("AND",2,3);
            }
            else
            {
                S2 = XOR[2] + 2ll*ask("AND",1,2) ;
                S3 = (XOR[2] ^ XOR[i]) + 2ll*ask("AND",2,i);
            }
            a = (S1 + S2 - S3)/2 ;
            break;
        }
        
        if(xor_last_occur[XOR[i]]!=0) // same number found
        {
            long long int S1 = XOR[i] + 2ll*ask("AND",1,i);
            long long int S2 = S1 ;
            long long int S3 = 2ll * ask("AND",i,xor_last_occur[XOR[i]]) ;
            
            a = (S1 + S2 - S3)/2 ;
            
            break;
        }
        xor_last_occur[XOR[i]] = i ;
    }
    
    vector<long long int>ans(n+1);
    ans[1] = a ;
    for(int i=2;i<=n;i++)
        ans[i] = a ^ XOR[i] ;
        
    cout<<"! ";
    for(int i=1;i<=n;i++)
        cout<<ans[i]<<" ";
        
    cout<<"\n";
    cout.flush();
    
    return 0;
}







