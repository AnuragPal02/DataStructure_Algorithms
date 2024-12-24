#include <bits/stdc++.h>
using namespace std;

vector<string> executeLoop(const vector<string>& instructions, int iterations) {
    vector<string> outputLines;

    for (int currentIteration = 1; currentIteration <= iterations; ++currentIteration) {
        for (const string& instruction : instructions) {
            if (instruction.find("continue") == 0) {
                int continueNum = stoi(instruction.substr(9));
                if (continueNum == currentIteration) {
                    break;
                }
            } else if (instruction.find("break") == 0) {
                int breakNum = stoi(instruction.substr(6));
                if (breakNum == currentIteration) {
                    return outputLines;
                }
            } else {
                outputLines.push_back(instruction);
            }
        }
    }
    return outputLines;
}

vector<string> processInstructions(const vector<string>& commands) {
    stack<pair<vector<string>, int>> loopStack;
    vector<string> finalOutput;
    size_t index = 0;

    while (index < commands.size()) {
        const string& command = commands[index];

        if (command.find("for") == 0) {
            int times = stoi(command.substr(4));
            loopStack.push({{}, times});
        } else if (command == "do") {
            // Do nothing, just a placeholder
        } else if (command == "done") {
            auto loopPair = loopStack.top();
            auto& loopBody = loopPair.first;
            auto iterations = loopPair.second;
            loopStack.pop();
            vector<string> result = executeLoop(loopBody, iterations);

            if (!loopStack.empty()) {
                loopStack.top().first.insert(
                    loopStack.top().first.end(), result.begin(), result.end());
            } else {
                finalOutput.insert(finalOutput.end(), result.begin(), result.end());
            }
        } else if (command.find("print") == 0) {
            size_t startQuote = command.find('"') + 1;
            size_t endQuote = command.rfind('"');
            string message = command.substr(startQuote, endQuote - startQuote);

            if (!loopStack.empty()) {
                loopStack.top().first.push_back(message);
            } else {
                finalOutput.push_back(message);
            }
        } else if (command.find("break") == 0) {
            int n = stoi(command.substr(6));
            if (!loopStack.empty()) {
                loopStack.top().first.push_back("break " + to_string(n));
            }
        } else if (command.find("continue") == 0) {
            int n = stoi(command.substr(9));
            if (!loopStack.empty()) {
                loopStack.top().first.push_back("continue " + to_string(n));
            }
        }

        ++index;
    }

    return finalOutput;
}

int main() {
    int numCommands;
    cin >> numCommands;
    cin.ignore();

    vector<string> commands(numCommands);
    for (int i = 0; i < numCommands; ++i) {
        getline(cin, commands[i]);
    }

    vector<string> result = processInstructions(commands);
    for (const string& line : result) {
        cout << line << endl;
    }

    return 0;
}