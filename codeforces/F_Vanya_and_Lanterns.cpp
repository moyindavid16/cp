#include <bits/stdc++.h>
#define ll long long
// #define int ll
#define pb push_back
 
const int INF=(int)1e9;
const ll lINF=(int)4e15;
 
using namespace std;
 
void solve(){
  int n,l; cin >> n >> l;
  vector<int> v(n);
  for(int i=0;i<n;i++)cin >> v[i];

  sort(v.begin(), v.end());
  int ans=max(v[0], l-v[n-1]);
  int mod = 0;

  for(int i=1;i<n;i++){
    int temp = (v[i]-v[i-1])/2;
    if(temp>=ans){
      if(temp==ans){
        mod = max((v[i]-v[i-1])%2, mod);
      }
      else mod = (v[i]-v[i-1])%2;
      ans = max(ans, temp);
      
    }
  }
  string res = to_string(ans);
  if(mod)res+=".5";
  cout << res << endl;

}
 
int32_t main(){
    int t=1;//cin>>t;
    while(t--)solve();
    return 0;
}