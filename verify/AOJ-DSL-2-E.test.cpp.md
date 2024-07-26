---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: library/DataStructure/DualSegmentTree.hpp
    title: "Dual Segment Tree - \u53CC\u5BFE\u30BB\u30B0\u30E1\u30F3\u30C8\u6728"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_E
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_E
  bundledCode: "#line 1 \"verify/AOJ-DSL-2-E.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_E\"\
    \n\n#line 1 \"library/DataStructure/DualSegmentTree.hpp\"\n/**\n * @file DualSegmentTree.hpp\n\
    \ * @author log K (lX57)\n * @brief Dual Segment Tree - \u53CC\u5BFE\u30BB\u30B0\
    \u30E1\u30F3\u30C8\u6728\n * @version 1.0\n * @date 2023-11-08\n */\n\n#include\
    \ <bits/stdc++.h>\nusing namespace std;\n\ntemplate<typename OperatorMonoid>\n\
    struct DualSegmentTree{\n    private:\n    using H = function<OperatorMonoid(OperatorMonoid,\
    \ OperatorMonoid)>;\n\n    int size_, offset_, zeroindex_;\n    vector<OperatorMonoid>\
    \ lazy_;\n    const H h;\n    const OperatorMonoid om1_;\n\n    inline void check_(int\
    \ x){\n        assert(1 <= x && x <= size_);\n    }\n\n    void eval_(int k){\n\
    \        if(lazy_[k] == om1_) return;\n        if(k < size_){\n            lazy_[k\
    \ * 2 + 0] = h(lazy_[k * 2 + 0], lazy_[k]);\n            lazy_[k * 2 + 1] = h(lazy_[k\
    \ * 2 + 1], lazy_[k]);\n            lazy_[k] = om1_;\n        }\n    }\n\n   \
    \ void update_(int ul, int ur, OperatorMonoid x, int left, int right, int cell){\n\
    \        eval_(cell);\n        if(ul <= left && right <= ur){\n            lazy_[cell]\
    \ = h(lazy_[cell], x);\n            eval_(cell);\n        }\n        else if(ul\
    \ < right && left < ur){\n            int mid = (left + right) / 2;\n        \
    \    update_(ul, ur, x, left, mid, cell * 2 + 0);\n            update_(ul, ur,\
    \ x, mid, right, cell * 2 + 1);\n        }\n    }\n    \n    OperatorMonoid query_(int\
    \ k, int left, int right, int cell){\n        eval_(cell);\n        if(k == left\
    \ && right - left == 1) return lazy_[cell];\n        int mid = (left + right)\
    \ / 2;\n        if(k < mid) return query_(k, left, mid, cell * 2 + 0);\n     \
    \   else return query_(k, mid, right, cell * 2 + 1);\n    }\n\n    public:\n \
    \   /**\n     * @brief \u53CC\u5BFE\u30BB\u30B0\u30E1\u30F3\u30C8\u6728\u3092\u8981\
    \u7D20\u6570 `Size` \u3067\u521D\u671F\u5316\u3059\u308B\u3002\n     * @param\
    \ Size \u53CC\u5BFE\u30BB\u30B0\u30E1\u30F3\u30C8\u6728\u306E\u8981\u7D20\u6570\
    \n     * @param Composite \u9045\u5EF6\u8A55\u4FA1\u306E\u5408\u6210\u3092\u884C\
    \u3046\u6F14\u7B97\n     * @param OperatorMonoid_Identity \u64CD\u4F5C\u30E2\u30CE\
    \u30A4\u30C9\u306E\u5358\u4F4D\u5143\n     * @param ZeroIndex 0-index\u3068\u3057\
    \u3066\u6271\u3044\u305F\u3044\u304B (default = `false`)\n     */\n    DualSegmentTree(int\
    \ Size, H Composite,\n    const OperatorMonoid &OperatorMonoid_Identity, bool\
    \ ZeroIndex = false)\n    : h(Composite), om1_(OperatorMonoid_Identity), zeroindex_(ZeroIndex){\n\
    \        size_ = 1;\n        while(size_ < Size) size_ <<= 1;\n        offset_\
    \ = size_ - 1;\n        lazy_.resize(2 * size_, om1_);\n    }\n    \n    /**\n\
    \     * @brief \u53CC\u5BFE\u30BB\u30B0\u30E1\u30F3\u30C8\u6728\u3092\u8981\u7D20\
    \u6570 `Size` \u3067\u521D\u671F\u5316\u3059\u308B\u3002\n     * @param Init_Data\
    \ \u521D\u671F\u30C7\u30FC\u30BF\u306E\u914D\u5217\n     * @param Composite \u9045\
    \u5EF6\u8A55\u4FA1\u306E\u5408\u6210\u3092\u884C\u3046\u6F14\u7B97\n     * @param\
    \ OperatorMonoid_Identity \u64CD\u4F5C\u30E2\u30CE\u30A4\u30C9\u306E\u5358\u4F4D\
    \u5143\n     * @param ZeroIndex 0-index\u3068\u3057\u3066\u6271\u3044\u305F\u3044\
    \u304B (default = `false`)\n     */\n    DualSegmentTree(vector<OperatorMonoid>\
    \ &Init_Data, H Composite,\n    const OperatorMonoid &OperatorMonoid_Identity,\
    \ bool ZeroIndex = false)\n    : h(Composite), om1_(OperatorMonoid_Identity),\
    \ zeroindex_(ZeroIndex){\n        size_ = 1;\n        while(size_ < (int)Init_Data.size())\
    \ size_ <<= 1;\n        offset_ = size_ - 1;\n        lazy_.resize(2 * size_,\
    \ om1_);\n        for(int i = 0; i < (int)Init_Data.size(); ++i){\n          \
    \  lazy_[size_ + i] = Init_Data[i];\n        }\n    }\n\n    /**\n     * @brief\
    \ \u534A\u958B\u533A\u9593 `[Left, Right)` \u306B\u5BFE\u3057\u3066\u533A\u9593\
    \u66F4\u65B0\u30AF\u30A8\u30EA\u3092\u51E6\u7406\u3059\u308B\u3002\n     * @param\
    \ Left \u534A\u958B\u533A\u9593\u306E\u5DE6\u7AEF\n     * @param Right \u534A\u958B\
    \u533A\u9593\u306E\u53F3\u7AEF\n     * @param OP \u66F4\u65B0\u64CD\u4F5C\n  \
    \   */\n    void update(int Left, int Right, OperatorMonoid OP){\n        check_(Left\
    \ + zeroindex_);\n        check_(Right + zeroindex_ - 1);\n        update_(Left\
    \ + zeroindex_, Right + zeroindex_, OP, 1, size_ + 1, 1);\n    }\n\n    /**\n\
    \     * @brief \u8981\u7D20\u756A\u53F7 `k` \u306E\u8981\u7D20\u3092\u53D6\u5F97\
    \u3059\u308B\u3002\n     * @param k \u53D6\u5F97\u5148\u306E\u8981\u7D20\u756A\
    \u53F7 (default = 1-index)\n     * @return OperatorMonoid \u53D6\u5F97\u3057\u305F\
    \u7D50\u679C\n     */\n    OperatorMonoid query(int k){\n        check_(k + zeroindex_);\n\
    \        return query_(k + zeroindex_, 1, size_ + 1, 1);\n    }\n\n    OperatorMonoid\
    \ operator[](const int &k){\n        return query(k);\n    }\n};\n#line 4 \"verify/AOJ-DSL-2-E.test.cpp\"\
    \n\nint main(){\n    int n, q; cin >> n >> q;\n    vector<long long> Init_Data(n,\
    \ 0);\n    DualSegmentTree<long long> seg(Init_Data,\n        [&](long long l,\
    \ long long r){return l + r;},\n        0);\n    while(q--){\n        int query;\
    \ cin >> query;\n        if(query == 0){\n            long long s, t, x; cin >>\
    \ s >> t >> x;\n            seg.update(s, t + 1, x);\n        }\n        else{\n\
    \            int i; cin >> i;\n            cout << seg[i] << endl;\n        }\n\
    \    }\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_E\"\
    \n\n#include \"../library/DataStructure/DualSegmentTree.hpp\"\n\nint main(){\n\
    \    int n, q; cin >> n >> q;\n    vector<long long> Init_Data(n, 0);\n    DualSegmentTree<long\
    \ long> seg(Init_Data,\n        [&](long long l, long long r){return l + r;},\n\
    \        0);\n    while(q--){\n        int query; cin >> query;\n        if(query\
    \ == 0){\n            long long s, t, x; cin >> s >> t >> x;\n            seg.update(s,\
    \ t + 1, x);\n        }\n        else{\n            int i; cin >> i;\n       \
    \     cout << seg[i] << endl;\n        }\n    }\n}"
  dependsOn:
  - library/DataStructure/DualSegmentTree.hpp
  isVerificationFile: true
  path: verify/AOJ-DSL-2-E.test.cpp
  requiredBy: []
  timestamp: '2024-04-29 18:47:07+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/AOJ-DSL-2-E.test.cpp
layout: document
redirect_from:
- /verify/verify/AOJ-DSL-2-E.test.cpp
- /verify/verify/AOJ-DSL-2-E.test.cpp.html
title: verify/AOJ-DSL-2-E.test.cpp
---