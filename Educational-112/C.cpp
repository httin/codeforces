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

const int maxN = 100005;
array<int,maxN> a[2];
array<ll,maxN> sum[2];
void solve() {
    int n;
    cin >> n;
    memset(&sum[0], 0, maxN*sizeof(ll));
    memset(&sum[1], 0, maxN*sizeof(ll));
    for (int i = 1; i <= n; i++)
        cin >> a[0][i];
    for (int i = 1; i <= n; i++)
        cin >> a[1][i];
    if (n==1) {
        cout << "0\n";
        return;
    }
    if (n==2) {
        cout << min(a[0][2], a[1][1]) << '\n';
        return;
    }
    // a1 a2 |a3| a4 a5 a6
    // b1 b2 |b3| b4 b5 b6
    sum[0][n] = a[0][n];
    for (int i=n-1; i>=1; i--)
        sum[0][i] = sum[0][i+1] + a[0][i];
    sum[1][1] = a[1][1];
    for (int i=2; i<=n; i++)
        sum[1][i] = sum[1][i-1] + a[1][i];
    
    ll ans=INF;
    for (int i=1; i<=n; i++) {
        ans = min(ans, max(sum[0][i+1], sum[1][i-1]));
    }
    cout << ans << '\n';
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
