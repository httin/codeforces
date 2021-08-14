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

const int maxN = 100000;
void solve() {
    int n, ans=0;
    ll s=0, llya=0;
    pqg<int> pqa, pqb;
    priority_queue<int, vector<int>> pqbMax;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a, s += a;
        pqa.push(a);
    }
    for (int i = 0; i < n; i++) {
        int b;
        cin >> b, llya += b;
        pqb.push(b);
    }
    for (int i=0; i<n/4; i++) {
        s -= pqa.top();
        pqa.pop();
        llya -= pqb.top();
        pqbMax.push(pqb.top());
        pqb.pop();
    }
    //cout<<"s="<<s<<" llya="<< llya << endl;
    while (s < llya) {
        ++ans;
        pqa.push(100);
        s += 100;
        if (pqbMax.empty()) {
            pqb.push(0);
            llya += 0;
        } else {
            pqb.push(pqbMax.top());
            llya += pqbMax.top();
            pqbMax.pop();
        }
        if ((n+ans)%4==0) {
            s -= pqa.top();
            pqa.pop();
            llya -= pqb.top();
            pqbMax.push(pqb.top());
            pqb.pop();
            //cout<<"s="<<s<<" llya="<< llya << endl;
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
