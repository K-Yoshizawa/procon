---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: icpc/HeavyLightDecomposition.hpp
    title: icpc/HeavyLightDecomposition.hpp
  - icon: ':heavy_check_mark:'
    path: icpc/Template.hpp
    title: icpc/Template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/5/GRL_5_C
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/5/GRL_5_C
  bundledCode: "#line 1 \"verify_icpc/AOJ-GRL-5-C.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/5/GRL_5_C\"\
    \n\n#line 2 \"icpc/Template.hpp\"\n\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\n\nusing ll = long long;\nusing vi = vector<int>;\nusing vl = vector<ll>;\n\
    using vvi = vector<vi>;\nusing vvl = vector<vl>;\nusing pi = pair<int, int>;\n\
    #line 2 \"icpc/HeavyLightDecomposition.hpp\"\n\nusing Edge = pair<int, ll>;\n\
    using Graph = vector<vector<Edge>>;\n\nstruct hld{\n    Graph &G;\n    vi subtree,\
    \ depth, ofs, pv;\n\n    int timer = 1;\n    vi in, out;\n    \n    vvi column;\n\
    \    vector<pi> loc;\n\n    int dfs1(int v, int p){\n        int ret = 0;\n  \
    \      for(auto [to, cost] : G[v]){\n            if(to == p) continue;\n     \
    \       depth[to] = depth[v] + 1;\n            pv[to] = v;\n            ret +=\
    \ dfs1(to, v);\n        }\n        return subtree[v] = ret + 1;\n    }\n\n   \
    \ void dfs2(int v, int p, int c){\n        in[v] = timer++;\n        if(column.size()\
    \ == c) column.emplace_back(vi{});\n        loc[v] = {c, column[c].size()};\n\
    \        column[c].push_back(v);\n        Edge heavy;\n        int mst = 0;\n\
    \        for(auto [to, cost] : G[v]){\n            if(to == p) continue;\n   \
    \         if(mst < subtree[to]){\n                heavy = {to, cost};\n      \
    \          mst = subtree[to];\n            }\n        }\n        if(mst) dfs2(heavy.first,\
    \ v, c);\n        for(auto [to, cost] : G[v]){\n            if(to == p or to ==\
    \ heavy.first) continue;\n            dfs2(to, v, column.size());\n        }\n\
    \        out[v] = timer++;\n    }\n\n    int head(int v){\n        auto [i, j]\
    \ = loc[v];\n        return column[i][0];\n    }\n\n    hld(Graph &G) : G(G){\n\
    \        int V = G.size();\n        subtree.resize(V, 0);\n        depth.resize(V,\
    \ 0);\n        pv.resize(V, -1);\n        dfs1(0, -1);\n        loc.resize(V);\n\
    \        in.resize(V);\n        out.resize(V);\n        dfs2(0, -1, 0);\n    \
    \    ofs.resize(column.size(), 1);\n        for(int i = 1; i < column.size();\
    \ ++i){\n            ofs[i] = ofs[i - 1] + column[i - 1].size();\n        }\n\
    \    }\n\n    vi location(){\n        vi ret(G.size(), -1);\n        for(int i\
    \ = 0; i < G.size(); ++i){\n            ret[i] = ofs[loc[i].first] + loc[i].second;\n\
    \        }\n        return ret;\n    }\n\n    int lca(int u, int v){\n       \
    \ while(1){\n            int hu = head(u), hv = head(v);\n            if(depth[hu]\
    \ > depth[hv]) swap(u, v), swap(hu, hv);\n            if(hu == hv) return (depth[u]\
    \ < depth[v] ? u : v);\n            v = pv[hv];\n        }\n    }\n\n    vector<pi>\
    \ pathquery(int u, int v = 0){\n        vector<pi> ret;\n        while(1){\n \
    \           int hu = head(u), hv = head(v);\n            if(depth[hu] > depth[hv])\
    \ swap(u, v), swap(hu, hv);\n            if(hu == hv){\n                if(depth[u]\
    \ > depth[v]) swap(u, v);\n                auto [uc, ui] = loc[u];\n         \
    \       auto [vc, vi] = loc[v];\n                ret.push_back({ofs[uc] + ui,\
    \ ofs[vc] + vi + 1});\n                return ret;\n            }\n          \
    \  auto [vc, vi] = loc[v];\n            ret.push_back({ofs[vc], ofs[vc] + vi +\
    \ 1});\n            v = pv[hv];\n        }\n    }\n\n    pi subtreequery(int v){\n\
    \        return {in[v], out[v]};\n    }\n};\n#line 4 \"verify_icpc/AOJ-GRL-5-C.test.cpp\"\
    \n\nint main(){\n    int n; cin >> n;\n    Graph G(n);\n    for(int i = 0; i <\
    \ n; ++i){\n        int k; cin >> k;\n        for(int j = 0; j < k; ++j){\n  \
    \          int c; cin >> c;\n            G[i].push_back({c, 1});\n           \
    \ G[c].push_back({i, 1});\n        }\n    }\n\n    hld HLD(G);\n    int q; cin\
    \ >> q;\n    for(int i = 0; i < q; ++i){\n        int u, v; cin >> u >> v;\n \
    \       cout << HLD.lca(u, v) << endl;\n    }\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/5/GRL_5_C\"\
    \n\n#include \"../icpc/HeavyLightDecomposition.hpp\"\n\nint main(){\n    int n;\
    \ cin >> n;\n    Graph G(n);\n    for(int i = 0; i < n; ++i){\n        int k;\
    \ cin >> k;\n        for(int j = 0; j < k; ++j){\n            int c; cin >> c;\n\
    \            G[i].push_back({c, 1});\n            G[c].push_back({i, 1});\n  \
    \      }\n    }\n\n    hld HLD(G);\n    int q; cin >> q;\n    for(int i = 0; i\
    \ < q; ++i){\n        int u, v; cin >> u >> v;\n        cout << HLD.lca(u, v)\
    \ << endl;\n    }\n}"
  dependsOn:
  - icpc/HeavyLightDecomposition.hpp
  - icpc/Template.hpp
  isVerificationFile: true
  path: verify_icpc/AOJ-GRL-5-C.test.cpp
  requiredBy: []
  timestamp: '2023-11-24 19:51:17+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify_icpc/AOJ-GRL-5-C.test.cpp
layout: document
redirect_from:
- /verify/verify_icpc/AOJ-GRL-5-C.test.cpp
- /verify/verify_icpc/AOJ-GRL-5-C.test.cpp.html
title: verify_icpc/AOJ-GRL-5-C.test.cpp
---