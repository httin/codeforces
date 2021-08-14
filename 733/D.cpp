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

const int maxN = 2e5+5;
int a[maxN];
void solve() {
    int n, cnt=0;
    cin >> n;
    vector<bool> vis(n+1, 0);
    vector<int> b(n+1, 0);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        if (!vis[a[i]]) {
            b[i] = a[i]; // b: i love a[i]
            vis[a[i]] = 1; // a[i] has been gifted
            ++cnt;
        }
    }
    
    // there is at most one i that b[i]=i
    for (int i=1, j=n; i<=n; i++) {
        if (b[i]==0) {
            while (vis[j]) j--;
            b[i] = j;
            j--;
        }
    }
    
    //for (int i=1; i<=n; i++) cout << b[i] << ' ';
    //cout << endl;
    //for (int i=1; i<=n; i++) cout << i << ' ';
    //cout << endl;
    
    for (int i=1; i<=n; i++) {
        if (b[i] == i) {
            b[i] = a[i];
            for (int j=1; j<=n; j++) {
                if (i!=j && b[j]==a[i]) {
                    b[j] = i;
                }
            }
            break;
        }
    }
    cout << cnt << '\n';
    for (int i=1; i<=n; i++)
        cout << b[i] << ' ';
    cout << '\n';
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
