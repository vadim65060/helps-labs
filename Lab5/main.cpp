#include <iostream>
#include <algorithm>

using namespace std;

bool check(const string &s) {
    int count[256] = {0};
    for (int i = 0; i < s.size(); ++i) {
        count[s[i]]++;
    }
    for (int i = 0; i < 256; ++i) {
        if (count[i] == 3)return true;
    }
    return false;
}

bool cmp(const string &a, const string &b) {
    if (a.size() != b.size())return a.size() < b.size();
    return a < b;
}

void AddStr(string arr[], int &k, string &s, int n) {
    int mxLen = 0, mxLenId = -1;
    for (int i = 0; i < k; ++i) {
        if (arr[i] == s)return;
        if (arr[i].size() > mxLen) {
            mxLen = arr[i].size();
            mxLenId = i;
        }
    }
    if (k < n) {
        arr[k] = s;
        ++k;
        return;
    }
    if (mxLen > s.size())arr[mxLenId] = s;
}

int main() {
    int n;
    cin >> n;
    //freopen("input.txt","r",stdin);
    string s;
    string res[n];
    int k = 0;
    while (cin >> s) {
        //if (s == "0")break;
        if (check(s)) {
            AddStr(res, k, s, n);
        }
    }
    sort(res, res + k, cmp);
    //freopen("output.txt","w",stdout);
    for (int i = 0; i < k; ++i) {
        cout << res[i] << ' ';
    }
}
