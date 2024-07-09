#include <bits/stdc++.h>
#define ll long long
//#define int ll
#define pb push_back
 
const int INF=(int)1e9;
const ll lINF=(int)4e15;
 
using namespace std;

bool good(vector<int> c){
  int last = __gcd(c[0], c[1]);
  for(int i=2;i<c.size();i++){
    int curr = __gcd(c[i], c[i-1]);
    if(last > curr){
      return 0;
    }
    last = curr;
  }
  return 1;
}
 
void solve(){
    int n; cin >> n;
    vector<int> v(n);
    for(int i=0;i<n;i++)cin >> v[i];

    int last = __gcd(v[0], v[1]), lsti = -1;
    for(int i=2;i<n;i++){
      int curr = __gcd(v[i], v[i-1]);
      if(last > curr){
        lsti=i;
        break;
      }
      last = curr;
    }
    if(lsti!=-1){
      // cout << lsti;
      vector<int> b1, b2, b3;b1=b2=b3=v;
      if(lsti-1>=0)b1.erase(b1.begin()+lsti-1);
      b2.erase(b2.begin()+lsti);
      if(lsti-2>=0)b3.erase(b3.begin()+lsti-2);
      if(good(b1) || good(b2) || good(b3))cout << "YES";
      else cout << "NO";
      cout << endl;return;
    }
    cout << "YES" << endl;

}
 
int32_t main(){
    int t=1;cin>>t;
    while(t--)solve();
    return 0;
}