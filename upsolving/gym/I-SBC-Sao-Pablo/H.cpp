#include<bits/stdc++.h>
using namespace std;

struct SegmentTree{
	vector<int> tree; 
	int n;
	SegmentTree(int n) : n(n) , tree(2 * n + 5, 0) {}
	void upd(int p, int v){
		p += n; 
		for(tree[p] = v; p > 1; p>>=1) tree[p>>1] = max(tree[p],tree[p^1]);
	}
	int query(int l, int r){ // [l, r)
		int res = 0;
		for(l += n, r += n; l < r; l >>= 1, r >>= 1){
			if(l & 1) res = max(res, tree[l++]);
			if(r & 1) res = max(res, tree[--r]);
		}
		return res;
	}
};

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int q, k; cin >> q >> k;
    SegmentTree seg(k);
    for(int i = 0; i < k; i++) seg.upd(i, i);
    int ini = 0;

    for(int qq = 0; qq < q; qq++){
        int op; cin >> op;
        if(op == 1) {
            
        }
    }
}