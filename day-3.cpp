#include <bits/stdc++.h>

using namespace std;

int getTreeCount(vector<vector<char>> map, int col_increment,
                 int row_increment) {
  int bottom_row = map.size() - 1;
  int curr_row = 0;
  int curr_col = 0;
  int tree_count = 0;

  while (curr_row != bottom_row) {
    curr_col += col_increment;
    curr_row += row_increment;

    if (curr_col >= map[0].size()) {
      curr_col = curr_col - map[0].size();
    }

    if (map[curr_row][curr_col] == '#') {
      tree_count++;
    }
  }

  return tree_count;
}

int main() {
  freopen("input/day-3.txt", "r", stdin);

  ios::sync_with_stdio(0);
  cin.tie(0);

  string line;
  vector<vector<char>> map;

  while (getline(cin, line)) {
    vector<char> row;

    for (auto character : line) {
      row.push_back(character);
    }

    map.push_back(row);
  }

  int initial_tree_count = getTreeCount(map, 3, 1);

  cout << initial_tree_count << "\n";

  vector<int> col_increments = {1, 3, 5, 7, 1};
  vector<int> row_increments = {1, 1, 1, 1, 2};
  vector<int> tree_counts;

  for (int i = 0; i < col_increments.size(); i++) {
    tree_counts.push_back(
        getTreeCount(map, col_increments[i], row_increments[i]));
  }

  long product = 1;

  for (int tree_count : tree_counts) {
    product *= tree_count;
  }

  cout << product << "\n";

  return 0;
}
