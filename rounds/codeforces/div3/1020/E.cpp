#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n, q; cin >> n >> q;
    vector<int> a(n + 1), pos(n + 1);
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 1; i <= n; i++) pos[a[i]] = i;

    for(int qq = 0; qq < q; qq++){
        int l, r, k; cin >> l >> r >> k;
        if(pos[k] < l || pos[k] > r) {cout << "-1 "; continue;}

        vector<int> b;
        int small = 0, big = 0;
        int allbig = n - k, allsmall = k - 1;
        while(true){
            int mid = (l + r) / 2;
            if(pos[k] == mid) break;
            else if(pos[k] < mid) {
                r = mid - 1;
                if(a[mid] < k){
                    big++;
                    b.emplace_back(a[mid]);
                }else allbig--;
            }
            else {
                l = mid + 1;
                if(a[mid] > k){
                    small++;
                    b.emplace_back(a[mid]);
                } else allsmall--;
            }
        }

        int ans = b.size();

        for(auto x : b){
            if(x > k) {
                big--;
                allbig--;
            }
            else {
                small--;
                allsmall--;
            }
        }

        if(big > 0){
            if(big > (allbig)) {cout << "-1 "; continue;}
            else ans+= big;
        } 

        if(small > 0) {
            if(small > allsmall) {cout << "-1 "; continue;}
            else ans+= small;
        }
        cout << ans << " ";
    }
    cout << "\n";
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int tt; cin >> tt;
    while(tt--) solve();
}