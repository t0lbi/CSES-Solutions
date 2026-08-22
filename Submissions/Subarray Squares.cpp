// Submission Timestamp: 2026-04-04 23:11:55

#pragma optimize("Bismillahirrahmanirrahim")
//█▀█─█──█──█▀█─█─█
//█▄█─█──█──█▄█─█■█
//█─█─█▄─█▄─█─█─█─█
//Allahuekber
//ahmet23 orz...
//Sani buyuk Osman Pasa Plevneden cikmam diyor.
//FatihSultanMehmedHan
//YavuzSultanSelimHan
//AbdulhamidHan
#define author tolbi
#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define vint(x) vector<int> x
#define deci(x) int x;cin>>x;
#define decstr(x) string x;cin>>x;
#define cinarr(x) for (auto &it : x) cin>>it;
#define coutarr(x) for (auto &it : x) cout<<it<<" ";cout<<endl;
#define sortarr(x) sort(x.begin(),x.end())
#define sortrarr(x) sort(x.rbegin(),x.rend())
#define det(x) cout<<"NO\0YES"+x*3<<endl;
#define INF LONG_LONG_MAX
#define rev(x) reverse(x.begin(),x.end());
#define ios ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define tol(bi) (1LL<<((int)(bi)))
const int MOD = 1e9+7;
using namespace std;
mt19937 ayahya(chrono::high_resolution_clock().now().time_since_epoch().count());
vector<int> pref;
int C(int i, int j){
  return (pref[i]-pref[j])*(pref[i]-pref[j]);
}
vector<int> oldm;
vector<int> newm;
void calc(int l, int r, int optl, int optr){
  if (l>r) return;
  int mid = l+(r-l)/2;
  newm[mid]=1e17;
  int opt = -1;
  for (int i = max(0ll,optl); i <= min(mid-1,optr); i++){
    if (newm[mid]>oldm[i]+C(i,mid)){
      newm[mid]=oldm[i]+C(i,mid);
      opt=i;
    }
  }
  calc(l,mid-1,optl,opt);
  calc(mid+1,r,opt,optr);
}
int32_t main(){
  ios;
  int t=1;
  int tno = 0;
  if (!t) cin>>t;
  while (t-(tno++)){
    deci(n);deci(k);
    pref.resize(n);
    cinarr(pref);
    for (int i = 1; i < n; ++i)
    {
      pref[i]+=pref[i-1];
    }
    oldm.resize(n);
    newm.resize(n);
    for (int i = 0; i < n; ++i)
    {
      oldm[i]=pref[i]*pref[i];
    }
    for (int i = 2; i <= k; i++){
      calc(0,n-1,0,n-1);
      swap(oldm,newm);
    }
    cout<<oldm.back()<<endl;
  }
}