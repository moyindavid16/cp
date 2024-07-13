#include <bits/stdc++.h>
#define ll long long
#define int ll
#define pb push_back
 
const int INF=(int)1e9;
const ll lINF=(int)4e15;
 
using namespace std;

class Seg{
  public:
  vector<int> tree;
  int sz;
  Seg(int n, vector<int>& v){
    sz=1;
    while(sz<n)sz=sz<<1;
    tree.assign(2*sz, lINF);

    for(int i=0;i<v.size();i++)tree[sz+i]=v[i];
    for(int j=sz-1;j>0;j--)tree[j] = min(tree[j*2], tree[j*2 + 1]);
  }

  int get_min(int node, int ql, int qr, int l, int r){
    if(l>=ql && r<=qr)return tree[node];
    if(r<ql || l>qr)return lINF;

    int last_left = (l+r)/2;
    return min(get_min(node*2, ql, qr, l, last_left), get_min(node*2+1, ql, qr, last_left+1, r));
  }

  void update(int node, int val){
    node+=sz;
    tree[node] = val;
    for(int j=node/2;j>=1;j/=2)tree[j] = min(tree[j*2], tree[j*2+1]);
  }
};
 
void solve(){
  int n, q; cin >> n >> q;
  vector<int> a(n);
  for(int i=0;i<n;i++)cin >> a[i];
  
  Seg tree = Seg(n, a);
  while(q--){
    int type; cin >> type;
    if(type==1){
      int node, val;cin >> node >> val;
      node--;
      tree.update(node, val);
    }
    else{
      int l,r; cin >> l >> r;
      l--;r--;
      cout << tree.get_min(1, l, r, 0, tree.sz-1) << "\n";
    }
  }
}
 
int32_t main(){
  int t=1;//cin>>t;
  while(t--)solve();
  return 0;
}