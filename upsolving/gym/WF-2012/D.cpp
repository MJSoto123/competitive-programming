#include <bits/stdc++.h>
using namespace std;
const double PI = acos(-1.0);

void solve(int n) {
    string s; cin >> s;

    long long a = 1, b = 1;
    for(int i = 8; i <= n; i++) {
        long long temp = b;
        b += a;
        a = temp;
        cout << a << " " << b << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(2);
    
    int n, tt = 1;
    while (cin >> n) {
        cout << "Case " << tt << ": "; tt++;
        solve(n + 1);
    }
}
