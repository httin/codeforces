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

const int maxN = 200000;
int h,w;
bool isEdge(int r, int c) {
    return r==1 || r==h || c==1 || c==w;
}
bool isValid(const vector<string>& s, int r, int c) {
    return  s[r-1][c]=='0' && 
            s[r][c-1]=='0' &&
            s[r+1][c]=='0' &&
            s[r][c+1]=='0' &&
            s[r-1][c-1]=='0' &&
            s[r-1][c+1]=='0' &&
            s[r+1][c-1]=='0' &&
            s[r+1][c+1]=='0';
}
void solve() {
    cin >> h >> w;
    vector<string> ans(h+2, string(w+2,'0'));

    for (int i=1; i<=h; i++) {
        for (int j=1; j<=w; j++) {
            if (isEdge(i,j) && isValid(ans,i,j)) {
                ans[i][j]='1';
            }
        }
    }
    
    for (int i=1; i<=h; i++) {
        for (int j=1; j<=w; j++) {
            cout << ans[i][j];
        }
        cout <<'\n';
    }
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
