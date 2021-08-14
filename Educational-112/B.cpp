#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
 
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
using vi = vector<int>;
using vpii = vector<pii>;
 
#define sz(x) int((x).size())
#define bg(x) begin(x)
#define all(x) bg(x), end(x)
#define rall(x) x.rbegin(), x.rend() 
#define sor(x) sort(all(x)) 
#define pb push_back
#define eb emplace_back 
#define pf push_front
#define lb lower_bound
#define ub upper_bound
  
#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define F0R(i,a) FOR(i,0,a)
#define ROF(i,a,b) for (int i = (b)-1; i >= (a); --i)
#define R0F(i,a) ROF(i,0,a)
#define each(a,x) for (auto& a: x)
 
const int dr[4] = {1,0,-1,0};
const int dc[4] = {0,1,0,-1};
const int MOD = 1e9+7;
const ll INF = 1e18; // not too close to LLONG_MAX
mt19937 rng((uint32_t)chrono::steady_clock::now().time_since_epoch().count()); 
template<class T> using pqg = priority_queue<T,vector<T>,greater<T>>;
template<typename T> using ordered_set = 
tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

void solve() {
    // 0 <= x1 < x2 <= W, 0 <= y1 < y2 <= H
    int W,H,x1,y1,x2,y2,w,h;
    cin >> W >> H >> x1 >> y1 >> x2 >> y2 >> w >> h;
    int diffx = W - x2, diffy = H - y2;
    
    if (x1 + diffx < w && y1 + diffy < h) {
        cout << -1 << '\n';
        return;
    } else {
        int maxw = max(W-x2, x1);
        int minw = min(W-x2, x1);
        int maxh = max(H-y2, y1);
        int minh = min(H-y2, y1);
        //cout<<maxw<<' '<<minw<<' '<<maxh<<' '<<minh<<endl;
        double ans=1e9;
        if (w <= maxw || h <= maxh) {
            ans = 0;
        } else if (maxw == 0) { // x1=0, x2=W
            ans = (double)abs(h - maxh);
        } else if (maxh == 0) { // y1=0, y2=H
            ans = (double)abs(w - maxw);
        } else {
            if (w - maxw <= minw && h - maxh <= minh)
                ans = (double)min(w - maxw, h - maxh);
            else if (w - maxw > minw)
                ans = (double)(h - maxh);
            else
                ans = (double)(w - maxw);
        }
        cout << fixed << setprecision(12) << ans << '\n';
    }
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        solve();
    }
    return 0;
}
