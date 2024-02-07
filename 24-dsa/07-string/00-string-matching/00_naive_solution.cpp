#include<bits/stdc++.h>
using namespace std;

int naive_pattern_matching(string text, string pattern) {
  int n = text.length();
  int m = pattern.length();

  for (int i=0; i<n-m+1; i++) {
    int k=i;
    for (int j=0; j<m; j++) {
      if (text[k] != pattern[j]) 
        break;
      k++;
    }
    if (i+m == k)
      return i;
  }
  return -1;
}

int main(int argc, char const *argv[]) {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  freopen("input.txt", "r", stdin);

  int t;
  cin >> t;
  cin.ignore();

  while(t--) {
    string pattern, text;
    
    getline(cin, text);
    getline(cin, pattern);

    cout << naive_pattern_matching(text, pattern) << endl;
  }

  return 0;
}