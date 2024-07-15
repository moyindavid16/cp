#include <bits/stdc++.h>
#define ll long long
#define int ll
#define pb push_back
 
const int INF=(int)1e9;
const ll lINF=(int)4e15;
 
using namespace std;
 
void solve(){
  int n; cin >> n;
  string s_raw = bitset<64>(n).to_string();
  string s;
  bool skip=1;
  for(auto u: s_raw){
    if(skip && u=='0')continue;
    else{
      skip=0;
      s+=u;
    }
  }
  int sz = s.size();
  vector<unsigned ll> ans;
  for(int i=sz-1;i>=0;i--){
    if(s[i]=='0')continue;
    string temp = s;
    temp[i]='0';
    bitset<64> bits(temp);
    unsigned ll num = bits.to_ullong();
    if(num)ans.pb(num);
  }
  reverse(ans.begin(), ans.end());
  ans.push_back(n);
  cout << ans.size() << endl;
  for(auto u: ans)cout << u << " ";
  cout << "\n";
}
 
int32_t main(){
  int t=1;cin>>t;
  while(t--)solve();
  return 0;
}