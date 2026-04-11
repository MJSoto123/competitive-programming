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

const int N = 100000000;
bitset<N> composite;

void init(){
    // (WARNING) Todos los pares son primos
    for(int i = 3; i * i <= N; i += 2) {
		if(!composite[i]) {
			for(int j = i * i; j <= N; j += i) composite[j] = 1;
		}
	}
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    init();
    int cnt = 1;
    cout << 2 << "\n";
    for(int i = 3; i < N; i += 2){
        if(!composite[i]){
            cnt++;
            if(cnt % 100 == 1) cout << i << "\n";
        }
    }
}