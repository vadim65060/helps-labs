#include <iostream>
#include <algorithm>

using namespace std;

bool check(int n) {
    int a = n % 10;
    n /= 10;
    while (n > 0) {
        if (a != n % 10)return false;
        n /= 10;
    }
    return true;
}

bool cmp(int a, int b) {
    return a > b;
}

int main() {
    int n;
    cin >> n;
    int a[n];

    int k = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        k += check(a[i]);
    }
    if (k >= 3) {
        sort(a, a + n, cmp);
    }
    for (int i = 0; i < n; i++) {
        cout << a[i] << ' ';
    }
    return 0;
}
