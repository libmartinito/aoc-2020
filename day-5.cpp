#include <bits/stdc++.h>

using namespace std;

int getRow(string row_spec) {
  int lo = 0;
  int hi = 127;

  for (char ch : row_spec) {
    int mid = floor(lo + (hi - lo) / 2);

    if (hi - lo == 1) {
      if (ch == 'F') {
        return lo;
      } else {
        return hi;
      }
    } else if (ch == 'F') {
      hi = mid;
    } else {
      lo = mid + 1;
    }
  }

  return -1;
}

int getCol(string col_spec) {
  int lo = 0;
  int hi = 7;

  for (char ch : col_spec) {
    int mid = floor(lo + (hi - lo) / 2);

    if (hi - lo == 1) {
      if (ch == 'L') {
        return lo;
      } else {
        return hi;
      }
    } else if (ch == 'L') {
      hi = mid;
    } else {
      lo = mid + 1;
    }
  }

  return -1;
}

int main() {
  freopen("input/day-5.txt", "r", stdin);

  ios::sync_with_stdio(0);
  cin.tie(0);

  string spec;
  int max_id = 0;
  vector<int> ids;

  while (cin >> spec) {
    string row_spec = spec.substr(0, 7);
    string col_spec = spec.substr(7, 3);
    int row = getRow(row_spec);
    int col = getCol(col_spec);

    int id = row * 8 + col;
    ids.push_back(id);
    max_id = max(max_id, id);
  }

  sort(ids.begin(), ids.end());
  vector<int> vacant_seat_ids;

  for (int i = 1; i < ids.size(); i++) {
    if (ids[i] - ids[i - 1] == 2) {
      vacant_seat_ids.push_back(ids[i] - 1);
    }
  }

  cout << max_id << "\n";

  for (int vacant_seat_id : vacant_seat_ids) {
    cout << "vacant_seat_id: " << vacant_seat_id << "\n";
  }

  return 0;
}
