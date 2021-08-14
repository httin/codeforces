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

const int maxN = 200001;
string a[2];
void solve() {
    int n;
    cin >> n;
    for (int i=0; i<2; i++)
        cin >> a[i];
    a[0].pb('0');
    a[1].pb('0');
    int ans=0;
    if (a[1][0]=='1') {
        if (a[0][0]=='0') {
            ++ans;
        } else if (a[0][1]=='1') {
            ++ans;
            a[0][1]='0';
        }
    }
    for (int i=1; i<n; i++) {
        if (a[1][i]=='1') {
            if (a[0][i]=='0') {
                ++ans;
            } else {
                if (a[0][i-1]=='1') {
                    ++ans;
                    a[0][i-1]='0';
                } else if (a[0][i+1]=='1') {
                    ++ans;
                    a[0][i+1]='0';
                }
            }
        }
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
