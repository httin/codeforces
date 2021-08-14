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
const int MOD = 998244353;
const ll INF = 1e18; // not too close to LLONG_MAX
mt19937 rng((uint32_t)chrono::steady_clock::now().time_since_epoch().count()); 
template<class T> using pqg = priority_queue<T,vector<T>,greater<T>>;

const int maxN = 1e5+5;
int dp[maxN];
void solve() {
    int n;
    string s;
    cin >> n;
    cin >> s;
    if (n <= 2) {
        cout << 1 << '\n';
        return;
    }
    dp[1] = 1;
    dp[2] = 1;
    for (int i=3; i<=n; i++) {
        int j=i-1;
        if (s[j]=='1') {
            if (s[j-1]=='1')
                dp[i] = dp[i-1] + dp[i-2];
            else
                dp[i] = dp[i-1];
        } else {
            if (s[j-1]=='1')
                dp[i] = dp[i-1] + (s[j-2]-'0')*dp[i-2];            
            else
                dp[i] = dp[i-1];
        }
    }
    for (int i=1; i<=n; i++) cout << dp[i] << ' '; 
    cout << endl;
    cout << dp[n] << '\n';
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
