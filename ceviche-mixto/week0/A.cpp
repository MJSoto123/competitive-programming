#include<bits/stdc++.h>
#define all(x) begin(x),end(x)
#define sz(x) (int)(x).size()
#define rep(i,a,b) for(int i = (a) ; i < (b) ; i++)

using namespace ::std;
using ll = long long;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int , int> pii;
typedef vector<pii> vii;

const ll fix = 1e7;

double rad(double angle){
    return angle / 180.0 * acos(-1);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cout << fixed << setprecision(3);
    double len, n, c;
    while(true){
        cin >> len >> n >> c;
        if(len == -1) break;

        double len2 = (1.0 + n * c);
        ll l = 0 * fix, r = 90 * fix;
        while(r - l > 1){
            ll mid = l + r >> 1;
            double angle = rad((1.0 * mid) / (1.0 * fix));

            double cur = angle * (1 / sin(angle));
            if(cur > len2) r = mid;
            else l = mid;
        }

        double angle = rad((1.0 * l) / (1.0 * fix)) / 2.0;
        double ans = (len / 2.0) * (sin(angle) / cos(angle));
        cout << ans << "\n";
    }   
}