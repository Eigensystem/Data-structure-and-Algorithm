#include <string>
#include <vector>
#include <utility>
#include <unordered_map>
#include <iostream>

using namespace std;

class Solution {
  void combine(vector<pair<char, bool>>& a, 
              unordered_map<string, bool>& dedup,
              string str,
              int cnt)
  {
    string raw_str = str;
    for (int i = 0; i < a.size(); ++i) {
      if (!a[i].second) {
        str = raw_str;
        a[i].second = 1;
        str += a[i].first;
        if (cnt == 1) {
          dedup[str] = 0;
          a[i].second = 0;
          return;
        }
        else combine(a, dedup, str, cnt-1);
        a[i].second = 0;
      }
    }
  }

  public:
    vector<string> permutation(string s) {
      unordered_map<string, bool> dedup;
      vector<pair<char, bool>> alpha_pair;
      vector<string> res;
      if (s.size() == 0) return res;
      for (auto i: s)
        alpha_pair.push_back(pair<char, bool>(i, 0));
      string tmp;
      combine(alpha_pair, dedup, tmp, s.size());
      for (auto i: dedup)
        res.push_back(i.first);
      return res;
    }
};

int main() {
  Solution a;
  vector<string>b = a.permutation("abcd");
  for (auto i: b)
    cout << i << " ";
}