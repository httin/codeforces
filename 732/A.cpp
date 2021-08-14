#include <bits/stdc++.h>
using namespace std;
 
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

const int maxN = 100;
int a[maxN+1];
int b[maxN+1];
array<int,2> ans[maxN+1];
void solve() {
    int n, sa=0, sb=0, m=0;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i], sa+=a[i];
    for (int i = 1; i <= n; i++)
        cin >> b[i], sb+=b[i];
    if (sa!=sb) {
        cout << -1 << '\n';
        return;
    }
    for (int i=1, j=1, k=1; i <= n; i++) {
        int c = b[i] - a[i];
        if (c > 0) {
            m += c;
            while (c) {
                ans[j][1] = i;
                c--;
                j++;
            }
        } else if (c < 0) {
            while (c < 0) {
                ans[k][0] = i;
                c++;
                k++;
            }
        }
    }
    
    cout << m << '\n';
    for (int i=1; i <= m; i++) {
        cout << ans[i][0] << ' ' << ans[i][1] << '\n';
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
