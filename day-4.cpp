#include <bits/stdc++.h>

using namespace std;

vector<string> split(string line, char delimiter) {
  vector<string> words;
  string word = "";

  for (char character : line) {
    if (character == delimiter) {
      words.push_back(word);
      word = "";
    } else {
      word += character;
    }
  }

  if (word.length() > 0) {
    words.push_back(word);
  }

  return words;
}

bool validatePassport(set<string> fields) {
  set<string> all_fields = {"byr", "iyr", "eyr", "hgt", "hcl", "ecl", "pid"};

  for (string field : all_fields) {
    if (fields.count(field) == 0) {
      return false;
    }
  }

  return true;
}

bool validateYear(string type, string year_str) {
  if (year_str.length() != 4) {
    return false;
  }

  int year = stoi(year_str);

  if (type == "byr" && (year < 1920 || year > 2002)) {
    return false;
  }

  if (type == "iyr" && (year < 2010 || year > 2020)) {
    return false;
  }

  if (type == "eyr" && (year < 2020 || year > 2030)) {
    return false;
  }

  return true;
}

bool validateHeight(string height_str) {
  size_t cm_pos = height_str.find("cm");
  size_t in_pos = height_str.find("in");

  if (cm_pos == string::npos && in_pos == string::npos) {
    return false;
  }

  if (cm_pos != string::npos) {
    int height = stoi(height_str.substr(0, cm_pos));

    if (height < 150 || height > 193) {
      return false;
    }
  }

  if (in_pos != string::npos) {
    int height = stoi(height_str.substr(0, in_pos));

    if (height < 59 || height > 76) {
      return false;
    }
  }

  return true;
}

bool validateHairColor(string hair_color) {
  if (hair_color.length() != 7) {
    return false;
  }

  if (hair_color[0] != '#') {
    return false;
  }

  for (char character : hair_color) {
    if (character == '#') {
      continue;
    }

    if (!((character >= 'a' && character <= 'f') ||
          (character >= '0' && character <= '9'))) {
      return false;
    }
  }

  return true;
}

bool validateEyeColor(string eye_color) {
  set<string> colors = {"amb", "blu", "brn", "gry", "grn", "hzl", "oth"};

  if (colors.count(eye_color) == 0) {
    return false;
  }

  return true;
}

bool validatePassportID(string passport_id) {
  if (passport_id.length() != 9) {
    return false;
  }

  for (char character : passport_id) {
    if (!(character >= '0' && character <= '9')) {
      return false;
    }
  }

  return true;
}

bool validatePassportFields(map<string, string> field_values) {
  if (!validateYear("byr", field_values["byr"])) {
    return false;
  }

  if (!validateYear("iyr", field_values["iyr"])) {
    return false;
  }

  if (!validateYear("eyr", field_values["eyr"])) {
    return false;
  }

  if (!validateHeight(field_values["hgt"])) {
    return false;
  }

  if (!validateHairColor(field_values["hcl"])) {
    return false;
  }

  if (!validateEyeColor(field_values["ecl"])) {
    return false;
  }

  if (!validatePassportID(field_values["pid"])) {
    return false;
  }

  return true;
}

int main() {
  freopen("input/day-4.txt", "r", stdin);

  ios::sync_with_stdio(0);
  cin.tie(0);

  string line;
  set<string> fields;
  map<string, string> field_values;
  int valid_passport_count;
  int valid_passport_fields_count;

  while (getline(cin, line)) {
    if (line.length() == 0) {
      if (validatePassport(fields)) {
        valid_passport_count++;
      }

      fields = {};

      if (validatePassportFields(field_values)) {
        valid_passport_fields_count++;
      }

      field_values = {};

      continue;
    }

    vector<string> pairs = split(line, ' ');

    for (string pair : pairs) {
      vector<string> field_value = split(pair, ':');
      fields.insert(field_value[0]);
      field_values[field_value[0]] = field_value[1];
    }
  }

  if (fields.size() >= 0 && validatePassport(fields)) {
    valid_passport_count++;
  }

  if (field_values.size() > 0 && validatePassportFields(field_values)) {
    valid_passport_fields_count++;
  }

  cout << valid_passport_count << "\n";
  cout << valid_passport_fields_count << "\n";

  return 0;
}
