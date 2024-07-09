#include <bits/stdc++.h>
#define ll long long
#define int ll
#define pb push_back
 
const int INF=(int)1e9;
const ll lINF=(int)4e15;
 
using namespace std;
 
void solve(){
	int n; cin >> n;
  vector<int> x(n-1,0);
  for(int i=0;i<n-1;i++)cin >> x[i];

  vector<int> res(n,0);
  res[0] = x[0]+1;

  for(int i=0;i<n-1;i++){
    int temp = x[i] + res[i];
    if(i<n-2){
      temp+=max((long long)0, (x[i+1]-x[i])/res[i]) * res[i];
    }
    res[i+1]=temp;
  }

  for(auto u: res)cout << u << " ";
  cout << endl;
}
 
int32_t main(){
    int t=1;cin>>t;
    while(t--)solve();
    return 0;
}