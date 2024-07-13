#include <bits/stdc++.h>
#define ll long long
#define int ll
#define pb push_back
 
const int INF=(int)1e9;
const ll lINF=(int)4e15;
 
using namespace std;
 
void solve(){
  int n,x; cin >> n >> x;
  vector<int> a(n);
  for(int i=0;i<n;i++)cin >> a[i];

  int ans=1;
  unordered_set<int> cur = {1};
  for(auto u: a){
    unordered_set<int> tcur = cur;
    for(auto num: cur){
      if(u*num<=x && x%(u*num)==0){
        tcur.insert(u*num);
      }
    }
    cur = tcur;

    if(tcur.find(x)!=tcur.end()){
      ans+=1;
      cur = {1,u};
    }
  }

  cout << ans << "\n";
}
 
int32_t main(){
  int t=1;cin>>t;
  while(t--)solve();
  return 0;
}