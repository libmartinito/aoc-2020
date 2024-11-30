#include <bits/stdc++.h>

using namespace std;

int getBagCountWithShinyGoldBag(map<string, map<string, int>> &bag_contents,
                                string &initial_type, string curr_type,
                                set<string> &types) {
  if (initial_type == "shiny gold") {
    return 0;
  }

  if (curr_type == "none") {
    return 0;
  }

  if (curr_type == "shiny gold") {
    types.insert(initial_type);
    return 0;
  }

  for (auto x : bag_contents[curr_type]) {
    getBagCountWithShinyGoldBag(bag_contents, initial_type, x.first, types);
  }

  return 0;
}

int getTotalBagsInGoldBag(map<string, map<string, int>> &bag_contents,
                          string curr_type, int prev_count) {
  if (curr_type == "none") {
    return 0;
  }

  int count = prev_count;

  for (auto x : bag_contents[curr_type]) {
    count +=
        getTotalBagsInGoldBag(bag_contents, x.first, x.second * prev_count);
  }

  return count;
}

int main() {
  freopen("input/day-7.txt", "r", stdin);

  ios::sync_with_stdio(0);
  cin.tie(0);

  string line;
  map<string, map<string, int>> bag_contents;

  while (getline(cin, line)) {
    string type = line.substr(0, line.find("bags") - 1);
    string contents_str = line.substr(line.find("contain") + 7 + 1);

    if (contents_str == "no other bags.") {
      bag_contents[type]["none"] = -1;
      continue;
    }

    size_t comma_pos = contents_str.find(",");

    if (comma_pos == string::npos) {
      int content_count = stoi(contents_str.substr(0, 1));
      string content_type =
          contents_str.substr(2, contents_str.find("bag") - 1 - 2);
      bag_contents[type][content_type] = content_count;
    }

    while (contents_str != "") {
      int content_count = stoi(contents_str.substr(0, 1));
      string content_type =
          contents_str.substr(2, contents_str.find("bag") - 1 - 2);
      bag_contents[type][content_type] = content_count;

      if (comma_pos != string::npos) {
        contents_str = contents_str.substr(comma_pos + 2);
      } else {
        contents_str = "";
      }

      comma_pos = contents_str.find(",");
    }
  }

  set<string> types;

  for (auto x : bag_contents) {
    string initial_type = x.first;
    getBagCountWithShinyGoldBag(bag_contents, initial_type, initial_type,
                                types);
  }

  cout << types.size() << "\n";

  int count = 0;

  for (auto x : bag_contents["shiny gold"]) {
    count += getTotalBagsInGoldBag(bag_contents, x.first, x.second);
  }

  cout << count << "\n";

  return 0;
}
