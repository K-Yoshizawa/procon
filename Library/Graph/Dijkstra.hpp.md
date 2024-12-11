---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Library/Common.hpp
    title: Library/Common.hpp
  - icon: ':heavy_check_mark:'
    path: Library/Graph/Graph.hpp
    title: "Graph - \u30B0\u30E9\u30D5\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/AOJ-GRL-1-A.test.cpp
    title: verify/AOJ-GRL-1-A.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "Dijkstra - \u30C0\u30A4\u30AF\u30B9\u30C8\u30E9\u6CD5"
    links: []
  bundledCode: "#line 1 \"Library/Graph/Dijkstra.hpp\"\n/**\n * @file Dijkstra.hpp\n\
    \ * @brief Dijkstra - \u30C0\u30A4\u30AF\u30B9\u30C8\u30E9\u6CD5\n * @version\
    \ 4.0\n * @date 2024-09-01\n */\n\n#line 2 \"Library/Graph/Graph.hpp\"\n\n/**\n\
    \ * @file Graph.hpp\n * @brief Graph - \u30B0\u30E9\u30D5\u30C6\u30F3\u30D7\u30EC\
    \u30FC\u30C8\n * @version 1.0\n * @date 2024-09-01\n */\n\n#line 2 \"Library/Common.hpp\"\
    \n\n/**\n * @file Common.hpp\n */\n\n#include <algorithm>\n#include <array>\n\
    #include <bitset>\n#include <cassert>\n#include <cstdint>\n#include <deque>\n\
    #include <functional>\n#include <iomanip>\n#include <iostream>\n#include <limits>\n\
    #include <map>\n#include <numeric>\n#include <queue>\n#include <set>\n#include\
    \ <stack>\n#include <string>\n#include <tuple>\n#include <utility>\n#include <vector>\n\
    using namespace std;\n#line 11 \"Library/Graph/Graph.hpp\"\n\nusing Vertex = int;\n\
    \ntemplate<typename CostType>\nstruct Edge{\n    Edge() = default;\n    Edge(int\
    \ from, int to, CostType cost, int id = -1) : from(from), to(to), cost(cost),\
    \ id(id){}\n\t\n    int from{-1}, to{-1}, id{-1};\n    CostType cost{1};\n};\n\
    \ntemplate<typename CostType = int32_t>\nclass Graph{\n    public:\n    Graph()\
    \ = default;\n\n    /**\n     * @brief \u9802\u70B9\u6570 `vertex_size` \u306E\
    \u30B0\u30E9\u30D5\u3092\u69CB\u7BC9\u3059\u308B\u3002\n     * @param vertex_size\
    \ \u9802\u70B9\u6570\n     * @param directed `true` \u306E\u5834\u5408\u3001\u6709\
    \u5411\u30B0\u30E9\u30D5\u3068\u3057\u3066\u69CB\u7BC9\u3059\u308B `(default =\
    \ false)`\n     */\n    Graph(int vertex_size, bool directed = false) : \n   \
    \     vertex_(vertex_size), adjacent_list_(vertex_size),\n        directed_flag_(directed){}\n\
    \n    /**\n     * @brief \u30B0\u30E9\u30D5 G \u306E\u9802\u70B9\u6570\u3092\u53D6\
    \u5F97\u3059\u308B\u3002\n     * @return size_t \u30B0\u30E9\u30D5 G \u306E\u9802\
    \u70B9\u6570\n     */\n    size_t get_vertex_size() const {\n        return vertex_;\n\
    \    }\n\n    /**\n     * @brief \u30B0\u30E9\u30D5 G \u306E\u8FBA\u6570\u3092\
    \u53D6\u5F97\u3059\u308B\u3002\n     * @return size_t \u30B0\u30E9\u30D5 G \u306E\
    \u8FBA\u6570\n     */\n    size_t get_edge_size() const {\n        return edge_;\n\
    \    }\n\n    /**\n     * @brief \u30B0\u30E9\u30D5 G \u306B\u5BFE\u3059\u308B\
    \u5341\u5206\u5927\u304D\u306A\u5024(`INF`)\u3092\u53D6\u5F97\u3059\u308B\u3002\
    \n     * @note `numeric_limits<CostType>::max() / 4` \u3092\u63A1\u7528\u3057\u3066\
    \u3044\u308B\u3002\n     * @return CostType `INF`\n     */\n    CostType get_inf()\
    \ const {\n        return inf_;\n    }\n\n    /**\n     * @brief 2\u9802\u70B9\
    \ `s` `t` \u9593\u306B\u91CD\u307F `c` \u306E\u8FBA\u3092\u5F35\u308B\u3002\u6709\
    \u5411\u30B0\u30E9\u30D5\u306E\u5834\u5408\u306F `s` \u304B\u3089 `t` \u3078\u306E\
    \u6709\u5411\u8FBA\u304C\u3001\u7121\u5411\u30B0\u30E9\u30D5\u306E\u5834\u5408\
    \u306F `s` `t` \u9593\u306E\u7121\u5411\u8FBA\u304C\u5F35\u3089\u308C\u308B\u3002\
    \n     * @param s \u59CB\u70B9\u306E\u9802\u70B9(\u6709\u5411\u8FBA)\n     * @param\
    \ t \u7D42\u70B9\u306E\u9802\u70B9(\u6709\u5411\u8FBA)\n     * @param c \u91CD\
    \u307F `(default = 1)`\n     * @param id \u8FBA\u306E\u756A\u53F7\u3092\u660E\u793A\
    \u7684\u306B\u6307\u5B9A\u3059\u308B `(default = -1)`\n     */\n    void AddEdge(Vertex\
    \ s, Vertex t, CostType c = 1, int id = -1){\n        Validate(s);\n        Validate(t);\n\
    \        int edge_id = edge_++;\n        if(id != -1) edge_id = id;\n        adjacent_list_[s].push_back(Edge(s,\
    \ t, c, edge_id));\n        if(!directed_flag_){\n            adjacent_list_[t].push_back(Edge(t,\
    \ s, c, edge_id));\n        }\n    }\n\n    /**\n     * @brief \u30B0\u30E9\u30D5\
    \u306B\u6307\u5B9A\u3057\u305F\u8FBA\u6570\u306E\u60C5\u5831\u3092\u5165\u529B\
    \u3059\u308B\u3002\n     * @note \u5165\u529B\u5F62\u5F0F\u304C `u v w` \u307E\
    \u305F\u306F `u v` \u306E\u5F62\u5F0F\u3067\u8868\u3055\u308C\u308B\u5165\u529B\
    \u5F62\u5F0F\u306B\u5BFE\u5FDC\u3057\u3066\u3044\u308B\u3002\n     * @param edge_count\
    \ \u8FBA\u6570 E\n     * @param weighted_graph \u91CD\u307F\u4ED8\u304D\u8FBA\u3067\
    \u3042\u308B\u304B `(default = true)`\n     * @param one_index \u9802\u70B9\u304C\
    1-index\u3067\u3042\u308B\u304B `(default = true)`\n     */\n    void InputGraph(int\
    \ edge_count, bool weighted_graph = true, bool one_index = true){\n        for(int\
    \ i = 0; i < edge_count; ++i){\n            int s, t; cin >> s >> t;\n       \
    \     if(one_index) --s, --t;\n            CostType w = 1;\n            if(weighted_graph)\
    \ cin >> w;\n            AddEdge(s, t, w);\n        }\n    }\n\n    vector<Edge<CostType>>\
    \ &operator[](Vertex v){\n        return adjacent_list_[v];\n    }\n\n    const\
    \ vector<Edge<CostType>> &operator[](Vertex v) const {\n        return adjacent_list_[v];\n\
    \    }\n\n    inline void Validate(int vertex) const {\n        assert(0 <= vertex\
    \ && vertex < vertex_);\n    }\n\n    private:\n    size_t vertex_{0}, edge_{0};\n\
    \    vector<vector<Edge<CostType>>> adjacent_list_;\n\n    bool directed_flag_;\n\
    \    CostType inf_{numeric_limits<CostType>::max() / 4};\n};\n\n/**\n * @brief\
    \ \u30B0\u30E9\u30D5\u306E\u96A3\u63A5\u884C\u5217\u3092\u8FD4\u3059\u3002\n *\
    \ @note verify : https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/11/ALDS1_11_A\n\
    \ * @note \u8A08\u7B97\u91CF : O(V + E)\n * @note \u591A\u91CD\u8FBA\u306B\u3064\
    \u3044\u3066\u306F\u3001\u6700\u3082\u91CD\u307F\u304C\u5C0F\u3055\u3044\u8FBA\
    \u3092\u63A1\u7528\n * @param graph \u9802\u70B9\u6570 V \u306E\u30B0\u30E9\u30D5\
    \n * @param not_adjacent_value 2\u9802\u70B9 u, v \u9593\u306B\u8FBA\u304C\u5B58\
    \u5728\u3057\u306A\u3044\u5834\u5408\u306E\u5024 `(default = 0)`\n * @attention\
    \ \u81EA\u5DF1\u30EB\u30FC\u30D7\u304C\u542B\u307E\u308C\u308B\u30B0\u30E9\u30D5\
    \u306B\u3064\u3044\u3066\u306F\u672A\u5B9A\u7FA9\n * @return vector<vector<CostType>>\
    \ V \xD7 V \u306E\u96A3\u63A5\u884C\u5217\n */\ntemplate<typename CostType>\n\
    vector<vector<CostType>> GraphConvertMatrix(const Graph<CostType> &graph, CostType\
    \ not_adjacent_value = 0){\n    size_t V = graph.get_vertex_size();\n    vector<vector<CostType>>\
    \ ret(V, vector<CostType>(V, not_adjacent_value));\n    for(int i = 0; i < V;\
    \ ++i){\n        for(const Edge<CostType> &e : graph[i]){\n            if(ret[i][e.to]\
    \ == not_adjacent_value || ret[i][e.to] > e.cost){\n                ret[i][e.to]\
    \ = e.cost;\n            }\n        }\n    }\n    return ret;\n}\n\n/**\n * @brief\
    \ \u30B0\u30E9\u30D5\u306E\u8FBA\u3092\u9006\u9806\u306B\u3057\u305F\u30B0\u30E9\
    \u30D5\u3092\u8FD4\u3059\u3002\n * @param graph \u9802\u70B9\u6570 V \u306E\u30B0\
    \u30E9\u30D5\n * @attention \u7121\u5411\u30B0\u30E9\u30D5\u306B\u5BFE\u3059\u308B\
    \u52D5\u4F5C\u306F\u672A\u5B9A\u7FA9\n * @return Graph<CostType> G \u306E\u8FBA\
    \u3092\u9006\u306B\u3057\u305F\u30B0\u30E9\u30D5\n */\ntemplate<typename CostType>\n\
    Graph<CostType> GraphReverse(const Graph<CostType> &graph){\n    size_t V = graph.get_vertex_size();\n\
    \    Graph<CostType> ret(V, true);\n    for(int i = 0; i < V; ++i){\n        for(const\
    \ Edge<CostType> &e : graph[i]){\n            ret.AddEdge(e.to, e.from, e.cost);\n\
    \        }\n    }\n    return ret;\n}\n\n/**\n * @brief \u30B0\u30E9\u30D5\u306E\
    \u8FBA\u96C6\u5408\u3092\u8FD4\u3059\u3002\n * @param graph \u9802\u70B9\u6570\
    \ V \u306E\u30B0\u30E9\u30D5\n * @param sorted \u8FBA\u96C6\u5408\u3092\u30B3\u30B9\
    \u30C8\u3067\u30BD\u30FC\u30C8\u3057\u305F\u72B6\u614B\u3067\u8FD4\u3059\u304B\
    \ `(default = false)`\n * @return vector<Edge<CostType>> G \u306E\u8FBA\u96C6\u5408\
    \n */\ntemplate<typename CostType>\nvector<Edge<CostType>> GraphConvertEdgeSet(const\
    \ Graph<CostType> &graph, bool sorted = false){\n    vector<Edge<CostType>> ret;\n\
    \    set<int> picked;\n    for(int v = 0; v < graph.get_vertex_size(); ++v){\n\
    \        for(Edge<CostType> e : graph[v]){\n            if(!picked.contains(e.id)){\n\
    \t\t\t\tret.emplace_back(e);\n                picked.insert(e.id);\n\t\t\t}\n\
    \        }\n    }\n    if(sorted){\n        sort(ret.begin(), ret.end(), [&](Edge<CostType>\
    \ &l, Edge<CostType> &r){\n            return l.cost < r.cost;\n        });\n\
    \    }\n    return ret;\n}\n#line 9 \"Library/Graph/Dijkstra.hpp\"\n\ntemplate<typename\
    \ CostType>\nclass Dijkstra{\n    public:\n    Dijkstra(Graph<CostType> &G) :\
    \ \n            graph_(G), inf_(G.get_inf()), dist_(G.get_vertex_size(), inf_),\n\
    \            prev_vertex_(G.get_vertex_size(), -1){}\n\n    /**\n     * @brief\
    \ \u9802\u70B9 `source` \u304B\u3089\u4ED6\u306E\u5168\u9802\u70B9\u3078\u306E\
    \u6700\u77ED\u8DDD\u96E2\u3092\u6C42\u3081\u308B\u3002\n     * @note \u5230\u9054\
    \u4E0D\u80FD\u306E\u5834\u5408\u3001`inf` \u3068\u306A\u308B\u3002\n     * @param\
    \ source \u59CB\u70B9\u306E\u9802\u70B9\n     */\n    void Solve(Vertex source){\n\
    \        graph_.Validate(source);\n        if(source_vertex_ == source) return;\n\
    \        dist_.assign(dist_.size(), inf_);\n        prev_vertex_.assign(prev_vertex_.size(),\
    \ -1);\n        dist_[source] = 0;\n        using P = pair<CostType, Vertex>;\n\
    \        priority_queue<P, vector<P>, greater<P>> que;\n        que.emplace(0,\
    \ source);\n        while(que.size()){\n            auto [d, v] = que.top(); que.pop();\n\
    \            if(dist_[v] != d) continue;\n            for(Edge<CostType> &e :\
    \ graph_[v]){\n                CostType nd = d + e.cost;\n                if(nd\
    \ < dist_[e.to]){\n                    dist_[e.to] = nd;\n                   \
    \ prev_vertex_[e.to] = v;\n                    que.emplace(nd, e.to);\n      \
    \          }\n            }\n        }\n        source_vertex_ = source;\n   \
    \ }\n\n    /**\n     * @brief \u9802\u70B9 `source` \u304B\u3089\u9802\u70B9 `target`\
    \ \u306B\u5230\u9054\u53EF\u80FD\u304B\u3092\u8FD4\u3059\u3002\n     * @attention\
    \ \u4E88\u3081\u59CB\u70B9\u306E\u9802\u70B9 `source` \u306B\u3064\u3044\u3066\
    \ `Solve()` \u3092\u547C\u3073\u51FA\u3057\u3066\u3044\u308B\u5FC5\u8981\u304C\
    \u3042\u308B\u3002\n     * @param target \u7D42\u70B9\u306E\u9802\u70B9\n    \
    \ * @return true \u5230\u9054\u53EF\u80FD\n     * @return false \u5230\u9054\u4E0D\
    \u80FD\n     */\n    bool Reachable(Vertex target) const {\n        graph_.Validate(target);\n\
    \        return dist_[target] != inf_;\n    }\n\n    /**\n     * @brief \u9802\
    \u70B9 `source` \u304B\u3089\u9802\u70B9 `target` \u3078\u306E\u6700\u77ED\u30D1\
    \u30B9\u3092\u8FD4\u3059\u3002\n     * @attention \u4E88\u3081\u59CB\u70B9\u306E\
    \u9802\u70B9 `source` \u306B\u3064\u3044\u3066 `Solve()` \u3092\u547C\u3073\u51FA\
    \u3057\u3066\u3044\u308B\u5FC5\u8981\u304C\u3042\u308B\u3002\n     * @attention\
    \ \u9802\u70B9 `target` \u306B\u5230\u9054\u4E0D\u80FD\u306E\u5834\u5408\u3001\
    \u7A7A\u5217\u3092\u8FD4\u3059\u3002\n     * @param target \u7D42\u70B9\u306E\u9802\
    \u70B9\n     * @return vector<Vertex> \u6700\u77ED\u30D1\u30B9\u306B\u542B\u307E\
    \u308C\u308B\u9802\u70B9\u5217\u3092 `source` \u304B\u3089 `target` \u306E\u9806\
    \u306B\u4E26\u3079\u305F\u3082\u306E\u3002\u5230\u9054\u4E0D\u80FD\u306E\u5834\
    \u5408\u306F\u7A7A\u5217\u304C\u8FD4\u3055\u308C\u308B\u3002\n     */\n    vector<Vertex>\
    \ Restore(Vertex target) const {\n        graph_.Validate(target);\n        if(!Reachable(target))\
    \ return vector<Vertex>{};\n        vector<Vertex> ret{target};\n        Vertex\
    \ v = target;\n        while(v != source_vertex_){\n            v = prev_vertex_[v];\n\
    \            ret.push_back(v);\n        }\n        reverse(ret.begin(), ret.end());\n\
    \        return ret;\n    }\n\n    /**\n     * @brief \u9802\u70B9 `source` \u304B\
    \u3089\u9802\u70B9 `target` \u3078\u306E\u6700\u77ED\u7D4C\u8DEF\u9577\u3092\u8FD4\
    \u3059\u3002\n     * @attention \u4E88\u3081\u59CB\u70B9\u306E\u9802\u70B9 `source`\
    \ \u306B\u3064\u3044\u3066 `Solve()` \u3092\u547C\u3073\u51FA\u3057\u3066\u3044\
    \u308B\u5FC5\u8981\u304C\u3042\u308B\u3002\n     * @attention \u5230\u9054\u4E0D\
    \u80FD\u306E\u5834\u5408\u306F `inf` \u304C\u8FD4\u3055\u308C\u308B\u3002\n  \
    \   * @param target \u7D42\u70B9\u306E\u9802\u70B9\n     * @return CostType \u6700\
    \u77ED\u7D4C\u8DEF\u9577\n     */\n    CostType Distance(Vertex target) const\
    \ {\n        graph_.Validate(target);\n        return dist_[target];\n    }\n\n\
    \    CostType operator[](Vertex target){\n        return Distance(target);\n \
    \   }\n\n    const CostType operator[](Vertex target) const {\n        return\
    \ Distance(target);\n    }\n\n    private:\n    Graph<CostType> &graph_;\n\n \
    \   CostType inf_;\n    vector<CostType> dist_;\n    vector<Vertex> prev_vertex_;\n\
    \    Vertex source_vertex_{-1};\n};\n"
  code: "/**\n * @file Dijkstra.hpp\n * @brief Dijkstra - \u30C0\u30A4\u30AF\u30B9\
    \u30C8\u30E9\u6CD5\n * @version 4.0\n * @date 2024-09-01\n */\n\n#include \"Graph.hpp\"\
    \n\ntemplate<typename CostType>\nclass Dijkstra{\n    public:\n    Dijkstra(Graph<CostType>\
    \ &G) : \n            graph_(G), inf_(G.get_inf()), dist_(G.get_vertex_size(),\
    \ inf_),\n            prev_vertex_(G.get_vertex_size(), -1){}\n\n    /**\n   \
    \  * @brief \u9802\u70B9 `source` \u304B\u3089\u4ED6\u306E\u5168\u9802\u70B9\u3078\
    \u306E\u6700\u77ED\u8DDD\u96E2\u3092\u6C42\u3081\u308B\u3002\n     * @note \u5230\
    \u9054\u4E0D\u80FD\u306E\u5834\u5408\u3001`inf` \u3068\u306A\u308B\u3002\n   \
    \  * @param source \u59CB\u70B9\u306E\u9802\u70B9\n     */\n    void Solve(Vertex\
    \ source){\n        graph_.Validate(source);\n        if(source_vertex_ == source)\
    \ return;\n        dist_.assign(dist_.size(), inf_);\n        prev_vertex_.assign(prev_vertex_.size(),\
    \ -1);\n        dist_[source] = 0;\n        using P = pair<CostType, Vertex>;\n\
    \        priority_queue<P, vector<P>, greater<P>> que;\n        que.emplace(0,\
    \ source);\n        while(que.size()){\n            auto [d, v] = que.top(); que.pop();\n\
    \            if(dist_[v] != d) continue;\n            for(Edge<CostType> &e :\
    \ graph_[v]){\n                CostType nd = d + e.cost;\n                if(nd\
    \ < dist_[e.to]){\n                    dist_[e.to] = nd;\n                   \
    \ prev_vertex_[e.to] = v;\n                    que.emplace(nd, e.to);\n      \
    \          }\n            }\n        }\n        source_vertex_ = source;\n   \
    \ }\n\n    /**\n     * @brief \u9802\u70B9 `source` \u304B\u3089\u9802\u70B9 `target`\
    \ \u306B\u5230\u9054\u53EF\u80FD\u304B\u3092\u8FD4\u3059\u3002\n     * @attention\
    \ \u4E88\u3081\u59CB\u70B9\u306E\u9802\u70B9 `source` \u306B\u3064\u3044\u3066\
    \ `Solve()` \u3092\u547C\u3073\u51FA\u3057\u3066\u3044\u308B\u5FC5\u8981\u304C\
    \u3042\u308B\u3002\n     * @param target \u7D42\u70B9\u306E\u9802\u70B9\n    \
    \ * @return true \u5230\u9054\u53EF\u80FD\n     * @return false \u5230\u9054\u4E0D\
    \u80FD\n     */\n    bool Reachable(Vertex target) const {\n        graph_.Validate(target);\n\
    \        return dist_[target] != inf_;\n    }\n\n    /**\n     * @brief \u9802\
    \u70B9 `source` \u304B\u3089\u9802\u70B9 `target` \u3078\u306E\u6700\u77ED\u30D1\
    \u30B9\u3092\u8FD4\u3059\u3002\n     * @attention \u4E88\u3081\u59CB\u70B9\u306E\
    \u9802\u70B9 `source` \u306B\u3064\u3044\u3066 `Solve()` \u3092\u547C\u3073\u51FA\
    \u3057\u3066\u3044\u308B\u5FC5\u8981\u304C\u3042\u308B\u3002\n     * @attention\
    \ \u9802\u70B9 `target` \u306B\u5230\u9054\u4E0D\u80FD\u306E\u5834\u5408\u3001\
    \u7A7A\u5217\u3092\u8FD4\u3059\u3002\n     * @param target \u7D42\u70B9\u306E\u9802\
    \u70B9\n     * @return vector<Vertex> \u6700\u77ED\u30D1\u30B9\u306B\u542B\u307E\
    \u308C\u308B\u9802\u70B9\u5217\u3092 `source` \u304B\u3089 `target` \u306E\u9806\
    \u306B\u4E26\u3079\u305F\u3082\u306E\u3002\u5230\u9054\u4E0D\u80FD\u306E\u5834\
    \u5408\u306F\u7A7A\u5217\u304C\u8FD4\u3055\u308C\u308B\u3002\n     */\n    vector<Vertex>\
    \ Restore(Vertex target) const {\n        graph_.Validate(target);\n        if(!Reachable(target))\
    \ return vector<Vertex>{};\n        vector<Vertex> ret{target};\n        Vertex\
    \ v = target;\n        while(v != source_vertex_){\n            v = prev_vertex_[v];\n\
    \            ret.push_back(v);\n        }\n        reverse(ret.begin(), ret.end());\n\
    \        return ret;\n    }\n\n    /**\n     * @brief \u9802\u70B9 `source` \u304B\
    \u3089\u9802\u70B9 `target` \u3078\u306E\u6700\u77ED\u7D4C\u8DEF\u9577\u3092\u8FD4\
    \u3059\u3002\n     * @attention \u4E88\u3081\u59CB\u70B9\u306E\u9802\u70B9 `source`\
    \ \u306B\u3064\u3044\u3066 `Solve()` \u3092\u547C\u3073\u51FA\u3057\u3066\u3044\
    \u308B\u5FC5\u8981\u304C\u3042\u308B\u3002\n     * @attention \u5230\u9054\u4E0D\
    \u80FD\u306E\u5834\u5408\u306F `inf` \u304C\u8FD4\u3055\u308C\u308B\u3002\n  \
    \   * @param target \u7D42\u70B9\u306E\u9802\u70B9\n     * @return CostType \u6700\
    \u77ED\u7D4C\u8DEF\u9577\n     */\n    CostType Distance(Vertex target) const\
    \ {\n        graph_.Validate(target);\n        return dist_[target];\n    }\n\n\
    \    CostType operator[](Vertex target){\n        return Distance(target);\n \
    \   }\n\n    const CostType operator[](Vertex target) const {\n        return\
    \ Distance(target);\n    }\n\n    private:\n    Graph<CostType> &graph_;\n\n \
    \   CostType inf_;\n    vector<CostType> dist_;\n    vector<Vertex> prev_vertex_;\n\
    \    Vertex source_vertex_{-1};\n};"
  dependsOn:
  - Library/Graph/Graph.hpp
  - Library/Common.hpp
  isVerificationFile: false
  path: Library/Graph/Dijkstra.hpp
  requiredBy: []
  timestamp: '2024-11-18 02:33:08+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/AOJ-GRL-1-A.test.cpp
documentation_of: Library/Graph/Dijkstra.hpp
layout: document
redirect_from:
- /library/Library/Graph/Dijkstra.hpp
- /library/Library/Graph/Dijkstra.hpp.html
title: "Dijkstra - \u30C0\u30A4\u30AF\u30B9\u30C8\u30E9\u6CD5"
---