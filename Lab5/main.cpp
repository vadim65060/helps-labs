#include <iostream>
#include <vector>
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

int main() {
    int n;
    cin >> n;
    //freopen("input.txt","r",stdin);
    string s;
    vector<string> res;
    while (cin >> s) {
        if(s=="0")break;
        if (check(s)) {
            res.push_back(s);
        }
    }
    sort(res.begin(), res.end(), cmp);
    //freopen("output.txt","w",stdout);
    int k = 1;
    cout << res[0] << ' ';
    for (int i = 1; i < res.size(); ++i) {
        if (res[i] != res[i - 1]) {
            cout << res[i] << ' ';
            k++;
        }
        if (k == n)return 0;
    }
}
