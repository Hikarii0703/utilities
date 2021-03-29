/*
                君のいない　世界にも
                何かの意味はきっとあって

                でも君のいない　世界など
                夏休みのない　八月のよう

                君のいない　世界など
                笑うことない　サンタのよう

                君のいない　世界など...
*/
#define MULTICASE 0
#define FILEIO 0
#define INTERACTIVE 0

#include <bits/stdc++.h>
// libraries ==========================================================
// *INDENT-OFF* {{{
// #include <atcoder/fenwicktree>
// #include <atcoder/segtree>
// #include <atcoder/lazysegtree>
// #include <atcoder/string>
// #include <atcoder/math>
// #include <atcoder/modint>
// #include <atcoder/dsu>
// #include <atcoder/maxflow>
// #include <atcoder/mincostflow>
// #include <atcoder/scc>
// #include <atcoder/twosat>
// *INDENT-ON* }}}
// end of libraries ===================================================

// template ===========================================================
// *INDENT-OFF* {{{

// shorthands

// types
using i64 = long long;
using u64 = unsigned long long;
using uint = unsigned;
using db = double;
using ld = long double;
using str = std::string;

// limits
constexpr int MAX32 = INT_MAX;
constexpr int MIN32 = INT_MIN;
constexpr i64 MAX64 = LLONG_MAX;
constexpr i64 MIN64 = LLONG_MIN;

// pairs
using pi = std::pair<int, int>;
using p64 = std::pair<i64, i64>;
using pdb = std::pair<db, db>;

// vectors of types
using vb = std::vector<bool>;
using vi = std::vector<int>;
using v64 = std::vector<i64>;
using vdb = std::vector<db>;
using vld = std::vector<ld>;
using vstr = std::vector<str>;

// vectors of pairs
using vpi = std::vector<pi>;
using vp64 = std::vector<p64>;
using vpdb = std::vector<pdb>;

// vectors of vectors
using vvi = std::vector<vi>;
using vv64 = std::vector<v64>;
using vvpi = std::vector<vpi>;
using vvp64 = std::vector<vp64>;
using vvb = std::vector<vb>;

// priority_queue -> heap
template <class T, class Cmp = std::less<T>> using maxheap = std::priority_queue<T, std::vector<T>, Cmp>;
template <class T> using minheap = std::priority_queue<T, std::vector<T>, std::greater<T>>;

#define all(_x_) begin(_x_), end(_x_)
#define rall(_x_) rbegin(_x_), rend(_x_)
#define bb(_x_) begin(_x_), begin(_x_)
#define rbb(_x_) rbegin(_x_), rbegin(_x_)
#define fi first
#define se second
#define CAT(x, y) CAT_(x, y)
#define CAT_(x, y) x ## y

// variadic for-loops

// for with type
#define furtS(T, _i_, _a_, _b_, _c_) for (T _i_ = (_a_), CAT(_j_, __LINE__) = (_b_); _i_ <= CAT(_j_, __LINE__); _i_ += (_c_))
#define furtU(T, _i_, _a_, _b_) furtS(T, _i_, _a_, _b_, 1)
#define furtN(T, _i_, _n_) furtS(T, _i_, 0, _n_ - 1, 1)

// reversed for with type
#define rfurtS(T, _i_, _a_, _b_, _c_) for (T _i_ = (_a_), CAT(_j_, __LINE__) = (_b_); _i_ >= CAT(_j_, __LINE__); _i_ -= (_c_))
#define rfurtU(T, _i_, _a_, _b_) rfurtS(T, _i_, _a_, _b_, 1)
#define rfurtN(T, _i_, _n_) rfurtS(T, _i_, _n_ - 1, 0, 1)

// for
#define furS(_i_, _a_, _b_, _c_) furtS(int, _i_, _a_, _b_, _c_)
#define furU(_i_, _a_, _b_) furS(_i_, _a_, _b_, 1)
#define furN(_i_, _n_) furS(_i_, 0, (_n_) - 1, 1)

