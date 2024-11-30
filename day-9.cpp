#include <bits/stdc++.h>
#include <limits>

using namespace std;

bool isTargetSumOfTwoNumbers(vector<long> &nums, int lo, int hi, long target) {
  set<long> nums_set;

  for (int i = lo; i < hi; i++) {
    if (nums_set.count(target - nums[i]) != 0) {
      return true;
    } else {
      nums_set.insert(nums[i]);
    }
  }

  return false;
}

long getSum(vector<long> &nums, int lo, int hi) {
  long sum = 0;

  for (int i = lo; i <= hi; i++) {
    sum += nums[i];
  }

  return sum;
}

long getMin(vector<long> &nums, int lo, int hi) {
  long min = numeric_limits<long>::max();

  for (int i = lo; i <= hi; i++) {
    if (nums[i] < min) {
      min = nums[i];
    }
  }

  return min;
}

long getMax(vector<long> &nums, int lo, int hi) {
  long max = numeric_limits<long>::min();

  for (int i = lo; i <= hi; i++) {
    if (nums[i] > max) {
      max = nums[i];
    }
  }

  return max;
}

int main() {
  freopen("input/day-9.txt", "r", stdin);

  ios::sync_with_stdio(0);
  cin.tie(0);

  vector<long> nums;
  string num_str;

  while (cin >> num_str) {
    nums.push_back(stol(num_str));
  }

  long first_invalid_number;
  int lo = 0;
  int hi = lo + 25;

  while (hi != nums.size()) {
    if (!isTargetSumOfTwoNumbers(nums, lo, hi, nums[hi])) {
      first_invalid_number = nums[hi];
      break;
    } else {
      lo++;
      hi++;
    }
  }

  cout << first_invalid_number << "\n";

  int sum_lo = 0;
  int sum_hi = 1;
  long sum = getSum(nums, sum_lo, sum_hi);

  while (sum != first_invalid_number && sum_hi < nums.size() &&
         sum_lo < sum_hi) {
    if (sum < first_invalid_number) {
      sum_hi++;
    } else if (sum > first_invalid_number) {
      sum_lo++;
    }

    sum = getSum(nums, sum_lo, sum_hi);
  }

  long min = getMin(nums, sum_lo, sum_hi);
  long max = getMax(nums, sum_lo, sum_hi);

  cout << min + max << "\n";

  return 0;
}
