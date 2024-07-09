#include <bits/stdc++.h>
#define ll long long
#define int ll
#define pb push_back
 
const int INF=(int)1e9;
const ll lINF=(int)4e15;
 
using namespace std;

int score(int n, int k, vector<int> p, vector<int> a, int pos){
  vector<int> cyc(n+1,0);
  int curr = pos;
  for(int i=1;i<=n;i++){
    cyc[i]=cyc[i-1] + a[curr];
    curr = p[curr]-1;
  }
  
  int ans = (k/n)*cyc[n] + cyc[k%n];
  for(int i=1;i<=n&&i<=k;i++){
    ans = max(ans, cyc[i-1]+(k-i+1)*a[pos]);
    pos = p[pos]-1;
  }
  return ans;

}
 
void solve(){
	int n,k,b,s; cin >> n >> k >> b >> s;
  vector<int> p(n,0), a(n,0);
  for(int i=0;i<n;i++)cin >> p[i];
  for(int i=0;i<n;i++)cin >> a[i];
	
  int bscore = score(n, k, p, a, b-1), sscore = score(n, k, p, a, s-1);
  string ans="Draw";
  if(bscore>sscore)ans = "Bodya";
  else if(bscore<sscore)ans="Sasha";

  cout << ans << endl;
}
 
int32_t main(){
    int t=1;cin>>t;
    while(t--)solve();
    return 0;
}