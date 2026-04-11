#include<bits/stdc++.h>

using namespace std;

int main(){
    int n; cin >> n;
    vector<long long> a(n);

    for(int i = 0; i < n; i++) cin >> a[i];
    sort(a.begin(), a.end());

    vector<long long> pref = a;
    for(int i = 1; i < n; i++) pref[i] += pref[i - 1];

    long long ans = 0;
    for(int i = 0; i < n; i++){
        int target = 100'000'000 - a[i];

        int l = i, r = n; 
        while(r - l > 1){
            int mid = l + r >> 1;
            if(a[mid] < target) l = mid;
            else r = mid;
        }
        // l ultimo <= que target
        if(l != i) {
            ans += pref[l] - pref[i];
            ans += a[i] * (l - i);
        }
        ans += pref[n - 1] - pref[l];
        ans += a[i] * (n - 1 - l);
        ans -= 1LL * 100'000'000 * (n - 1 - l);
    }
    cout << ans << "\n";
}