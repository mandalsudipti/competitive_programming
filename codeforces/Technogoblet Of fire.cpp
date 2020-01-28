#include<bits/stdc++.h>
using namespace std;

bool sort_by_school( const vector<int>& v1, 
               const vector<int>& v2 ) { 
 return v1[1] < v2[1]; 
} 

bool sort_by_power( const vector<int>& v1, 
               const vector<int>& v2 ) { 
 return v1[0] < v2[0]; 
} 

int main()
{
    int n , m ,k ,i , val;
    cin>>n>>m>>k;
    int query[k] , cnt=0;
    vector<vector<int> > arr(n) ;
    for(i=0;i<n;i++)
        arr[i]=vector<int>(3);
    for(i=0;i<n;i++) //power
        cin>>arr[i][0];
    for(i=0;i<n;i++)
        cin>>arr[i][1]; //school
    for(i=0;i<n;i++)
        arr[i][2]=i+1; //id;
    
    for(i=0;i<k;i++)
        cin>>query[i];
    sort(arr.begin(),arr.end(),sort_by_school);
    
    int start=0  ;
    for(i=0;i<n;i++)
    {
        if(i==n-1 || arr[i][1]!=arr[i+1][1])
        {
            sort(arr.begin()+start,arr.begin()+i+1,sort_by_power);
            start=i+1;
        }
    }
    for(i=0;i<k;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(query[i]==arr[j][2] && j+1<n && arr[j][1]==arr[j+1][1])
            {
                cnt++; 
            }
        }
    }
    cout<<cnt;
    return 0;
}