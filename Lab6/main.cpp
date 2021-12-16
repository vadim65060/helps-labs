#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

void ArrRead(vector<vector<int>> &arr, int n, int m) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            int temp;
            cin >> temp;
            arr[i].push_back(temp);
        }
    }
}

void ArrPrint(vector<vector<int>> &arr) {
    for (int i = 0; i < arr.size(); ++i) {
        for (int j = 0; j < arr[i].size(); ++j) {
            cout << arr[i][j] << ' ';
        }
        cout << endl;
    }
}

int GetMin(vector<vector<int>> &arr) {
    int mn = INT_MAX;
    for (int i = 0; i < arr.size(); ++i) {
        for (int j = 0; j < arr[i].size(); ++j) {
            mn = min(arr[i][j], mn);
        }
    }
    return mn;
}

int GetMax(vector<vector<int>> &arr) {
    int mx = INT_MIN;
    for (int i = 0; i < arr.size(); ++i) {
        for (int j = 0; j < arr[i].size(); ++j) {
            mx = max(arr[i][j], mx);
        }
    }
    return mx;
}

int ArrSort(vector<vector<int>> &arr) {
    for (int i = 0; i < arr.size(); ++i) {
        sort(arr[i].begin(), arr[i].end());
    }
}

int SumNum(int n) {
    int sum = 0;
    while (n > 0) {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> arr(n);
    ArrRead(arr, n, m);
    if (SumNum(GetMin(arr)) == SumNum(GetMax(arr)))ArrSort(arr);
    ArrPrint(arr);
    return 0;
}
