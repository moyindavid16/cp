#include <bits/stdc++.h>
#define ll long long
//#define int ll
#define pb push_back
 
const int INF=(int)1e9;
const ll lINF=(int)4e15;
 
using namespace std;
 
void solve(){
  int n, dest; cin >> n >> dest;
  vector<int> v(n-1,0);
  for(int i=0;i<n-1;i++){
    int x; cin >> x;
    v[i] = x;
  }
  
  int curr=0;
  while(curr!=dest-1 && curr!=n-1){
    curr += v[curr];
  }
  if(curr==dest-1){
    cout << "YES";
  }
  else cout << "NO";
  cout << endl;

}
 
int32_t main(){
    int t=1;//cin>>t;
    while(t--)solve();
    return 0;
}