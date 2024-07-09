#include <bits/stdc++.h>
#define ll long long
//#define int ll
#define pb push_back
 
const int INF=(int)1e9;
const ll lINF=(int)4e15;
 
using namespace std;
 
void solve(){
  int n; cin >> n;
  vector<int> a(n);
  for(int i=0;i<n;i++)cin >> a[i];

  int mx=-INF;
  for(int i=1;i<n;i++){
    mx=max(mx, min(a[i], a[i-1]));
  }

  for(int i=0;i<n-2;i++){
    vector<int> temp = {a[i], a[i+1], a[i+2]};
    sort(temp.begin(), temp.end());
    mx=max(temp[1],mx);
  }

  cout << mx << endl;
}
 
int32_t main(){
    int t=1;cin>>t;
    while(t--)solve();
    return 0;
}