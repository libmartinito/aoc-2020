#include <bits/stdc++.h>

using namespace std;

bool oldIsValidPassword(int start, int end, char character, string password) {
  int char_count = 0;

  for (char current_char : password) {
    if (current_char == character) {
      char_count++;
    }
  }

  if (char_count >= start && char_count <= end) {
    return true;
  }

  return false;
}

bool newIsValidPassword(int start, int end, char character, string password) {
  if (password[start - 1] == character && password[end - 1] == character) {
    return false;
  }

  if (password[start - 1] == character || password[end - 1] == character) {
    return true;
  }

  return false;
}

int main() {
  freopen("input/day-2.txt", "r", stdin);

  ios::sync_with_stdio(0);
  cin.tie(0);

  string line;
  int valid_password_count = 0;
  int new_valid_password_count = 0;

  while (getline(cin, line)) {
    size_t space_position = line.find(" ");
    size_t colon_position = line.find(":");

    string range = line.substr(0, space_position);
    char character = line[colon_position - 1];

    size_t dash_position = range.find("-");

    int start = stoi(range.substr(0, dash_position));
    int end = stoi(range.substr(dash_position + 1, space_position));

    string password = line.substr(colon_position + 2);

    if (oldIsValidPassword(start, end, character, password)) {
      valid_password_count++;
    }

    if (newIsValidPassword(start, end, character, password)) {
      new_valid_password_count++;
    }
  }

  cout << valid_password_count << "\n";
  cout << new_valid_password_count << "\n";

  return 0;
}
