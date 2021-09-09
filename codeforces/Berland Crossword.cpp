#include <bits/stdc++.h>
using namespace std;

int main()
{
	int T;
	cin >>T;
	while (T--)
	{
		bool flag = false;
		int n, A, B, C, D;
		cin >> n >> A >> B >> C >> D;
		for(int i = 0; i < 16; i++)
		{
			int a = A, b = B, c = C, d = D;
			if(i&1) a--, b--;
			if(i&2) b--, c--;
			if(i&4) c--, d--;
			if(i&8) d--, a--;
			if(a>=0 && a<=n-2 && b>=0 && b<=n-2 && c>=0 && c<=n-2 && d>=0 && d<=n-2) 
			{
				flag = true;
			}
		}
		cout << (flag ? "YES\n" : "NO\n");
	}
}