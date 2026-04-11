#include<bits/stdc++.h>
using namespace std;

int query(int pos){
    cout << "? " << pos + 1 << endl;
    int val; cin >> val;
    return val;
}

void solve(){
    int n, k; cin >> n >> k;
    vector<int> a(k), b(k);
    if(n == 2 * k) {cout << "! " <<  k << " " << k << endl; return;}

    for(int i = 0; i < k; i++) a[i] = query(i);
    for(int i = 0; i < k; i++) b[i] = query(n - k + i);

    reverse(b.begin(), b.end());
    bool eq = true;
    for(int i = 0; i < k; i++) {
        if(a[(n - k + i) % k] != b[(k - 1 - i)]) eq = false;
    }

    if(eq) {cout << "! -1" << endl; return;}

    int l = -1, r = n;
    while(r - l > 1){
        int mid = l + r >> 1;
        int now = query(mid);

        if(now == a[mid % k] && now == b[(n - mid - 1) % k]) {
            if(mid > 0){
                if(query(mid - 1) == a[(mid - 1) % k]) l = mid;
                else r = mid;
            }else{
                if(query(mid + 1) == a[(mid + 1) % k]) l = mid;
                else r = mid;
            }
        }
        else if(now == a[mid % k]) l = mid;
        else r = mid; 
    }

    bool diff = false;
    for(int i = l; i > (l - k); i--){
        if(query(i) != b[(n - i - 1) % k]) diff = true;
    }
    
    if(diff) cout << "! " << min((l + 1), n - k) << " " << max(n - l - 1, k) << endl;
    else cout << "! -1" << endl;
    cout << endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int tt; cin >> tt;
    while(tt--) solve();
}