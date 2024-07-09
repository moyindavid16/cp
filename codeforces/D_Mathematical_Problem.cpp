#include <bits/stdc++.h>
#define ll long long
//#define int ll
#define pb push_back
 
const int INF=(int)1e9;
const ll lINF=(int)4e15;
 
using namespace std;
 
void solve(){
  int n;cin >> n;
  string s; cin >> s;

  if(n==2){
    cout << stoi(s) << endl;
    return;
  }
  if(n==3){
    int a1=s[0]-'0', b1 = int(s[1]-'0')*10 + int(s[2]-'0');
    int a2=s[2]-'0', b2 = int(s[0]-'0')*10 + int(s[1]-'0');
    cout << min({a1+b1, a2+b2, a1*b1, a2*b2}) << endl;
    return;
  }


  for(int i=0;i<n;i++){
    if(s[i]=='0'){
      cout << 0 << endl;return;
    }
  }

  int ans=INF, mn=100, mni=0, d1i=-1;
  // for(int i=0;i<n-1;i++){
  //   if(i<n-2 && s[i]=='1' && s[i]==s[i+1]){
  //     continue;
  //   }
  //   int temp = int(s[i]-'0')*10 + int(s[i+1]-'0');
  //   if(temp<mn){
  //     mn=temp;
  //     mni=i;
  //   }
  // }

  // for(int i=0;i<n;i++){
  //   if(mni==i){
  //     if(mn>1)ans+=mn;
  //     i++;
  //   }
  //   else{
  //     if(s[i]!='1')ans+=int(s[i]-'0');
  //   }
  // }

  for(int i=0;i<n-1;i++){
    int temp=0;
    for(int j=0;j<n;j++){
      if(i==j){
        int num = int(s[j]-'0')*10 + int(s[j+1]-'0');
        if(num>1)temp+=num;
        j++;
      }
      else{
        if(s[j]!='1')temp+=int(s[j]-'0');
      }
      
    }
    ans = min(ans, temp);
  }
  cout << ans << endl;

}
 
int32_t main(){
    int t=1;cin>>t;
    while(t--)solve();
    return 0;
}