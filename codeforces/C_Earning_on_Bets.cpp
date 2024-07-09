#include <bits/stdc++.h>
#define ll long long
//#define int ll
#define pb push_back
 
const int INF=(int)1e9;
const ll lINF=(int)4e15;
 
using namespace std;
 
void solve(){
    int n; cin >> n;
    vector<int> v(n);
    for(int i=0;i<n;i++)cin >> v[i];

    float dem = 1;
    for(auto u:v){
      float temp = (float)1/u;
      // cout << temp;
      dem-=temp;
    }
    
    if(dem<=0.00000005){
      cout << -1 << endl;
      return;
    }

    int x = ceil(n/dem)-1;
    vector<int> ans;
    // while(x>n){
    //   for(auto u: v){
    //     ans.push_back(x/u + 1);
    //     x-=x/u + 1;
    //   }
    // }
    // cout << x << " ";
    for(auto u: v){
      ans.push_back(x/u + 1);
      cout << x/u + 1 << " ";
    }
    cout << endl;

}
 
int32_t main(){
    int t=1;cin>>t;
    while(t--)solve();
    return 0;
}