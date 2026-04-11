#include<bits/stdc++.h>

using namespace std;

int main(){
    int n, k; cin >> n >> k;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    int ans = 0;
    int curr = k;
    for(int i = 0; i < n; i++){
        if(a[i] > curr) {ans++; curr = k;}
        curr -= a[i];
    }
    cout << ans + 1 << "\n";
}