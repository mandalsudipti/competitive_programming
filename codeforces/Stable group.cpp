#include<bits/stdc++.h>
using namespace std ;


int main()
{
    long long int n , add , diff ;
    cin>>n>>add>>diff ;
    
    vector<long long int>student(n) ;
    for(int i = 0 ; i < n ; i++)
        cin>>student[i] ;
    sort(student.begin() , student.end());
    
    vector<long long int>gap ;
    
    for(int i = 1 ; i < n ; i++)
    {
        if(student[i] - student[i-1] > diff)
        {
            long long int tmp = (student[i] - student[i-1])/diff + ((student[i] - student[i-1])%diff != 0) ;
            tmp--;
            gap.push_back(tmp);
        }
    }
    sort(gap.begin() , gap.end());
    
    int group = 1 ;
    for(int i = 0 ; i < gap.size() ; i++)
    {
        if(add < gap[i])
        {
            group+=(gap.size() - i) ;
            break;
        }
        else
            add-=gap[i] ;
    }
    cout<<group<<endl;
    
    return 0 ;
}
