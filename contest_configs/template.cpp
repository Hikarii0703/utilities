/*
        Ôi sáng nay sao tôi thấy tồi tệ
        Ôi sáng nay sao tôi dậy muộn thế
        Ôi sáng nay sao, làm sao làm sao
        Tôi thấy ai treo đầu tôi lên cao
        Tôi phóng ra xe, hôm nay đi học
        Nếu tôi còn bé thì tôi sẽ khóc
        Nhưng đã hai mươi, hai mươi, hai mươi
        Lên xe đi học, để ngồi lên ghế
        Không làm gì
*/

#ifndef LOCAL_DEFINE
#pragma GCC optimize ("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target ("avx,avx2")
#endif

#include <bits/stdc++.h>

// {{{
using i64 = long long;
using u64 = unsigned long long;

#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
#define bb(x) begin(x), begin(x)
#define rbb(x) rbegin(x), rbegin(x)

template <class A, class B> std::istream &operator>>(std::istream &is, std::pair<A, B> &p) { return is >> p.first >> p.second; }
template <class T> std::istream &operator>>(std::istream &is, std::vector<T> &v) { int sz = v.size(); for (int i = 0; i < sz; i++) { is >> v[i]; } return is; } 
class Reader { private: bool _M_ok_ = true; public: explicit operator bool() { return _M_ok_; } template <class T> Reader &operator, (T &_t_) { _M_ok_ &= !!(std::cin >> _t_); return *this; } };
template <class T> T reNxt() { T _x_; std::cin >> _x_; return _x_; }
#define re Reader(),
#define ri reNxt<int>()

template <class A, class B> std::ostream &operator<<(std::ostream &os, const std::pair<A, B> &p) { return os << p.first << ' ' << p.second; }
template <class T> std::ostream &operator<<(std::ostream &os, const std::vector<T> &v) { int sz = v.size(); for (int i = 0; i < sz - 1; i++) { os << v[i] << ' '; } return os << v[sz - 1];} 
template <char _sep_, char _end_> class Writer { private: bool _M_ok_ = true; bool _space_; void wrCh(char _c_) { if (_c_) std::cout << _c_; } public: Writer() : _space_(false) {} ~Writer() { wrCh(_end_); } explicit operator bool() { return _M_ok_; } template <class T> Writer &operator, (const T &_t_) { (_space_) ? (wrCh(_sep_)) : (void(_space_ = true)); _M_ok_ &= !!(std::cout << _t_); return *this; } };
#define pr Writer<'\0', '\0'>(),
#define	prln Writer<'\0', '\n'>(),
#define wr Writer<' ', ' '>(),
#define	wrln Writer<' ', '\n'>(),

template <class A, class B> inline bool chmin(A &t, const B &f) { if (t > f) { t = f; return true; } return false; }
template <class A, class B> inline bool chmax(A &t, const B &f) { if (t < f) { t = f; return true; } return false; }
template <class C> inline void remdup(C &x) { sort(x.begin(), x.end()); x.erase(unique(x.begin(), x.end()), x.end()); }
template <class C> inline int isz(const C &x) { return static_cast<int>(x.size()); }
template <typename I> struct __ { I &v_; explicit __(I &v) : v_{v} {} typename I::reverse_iterator begin() const { return v_.rbegin(); } typename I::reverse_iterator end() const { return v_.rend(); } };
template <typename I> __<I> rev(I &v) { return __<I>(v); }
#if __cplusplus < 201703L
inline long long gcd(long long a, long long b) { while (b) { a %= b; std::swap(a, b); } return a; }
inline long long lcm(long long a, long long b) { return a / gcd(a, b) * b; }
#endif

constexpr double EPS = 1e-9;
constexpr int INF = 1e9;
constexpr i64 INF64 = 1e18;
// }}}

using namespace std;

constexpr int N = 3e5 + 5;

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);



    return 0;
}

