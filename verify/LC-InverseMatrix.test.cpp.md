---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: library/Math/Matrix.hpp
    title: "Matrix - \u884C\u5217\u6F14\u7B97"
  - icon: ':heavy_check_mark:'
    path: library/modint.hpp
    title: modint
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/inverse_matrix
    links:
    - https://judge.yosupo.jp/problem/inverse_matrix
  bundledCode: "#line 1 \"verify/LC-InverseMatrix.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/inverse_matrix\"\
    \n\n#line 2 \"library/modint.hpp\"\n/**\n * @file modint.hpp\n * @author log K\
    \ (lX57)\n * @brief modint\n * @version 1.0\n * @date 2023-08-24\n */\n\n#include\
    \ <bits/stdc++.h>\nusing namespace std;\n\nconst int mod998 = 998244353;\nconst\
    \ int mod107 = 1000000007;\n\ntemplate< int mod >\nstruct ModInt {\n    int x;\n\
    \n    ModInt() : x(0) {}\n\n    ModInt(int64_t y) : x(y >= 0 ? y % mod : (mod\
    \ - (-y) % mod) % mod) {}\n\n    ModInt &operator+=(const ModInt &p) {\n     \
    \   if((x += p.x) >= mod) x -= mod;\n        return *this;\n    }\n\n    ModInt\
    \ &operator-=(const ModInt &p) {\n        if((x += mod - p.x) >= mod) x -= mod;\n\
    \        return *this;\n    }\n\n    ModInt &operator*=(const ModInt &p) {\n \
    \       x = (int) (1LL * x * p.x % mod);\n        return *this;\n    }\n\n   \
    \ ModInt &operator/=(const ModInt &p) {\n        *this *= p.inverse();\n     \
    \   return *this;\n    }\n\n    ModInt operator-() const { return ModInt(-x);\
    \ }\n\n    ModInt operator+(const ModInt &p) const { return ModInt(*this) += p;\
    \ }\n\n    ModInt operator-(const ModInt &p) const { return ModInt(*this) -= p;\
    \ }\n\n    ModInt operator*(const ModInt &p) const { return ModInt(*this) *= p;\
    \ }\n\n    ModInt operator/(const ModInt &p) const { return ModInt(*this) /= p;\
    \ }\n\n    bool operator==(const ModInt &p) const { return x == p.x; }\n\n   \
    \ bool operator!=(const ModInt &p) const { return x != p.x; }\n\n    ModInt inverse()\
    \ const {\n        int a = x, b = mod, u = 1, v = 0, t;\n        while(b > 0)\
    \ {\n            t = a / b;\n            swap(a -= t * b, b);\n            swap(u\
    \ -= t * v, v);\n        }\n        return ModInt(u);\n    }\n\n    ModInt pow(int64_t\
    \ n) const {\n        if(n == 0) return ModInt(1);\n        ModInt ret(1), mul(x);\n\
    \        while(n > 0) {\n            if(n & 1) ret *= mul;\n            mul *=\
    \ mul;\n            n >>= 1;\n        }\n        return ret;\n    }\n\n    friend\
    \ ostream &operator<<(ostream &os, const ModInt &p) {\n        return os << p.x;\n\
    \    }\n\n    friend istream &operator>>(istream &is, ModInt &a) {\n        int64_t\
    \ t;\n        is >> t;\n        a = ModInt< mod >(t);\n        return (is);\n\
    \    }\n\n    static int get_mod() { return mod; }\n};\n\nusing modint998 = ModInt<\
    \ mod998 >;\nusing modint107 = ModInt< mod107 >;\n\nusing vm998 = vector< modint998\
    \ >;\nusing vvm998 = vector< vector< modint998 > >;\nusing vm107 = vector< modint107\
    \ >;\nusing vvm107 = vector< vector< modint107 > >;\n#line 1 \"library/Math/Matrix.hpp\"\
    \n/**\n * @file Matrix.hpp\n * @author log K (lX57)\n * @brief Matrix - \u884C\
    \u5217\u6F14\u7B97\n * @version 1.0\n * @date 2023-10-11\n */\n\n#line 10 \"library/Math/Matrix.hpp\"\
    \nusing namespace std;\n\ntemplate<typename T>\nstruct Matrix{\n    public:\n\
    \    vector<vector<T>> A;\n\n    Matrix(){}\n    Matrix(int N, int M) : A(N, vector<T>(M,\
    \ 0)){}\n    Matrix(int N) : A(N, vector<T>(N, 0)){}\n    Matrix(vector<vector<T>>\
    \ &Data) : A(Data){}\n\n    size_t Height() const {return A.size();}\n    size_t\
    \ Width() const {return A[0].size();}\n    size_t Size() const {assert(Height()\
    \ == Width()); return Height();}\n\n    vector<T> const &operator[](int k) const{\n\
    \        return (A.at(k));\n    }\n\n    vector<T> &operator[](int k){\n     \
    \   return (A.at(k));\n    }\n\n    Matrix<T> &operator+=(const Matrix<T> &R){\n\
    \        int N = Height(), M = Width();\n        assert(N == R.Height() && M ==\
    \ R.Width());\n        for(int i = 0; i < N; ++i)\n            for(int j = 0;\
    \ j < M; ++j)\n                (*this)[i][j] += R[i][j];\n        return (*this);\n\
    \    }\n    \n    Matrix<T> &operator-=(const Matrix<T> &R){\n        int N =\
    \ Height(), M = Width();\n        assert(N == R.Height() && M == R.Width());\n\
    \        for(int i = 0; i < N; ++i)\n            for(int j = 0; j < M; ++j)\n\
    \                (*this)[i][j] -= R[i][j];\n        return (*this);\n    }\n \
    \   \n    Matrix<T> &operator*=(const Matrix<T> &R){\n        int N = Height(),\
    \ M = R.Width(), L = Width();\n        assert(L == R.Height());\n        vector<vector<T>>\
    \ tmp(N, vector<T>(M, 0));\n        for(int i = 0; i < N; ++i)\n            for(int\
    \ j = 0; j < M; ++j)\n                for(int k = 0; k < L; ++k)\n           \
    \         tmp[i][j] += (*this)[i][k] * R[k][j];\n        A.swap(tmp);\n      \
    \  return (*this);\n    }\n\n    Matrix<T> operator*(const Matrix<T> &R){\n  \
    \      return (Matrix(*this) *= R);\n    }\n\n    friend ostream &operator<<(ostream\
    \ &os, Matrix &p){\n        int N = p.Height(), M = p.Width();\n        for(int\
    \ i = 0; i < N; ++i){\n            for(int j = 0; j < M; ++j){\n             \
    \   os << p[i][j] << (j + 1 == M ? \"\" : \" \");\n            }\n           \
    \ os << (i + 1 == N ? \"\" : \"\\n\");\n        }\n        return (os);\n    }\n\
    \n    void print(){\n        int N = Height(), M = Width();\n        cerr << \"\
    Matrix ===============================\\n\";\n        for(int i = 0; i < N; ++i){\n\
    \            cerr << \"[\";\n            for(int j = 0; j < M; ++j){\n       \
    \         cerr << A[i][j] << \" ]\"[j + 1 == M];\n            }\n            cerr\
    \ << endl;\n        }\n    }\n\n    T det() const {\n        Matrix<T> tmp(*this);\n\
    \        T ret = 1;\n        int N = Size();\n        int i = 0;\n        for(int\
    \ j = 0; i < N && j < N; ++j){\n            // cerr << \"i = \" << i << \", j\
    \ = \" << j << endl;\n            // tmp.print();\n            bool found = false;\n\
    \            for(int ti = i; ti < N && !found; ++ti){\n                // cerr\
    \ << \" - ti = \" << ti << \", val = \" << tmp[ti][j] << endl;\n             \
    \   if(tmp[ti][j] != 0){\n                    if(ti != i){\n                 \
    \       swap(tmp[ti], tmp[i]);\n                        ret *= -1;\n         \
    \           }\n                    // cerr << \" -  - OK\\n\";\n             \
    \       found = true;\n                }\n            }\n            if(!found)\
    \ return 0;\n            // tmp.print();\n            for(int ti = i + 1; ti <\
    \ N; ++ti){\n                if(tmp[ti][j] == 0) continue;\n                T\
    \ mul = tmp[ti][j] / tmp[i][j];\n                // cerr << \" - ti = \" << ti\
    \ << \", mul = \" << mul << endl;\n                for(int tj = j; tj < N; ++tj){\n\
    \                    // cerr << \" -  - tj = \" << tj << \", sub = \" << tmp[i][tj]\
    \ << \" * \" << mul << \" = \" << tmp[i][tj] * mul << endl;\n                \
    \    tmp[ti][tj] -= tmp[i][tj] * mul;\n                }\n            }\n    \
    \        ++i;\n        }\n        for(int i = 0; i < N; ++i) ret *= tmp[i][i];\n\
    \        return ret;\n    }\n\n    bool isRegular() const {\n        return (det()\
    \ != 0);\n    }\n\n    static Matrix<T> I(size_t N){\n        Matrix<T> ret(N);\n\
    \        for(int i = 0; i < N; ++i) ret[i][i] = 1;\n        return (ret);\n  \
    \  }\n\n    static Matrix<T> inv(const Matrix<T> &M){\n        assert(M.isRegular());\n\
    \        Matrix<T> tmp(M), ret = Matrix<T>::I(M.Size());\n        int N = M.Size();\n\
    \        int i = 0;\n        for(int j = 0; i < N && j < N; ++j){\n          \
    \  bool found = false;\n            for(int ti = i; ti < N && !found; ++ti){\n\
    \                if(tmp[ti][j] != 0){\n                    if(ti != i){\n    \
    \                    swap(tmp[ti], tmp[i]);\n                        swap(ret[ti],\
    \ ret[i]);\n                    }\n                    found = true;\n       \
    \         }\n            }\n            T div = tmp[i][j];\n            for(int\
    \ tj = 0; tj < N; ++tj) tmp[i][tj] /= div, ret[i][tj] /= div;\n            for(int\
    \ ti = 0; ti < N; ++ti){\n                if(ti == i || tmp[ti][j] == 0) continue;\n\
    \                T mul = tmp[ti][j];\n                for(int tj = 0; tj < N;\
    \ ++tj){\n                    tmp[ti][tj] -= tmp[i][tj] * mul;\n             \
    \       ret[ti][tj] -= ret[i][tj] * mul;\n                }\n            }\n \
    \           ++i;\n        }\n        return ret;\n    }\n};\n#line 5 \"verify/LC-InverseMatrix.test.cpp\"\
    \n\nint main(){\n    int N; cin >> N;\n    vvm998 a(N, vm998(N));\n    for(int\
    \ i = 0; i < N; ++i){\n        for(int j = 0; j < N; ++j){\n            cin >>\
    \ a[i][j];\n        }\n    }\n\n    Matrix<modint998> A(a);\n    if(A.isRegular()){\n\
    \        auto B = Matrix<modint998>::inv(A);\n        cout << B << endl;\n   \
    \ }\n    else{\n        cout << -1 << endl;\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/inverse_matrix\"\n\n#include\
    \ \"../library/modint.hpp\"\n#include \"../library/Math/Matrix.hpp\"\n\nint main(){\n\
    \    int N; cin >> N;\n    vvm998 a(N, vm998(N));\n    for(int i = 0; i < N; ++i){\n\
    \        for(int j = 0; j < N; ++j){\n            cin >> a[i][j];\n        }\n\
    \    }\n\n    Matrix<modint998> A(a);\n    if(A.isRegular()){\n        auto B\
    \ = Matrix<modint998>::inv(A);\n        cout << B << endl;\n    }\n    else{\n\
    \        cout << -1 << endl;\n    }\n}"
  dependsOn:
  - library/modint.hpp
  - library/Math/Matrix.hpp
  isVerificationFile: true
  path: verify/LC-InverseMatrix.test.cpp
  requiredBy: []
  timestamp: '2023-10-11 01:51:01+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/LC-InverseMatrix.test.cpp
layout: document
redirect_from:
- /verify/verify/LC-InverseMatrix.test.cpp
- /verify/verify/LC-InverseMatrix.test.cpp.html
title: verify/LC-InverseMatrix.test.cpp
---