#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

int Sum(int n) {
    int sum = 0;
    while (n > 0) {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}

int MinNum(int n) {
    int mn = INT_MAX;
    while (n > 0) {
        mn = min(mn, n % 10);
        n /= 10;
    }
    return mn;
}

bool cmp(int a, int b) {
    int sumA = Sum(a), sumB = Sum(b);
    if (sumA != sumB)return sumA < sumB;
    int mnA = MinNum(a), mnB = MinNum(b);
    if (mnA != mnB)return mnA < mnB;
    return a < b;
}

int main() {
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a, a + n, cmp);
    for (int i = 0; i < n; i++) {
        cout << a[i] << ' ';
    }
}
