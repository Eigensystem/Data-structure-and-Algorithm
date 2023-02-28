#include <map>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<vector<int>> mergeSimilarItems 
  (vector<vector<int>>& items1, vector<vector<int>>& items2) {
    map<int, int> a;
    for (auto &i: items1) {
      if (a.find(i[0]) == a.end()) a[i[0]] = i[1];
      else a[i[0]] += i[1];
    }
    for (auto &i: items2) {
      if (a.find(i[0]) == a.end()) a[i[0]] = i[1];
      else a[i[0]] += i[1];
    }
    vector<vector<int>> res;
    for (auto &i: a) {
      res.push_back(vector<int>{i.first, i.second});
    }
    return res;
  }
};