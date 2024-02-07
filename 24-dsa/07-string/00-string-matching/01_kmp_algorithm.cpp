#include<bits/stdc++.h>
using namespace std;

vector<int> suff_pref_array(string pattern);

int kmp_algo(string text, string pattern) {
  int n = text.length();
  int m = pattern.length();

  vector<int> lpsArr = suff_pref_array(pattern);

  int i = 0, j = 0;
  while (i < n) {
    if (text[i] == pattern[j]) {
      i++; j++;
    } else {
      if (j != 0)
        j = lpsArr[j-1];
      else
        i ++;
    }

    // found match
    if (j == m) {
      return i-j;
    }
  }
  return -1;
}

vector<int> suff_pref_array(string pattern) {
  int m = pattern.length();
  vector<int> arr(m, 0);
  int lps = 0;  // longest prefix which also suffix for current block defined by i
  int i=1;
  while (i<m) {
    if (pattern[i] == pattern[lps]) {
      arr[i] = lps + 1;   // go to +1 location
      lps += 1;           // for next block start +1
      i++;                // we can go to next block as we found it.
    } else {
      if (lps != 0) {
        lps = arr[lps-1];   // try reducing lps
      } else {
        arr[i] = 0;         // there is not prefix & suffix matching
        i++;
      }
    }
  }
  return arr;
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

    cout << kmp_algo(text, pattern) << endl;
  }

  return 0;
}