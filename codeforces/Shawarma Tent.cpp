#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long int n , sx , sy ;
    cin>>n>>sx>>sy;
    long long int location[n][2],i;
    for(i=0;i<n;i++)
    {
        cin>>location[i][0]>>location[i][1];
    } 
    long long int left=0 , right=0 , up=0 , down=0 ;
    for(i=0;i<n;i++)
    {
        if(location[i][0]<sx)
            up++;
        else if(location[i][0]>sx)
            down++;
        if(location[i][1]<sy)
            left++;
        else if(location[i][1]>sy)
            right++;
    }
    long long int cnt = max(max(left,right),max(up,down));
    cout<<cnt<<endl;
    if(cnt==left)
        cout<<sx<<" "<<sy-1;
    else if(cnt==right)
        cout<<sx<<" "<<sy+1;
    else if(cnt==up)
        cout<<sx-1<<" "<<sy;
    else if(cnt==down)
        cout<<sx+1<<" "<<sy;
    return 0;
}

