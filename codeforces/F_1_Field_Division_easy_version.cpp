#include <bits/stdc++.h>
#define ll long long
#define int ll
#define pb push_back
 
const int INF=(int)1e9;
const ll lINF=(int)4e15;
 
using namespace std;

int fsize(map<int, int> &col, int n, int m, map<int, int> &mcol){
  int res = 0, mn=0, lsc=-1;
  
  for(auto &[i,k]: col){
    res+=(n-mn)*(max(i-lsc-1, (int)0));
    lsc = i;
    mcol[i] = mn;
    mn=max(mn,col[i]);    
    if(col[i]>=n)return res;    
    res+=n-mn;
  }
  res+= (n-mn)*(max(m-lsc-1, (int)0));
  return res;
}
 
void solve(){
    int n, m , k; cin >> n >> m >> k;
    vector<array<int, 2>> f;f.clear();
    map<int, int> col, mcol;col.clear();mcol.clear();

    for(int i=0;i<k;i++){
      int a,b; cin >> a >> b;
      f.pb({a-1,b-1});
      col[b-1] = max(col[b-1], a);
    }

    for(auto [k,v]: col)mcol[k]=lINF;
    int firstCol = (*min_element(col.begin(), col.end())).first;
    mcol[firstCol] = 0;

    int initial = fsize(col, n, m, mcol);
    cout << initial << endl;

    for(int i=0;i<k;i++){
      if(col[f[i][1]] == f[i][0]+1){
        if(mcol[f[i][1]]<col[f[i][1]])cout << 1;
        else cout << "0";
        cout << " ";
      }
      else cout << 0 << " ";
    }
    cout << endl;

}
 
int32_t main(){
    int t=1;cin>>t;
    while(t--)solve();
    return 0;
}