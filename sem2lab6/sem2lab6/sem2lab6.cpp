#include <iostream>
#include <string>
#include <algorithm>

using namespace std;
int main() {
    int n;
    cin >> n;
    bool f = true;

    for (int i = 0; i <= n; ++i) {
        string s;
        cin >> s;
        int k0 = 0, k1 = 0, k2 = 0;
        for (int j = 0; j < s.size(); ++j) {
            if (s[j] > s[j + 1] and i != s.size() - 1) {
                f = false;
            }
            else if (s[i] == '0') {
                k0++;
            }
            else if (s[i] == '1') {
                k1++;
            }
            else if (s[i] == '2') {
                k2++;
            }
        }
        if (k1 == k0 and k0 == k2 and f) cout << "YES";
        else cout << "NO";
    }
}