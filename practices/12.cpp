#include <bitset>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {

  bool match(vector<vector<char>>& board, string& word,
              vector<vector<bool>>& flags, int i, int j, int rows, int cols,
              int n) {
    flags[i][j] = 1;
    if (i != 0 && flags[i - 1][j] != 1 && board[i - 1][j] == word[n]) {
      if (n == word.size() - 1) return true;
      if (match(board, word, flags, i - 1, j, rows, cols, n + 1)) return true;
    }
    if (i != rows - 1 && flags[i + 1][j] != 1 && board[i + 1][j] == word[n]) {
      if (n == word.size() - 1) return true;
      if (match(board, word, flags, i + 1, j, rows, cols, n + 1)) return true;
    }
    if (j != 0 && flags[i][j - 1] != 1 && board[i][j - 1] == word[n]) {
      if (n == word.size() - 1) return true;
      if (match(board, word, flags, i, j - 1, rows, cols, n + 1)) return true;
    }
    if (j != cols - 1 && flags[i][j + 1] != 1 && board[i][j + 1] == word[n]) {
      if (n == word.size() - 1) return true;
      if (match(board, word, flags, i, j + 1, rows, cols, n + 1)) return true;
    }
    flags[i][j] = 0;
    return false;
  }

public:
  bool exist(vector<vector<char>>& board, string word) {
    int cols = board[0].size();
    int rows = board.size();
    vector<bool> row_flags(cols, 0);
    vector<vector<bool>> flags(rows, row_flags);
    for (int i = 0; i < rows; ++i) {
      for (int j = 0; j < cols; ++j) {
        if (board[i][j] == word[0] &&
            (word.size() == 1 ||
              match(board, word, flags, i, j, rows, cols, 1))) {
          return true;
        }
      }
    }
    return false;
  }
};
