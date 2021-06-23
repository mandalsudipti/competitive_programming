#include<bits/stdc++.h>
using namespace std ;

bool sortbysecond(const pair<long long int , long long int>& A , const pair<long long int , long long int>& B)
{
   return A.second < B.second ; 
}

int main()
{
    int n ;
    cin>>n;
    
    vector<pair<long long int,long long int>>arr(n);
    long long int a , b ;
    
    for(int i = 0 ; i < n ; i++)
    {
        cin>>a>>b;
        arr[i] = make_pair(a,b);
    }
    sort(arr.begin() , arr.end() , sortbysecond) ;
    
    long long int cost = 0  , product = 0;
    int left = 0 , right = arr.size() - 1 ;
    
    while(left <= right)
    {
        if(left != right)
        {
            if(product < arr[left].second)
            {
                if(product + arr[right].first <= arr[left].second)
                {
                    cost+=(arr[right].first * 2ll);
                    product+=arr[right].first ;
                    right--;
                }
                else
                {
                    long long int add = arr[left].second - product ;
                    cost+=(add * 2ll) ;
                    product+=add;
                    arr[right].first-=add;
                }
            }
            else
            {
                product+=arr[left].first ;
                cost+=arr[left].first ;
                left++ ;
            }
        }
        else
        {
            if(product < arr[left].second)
            {
                if(product + arr[left].first <= arr[left].second)
                {
                    cost+=(arr[left].first * 2ll) ;
                    product+=arr[left].first ;
                }
                else
                {
                    long long int add = arr[left].second - product ;
                    cost+=(add * 2ll);
                    product+=add;
                    arr[left].first-=add ;
                    
                    cost+=arr[left].first ;
                    product+=arr[left].first ;
                }
                left++;
            }
            else
            {
                cost+=arr[left].first ;
                product+=arr[left].first ;
                left++;
            }
        }
    }
    
    
    cout<<cost<<endl;
    
    return 0 ;
}
