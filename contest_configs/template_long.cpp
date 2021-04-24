/*
        Chỉ để lần cuối đi bên nhau,
        Cay đắng nhưng không đau.
        Nếu ai cũng mang tội thì
        Người mong đợi gì nơi tôi?
        Tiễn em tới đây thôi,
        Phố mưa cũng đang tạnh rồi...

        Cho dù chẳng biết sẽ đi đâu,
        Cũng giống như lần đầu,
        Nhưng nếu em có đoái hoài cũng đừng
        Ngoái lại nhìn sang tôi.
        Em cứ đi tiếp thôi.
        Lần cuối ấy cũng qua mất rồi,
        Y như một giấc mơ trôi...
*/

// control panel ======================================================
#define MULTICASE 0
#define FILEIO 0
#define INTERACTIVE 0
// end of control panel ===============================================

// libraries ==========================================================
#include <bits/stdc++.h>
// #include <atcoder/all>
// end of libraries ===================================================

// template ===========================================================
// {{{

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
#define furj4(_a_, _b_, _c_, _d, _x_) for (auto &[_a_, _b_, _c_, _d_] : _x_)

#define NumArgsT(_1, _2, _3, _4, _5, furtFunc, ...) furtFunc
#define NumArgs(_1, _2, _3, _4, furFunc, ...) furFunc
#define NumArgsE(_1, _2, _3, _4, _5, furjFunc, ...) furjFunc

#define furt(...) NumArgsT(__VA_ARGS__, furtS, furtU, furtN) (__VA_ARGS__)
#define rfurt(...) NumArgsT(__VA_ARGS__, rfurtS, rfurtU, rfurtN) (__VA_ARGS__)
#define fur(...) NumArgs(__VA_ARGS__, furS, furU, furN) (__VA_ARGS__)
#define rfur(...) NumArgs(__VA_ARGS__, rfurS, rfurU, rfurN) (__VA_ARGS__)
#define furj(...) NumArgsE(__VA_ARGS__, furj4, furj3, furj2, furj1) (__VA_ARGS__)
#define rep(_x_) fur(CAT(_rep_, __LINE__), _x_)
#define furdich for (;;)

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
template <class T> T reNxt() { T _x_; std::cin >> _x_; return _x_; }
#define re Reader(),
#define ri reNxt<int>()

// write
template <class A, class B> std::ostream &operator<<(std::ostream &os, const std::pair<A, B> &p) { return os << p.first << ' ' << p.second; }
template <class T> std::ostream &operator<<(std::ostream &os, const std::vector<T> &v) { int sz = v.size(); for (int i = 0; i < sz - 1; i++) { os << v[i] << ' '; } return os << v[sz - 1];} 
template <char _sep_, char _end_> class Writer { private: bool _M_ok_ = true; bool _space_; void wrCh(char _c_) { if (_c_) std::cout << _c_; } public: Writer() : _space_(false) {} ~Writer() { wrCh(_end_); } explicit operator bool() { return _M_ok_; } template <typename T> Writer &operator, (const T &_t_) { (_space_) ? (wrCh(_sep_)) : (void(_space_ = true)); _M_ok_ &= !!(std::cout << _t_); return *this; } };
#define pr Writer<'\0', '\0'>(),
#define	prln Writer<'\0', '\n'>(),
#define wr Writer<' ', ' '>(),
#define	wrln Writer<' ', '\n'>(),

// container access
template <class C> inline void clear(C& c) { c.clear(); }
#define TEMPL_ELEM(func) template <class C> constexpr inline auto func(C &c) -> decltype(c.func()) { return c.func(); }
TEMPL_ELEM(front) TEMPL_ELEM(back) TEMPL_ELEM(top)
#if __cplusplus < 201703L
TEMPL_ELEM(empty) TEMPL_ELEM(data)
#endif
#undef TEMPL_ELEM

// utilities
template <class A, class B> inline bool chmin(A &t, const B &f) { if (t > f) { t = f; return true; } return false; }
template <class A, class B> inline bool chmax(A &t, const B &f) { if (t < f) { t = f; return true; } return false; }
template <class C> inline void remdup(C &x) { sort(x.begin(), x.end()); x.erase(unique(x.begin(), x.end()), x.end()); }
template <class C> inline i64 isz(const C &x) { return static_cast<i64>(x.size()); }
template <typename I> struct __ { I &v_; explicit __(I &v) : v_{v} {} typename I::reverse_iterator begin() const { return v_.rbegin(); } typename I::reverse_iterator end() const { return v_.rend(); } };
template <typename I> __<I> rev(I &v) { return __<I>(v); }
template <class I> inline I maxelem(I f, I l) { return std::max_element(f, l); }
template <class I> inline I minelem(I f, I l) { return std::min_element(f, l); }

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
} // namespace std
void debug_out() { std::cerr << std::endl; } template <class Head, class... Tail> void debug_out(Head H, Tail... T) { std::cerr << " " << std::to_string(H); debug_out(T...); }
#define debug(...) std::cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#define err(...) fprintf(stderr, __VA_ARGS__)
#else
#define debug(...) "Goodbye."
#define err(...) "Don't find me."
#endif // LOCAL_DEFINE

