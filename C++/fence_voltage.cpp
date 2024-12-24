#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int numLines;
    cin >> numLines;
    vector<vector<pair<int, int>>> lineSegments(numLines);
    map<pair<int, int>, vector<int>> coordinateMap;

    for (int i = 0; i < numLines; i++) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        int dx = x2 - x1, dy = y2 - y1;
        int steps = max(abs(dx), abs(dy));
        int stepX = (dx == 0) ? 0 : dx / abs(dx);
        int stepY = (dy == 0) ? 0 : dy / abs(dy);

        for (int j = 0; j <= steps; j++) {
            int currentX = x1 + stepX * j;
            int currentY = y1 + stepY * j;
            lineSegments[i].emplace_back(make_pair(currentX, currentY));
            coordinateMap[{currentX, currentY}].emplace_back(i);
        }
    }

    string inputLine;
    getline(cin, inputLine);
    getline(cin, inputLine);
    unordered_map<string, int> thresholds;

    int pos = 0, lineLength = inputLine.size();
    while (pos < lineLength) {
        size_t delimiterPos = inputLine.find(':', pos);
        if (delimiterPos == string::npos) break;
        string key = inputLine.substr(pos, delimiterPos - pos);
        pos = delimiterPos + 1;
        size_t spacePos = inputLine.find(' ', pos);
        if (spacePos == string::npos) spacePos = lineLength;
        int thresholdValue = stoi(inputLine.substr(pos, spacePos - pos));
        thresholds[key] = thresholdValue;
        pos = spacePos + 1;
    }

    string queryKey;
    cin >> queryKey;

    ll totalCost = 0;

    for (auto &entry : coordinateMap) {
        if (entry.second.size() >= 2) {
            int overlapCount = entry.second.size();
            int minCost = INT_MAX;

            for (auto segmentIndex : entry.second) {
                auto &currentSegment = lineSegments[segmentIndex];
                size_t segmentSize = currentSegment.size();
                size_t positionInSegment = find(currentSegment.begin(), currentSegment.end(), entry.first) - currentSegment.begin();
                int leftDistance = positionInSegment;
                int rightDistance = segmentSize - positionInSegment - 1;
                int costPerStep = (leftDistance > 0 && rightDistance > 0) ? min(leftDistance, rightDistance) : max(leftDistance, rightDistance);
                minCost = min(minCost, costPerStep);
            }
            totalCost += (ll)overlapCount * minCost;
        }
    }

    if (thresholds.find(queryKey) != thresholds.end()) {
        if (totalCost >= thresholds[queryKey]) {
            cout << "Yes\n";
        } else {
            cout << "No\n";
        }
    } else {
        cout << "No\n";
    }

    int validThresholdsCount = 0, totalThresholdsCount = thresholds.size();
    for (auto &thresholdEntry : thresholds) {
        if (totalCost >= thresholdEntry.second) {
            validThresholdsCount++;
        }
    }

    double successRate = (double)validThresholdsCount / totalThresholdsCount;
    cout << fixed << setprecision(2) << successRate;

    return 0;
}