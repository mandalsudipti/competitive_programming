#include<bits/stdc++.h>
using namespace std;

void take_ip(vector<int>&C , vector<int>&A , vector<int>&B)
{
    for(int i = 0 ; i < C.size() ; i++)
        cin>>C[i];
        
    for(int i = 0 ;i < A.size() ; i++)
        cin>>A[i];
    for(int i = 0 ; i < B.size() ; i++)
    {
        cin>>B[i];
        if(A[i] > B[i])
            swap(A[i],B[i]);
    }
}

int main()
{
    int T ;
    cin>>T;
    while(T--)
    {
        int n ;
        cin>>n;
        vector<int>C(n),A(n),B(n);
        take_ip(C ,A , B);
        
        vector<long long int>X(n,0) , Y(n,0) , Z(n,0);
        for(int i = 0 ; i < n-1 ; i++)
        {
            X[i] = A[i+1] - 1 ;
            Z[i] = C[i] - B[i+1] ;
            Y[i] = C[i] - X[i] - Z[i] -1;
            //cout<<X[i]<<" "<<Y[i]<<" "<<Z[i]<<endl;
        }
        Y[n-1] = C[n-1] ;
        
        vector<long long int>edge_left(n,0);
        edge_left[1] = Y[0] + 2 ;
        for(int i = 2 ; i < n ; i++)
        {
            if(Y[i-1] == 0)
                edge_left[i] = 2 ;
            else
                edge_left[i] = 2 + max(edge_left[i-1] + X[i-1] + Z[i-1] , Y[i-1]);
            //cout<<edge_left[i]<<endl;
        }
    
        vector<long long int>cycle_length(n,0);
        for(int i = 1 ; i < n ; i++)
            cycle_length[i] = C[i] + edge_left[i] - 1 ;
            
        long long int maximum = 0 ;
        for(int i = 0 ; i < n ; i++)
            maximum = max(maximum , cycle_length[i]);
            
        cout<<maximum<<endl;
    }
    
    return 0;
}