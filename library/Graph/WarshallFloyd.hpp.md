---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: library/Graph/GraphTemplate.hpp
    title: "Graph Template - \u30B0\u30E9\u30D5\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/AOJ-GRL-1-C.test.cpp
    title: verify/AOJ-GRL-1-C.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "WarshallFloyd - \u5168\u70B9\u5BFE\u9593\u6700\u77ED\u7D4C\u8DEF"
    links: []
  bundledCode: "#line 1 \"library/Graph/WarshallFloyd.hpp\"\n/**\n * @file WarshallFloyd.hpp\n\
    \ * @author log_K (lX57)\n * @brief WarshallFloyd - \u5168\u70B9\u5BFE\u9593\u6700\
    \u77ED\u7D4C\u8DEF\n * @version 2.2\n * @date 2023-10-02\n */\n\n#line 2 \"library/Graph/GraphTemplate.hpp\"\
    \n\n/**\n * @file GraphTemplate.hpp\n * @author log K (lX57)\n * @brief Graph\
    \ Template - \u30B0\u30E9\u30D5\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8\n * @version\
    \ 2.2\n * @date 2023-10-02\n */\n\n#include <bits/stdc++.h>\nusing namespace std;\n\
    \nusing Vertex = int;\nusing EdgeID = int;\nusing EdgeIndex = int;\n\ntemplate<typename\
    \ CostType>\nstruct Edge{\n    EdgeID ID{-1};\n    Vertex src{-1}, to{-1};\n \
    \   CostType cost, cap;\n    EdgeIndex sidx, tidx;\n\n    Edge() = default;\n\
    \    Edge(EdgeID ID, Vertex src, Vertex to, CostType cost, CostType cap, EdgeIndex\
    \ sidx, EdgeIndex tidx) :\n        ID(ID), src(src), to(to), cost(cost), cap(cap),\
    \ sidx(sidx), tidx(tidx){}\n\n    void print(){\n        cerr << \"Edge \" <<\
    \ ID << \" : (\" << src << \" -> \" << to << \"), Cost = \" << cost << \", Capacity\
    \ = \" << cap << \", Place = [\" << sidx << \", \" << tidx << \"]\" << endl;\n\
    \    }\n};\n\ntemplate<typename CostType>\nusing EdgeSet = vector<Edge<CostType>>;\n\
    template<typename CostType>\nusing IncidentList = vector<vector<Edge<CostType>>>;\n\
    using AdjacentList = vector<vector<Vertex>>;\n\ntemplate<typename CostType>\n\
    struct Graph{\n    protected:\n    int __CntVertex, __CntEdge;\n    bool __isDirected;\n\
    \    EdgeSet<CostType> __ES, __RES;\n    IncidentList<CostType> __IL;\n    AdjacentList\
    \ __AL;\n\n    public:\n    CostType INF;\n\n    Graph(int VertexSize, bool isDirected\
    \ = false) : __CntVertex(VertexSize), __isDirected(isDirected), __CntEdge(0),\
    \ __IL(VertexSize), __AL(VertexSize), INF(numeric_limits<CostType>::max() / 2){}\n\
    \n    Graph() = default;\n\n    void add(Vertex Source, Vertex To, CostType Cost\
    \ = 1){\n        assert(0 <= Source && Source < __CntVertex);\n        assert(0\
    \ <= To && To < __CntVertex);\n        EdgeIndex sidx = __IL[Source].size(), tidx\
    \ = __IL[To].size();\n        Edge<CostType> es{__CntEdge, Source, To, Cost, 1,\
    \ sidx, tidx};\n        Edge<CostType> et{__CntEdge, To, Source, Cost, 1, tidx,\
    \ sidx};\n        __ES.push_back(es);\n        __RES.push_back(et);\n        __IL[Source].push_back(es),\
    \ __AL[Source].push_back(To);\n        if(!__isDirected) __IL[To].push_back(et),\
    \ __AL[To].push_back(Source);\n        ++__CntEdge;\n    }\n\n    vector<vector<CostType>>\
    \ matrix(CostType NotAdjacent = numeric_limits<CostType>::max() / 2){\n      \
    \  vector ret(__CntVertex, vector(__CntVertex, NotAdjacent));\n        for(Vertex\
    \ v = 0; v < __CntVertex; ++v){\n            ret[v][v] = 0;\n            for(auto\
    \ e : __IL[v]){\n                ret[v][e.to] = e.cost;\n            }\n     \
    \   }\n        return ret;\n    }\n\n    inline int vsize(){\n        return __CntVertex;\n\
    \    }\n\n    inline int esize(){\n        return __CntEdge;\n    }\n\n    inline\
    \ int incsize(Vertex v){\n        return __IL[v].size();\n    }\n\n    bool directed(){\n\
    \        return __isDirected;\n    }\n\n    inline EdgeSet<CostType> &get_edgeset(){\n\
    \        return __ES;\n    }\n\n    inline IncidentList<CostType> &get_incidentlist(){\n\
    \        return __IL;\n    }\n\n    inline vector<Edge<CostType>> &get_incident(Vertex\
    \ v){\n        assert(0 <= v && v < __CntVertex);\n        return __IL[v];\n \
    \   }\n\n    inline AdjacentList &get_adjacentlist(){\n        return __AL;\n\
    \    }\n\n    inline vector<Vertex> &get_adjacent(Vertex v){\n        assert(0\
    \ <= v && v < __CntVertex);\n        return __AL[v];\n    }\n\n    vector<Edge<CostType>>\
    \ operator[](Vertex v){\n        return get_incident(v);\n    }\n\n    void print_edgeset(bool\
    \ OneIndex = true){\n        for(int e = 0; e < __CntEdge; ++e){\n           \
    \ cout << e + OneIndex << \" : (\" << __ES[e].from + OneIndex << (__isDirected\
    \ ? \" -> \" : \" <-> \") << __ES[e].to + OneIndex << \") = \" << __ES[e].cost\
    \ << \" (\" << __ES[e].cap << \")\" << endl;\n        }\n    }\n\n    void print_incidentlist(bool\
    \ OneIndex = true){\n        for(int i = 0; i < __CntVertex; ++i){\n         \
    \   cout << i + OneIndex << \" :\";\n            for(int j = 0; j < __IL[i].size();\
    \ ++j){\n                cout << \" (\" << __IL[i][j].to << \" / \" << __IL[i][j].cost\
    \ << \", \" << __IL[i][j].cap << \")\";\n            }\n            cout << endl;\n\
    \        }\n    }\n\n    void print_matrix(CostType NotAdjacent = numeric_limits<CostType>::max()\
    \ / 2, bool DisplayINF = true){\n        auto mat = matrix(NotAdjacent);\n   \
    \     for(int i = 0; i < __CntVertex; ++i){\n            cout << (DisplayINF &&\
    \ mat[i][0] == NotAdjacent ? \"INF\" : to_string(mat[i][0]));\n            for(int\
    \ j = 1; j < __CntVertex; ++j){\n                cout << \" \" << (DisplayINF\
    \ && mat[i][j] == NotAdjacent ? \"INF\" : to_string(mat[i][j]));\n           \
    \ }\n            cout << endl;\n        }\n    }\n};\n#line 10 \"library/Graph/WarshallFloyd.hpp\"\
    \n\ntemplate<typename CostType>\nstruct WarshallFloyd{\n    private:\n    bool\
    \ __NegativeCycle;\n    int __Size;\n    CostType __INF;\n    vector<vector<CostType>>\
    \ __Dist;\n\n    void __solve(){\n        for(int k = 0; k < __Size; ++k){\n \
    \           for(int i = 0; i < __Size; ++i){\n                for(int j = 0; j\
    \ < __Size; ++j){\n                    if(__Dist[i][k] == __INF || __Dist[k][j]\
    \ == __INF) continue;\n                    __Dist[i][j] = min(__Dist[i][j], __Dist[i][k]\
    \ + __Dist[k][j]);\n                }\n            }\n        }\n        __NegativeCycle\
    \ = false;\n        for(int i = 0; i < __Size; ++i) __NegativeCycle |= __Dist[i][i]\
    \ < 0;\n    }\n\n    public:\n    WarshallFloyd(Graph<CostType> &G) : __Size(G.vsize()),\
    \ __INF(G.INF), __Dist(G.matrix()){\n        __solve();\n    }\n\n    WarshallFloyd(vector<vector<CostType>>\
    \ &M) : __Size((int)M.size()), __INF(numeric_limits<CostType>::max() / 2), __Dist(M){\n\
    \        __solve();\n    }\n\n    inline bool negative(){\n        return __NegativeCycle;\n\
    \    }\n\n    CostType dist(Vertex Start, Vertex Goal){\n        assert(0 <= Start\
    \ && Start < __Size);\n        assert(0 <= Goal && Goal < __Size);\n        return\
    \ __Dist[Start][Goal];\n    }\n    \n    void print(CostType NotAdjacent = numeric_limits<CostType>::max()\
    \ / 2, bool DisplayINF = true){\n        for(int i = 0; i < __Size; ++i){\n  \
    \          cout << (DisplayINF && __Dist[i][0] == NotAdjacent ? \"INF\" : to_string(__Dist[i][0]));\n\
    \            for(int j = 1; j < __Size; ++j){\n                cout << \" \" <<\
    \ (DisplayINF && __Dist[i][j] == NotAdjacent ? \"INF\" : to_string(__Dist[i][j]));\n\
    \            }\n            cout << endl;\n        }\n    }\n};\n"
  code: "/**\n * @file WarshallFloyd.hpp\n * @author log_K (lX57)\n * @brief WarshallFloyd\
    \ - \u5168\u70B9\u5BFE\u9593\u6700\u77ED\u7D4C\u8DEF\n * @version 2.2\n * @date\
    \ 2023-10-02\n */\n\n#include \"GraphTemplate.hpp\"\n\ntemplate<typename CostType>\n\
    struct WarshallFloyd{\n    private:\n    bool __NegativeCycle;\n    int __Size;\n\
    \    CostType __INF;\n    vector<vector<CostType>> __Dist;\n\n    void __solve(){\n\
    \        for(int k = 0; k < __Size; ++k){\n            for(int i = 0; i < __Size;\
    \ ++i){\n                for(int j = 0; j < __Size; ++j){\n                  \
    \  if(__Dist[i][k] == __INF || __Dist[k][j] == __INF) continue;\n            \
    \        __Dist[i][j] = min(__Dist[i][j], __Dist[i][k] + __Dist[k][j]);\n    \
    \            }\n            }\n        }\n        __NegativeCycle = false;\n \
    \       for(int i = 0; i < __Size; ++i) __NegativeCycle |= __Dist[i][i] < 0;\n\
    \    }\n\n    public:\n    WarshallFloyd(Graph<CostType> &G) : __Size(G.vsize()),\
    \ __INF(G.INF), __Dist(G.matrix()){\n        __solve();\n    }\n\n    WarshallFloyd(vector<vector<CostType>>\
    \ &M) : __Size((int)M.size()), __INF(numeric_limits<CostType>::max() / 2), __Dist(M){\n\
    \        __solve();\n    }\n\n    inline bool negative(){\n        return __NegativeCycle;\n\
    \    }\n\n    CostType dist(Vertex Start, Vertex Goal){\n        assert(0 <= Start\
    \ && Start < __Size);\n        assert(0 <= Goal && Goal < __Size);\n        return\
    \ __Dist[Start][Goal];\n    }\n    \n    void print(CostType NotAdjacent = numeric_limits<CostType>::max()\
    \ / 2, bool DisplayINF = true){\n        for(int i = 0; i < __Size; ++i){\n  \
    \          cout << (DisplayINF && __Dist[i][0] == NotAdjacent ? \"INF\" : to_string(__Dist[i][0]));\n\
    \            for(int j = 1; j < __Size; ++j){\n                cout << \" \" <<\
    \ (DisplayINF && __Dist[i][j] == NotAdjacent ? \"INF\" : to_string(__Dist[i][j]));\n\
    \            }\n            cout << endl;\n        }\n    }\n};"
  dependsOn:
  - library/Graph/GraphTemplate.hpp
  isVerificationFile: false
  path: library/Graph/WarshallFloyd.hpp
  requiredBy: []
  timestamp: '2023-11-21 13:10:32+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/AOJ-GRL-1-C.test.cpp
