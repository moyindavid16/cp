#include <bits/stdc++.h>
#define ll long long
#define int ll
#define pb push_back
 
const int INF=(int)1e9;
const ll lINF=(int)4e15;
 
using namespace std;
 
void solve(){
	int n,k; cin >> n >> k;
  vector<int> a(n,0);
  int mn = lINF, cnt=0;
  for(int i=0;i<n;i++){
    cin >> a[i];
  }
  sort(a.begin(), a.end());
  reverse(a.begin(), a.end());
  mn = a.back();
  while(!a.empty()&&a.back()==mn)cnt++,a.pop_back();
  
  while(!a.empty()){
    int dif = a.back()-mn;
    if(k<dif*cnt)break;
    k-=dif*cnt;
    mn = a.back();
    while(!a.empty()&&a.back()==mn)cnt++,a.pop_back();
  }
  mn += k/cnt;
  int res = n*mn;
  cnt-= k%cnt + 1;
  cout << res-cnt << endl;
}
 
int32_t main(){
    int t=1;cin>>t;
    while(t--)solve();
    return 0;
}