// reversed for
#define rfurS(_i_, _a_, _b_, _c_) rfurtS(int, _i_, _a_, _b_, _c_)
#define rfurU(_i_, _a_, _b_) rfurS(_i_, _a_, _b_, 1)
#define rfurN(_i_, _n_) rfurS(_i_, (_n_) - 1, 0, 1)

// for each
#define furj1(_a_, _x_) for (auto &_a_ : _x_)
#define furj2(_a_, _b_, _x_) for (auto &[_a_, _b_] : _x_)
#define furj3(_a_, _b_, _c_, _x_) for (auto &[_a_, _b_, _c_] : _x_)

#define NumArgsT(_1, _2, _3, _4, _5, furtFunc, ...) furtFunc
#define NumArgs(_1, _2, _3, _4, furFunc, ...) furFunc
#define NumArgsE(_1, _2, _3, _4, furjFunc, ...) furjFunc

#define furt(...) NumArgsT(__VA_ARGS__, furtS, furtU, furtN) (__VA_ARGS__)
#define rfurt(...) NumArgsT(__VA_ARGS__, rfurtS, rfurtU, rfurtN) (__VA_ARGS__)
#define fur(...) NumArgs(__VA_ARGS__, furS, furU, furN) (__VA_ARGS__)
#define rfur(...) NumArgs(__VA_ARGS__, rfurS, rfurU, rfurN) (__VA_ARGS__)
#define furj(...) NumArgsE(__VA_ARGS__, furj3, furj2, furj1) (__VA_ARGS__)
#define rep(_x_) fur(CAT(_rep_, __LINE__), _x_)
#define furimmer for (;;)

// bit stuff
#define popcnt(x) __builtin_popcountll(x)
#define clz(x) __builtin_clzll(x)
#define ffs(x) __builtin_ffsll(x)
template <class T> bool getBit(T mask, int b) { return (mask >> b & T(1)); }
template <class T> void setBit(T &mask, int b) { mask |= (T(1) << b); }
template <class T> void delBit(T &mask, int b) { mask &= ~(T(1) << b); }
template <class T> void flipBit(T &mask, int b) { mask ^= (T(1) << b); }

// read
template <class A, class B> std::istream &operator>>(std::istream &is, std::pair<A, B> &p) { return is >> p.first >> p.second; }
template <class T> std::istream &operator>>(std::istream &is, std::vector<T> &v) { int sz = v.size(); for (int i = 0; i < sz; i++) { is >> v[i]; } return is; } 
class Reader { private: bool _M_ok_ = true; public: explicit operator bool() { return _M_ok_; } template <typename T> Reader &operator, (T &_t_) { _M_ok_ &= !!(std::cin >> _t_); return *this; } };
#define re Reader(),
template <class T> T reNxt() { T _x_; re _x_; return _x_; }
#define ri reNxt<int>()
#define r64 reNxt<i64>()
#define rdb reNxt<db>()
#define rld reNxt<ld>()
#define rst reNxt<str>()
#define rch reNxt<char>()

// write
template <class A, class B> std::ostream &operator<<(std::ostream &os, const std::pair<A, B> &p) { return os << p.first << ' ' << p.second; }
template <class T> std::ostream &operator<<(std::ostream &os, const std::vector<T> &v) { int sz = v.size(); for (int i = 0; i < sz - 1; i++) { os << v[i] << ' '; } return os << v[sz - 1];} 
template <char _sep_, char _end_> class Writer { private: bool _M_ok_ = true; bool _space_; void wrCh(char _c_) { if (_c_) std::cout << _c_; } public: Writer() : _space_(false) {} ~Writer() { wrCh(_end_); } explicit operator bool() { return _M_ok_; } template <typename T> Writer &operator, (const T &_t_) { (_space_) ? (wrCh(_sep_)) : (void(_space_ = true)); _M_ok_ &= !!(std::cout << _t_); return *this; } };
#define pr Writer<'\0', '\0'>(),
#define	prln Writer<'\0', '\n'>(),
#define wr Writer<' ', ' '>(),
#define	wrln Writer<' ', '\n'>(),

