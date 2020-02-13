#include<bits/stdc++.h>
using namespace std;

int main()
{
    string S ;
    cin>>S;
    vector<int>arr ;
    int i , j , partition = 1;
    for(i=0;i<S.length();i++)
        arr.push_back(S[i]-48);
    long long int product=1 , max_product = 1 , reduced;
    if(arr.size()==1)
    {
        cout<<arr[0];
        return 0;
    }
    for(j=0;j<S.length();j++)
        max_product = max_product * arr[j];
    for(j=1;j<S.length();j++)
        product=product*9;
    product = product*max(arr[0]-1,1);
    
    reduced = max(arr[0]-1,1);
    max_product = max(product,max_product);
    //cout<<product<<endl;
    for(i=2;i<S.length();i++)
    {
        if(arr[partition]-1>=1)
        {
            product = (product*arr[partition-1]*(arr[partition]-1))/(reduced*9);
            //cout<<"partition->"<<arr[i]<<" product->"<<product<<endl;
            reduced = arr[partition]-1;
            partition =i ;
            max_product = max(max_product , product);
        }
    }
    cout<<max_product;
    return 0;
}



