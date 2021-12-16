#include <iostream>

using namespace std;

int main() {
    string s;
    cin >> s;
    string signs[11] = {"...", "!", ",", "?", ";", ":", ".", "-", "\"", "(", ")"};
    int k = 0;
    for (int i = 0; i < 11; ++i) {
        for (int j = 0; j < s.length(); ++j)
            if (s[j] == signs[i][0])
                if (s.substr(j, signs[i].length()) == signs[i]) {
                    ++k;
                    for (int l = 0; l < signs[i].size(); ++l) {
                        s[j + l] = '#';
                    }
                    j += signs[i].length() - 1;
                }
        //cout<<s<<' '<<k<<endl;
    }
    cout << k;
    return 0;
}