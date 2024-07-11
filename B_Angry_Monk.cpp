#include <bits/stdc++.h>
#define ll long long
#define int ll
#define pb push_back
 
const int INF=(int)1e9;
const ll lINF=(int)4e15;
 
using namespace std;
 
void solve(){
  int n,k; cin >> n >> k;
  vector<int> v(k);
  for(int i=0;i<k;i++)cin >> v[i];
  sort(v.rbegin(), v.rend());
  int ans=0;
  for(int i=1;i<k;i++){
    ans+=v[i]+v[i]-1;
  }
  cout << ans << endl;
}
 
int32_t main(){
    int t=1;cin>>t;
    while(t--)solve();
    return 0;
}