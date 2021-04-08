/*
        Và em là ai?
        Là một đóa hoa đang nở
        Cùng mùi hương, cùng tình thương
        Của người yêu em...

        Và em là ai?
        Là một tiếng ca trong lòng cùng ai đó
        Cứ chạy theo dòng đời, chạy theo cuộc chơi
        Về nhau.
*/
#ifndef LOCAL_DEFINE
#pragma GCC optimize ("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target ("avx")
#endif

#include <bits/stdc++.h>

using i64 = long long;
using u64 = unsigned long long;

#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)

template <class A, class B> inline bool chmin(A &t, const B &f) { if (t > f) { t = f; return true; } return false; }
template <class A, class B> inline bool chmax(A &t, const B &f) { if (t < f) { t = f; return true; } return false; }
template <class C> inline long long length(const C &x) { return static_cast<long long>(x.size()); }
template <typename I> struct __ { I &v_; explicit __(I &v) : v_{v} {} typename I::reverse_iterator begin() const { return v_.rbegin(); } typename I::reverse_iterator end() const { return v_.rend(); } };
template <typename I> __<I> reversed(I &v) { return __<I>(v); }

constexpr double EPS = 1e-9;
constexpr int INF = 1e9;
constexpr i64 INF64 = 1e18;
constexpr int N = 3e5 + 5;

// ====*====*====*====*====*====*====*====*====*====*====*====*====*====*====*====*====*====

namespace Solution {

void solve() {

}

} // namespace Solution


signed main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int nTC; std::cin >> nTC;

    for (int iTC = 0; iTC < nTC; iTC++) {
        Solution::solve();
    }

    return 0;
}
