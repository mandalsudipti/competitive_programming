#include<bits/stdc++.h>
using namespace std ;

void get_sum(int A , int B , int C , vector<long long int>& sum , vector<long long int>& way_to_sum)
{
    for(int i = A+B ; i <= B+C ; i++)
    {
        sum.push_back(i) ;
    
        int min_x , max_x ;
        
        min_x = max( A , i - C) ; // x is min when y is max . y = [B,C]
        max_x = min( B , i - B) ; // x is max when y is min 
        
        way_to_sum.push_back(max_x - min_x + 1) ;
    }
}

int main()
{
    int A , B , C , D ;
    cin>>A>>B>>C>>D ;
    
    vector<long long int>sum ;
    vector<long long int>way_to_sum ;
    
    get_sum(A, B , C , sum , way_to_sum) ;
    
    int n = way_to_sum.size() ;
    for(int i = n-2 ; i >= 0 ; i--)
        way_to_sum[i]+=way_to_sum[i+1] ;
        
    long long int total_way = 0 ;
    for(int z = C ; z <= D ; z++)
    {
        int idx = upper_bound(sum.begin() , sum.end() , z) - sum.begin() ;
        if(idx < sum.size())
            total_way+=way_to_sum[idx] ;
    }
    
    cout<<total_way<<endl;
    
    return 0 ;
}
