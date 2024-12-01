#include <bits/stdc++.h>

using namespace std;

long getArrangementCount(vector<int> sorted_ratings, int curr_rating,
                         map<int, long> &memo) {
  if (memo.count(curr_rating) != 0) {
    return memo[curr_rating];
  }

  if (curr_rating == 0) {
    return 1;
  }

  long count_from_node = 0;

  for (int i = 1; i <= 3; i++) {
    auto it =
        find(sorted_ratings.begin(), sorted_ratings.end(), curr_rating - i);

    if (it != sorted_ratings.end()) {
      int next_index = distance(sorted_ratings.begin(), it);
      count_from_node +=
          getArrangementCount(sorted_ratings, sorted_ratings[next_index], memo);
    }
  }

  memo[curr_rating] = count_from_node;
  return memo[curr_rating];
}

int main() {
  freopen("input/day-10.txt", "r", stdin);

  ios::sync_with_stdio(0);
  cin.tie(0);

  vector<int> ratings;
  string rating;

  while (cin >> rating) {
    ratings.push_back(stoi(rating));
  }

  int one_diff_count = 0;
  int three_diff_count = 1;

  sort(ratings.begin(), ratings.end());

  int curr_rating = 0;

  for (int rating : ratings) {
    int diff = rating - curr_rating;
    if (diff > 3) {
      continue;
    }

    if (diff == 1) {
      one_diff_count++;
    }

    if (diff == 3) {
      three_diff_count++;
    }

    curr_rating = rating;
  }

  cout << one_diff_count * three_diff_count << "\n";

  ratings.insert(ratings.begin(), 0);
  ratings.push_back(ratings[ratings.size() - 1] + 3);

  map<int, long> memo = {};

  cout << getArrangementCount(ratings, ratings[ratings.size() - 1], memo)
       << endl;

  return 0;
}
