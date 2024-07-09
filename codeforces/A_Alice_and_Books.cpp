#include <bits/stdc++.h>
#define ll long long
#define int ll
#define pb push_back
 
const int INF=(int)1e9;
const ll lINF=(int)4e15;
 
using namespace std;
 
void solve(){
    int n; cin >> n;
    vector<int> v(n); int mx = -INF;
    for(int i=0;i<n;i++){
      cin >> v[i];
      if(i<n-1)mx=max(mx, v[i]);
    }

    cout << mx + v[n-1] << endl;

}
 
int32_t main(){
    int t=1;cin>>t;
    while(t--)solve();
    return 0;
}