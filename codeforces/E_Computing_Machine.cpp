#include <bits/stdc++.h>
#define ll long long
//#define int ll
#define pb push_back
 
const int INF=(int)1e9;
const ll lINF=(int)4e15;
 
using namespace std;
 
void solve(){
    int n; cin >> n;
    string a,b, ia, ib; cin >> a >> b; ia=a;ib=b;
    for(int i=0;i<n-2;i++){
      if(a[i]==a[i+2] && a[i]=='0')b[i+1]='1';
    }
    for(int i=0;i<n-2;i++){
      if(b[i]==b[i+2] && b[i]=='1')a[i+1]='1';
    }


    vector<int> dp(n+1,0);
    for(int i=0;i<n;i++){
      dp[i+1]=dp[i];
      if(a[i] == '1'){
        dp[i+1]++;
      }
    }

    int q; cin >> q;
    while(q--){
      int l,r; cin >> l >> r;
      int ans=0;
      if(r-l<4){
        for(int i=l;i<=r;i++){
          if(ia[i-1]=='1')ans++;
          else if(i>l && i<r && ib[i-2]==ib[i] && ib[i]=='1')ans++;
          else if(i>l && i<r){
            bool flag=0;
            if(i>l+1 && ib[i-2]=='0' && (ia[i-3]!=ia[i-1] || ia[i-1]=='1'))flag=1;
            if(i<=l+1 && ib[i-2]=='0')flag=1;
            if(i<r-1 && ib[i]=='0' && (ia[i-1]!=ia[i+1] || ia[i-1]=='1'))flag=1;
            if(i>=r-1 && ib[i]=='0')flag=1;
            if(!flag)ans++;
          }
        }
        cout << ans << endl;
        continue;
      }
      for(int i=l;i<=l+1;i++){
        if(ia[i-1]=='1')ans++;
        else if(i>l && i<r && ib[i-2]==ib[i] && ib[i]=='1')ans++;
        else if(i>l && i<r){
          bool flag=0;
          if(i>l+1 && ib[i-2]=='0' && (ia[i-3]!=ia[i-1] || ia[i-1]=='1'))flag=1;
          if(i<=l+1 && ib[i-2]=='0')flag=1;
          if(i<r-1 && ib[i]=='0' && (ia[i-1]!=ia[i+1] || ia[i-1]=='1'))flag=1;
          if(i>=r-1 && ib[i]=='0')flag=1;
          if(!flag)ans++;
        }
      }
      for(int i=r;i>=r-1;i--){
        if(ia[i-1]=='1')ans++;
        else if(i>l && i<r && ib[i-2]==ib[i] && ib[i]=='1')ans++;
        else if(i>l && i<r){
          bool flag=0;
          if(i>l+1 && ib[i-2]=='0' && (ia[i-3]!=ia[i-1] || ia[i-1]=='1'))flag=1;
          if(i<=l+1 && ib[i-2]=='0')flag=1;
          if(i<r-1 && ib[i]=='0' && (ia[i-1]!=ia[i+1] || ia[i-1]=='1'))flag=1;
          if(i>=r-1 && ib[i]=='0')flag=1;
          if(!flag)ans++;
        }
      }
      cout << dp[r-2]- dp[l+1] + ans << endl;
    }

}
 
int32_t main(){
    int t=1;cin>>t;
    while(t--)solve();
    return 0;
}