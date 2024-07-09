#include <bits/stdc++.h>
#define ll long long
// #define int ll
#define pb push_back
 
const int INF=(int)1e9;
const ll lINF=(int)4e15;
 
using namespace std;
 
void solve(){
  int n; cin >> n;
  string s,e; cin >> s >> e;
  int pstop=-1;
  while(pstop+1<min(s.size(), e.size()) && s[pstop+1]==e[pstop+1])pstop++;
  
  int needed = s.size()-pstop-1 + e.size()-pstop-1;
  // cout << pstop << " " << needed << endl;
  if(n>=needed){
    cout << "Yes";
  }
  else cout << "No";
  cout << endl;
}
 
int32_t main(){
    int t=1;//cin>>t;
    while(t--)solve();
    return 0;
}