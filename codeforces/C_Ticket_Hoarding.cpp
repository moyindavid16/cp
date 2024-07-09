#include <bits/stdc++.h>
#define ll long long
//#define int ll
#define pb push_back
 
const int INF=(int)1e9;
const ll lINF=(int)4e15;
 
using namespace std;
 
void solve(){
  int n, m, k; cin >> n >> m >> k;
  vector<int> v(n);
  for(int i=0;i<n;i++)cin >> v[i];
  int len = ceil((double)k/m);
  int mn = 0;
  for(int i=0;i<len;i++)mn+=v[i];
  int l=0, r=len-1;
  int ml=l, mr=r;
  int curr = mn;
  while(r<n-1){
    curr-=v[l];
    curr+=v[r+1];
    if(curr<mn){
      mn=curr;ml=l+1;mr=r+1;
    }
    l++;r++;
  }

  int res=0, x=0;
  vector<int> a;
  for(int i=ml;i<=mr;i++)a.pb(v[i]);
  sort(a.begin(), a.end());
  for(auto u: a){
    res+=min(m, k-x) * (x+u);
    x+=min(m,k-x);
  }
  cout << res << endl;
}
 
int32_t main(){
    int t=1;cin>>t;
    while(t--)solve();
    return 0;
}