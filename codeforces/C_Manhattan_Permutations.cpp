#include <bits/stdc++.h>
#define ll long long
#define int ll
#define pb push_back
 
const int INF=(int)1e9;
const ll lINF=(int)4e15;
 
using namespace std;
 
void solve(){
    int n,k; cin >> n >> k;
    if(k==0){
      cout << "Yes" << endl;
      for(int i=0;i<n;i++)cout << i+1 << " ";
      cout << endl;
      return;
    }

    vector<int> ans(n,0);int mx=0;
    for(int i=0;i<n;i++){ans[i]=i+1;}
    for(int i=0;i<n/2;i++){
      mx+= 2 * (ans[n-i-1] - ans[i]);
    }

    if(k%2==1 || k>mx){
      cout << "No" << endl;
      return;
    }
    
    int l=0,r=n-1;
    while(l<r && k>0){
      if(2*abs(ans[l]-ans[r])<=k){
        swap(ans[l], ans[r]);
        k-=2*abs(ans[l]-ans[r]);
      }
      else l--;
      l++;r--;
    }
    
    cout << "Yes" << endl;
    for(auto u: ans)cout << u << " ";
    cout << endl;


}
 
int32_t main(){
    int t=1;cin>>t;
    while(t--)solve();
    return 0;
}