// rng
#ifdef LOCAL_DEFINE
std::mt19937_64 rng(0703);
#else
std::mt19937_64 rng(std::chrono::steady_clock::now().time_since_epoch().count());
#endif // LOCAL_DEFINE
inline long long randrange(long long a, long long b) { return std::uniform_int_distribution<long long>(a, b)(rng); }

// hash map/set and idset
struct splitmix64_hash { static uint64_t splitmix64(uint64_t x) { x += 0x9e3779b97f4a7c15; x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9; x = (x ^ (x >> 27)) * 0x94d049bb133111eb; return x ^ (x >> 31); } size_t operator()(uint64_t x) const { static const uint64_t FIXED_RANDOM = std::chrono::steady_clock::now().time_since_epoch().count(); return splitmix64(x + FIXED_RANDOM); } };
#ifdef PB_DS_ASSOC_CNTNR_HPP
#warning "pbds used"
template <class T> using idset = __gnu_pbds::tree<T, __gnu_pbds::null_type, std::less<T>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;
// template <class T> using idmulset = __gnu_pbds::tree<T, __gnu_pbds::null_type, std::less_equal<T>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;
template <class K, class V, class Hash = splitmix64_hash> using hashmap = __gnu_pbds::gp_hash_table<K, V, Hash>;
template <class K, class Hash = splitmix64_hash> using hashset = hashmap<K, __gnu_pbds::null_type, Hash>;
#else
template <class K, class V> using hashmap = std::unordered_map<K, V, splitmix64_hash>;
template <class K> using hashset = std::unordered_set<K, splitmix64_hash>;
#endif // PB_DS_ASSOC_CNTNR_HPP

// multidimensional vector
template <class T, int D> struct dvec : public std::vector<dvec<T, D - 1>> { static_assert(D >= 1, "Vector dimension must be greater than zero!"); template <class... Args> dvec(int n, Args... args) : std::vector<dvec<T, D - 1>>(n, dvec<T, D - 1>(args...)) {} };
template <class T> struct dvec<T, 1> : public std::vector<T> { dvec(int n, const T &val = T()) : std::vector<T>(n, val) {} };

// modulo
#if ATCODER_MATH_HPP
// using imod = atcoder::modint998244353;
using imod = atcoder::modint1000000007;
#endif

// adjacent grid coords
// up upright right downright down downleft left upleft
constexpr int dx[] = {-1, -1,  0,  1,  1,  1,  0, -1};
constexpr int dy[] = { 0,  1,  1,  1,  0, -1, -1, -1};

// constants
constexpr db EPS = 1e-9;
constexpr int INF = 1e9;
constexpr i64 INF64 = 1e18;
// }}}
// end of template ====================================================

using namespace std;

constexpr int N = 3e5 + 5;

class Solver {
private:

public:
    void solve() {

    }
};


// initial run ========================================================
// will run ONCE only before solve(), regardless of MULTICASE
void initialRun() {

}
// end of initial run =================================================

// main ===============================================================
// {{{
signed main() {
#if FILEIO
#ifdef LOCAL_DEFINE
#warning "FILEIO ON"
#else
    freopen("${FILENAME}.inp", "r", stdin);
    freopen("${FILENAME}.out", "w", stdout);
#endif
#endif
    std::ios_base::sync_with_stdio(false);
#if not INTERACTIVE
    std::cin.tie(nullptr);
#endif
    std::cout << std::setprecision(12) << std::fixed;

    initialRun();

#if MULTICASE
#ifdef LOCAL_DEFINE
#warning "MULTICASE ON"
#endif
    int nTC; (std::cin >> nTC).ignore();
    for (int iTC = 0; iTC < nTC; iTC++) {
#endif
        // std::make_unique<Solver>()->solve();
        Solver solver; solver.solve();
#if MULTICASE
    }
#endif

    return 0;
}
// }}}
// end of main ========================================================
