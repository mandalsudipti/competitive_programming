#include<bits/stdc++.h>
using namespace std;

const int MAX=2005;
long long int  principal_diagonal[2*MAX], secondary_diagonal[2*MAX];
int mat[MAX][MAX];

int get_principal_diagonal(int i , int j , int n)
{
    return (i-j+n);
}

int get_secondary_diagonal(int i , int j)
{
    return (i+j);
}

int main()
{
    int n ,i,j;
    scanf("%d",&n);
    memset(principal_diagonal,0,sizeof(principal_diagonal));
    memset(secondary_diagonal,0,sizeof(secondary_diagonal));
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            //cin>>mat[i][j];
            scanf("%d",&mat[i][j]);
            int principal_diagonal_no= get_principal_diagonal(i,j,n);
            principal_diagonal[principal_diagonal_no]+=mat[i][j];
            
            int secondary_diagonal_no = get_secondary_diagonal(i,j);
            secondary_diagonal[secondary_diagonal_no]+=mat[i][j];
        }
    }
    long long int white_max=-1 , black_max=-1 ;
    int white_i , white_j , black_i , black_j;
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            int principal_diagonal_no = get_principal_diagonal(i,j,n);
            int secondary_diagonal_no = get_secondary_diagonal(i,j);
            long long int total=principal_diagonal[principal_diagonal_no]+secondary_diagonal[secondary_diagonal_no]-mat[i][j];
            if((i+j)%2==0)
            {
               if(total>black_max)
                {
                    black_max=total;
                    black_j=j;
                    black_i=i;
                }
            }
            else
            {
                if(total>white_max)
                {
                    white_max=total;
                    white_j=j;
                    white_i=i;
                }
            }
        }
    }
    //cout<<white_max+black_max<<endl;
    //cout<<white_i<<" "<<white_j<<" "<<black_i<<" "<<black_j;
    printf("%I64d\n",white_max+black_max);
    printf("%d %d %d %d",white_i,white_j,black_i,black_j);
    return 0;
}






