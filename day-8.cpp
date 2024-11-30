#include <bits/stdc++.h>

using namespace std;

map<string, int> getRunResult(vector<string> commands) {
  set<int> seen_commands;
  int acc = 0;
  int curr_command_index = 0;
  bool did_program_loop = 0;

  while (seen_commands.count(curr_command_index) == 0) {
    seen_commands.insert(curr_command_index);

    string line = commands[curr_command_index];

    string command = line.substr(0, 3);
    string type = line.substr(4, 1);
    int value = stoi(line.substr(5));

    if (command == "nop") {
      curr_command_index++;
    } else if (command == "jmp") {
      if (type == "+") {
        curr_command_index += value;
      } else {
        curr_command_index -= value;
      }
    } else if (command == "acc") {
      if (type == "+") {
        acc += value;
      } else {
        acc -= value;
      }

      curr_command_index++;
    }

    if (curr_command_index == commands.size()) {
      did_program_loop = 0;
      break;
    }

    if (seen_commands.count(curr_command_index)) {
      did_program_loop = 1;
    }
  };

  map<string, int> result;
  result["acc"] = acc;
  result["did_program_loop"] = did_program_loop;

  return result;
}

int getNextNopOrJmp(int curr_index, vector<string> commands) {
  for (int i = curr_index + 1; i < commands.size(); i++) {
    string command_type = commands[i].substr(0, 3);
    if (command_type == "nop" || command_type == "jmp") {
      return i;
    }
  }

  return -1;
}

vector<string> updateCommands(int nop_or_jmp_index, vector<string> commands) {
  string command = commands[nop_or_jmp_index];

  if (command.substr(0, 3) == "nop") {
    commands[nop_or_jmp_index] = "jmp" + command.substr(3);
  } else {
    commands[nop_or_jmp_index] = "nop" + command.substr(3);
  }

  return commands;
}

int main() {
  freopen("input/day-8.txt", "r", stdin);

  ios::sync_with_stdio(0);
  cin.tie(0);

  vector<string> commands;

  string command;

  while (getline(cin, command)) {
    commands.push_back(command);
  }

  cout << getRunResult(commands)["acc"] << "\n";

  int nop_or_jmp_index = 0;
  vector<string> updated_commands = commands;
  map<string, int> result = getRunResult(commands);

  while (result["did_program_loop"] == 1) {
    nop_or_jmp_index = getNextNopOrJmp(nop_or_jmp_index, commands);
    updated_commands = updateCommands(nop_or_jmp_index, commands);
    result = getRunResult(updated_commands);
  }

  cout << result["acc"] << "\n";

  return 0;
}
