#include <bits/stdc++.h>
#define ll long long
//#define int ll
#define pb push_back
 
const int INF=(int)1e9;
const ll lINF=(int)4e15;
 
using namespace std;
 
void solve(){
	int sz; string s;cin >> sz >> s;
	
  int cnt = 0;
  for(auto u: s){
    cnt+= (int)u=='U';
  }
  if(cnt%2==0){
    cout << "NO" << endl;
    return;
  }
  cout << "YES" << endl;
  return;
}
 
int32_t main(){
    int t=1;cin>>t;
    while(t--)solve();
    return 0;
}