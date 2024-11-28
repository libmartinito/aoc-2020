#include <bits/stdc++.h>

using namespace std;

int getSumOfTwoNumbers(vector<int> nums) {
  unordered_set<int> seen;

  for (auto num : nums) {
    if (seen.count(2020 - num) == 1) {
      cout << (2020 - num) * num << "\n";
      break;
    } else {
      seen.insert(num);
    }
  }

  return 0;
}

int getSumOfThreeNumbers(vector<int> nums) {
  int a, b, c;
  sort(nums.begin(), nums.end());

  for (int i = 0; i < nums.size(); i++) {
    a = nums[i];

    int lo = i + 1;
    int hi = nums.size() - 1;

    while (lo < hi) {
      b = nums[lo];
      c = nums[hi];

      if (a + b + c > 2020) {
        hi--;
      } else if (a + b + c < 2020) {
        lo++;
      } else {
        cout << a * b * c << "\n";
        break;
      }
    }
  }

  return 0;
}

int main() {
  freopen("input/day-1.txt", "r", stdin);

  ios::sync_with_stdio(0);
  cin.tie(0);

  vector<int> nums;
  int num;

  while (cin >> num) {
    nums.push_back(num);
  }

  getSumOfTwoNumbers(nums);
  getSumOfThreeNumbers(nums);

  return 0;
}
