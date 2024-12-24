#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iomanip>
using namespace std;

vector<vector<double>> rotatePolygon(const vector<vector<double>>& points, double angle) {
    vector<vector<double>> rotated(points.size(), vector<double>(2));
    double cosTheta = cos(angle);
    double sinTheta = sin(angle);

    for (size_t i = 0; i < points.size(); i++) {
        double x = points[i][0];
        double y = points[i][1];
        rotated[i][0] = x * cosTheta - y * sinTheta;
        rotated[i][1] = x * sinTheta + y * cosTheta;
    }

    return rotated;
}

double cross(const vector<double>& o, const vector<double>& a, const vector<double>& b) {
    return (a[0] - o[0]) * (b[1] - o[1]) - (a[1] - o[1]) * (b[0] - o[0]);
}

vector<vector<double>> computeConvexHull(vector<vector<double>>& points) {
    sort(points.begin(), points.end(), [](const vector<double>& a, const vector<double>& b) {
        return a[0] < b[0] || (a[0] == b[0] && a[1] < b[1]);
    });

    vector<vector<double>> lower;
    for (const auto& p : points) {
        while (lower.size() >= 2 && cross(lower[lower.size() - 2], lower.back(), p) <= 0) {
            lower.pop_back();
        }
        lower.push_back(p);
    }

    vector<vector<double>> upper;
    for (int i = points.size() - 1; i >= 0; i--) {
        const auto& p = points[i];
        while (upper.size() >= 2 && cross(upper[upper.size() - 2], upper.back(), p) <= 0) {
            upper.pop_back();
        }
        upper.push_back(p);
    }

    lower.pop_back();
    upper.pop_back();
    
    lower.insert(lower.end(), upper.begin(), upper.end());
    return lower;
}

int main() {
    int n;
    cin >> n;

    vector<vector<double>> points(n, vector<double>(2));
    
    for (int i = 0; i < n; i++) {
        cin >> points[i][0] >> points[i][1];
    }

    vector<vector<double>> hull = computeConvexHull(points);

    double minArea = numeric_limits<double>::max();
    double optimalLength = 0;
    double optimalBreadth = 0;

    for (size_t i = 0; i < hull.size(); i++) {
        size_t nextIndex = (i + 1) % hull.size();
        double deltaX = hull[nextIndex][0] - hull[i][0];
        double deltaY = hull[nextIndex][1] - hull[i][1];
        double rotationAngle = atan2(deltaY, deltaX);

        auto rotatedPoints = rotatePolygon(hull, -rotationAngle);

        double minX = numeric_limits<double>::max(), maxX = numeric_limits<double>::lowest();
        double minY = numeric_limits<double>::max(), maxY = numeric_limits<double>::lowest();

        for (const auto& point : rotatedPoints) {
            minX = min(minX, point[0]);
            maxX = max(maxX, point[0]);
            minY = min(minY, point[1]);
            maxY = max(maxY, point[1]);
        }

        double length = maxX - minX;
        double breadth = maxY - minY;
        double area = length * breadth;

        if (area < minArea) {
            minArea = area;
            optimalLength = length;
            optimalBreadth = breadth;
        }
    }

    int finalLength = static_cast<int>(ceil(min(optimalLength, optimalBreadth)));
    int finalBreadth = static_cast<int>(ceil(max(optimalLength, optimalBreadth)));

    cout << finalLength << " " << finalBreadth << endl;

    return 0;
}