// container access
#define TEMPL_ELEM(func) template <class C> constexpr inline auto func(C &c) -> decltype(c.func()) { return c.func(); }
TEMPL_ELEM(front) TEMPL_ELEM(back) TEMPL_ELEM(top)
#if __cplusplus < 201703L
TEMPL_ELEM(empty) TEMPL_ELEM(data)
#endif
template <class C> inline void clear(C& c) { c.clear(); }
#undef TEMPL_ELEM

// utilities
template <class A, class B> inline bool chmin(A &t, const B &f) { if (t > f) { t = f; return true; } return false; }
template <class A, class B> inline bool chmax(A &t, const B &f) { if (t < f) { t = f; return true; } return false; }
template <class C> inline void remdup(C &x) { sort(all(x)); x.erase(unique(all(x)), x.end()); }
template <class C> inline i64 len(const C &x) { return static_cast<i64>(x.size()); }
inline const str YN(bool cond) { return static_cast<const str &>((reinterpret_cast<const char *>((& (const int &)(23438671621410638LL >> (cond << 5)))))); }
inline const str yn(bool cond) { return static_cast<const str &>((reinterpret_cast<const char *>((& (const int &)(32481055248248654LL >> (cond << 5)))))); }
template <typename I> struct __ { I &v_; explicit __(I &v) : v_{v} {} typename I::reverse_iterator begin() const { return v_.rbegin(); } typename I::reverse_iterator end() const { return v_.rend(); } };
template <typename I> __<I> reversed(I &v) { return __<I>(v); }
template <class I> inline I maxElem(I f, I l) { return std::max_element(f, l); }
template <class I> inline I minElem(I f, I l) { return std::min_element(f, l); }

// debugger
#ifdef LOCAL_DEFINE
namespace std {
using namespace std;
template <class A, class B> string to_string(const std::pair<A, B> &p); template <class A, class B, class C> string to_string(const tuple<A, B, C> &p);
string to_string(const string &s) { return '"' + s + '"'; } string to_string(const char *s) { return to_string(static_cast<string>(s)); }
string to_string(char c) { return "\'" + string(1, c) + "\'"; } string to_string(bool b) { return (b ? "true" : "false"); }
string to_string(const std::vector<bool> &v) { bool first = true; string res = "{"; for (int i = 0; i < static_cast<int>(v.size()); i++) { if (!first) { res += ", "; } first = false; res += to_string(v[i]); } res += "}"; return res; }
template <size_t N> string to_string(const bitset<N> &v) { string res = ""; for (size_t i = 0; i < N; i++) { res += static_cast<char>('0' + v[i]); } return res; }
template <class A> string to_string(const A &v) { bool first = true; string res = "{"; for (const auto &x : v) { if (!first) { res += ", "; } first = false; res += to_string(x); } res += "}"; return res; }
template <class A, class B> string to_string(const std::pair<A, B> &p) { return "(" + to_string(p.first) + ", " + to_string(p.second) + ")"; }
template <class A, class B, class C> string to_string(const tuple<A, B, C> &p) { return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " + to_string(get<2>(p)) + ")"; }
void debug_out() { cerr << endl; } template <class Head, class... Tail> void debug_out(Head H, Tail... T) { cerr << " " << to_string(H); debug_out(T...); }
}
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define debug(...) "A world without you is..."
#endif // LOCAL_DEFINE

// randomizer
#ifdef LOCAL_DEFINE
std::mt19937_64 rng(0703);
#else
std::mt19937_64 rng(std::chrono::steady_clock::now().time_since_epoch().count());
#endif // LOCAL_DEFINE
inline i64 randrange(i64 a, i64 b) { return std::uniform_int_distribution<i64>(a, b)(rng); }

