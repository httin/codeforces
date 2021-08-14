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

const int maxN = 200001;
int a[maxN];
void solve() {
    int n,k,remain=0;
    cin >> n >> k;
    unordered_map<int,vector<int>> mp;
    vector<int> ans(n+1,0);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        mp[a[i]].pb(i);
    }
    
    for (auto it = mp.begin(); it != mp.end(); ) 
    {
        //cout << it->first << ": " << it->second.size() << endl;
        vector<int>& v = it->second;
        if (v.size() >= (size_t)k) {
            for (int i=0; i<(int)v.size(); i++) {
                ans[v[i]] = i<k ? i+1 : 0;
            }
            it = mp.erase(it);
        } else {
            ++it;
            remain += v.size();
        }
    }
    
    int color=0, q=remain/k;
    bool end=0;
    if (q>0) {
        for (auto& m:mp) {
            vector<int>& v=m.second;
            for (int i=0; i<(int)v.size(); i++) {
                ans[v[i]] = color%k + 1;
                ++color;
                if (color==k*q) {
                    end=1;
                    break;
                }
            }
            //remain -= (int)v.size();
            //cout << m.first << ": " << m.second.size() << " color=" << color << " rem="<<remain<<endl;
            if (end)
                break;
        }
    }
    
    for (int i=1; i<=n; i++)
        cout << ans[i] << ' ';
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
