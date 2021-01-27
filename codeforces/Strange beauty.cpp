#include <bits/stdc++.h>
using namespace std;

const int N = (int) 2e5 + 100;

int length[N];
int freq[N];

void solve() {
  int n;
  cin >> n;
  fill(length, length + N, 0);
  fill(freq, freq + N, 0);
  for (int i = 0; i < n; i++)
  {
    int x;
    cin >> x;
    freq[x]++;
  }
  
  for (int i = 1; i < N; i++)
  {
    length[i] += freq[i];
    for (int j = 2 * i; j < N; j += i)
        length[j] = max(length[j], length[i]);
  }
  cout << (n - *max_element(length, length + N)) << endl;
}

int main() {
  int T;
  cin >>T;
  while (T--) {
    solve();
  }
  return 0;
}