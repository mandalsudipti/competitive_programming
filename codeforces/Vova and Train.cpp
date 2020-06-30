#include<bits/stdc++.h>
using namespace std;

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int length , V , left , right ;
        cin>>length>>V>>left>>right ;
        int point = (length/V) - ((right/V)- ((left-1)/V));
        cout<<point<<endl;
    }
    return 0;
}