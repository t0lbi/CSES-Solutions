// Submission Timestamp: 2024-02-08 08:45:22

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
template<typename X, typename Y> istream& operator>>(istream& in, pair<X,Y> &pr) {return in>>pr.first>>pr.second;}
template<typename X, typename Y> ostream& operator<<(ostream& os, pair<X,Y> pr) {return os<<pr.first<<" "<<pr.second;}
template<typename X> istream& operator>>(istream& in, vector<X> &arr) {for(auto &it : arr) in>>it; return in;}
template<typename X> ostream& operator<<(ostream& os, vector<X> arr) {for(auto &it : arr) os<<it<<" "; return os;}
template<typename X, size_t Y> istream& operator>>(istream& in, array<X,Y> &arr) {for(auto &it : arr) in>>it; return in;}
template<typename X, size_t Y> ostream& operator<<(ostream& os, array<X,Y> arr) {for(auto &it : arr) os<<it<<" "; return os;}
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
mt19937 ayahya(chrono::high_resolution_clock().now().time_since_epoch().count());
int32_t main(){
	ios;
	int t=1;
	int tno = 0;
	if (!t) cin>>t;
	while (t-(tno++)){
		deci(k);
		deci(n);deci(m);
		vector<int> a(k+1);
		for (int i = 0; i < n; ++i)
		{
			deci(x);
			a[x]++;
		}
		vector<int> b(k+1);
		for (int i = 0; i < m; ++i)
		{
			deci(x);
			b[x]++;
		}
		vector<int> c = FFT::convolution<INF>(a,b);
		c.resize(2*k+1);
		for (int i = 2; i < c.size(); ++i)
		{
			cout<<c[i]<<" ";
		}
		cout<<endl;
	}
}