documentation_of: library/Graph/WarshallFloyd.hpp
layout: document
title: "Warshall Floyd - \u5168\u70B9\u5BFE\u9593\u6700\u77ED\u8DDD\u96E2"
---

<script type="text/javascript" async src="https://cdnjs.cloudflare.com/ajax/libs/mathjax/2.7.7/MathJax.js?config=TeX-MML-AM_CHTML">
</script>
<script type="text/x-mathjax-config">
 MathJax.Hub.Config({
 tex2jax: {
 inlineMath: [['$', '$'] ],
 displayMath: [ ['$$','$$'], ["\\[","\\]"] ]
 }
 });
</script>

## Abstract

全点対間最短距離問題をWarshall Floyd法を用いて求める。

## Variable

- private
    - `NegativeCycle` : 負の閉路が存在するか
    - `Size` : 頂点数
    - `Dist` : 隣接行列形式で表された最短距離。`Dist[i][j]`は頂点`i`から頂点`j`への最短距離を表している。

## Function

- `WarshallFloyd(Graph G)` : `Graph` で初期化し、全点対間最短距離問題を解く。$O(V^3)$
- `WarshallFloyd(vector<vector<CostType>> M)` : 隣接行列 `M` で初期化し、全点対間最短距離問題を解く。$O(V^3)$
- `negative()` : 負閉路を含むかを返す。
- `dist(Vertex Start, Vertex Goal)` : 頂点 `Start` から頂点 `Goal` への最短距離を返す。$O(1)$
- `print(CostType NotAdjacent, bool DisplayINF)` : 隣接行列を出力する。隣接していない頂点への距離を `INF` として表示することも可能。$O(V^2)$