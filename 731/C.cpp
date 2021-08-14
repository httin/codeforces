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
int a[maxN];
int b[maxN];
void solve() {
    int k,n,m;
    cin >> k >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < m; i++)
        cin >> b[i];
    
    vector<int> ans(m+n,-1);
    int i=0, j=0;
    while (i<n && j<m) {
        if (a[i]==0) {
            k += 1;
            ans[i+j] = 0;
            ++i;
            continue;
        }
        if (b[j]==0) {
            k += 1;
            ans[i+j] = 0;
            ++j;
            continue;
        }
        if (a[i] < b[j]) {
            if (a[i] <= k) {
                ans[i+j] = a[i];
                ++i;
            } else {
                cout << -1 << '\n';
                return;
            }
        } else {
            if (b[j] <= k) {
                ans[i+j] = b[j];
                ++j;
            } else {
                cout << -1 << '\n';
                return;
            }
        }
    }
    while (i<n) {
        if (a[i] <= k) {
            k += (a[i]==0)?1:0;
            ans[i+j] = a[i];
            ++i;
        } else {
            cout << -1 << '\n';
            return;
        }
    }
    while (j<m) {
        if (b[j] <= k) {
            k += (b[j]==0)?1:0;
            ans[i+j] = b[j];
            ++j;
        } else {
            cout << -1 << '\n';
            return;
        }
    }
    for (int l=0; l<m+n; l++) {
        cout << ans[l] << ' ';
    }
    cout << '\n';
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        cin.get();
        solve();
    }
    return 0;
}
