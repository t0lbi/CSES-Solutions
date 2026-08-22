// Submission Timestamp: 2026-05-19 00:50:30

#include <bits/stdc++.h>
using namespace std;
namespace FFT{
  void fft(vector<complex<double>> &a) {
    int n = a.size(), L = 31 - __builtin_clz(n);
    static vector<complex<long double>> R(2, 1);
    static vector<complex<double>> rt(2, 1);
    for (static int k = 2; k < n; k *= 2) {
      R.resize(n);
      rt.resize(n);
      auto x = polar(1.0L, acos(-1.0L) / k);
      for (int i = k; i < 2*k; i++) rt[i] = R[i] = i & 1 ? R[i / 2] * x : R[i / 2];
    }
  vector<int> rev(n);
  for (int i = 0; i < n; i++){
    rev[i] = (rev[i / 2] | (i & 1) << L) / 2;
  }
  for (int i = 0; i < n; i++){
    if (i < rev[i]) swap(a[i], a[rev[i]]);
  }
  for (int k = 1; k < n; k *= 2){
    for (int i = 0; i < n; i += 2 * k) {
      for (int j = 0; j < k; j++) {
        auto x = (double *)&rt[j + k], y = (double *)&a[i + j + k];
        complex<double> z(x[0] * y[0] - x[1] * y[1], x[0] * y[1] + x[1] * y[0]);
        a[i + j + k] = a[i + j] - z;
        a[i + j] += z;
      }
    }
  }
}
template <long long M> vector<long long> convolution(const vector<long long> &a, const vector<long long> &b) {
if (a.empty() || b.empty()) return {};
vector<long long> res(a.size() + b.size() - 1);
if (a.size()<=10 || b.size()<=10){
  for (int i = 0; i < a.size(); i++){
    for (int j = 0; j < b.size(); j++){
      res[i+j]+=(a[i]*b[j])%M;
      if (res[i+j]>=M) res[i+j]-=M;
    }
  }
  return res;
}
int B = 32 - __builtin_clz(res.size()), n = 1 << B, cut = int(sqrt(M));
vector<complex<double>> L(n), R(n), outs(n), outl(n);
for (int i = 0; i < a.size(); i++) L[i] = complex<double>((int)a[i] / cut, (int)a[i] % cut);
  for (int i = 0; i < b.size(); i++) R[i] = complex<double>((int)b[i] / cut, (int)b[i] % cut);
    FFT::fft(L), FFT::fft(R);
  for (int i = 0; i < n; i++){
    int j = -i & (n - 1);
    outl[j] = (L[i] + conj(L[j])) * R[i] / (2.0 * n);
    outs[j] = (L[i] - conj(L[j])) * R[i] / (2.0 * n) / 1i;
  }
  FFT::fft(outl), FFT::fft(outs);
  for (int i = 0; i < res.size(); i++) {
    long long av = (long long)(real(outl[i]) + .5), cv = (long long)(imag(outs[i]) + .5);
    long long bv = (long long)(imag(outl[i]) + .5) + (long long)(real(outs[i]) + .5);
    res[i] = ((av % M * cut + bv) % M * cut + cv) % M;
  }
  return res;
}
};
#define int long long
int32_t main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  string s;cin>>s;
  int n = s.length();
  vector<int> freq(n+1);
  freq[0] = 1;
  int cnt = 0;
  for (auto ch : s) {
    if (ch == '1') cnt++;
    freq[cnt]++;
  }
  vector<int> rfreq = freq;
  reverse(rfreq.begin(),rfreq.end());
  vector<int> ans = FFT::convolution<LONG_LONG_MAX>(freq,rfreq);
  ans[n] = 0;
  int cur = 0;
  for (int i = 0; i < n; i++) {
    if (s[i] == '0') cur++;
    else {
      ans[n] += cur * (cur+1) / 2;
      cur = 0;
    }
  }
  ans[n] += cur * (cur+1) / 2;
  for (int i = n; i < 2*n+1; i++) {
    cout<<ans[i]<<' ';
  }
  cout << '\n';
}