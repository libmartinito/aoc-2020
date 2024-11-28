#include <bits/stdc++.h>
#include <vector>

using namespace std;

int main() {
  freopen("input/day-6.txt", "r", stdin);

  ios::sync_with_stdio(0);
  cin.tie(0);

  string line;
  set<char> characters;
  int sum_of_questions_answered_with_yes;

  vector<set<char>> questions_answered;
  int sum_of_questions_where_everyone_answered_with_yes;

  while (getline(cin, line)) {
    if (line.length() == 0) {
      int questions_answered_count = 0;

      for (char ch : characters) {
        bool did_everyone_answer = true;

        for (set<char> question_answered : questions_answered) {
          if (question_answered.count(ch) == 0) {
            did_everyone_answer = false;
          }
        }

        if (did_everyone_answer) {
          questions_answered_count++;
        }
      }

      sum_of_questions_answered_with_yes += characters.size();
      sum_of_questions_where_everyone_answered_with_yes +=
          questions_answered_count;

      characters = {};
      questions_answered = {};
      continue;
    }

    set<char> question_answered;

    for (char ch : line) {
      if (characters.count(ch) == 0) {
        characters.insert(ch);
      }

      question_answered.insert(ch);
    }

    questions_answered.push_back(question_answered);
  }

  if (characters.size() > 0) {
    sum_of_questions_answered_with_yes += characters.size();
  }

  if (questions_answered.size() > 0) {
    int questions_answered_count = 0;

    for (char ch : characters) {
      bool did_everyone_answer = true;

      for (set<char> question_answered : questions_answered) {
        if (question_answered.count(ch) == 0) {
          did_everyone_answer = false;
        }
      }

      if (did_everyone_answer) {
        questions_answered_count++;
      }
    }

    sum_of_questions_where_everyone_answered_with_yes +=
        questions_answered_count;
  }

  cout << sum_of_questions_answered_with_yes << "\n";
  cout << sum_of_questions_where_everyone_answered_with_yes << "\n";

  return 0;
}
