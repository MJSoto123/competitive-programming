#include <bits/stdc++.h>
using namespace std;
const double PI = acos(-1.0);

void solve(int n) {
    vector<double> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    double mn, mx, add; cin >> mn >> mx >> add;

    auto get = [&](double now) {
        double sm = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                sm += (a[i] * a[j]) / (i + j + 1) * (pow(now, i + j + 1) - pow(mn, i + j + 1));
            }
        }
        return sm * PI;
    };

    cout << get(mx) << "\n";

    vector<double> ans;
    double target = add;
    
    while (ans.size() < 8) {
        double l = mn, r = mx;
        bool found = false;

        while (abs(r - l) > 1e-6) {
            double mid = (l + r) / 2.0;
            if (get(mid) < target) l = mid;
            else {
                r = mid;
                found = true;
            }
        }

        if (!found || r >= mx - 0.01) break;
        ans.push_back(r);
        target += add;
    }

    if (ans.empty()) cout << "insufficient volume\n";
    else {
        for (double x : ans) cout << x - mn << " ";
        cout << "\n";
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