#ifdef PB_DS_ASSOC_CNTNR_HPP
struct splitmix64_hash { static uint64_t splitmix64(uint64_t x) { x += 0x9e3779b97f4a7c15; x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9; x = (x ^ (x >> 27)) * 0x94d049bb133111eb; return x ^ (x >> 31); } size_t operator()(uint64_t x) const { static const uint64_t FIXED_RANDOM = std::chrono::steady_clock::now().time_since_epoch().count(); return splitmix64(x + FIXED_RANDOM); } };
template <class T> using idset = __gnu_pbds::tree<T, __gnu_pbds::null_type, std::less<T>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;
template <class T> using idmulset = __gnu_pbds::tree<T, __gnu_pbds::null_type, std::less_equal<T>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;
template <typename K, typename V, typename Hash = splitmix64_hash> using hashmap = __gnu_pbds::gp_hash_table<K, V, Hash>;
template <typename K, typename Hash = splitmix64_hash> using hashset = hashmap<K, __gnu_pbds::null_type, Hash>;
#endif // PB_DS_ASSOC_CNTNR_HPP

// y_combinator
#if __cplusplus >= 201402L
namespace std {
template <class Fun>
class ___ {
    Fun fun_;
public:
    template<class T> explicit ___(T &&fun): fun_(std::forward<T>(fun)) {}
    template<class ...Args> decltype(auto) operator()(Args &&...args) { return fun_(std::ref(*this), std::forward<Args>(args)...); }
};
template <class Fun> decltype(auto) y_combinator(Fun &&fun) { return ___<std::decay_t<Fun>>(std::forward<Fun>(fun)); }
} // namespace std
#endif

// multidimensional vector
template <int D, class T> struct dvec : public std::vector<dvec<D - 1, T>> { static_assert(D >= 1, "Vector dimension must be greater than zero!"); template <class... Args> dvec(int n, Args... args) : std::vector<dvec<D - 1, T>>(n, dvec<D - 1, T>(args...)) {} };
template <class T> struct dvec<1, T> : public std::vector<T> { dvec(int n, const T &val = T()) : std::vector<T>(n, val) {} };

// adjacent grid coords
// up upright right downright down downleft left upleft
constexpr int dx[] = {-1, -1,  0,  1,  1,  1,  0, -1};
constexpr int dy[] = { 0,  1,  1,  1,  0, -1, -1, -1};

void solveCase();
void initialRun();

int main() {
#if FILEIO
#ifdef LOCAL_DEFINE
#warning "FILEIO ON"
#else
    freopen("<<in>>", "r", stdin);
    freopen("<<out>>", "w", stdout);
#endif
#endif
    std::ios_base::sync_with_stdio(false); std::cin.tie(nullptr);
    std::cout << std::setprecision(12) << std::fixed;

    initialRun();

#if MULTICASE
#ifdef LOCAL_DEFINE
#warning "MULTICASE ON"
#endif
    int nTC; (std::cin >> nTC).ignore();
    for (int iTC = 0; iTC < nTC; iTC++) {
#endif
        solveCase();
#if MULTICASE
    }
#endif

    return 0;
}

// modulo
#if ATCODER_MATH_HPP
// using imod = modint998244353;
using imod = atcoder::modint1000000007;
#endif

// constants
constexpr db EPS = 1e-9;
constexpr int INF = 1e9;
constexpr i64 INF64 = 1e18;
constexpr int N = 3e5 + 5;

// *INDENT-ON* }}}
// end of template ====================================================

using namespace std;

void solveCase() {

}

// initial run ========================================================
// {{{ will run ONCE only before solveCase(), regardless of MULTICASE
void initialRun() {

}
// }}}
// end of initial run =================================================
