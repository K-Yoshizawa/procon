---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Library/Common.hpp
    title: Library/Common.hpp
  - icon: ':heavy_check_mark:'
    path: Library/Graph/Graph.hpp
    title: "Graph - \u30B0\u30E9\u30D5\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8"
  - icon: ':heavy_check_mark:'
    path: Library/Graph/LowLink.hpp
    title: "LowLink - \u6A4B\u3068\u95A2\u7BC0\u70B9"
  - icon: ':heavy_check_mark:'
    path: Library/Graph/TwoEdgeConnectedComponents.hpp
    title: "Two-Edge-Connected Components - \u4E8C\u8FBA\u9023\u7D50\u6210\u5206\u5206\
      \u89E3"
  - icon: ':heavy_check_mark:'
    path: Library/Template.hpp
    title: "Template - \u30C6\u30F3\u30D7\u30EC\u30FC\u30C8"
  - icon: ':heavy_check_mark:'
    path: Library/Tree/Tree.hpp
    title: "Tree - \u6728\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/two_edge_connected_components
    links:
    - https://judge.yosupo.jp/problem/two_edge_connected_components
  bundledCode: "#line 1 \"verify/LC-TwoEdgeConnectedComponents.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/two_edge_connected_components\"\n\n\
    #line 2 \"Library/Template.hpp\"\n\n/**\n * @file Template.hpp\n * @author log\
    \ K (lX57)\n * @brief Template - \u30C6\u30F3\u30D7\u30EC\u30FC\u30C8\n * @version\
    \ 1.9\n * @date 2024-10-27\n */\n\n#line 2 \"Library/Common.hpp\"\n\n/**\n * @file\
    \ Common.hpp\n */\n\n#include <algorithm>\n#include <array>\n#include <bitset>\n\
    #include <cassert>\n#include <cstdint>\n#include <deque>\n#include <functional>\n\
    #include <iomanip>\n#include <iostream>\n#include <limits>\n#include <map>\n#include\
    \ <numeric>\n#include <queue>\n#include <set>\n#include <stack>\n#include <string>\n\
    #include <tuple>\n#include <utility>\n#include <vector>\nusing namespace std;\n\
    #line 12 \"Library/Template.hpp\"\n#define ALL(x) (x).begin(), (x).end()\n#define\
    \ RALL(x) (x).rbegin(), (x).rend()\n#define SORT(x) sort(ALL(x))\n#define RSORT(x)\
    \ sort(RALL(x))\n#define REVERSE(x) reverse(ALL(x))\n#define SETPRE(digit) fixed\
    \ << setprecision(digit)\n#define POPCOUNT(x) __builtin_popcount(x)\n#define SUM(x)\
    \ reduce((x).begin(), (x).end())\n#define CEIL(nume, deno) ((nume) + (deno) -\
    \ 1) / (deno)\n#define IOTA(x) iota((x).begin(), (x).end(), 0)\n#define LOWERBOUND_IDX(arr,\
    \ val) distance((arr).begin(), lower_bound((arr).begin(), (arr).end(), val))\n\
    #define UPPERBOUND_IDX(arr, val) distance((arr).begin(), upper_bound((arr).begin(),\
    \ (arr).end(), val))\n\ninline string Yn(bool flag){return (flag) ? \"Yes\" :\
    \ \"No\";}\ninline bool YnPrint(bool flag){cout << Yn(flag) << endl;return flag;}\n\
    inline string YN(bool flag){return (flag) ? \"YES\" : \"NO\";}\ninline bool YNPrint(bool\
    \ flag){cout << YN(flag) << endl;return flag;}\ntemplate<class T>\nbool chmin(T\
    \ &src, const T &cmp){if(src > cmp){src = cmp; return true;}return false;}\ntemplate<class\
    \ T>\nbool chmax(T &src, const T &cmp){if(src < cmp){src = cmp; return true;}return\
    \ false;}\ntemplate<typename T>\ninline bool between(T min, T x, T max){return\
    \ min <= x && x <= max;}\ntemplate<typename T>\ninline bool ingrid(T y, T x, T\
    \ ymax, T xmax){return between(0, y, ymax - 1) && between(0, x, xmax - 1);}\n\
    template<typename T>\ninline T median(T a, T b, T c){return between(b, a, c) ||\
    \ between(c, a, b) ? a : (between(a, b, c) || between(c, b, a) ? b : c);}\ntemplate<typename\
    \ T>\ninline T except(T src, T cond, T excp){return (src == cond ? excp : src);}\n\
    template<typename T>\ninline T min(vector<T> &v){return *min_element((v).begin(),\
    \ (v).end());}\ntemplate<typename T>\ninline T max(vector<T> &v){return *max_element((v).begin(),\
    \ (v).end());}\nvector<int> make_sequence(int Size){\n    vector<int> ret(Size);\n\
    \    IOTA(ret);\n    return ret;\n}\ntemplate<typename T>\nvoid make_unique(vector<T>\
    \ &v){\n    sort(v.begin(), v.end());\n    auto itr = unique(v.begin(), v.end());\n\
    \    v.erase(itr, v.end());\n}\n\nusing ll = int64_t;\nusing ull = uint64_t;\n\
    using ld = long double;\n\nconst int INF_INT = numeric_limits<int>::max() >> 2;\n\
    const ll INF_LL = numeric_limits<ll>::max() >> 2;\n\nusing vi = vector<int>;\n\
    using vvi = vector<vi>;\nusing vl = vector<ll>;\nusing vvl = vector<vl>;\nusing\
    \ pi = pair<int, int>;\nusing pl = pair<ll, ll>;\nusing vs = vector<string>;\n\
    template <typename T>\nusing pq = priority_queue<T>;\ntemplate <typename T>\n\
    using rpq = priority_queue<T, vector<T>, greater<T>>;\n\nconst int dx4[4] = {1,\
    \ 0, -1, 0};\nconst int dy4[4] = {0, -1, 0, 1};\nconst int dx8[8] = {1, 1, 0,\
    \ -1, -1, -1, 0, 1};\nconst int dy8[8] = {0, -1, -1, -1, 0, 1, 1, 1};\n\nvector<pair<int,\
    \ int>> adjacent(int current_y, int current_x, int max_y, int max_x, bool dir_8\
    \ = false){\n    vector<pair<int, int>> ret;\n    for(int d = 0; d < 4 * (1 +\
    \ dir_8); ++d){\n        int next_y = current_y + (dir_8 ? dy8[d] : dy4[d]);\n\
    \        int next_x = current_x + (dir_8 ? dx8[d] : dx4[d]);\n        if(0 <=\
    \ next_y and next_y < max_y and 0 <= next_x and next_x < max_x){\n           \
    \ ret.emplace_back(next_y, next_x);\n        }\n    }\n    return ret;\n}\n\n\
    template <typename T1, typename T2>\nostream &operator<<(ostream &os, const pair<T1,\
    \ T2> &p){\n    os << p.first << \" \" << p.second;\n    return os;\n}\n\ntemplate\
    \ <typename T1, typename T2>\nistream &operator>>(istream &is, pair<T1, T2> &p){\n\
    \    is >> p.first >> p.second;\n    return is;\n}\n\ntemplate <typename T>\n\
    ostream &operator<<(ostream &os, vector<T> &v){\n    for (int i = 0; i < v.size();\
    \ ++i){\n        os << v[i] << (i + 1 != v.size() ? \" \" : \"\");\n    }\n  \
    \  return os;\n}\n\ntemplate <typename T>\nostream &operator<<(ostream &os, vector<vector<T>>\
    \ &v){\n    for (int i = 0; i < v.size(); ++i){\n        os << v[i] << (i + 1\
    \ != v.size() ? \"\\n\" : \"\");\n    }\n    return os;\n}\n\ntemplate <typename\
    \ T>\nistream &operator>>(istream &is, vector<T> &v){\n    for (int i = 0; i <\
    \ v.size(); ++i) is >> v[i];\n    return is;\n}\n\ntemplate <typename T>\nostream\
    \ &operator<<(ostream &os, set<T> &v){\n    for (auto &u : v){\n        os <<\
    \ u << \" \";\n    }\n    return os;\n}\n\ntemplate<typename T1, typename T2>\n\
    vector<pair<T1, T2>> AssembleVectorPair(vector<T1> &v1, vector<T2> &v2){\n   \
    \ assert(v1.size() == v2.size());\n    vector<pair<T1, T2>> v;\n    for(int i\
    \ = 0; i < v1.size(); ++i) v.push_back({v1[i], v2[i]});\n    return v;\n}\n\n\
    template<typename T1, typename T2>\npair<vector<T1>, vector<T2>> DisassembleVectorPair(vector<pair<T1,\
    \ T2>> &v){\n    vector<T1> v1;\n    vector<T2> v2;\n    transform(v.begin(),\
    \ v.end(), back_inserter(v1), [](auto p){return p.first;});\n    transform(v.begin(),\
    \ v.end(), back_inserter(v2), [](auto p){return p.second;});\n    return {v1,\
    \ v2};\n}\n\ntemplate<typename T1, typename T2, typename T3>\ntuple<vector<T1>,\
    \ vector<T2>, vector<T3>> DisassembleVectorTuple(vector<tuple<T1, T2, T3>> &v){\n\
    \    vector<T1> v1;\n    vector<T2> v2;\n    vector<T3> v3;\n    transform(v.begin(),\
    \ v.end(), back_inserter(v1), [](auto p){return get<0>(p);});\n    transform(v.begin(),\
    \ v.end(), back_inserter(v2), [](auto p){return get<1>(p);});\n    transform(v.begin(),\
    \ v.end(), back_inserter(v3), [](auto p){return get<2>(p);});\n    return {v1,\
    \ v2, v3};\n}\n\ntemplate<typename T1 = int, typename T2 = T1>\npair<vector<T1>,\
    \ vector<T2>> InputVectorPair(int size){\n    vector<pair<T1, T2>> v(size);\n\
    \    for(auto &[p, q] : v) cin >> p >> q;\n    return DisassembleVectorPair(v);\n\
    }\n\ntemplate<typename T1 = int, typename T2 = T1, typename T3 = T1>\ntuple<vector<T1>,\
    \ vector<T2>, vector<T3>> InputVectorTuple(int size){\n    vector<tuple<T1, T2,\
    \ T3>> v(size);\n    for(auto &[p, q, r] : v) cin >> p >> q >> r;\n    return\
    \ DisassembleVectorTuple(v);\n}\n\nll modpow(ll a, ll x, ll m){\n    ll ret =\
    \ 1, cur = a % m, rem = x;\n    while(rem){\n        if(rem & 1) ret = (ret *\
    \ cur) % m;\n        rem >>= 1, cur = (cur * cur) % m;\n    }\n    return ret;\n\
    }\n\n#ifdef LOGK\n#define VARIABLE(var) cerr << \"# \" << #var << \" = \" << var\
    \ << endl;\n#else\n#define VARIABLE(...) 42\n#endif\n#line 1 \"Library/Graph/TwoEdgeConnectedComponents.hpp\"\
    \n/**\n * @file TwoEdgeConnectedComponents.hpp\n * @brief Two-Edge-Connected Components\
    \ - \u4E8C\u8FBA\u9023\u7D50\u6210\u5206\u5206\u89E3\n * @version 1.0\n * @date\
    \ 2024-10-21\n */\n\n#line 2 \"Library/Graph/LowLink.hpp\"\n\n/**\n * @file LowLink.hpp\n\
    \ * @brief LowLink - \u6A4B\u3068\u95A2\u7BC0\u70B9\n * @version 1.0\n * @date\
    \ 2024-09-02\n */\n\n#line 2 \"Library/Graph/Graph.hpp\"\n\n/**\n * @file Graph.hpp\n\
    \ * @brief Graph - \u30B0\u30E9\u30D5\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8\n *\
    \ @version 1.0\n * @date 2024-09-01\n */\n\n#line 11 \"Library/Graph/Graph.hpp\"\
    \n\nusing Vertex = int;\n\ntemplate<typename CostType>\nstruct Edge{\n    Edge()\
    \ = default;\n    Edge(int from, int to, CostType cost, int id = -1) : from(from),\
    \ to(to), cost(cost), id(id){}\n\t\n    int from{-1}, to{-1}, id{-1};\n    CostType\
    \ cost{1};\n};\n\ntemplate<typename CostType = int32_t>\nclass Graph{\n    public:\n\
    \    Graph() = default;\n\n    /**\n     * @brief \u9802\u70B9\u6570 `vertex_size`\
    \ \u306E\u30B0\u30E9\u30D5\u3092\u69CB\u7BC9\u3059\u308B\u3002\n     * @param\
    \ vertex_size \u9802\u70B9\u6570\n     * @param directed `true` \u306E\u5834\u5408\
    \u3001\u6709\u5411\u30B0\u30E9\u30D5\u3068\u3057\u3066\u69CB\u7BC9\u3059\u308B\
    \ `(default = false)`\n     */\n    Graph(int vertex_size, bool directed = false)\
    \ : \n        vertex_(vertex_size), adjacent_list_(vertex_size),\n        directed_flag_(directed){}\n\
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
    \    }\n    return ret;\n}\n#line 11 \"Library/Graph/LowLink.hpp\"\n\ntemplate<typename\
    \ CostType>\nclass LowLink{\n    public:\n    LowLink(Graph<CostType> &graph)\
    \ :\n            graph_(graph), ord_(graph.get_vertex_size()), low_(graph.get_vertex_size()),\n\
    \            child_(graph.get_vertex_size()), state_(graph.get_vertex_size(),\
    \ 0){\n        for(int i = 0; i < graph.get_vertex_size(); ++i){\n           \
    \ if(!state_[i]) dfs(i, -1, 0);\n        }\n        BuildArticulationVertex();\n\
    \        BuildBridge();\n    }\n\n    /**\n     * @brief \u9802\u70B9 `v` \u306E\
    \ `ord[v]` \u3092\u8FD4\u3059\u3002\n     * @param v \u9802\u70B9\u756A\u53F7\
    \ (0-index)\n     * @return int \n     */\n    int get_ord(Vertex v) const {\n\
    \        graph_.Validate(v);\n        return ord_[v];\n    }\n\n    /**\n    \
    \ * @brief \u9802\u70B9 `v` \u306E `low[v]` \u3092\u8FD4\u3059\u3002\n     * @param\
    \ v \u9802\u70B9\u756A\u53F7 (0-index)\n     * @return int \n     */\n    int\
    \ get_low(Vertex v) const {\n        graph_.Validate(v);\n        return low_[v];\n\
    \    }\n\n    /**\n     * @brief \u95A2\u7BC0\u70B9\u3092\u5217\u6319\u3059\u308B\
    \u3002\n     * @note \u95A2\u7BC0\u70B9 : \u305D\u306E\u9802\u70B9\u3092\u9664\
    \u304F\u3068\u9023\u7D50\u6210\u5206\u304C\u5897\u3048\u308B\u3088\u3046\u306A\
    \u9802\u70B9\n     * @return vector<Vertex> \u95A2\u7BC0\u70B9\u306E\u9802\u70B9\
    \u756A\u53F7 (0-index)\n     */\n    vector<Vertex> &get_articulation_vertex(){\n\
    \        return articulation_vertex_;\n    }\n\n    /**\n     * @brief \u6A4B\u3092\
    \u5217\u6319\u3059\u308B\u3002\n     * @note \u6A4B : \u305D\u306E\u8FBA\u3092\
    \u9664\u304F\u3068\u9023\u7D50\u6210\u5206\u304C\u5897\u3048\u308B\u3088\u3046\
    \u306A\u9802\u70B9\n     * @return vector<Edge<CostType>> \u6A4B\u3067\u3042\u308B\
    \u8FBA\n     */\n    vector<Edge<CostType>> &get_bridge(){\n        return bridge_;\n\
    \    }\n\n    private:\n    bool dfs(Vertex v, int p, int order){\n        if(state_[v]\
    \ != 0) return false;\n        // cerr << \"# (v, p, order) = (\" << v << \",\
    \ \" << p << \", \" << order << \")\" << endl;\n        state_[v] = 1 + (p ==\
    \ -1);\n        ord_[v] = low_[v] = order;\n        for(Edge<CostType> &e : graph_[v]){\n\
    \            if(e.id == p) continue;\n            child_[v].push_back(e.to);\n\
    \            if(dfs(e.to, e.id, order + 1)){\n                low_[v] = min(low_[v],\
    \ low_[e.to]);\n            }\n            else{\n                child_[v].pop_back();\n\
    \                low_[v] = min(low_[v], ord_[e.to]);\n            }\n        }\n\
    \        return true;\n    }\n\n    void BuildArticulationVertex(){\n        for(int\
    \ u = 0; u < graph_.get_vertex_size(); ++u){\n            if(state_[u] == 2){\n\
    \                if(child_[u].size() > 1) articulation_vertex_.push_back(u);\n\
    \                continue;\n            }\n            bool exist = false;\n \
    \           for(Vertex v : child_[u]){\n                exist |= (get_ord(u) <=\
    \ get_low(v));\n            }\n            if(exist) articulation_vertex_.push_back(u);\n\
    \        }\n    }\n\n    void BuildBridge(){\n        auto es = GraphConvertEdgeSet(graph_,\
    \ false);\n        for(Edge<CostType> e : es){\n            Vertex u = e.from,\
    \ v = e.to;\n            if(get_ord(u) >= get_ord(v)) swap(u, v);\n          \
    \  if(get_ord(u) < get_low(v)) bridge_.push_back(e);\n        }\n    }\n\n   \
    \ Graph<CostType> &graph_;\n    vector<int> ord_, low_, state_;\n    vector<vector<Vertex>>\
    \ child_;\n\n    vector<Vertex> articulation_vertex_;\n    vector<Edge<CostType>>\
    \ bridge_;\n};\n#line 2 \"Library/Tree/Tree.hpp\"\n\n/**\n * @file Tree.hpp\n\
    \ * @brief Tree - \u6728\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8\n * @version 1.0\n\
    \ * @date 2024-09-02\n */\n\n#line 11 \"Library/Tree/Tree.hpp\"\n\nusing Vertex\
    \ = int;\n\ntemplate<typename CostType = int32_t>\nclass RootedTree{\n    public:\n\
    \    struct Node{\n        Node(Vertex parent = -1) : parent(parent){}\n\n   \
    \     Vertex parent{-1};\n        CostType cost{};\n        vector<Vertex> children{};\n\
    \    };\n\n    /**\n     * @brief \u9802\u70B9 `root_vertex` \u3092\u6839\u3068\
    \u3059\u308B\u9802\u70B9\u6570 `vertex_size` \u306E\u6839\u4ED8\u304D\u6728\u3092\
    \u69CB\u7BC9\u3059\u308B\u3002\n     * @note \u6839\u304C\u5165\u529B\u3067\u4E0E\
    \u3048\u3089\u308C\u306A\u308C\u306A\u3044\u304C\u5F8C\u3067\u5206\u304B\u308B\
    \u3001\u307F\u305F\u3044\u306A\u72B6\u6CC1\u306E\u6642\u306F `root_vertex = -1`\
    \ \u3068\u3059\u308B\u3068\u3088\u3044\n     * @param vertex_size \u9802\u70B9\
    \u6570\n     * @param root_vertex \u6839\u3068\u3059\u308B\u9802\u70B9 (default\
    \ = 0)\n     */\n    RootedTree(int vertex_size = 0, Vertex root_vertex = 0) :\n\
    \            vertex_size_(vertex_size), root_vertex_(root_vertex),\n         \
    \   node_(vertex_size){}\n\n    /**\n     * @brief \u6728\u306E\u9802\u70B9\u6570\
    \u3092\u8FD4\u3059\u3002\n     * @return int \u6728\u306E\u9802\u70B9\u6570\n\
    \     */\n    int get_vertex_size() const {\n        return vertex_size_;\n  \
    \  }\n\n    /**\n     * @brief \u6728\u306E\u6839\u306E\u9802\u70B9\u3092\u8FD4\
    \u3059\u3002\n     * @return Vertex \u6728\u306E\u6839\u306E\u9802\u70B9\u756A\
    \u53F7 (0-index)\n     */\n    Vertex get_root() const {\n        return root_vertex_;\n\
    \    }\n\n    /**\n     * @brief \u9802\u70B9 `v` \u306E\u89AA\u306E\u9802\u70B9\
    \u756A\u53F7\u3092\u8FD4\u3059\u3002\n     * @note `v` \u304C\u6839\u306E\u5834\
    \u5408\u3001`-1` \u304C\u8FD4\u3055\u308C\u308B\u3002\n     * @param v \u5B50\u306E\
    \u9802\u70B9\u756A\u53F7 (0-index)\n     * @return Vertex \u89AA\u306E\u9802\u70B9\
    \u756A\u53F7 (0-index)\n     */\n    Vertex get_parent(Vertex v) const {\n   \
    \     Validate(v);\n        return node_[v].parent;\n    }\n\n    /**\n     *\
    \ @brief \u9802\u70B9 `v` \u306E\u5B50\u306E\u9802\u70B9\u756A\u53F7\u5217\u3092\
    \u8FD4\u3059\u3002\n     * @note \u9802\u70B9\u756A\u53F7\u5217\u306F\u5165\u529B\
    \u9806\u306B\u8FD4\u3055\u308C\u308B\u3002\n     * @param v \u89AA\u306E\u9802\
    \u70B9\u756A\u53F7 (0-index)\n     * @return vector<Vertex> \u5B50\u306E\u9802\
    \u70B9\u756A\u53F7\u5217 (0-index)\n     */\n    vector<Vertex> &get_child(Vertex\
    \ v){\n        Validate(v);\n        return node_[v].children;\n    }\n\n    /**\n\
    \     * @brief \u9802\u70B9 `v` \u3068\u305D\u306E\u89AA\u3092\u7D50\u3076\u8FBA\
    \u306E\u91CD\u307F\u3092\u8FD4\u3059\u3002\n     * @attention `v` \u304C\u6839\
    \u306E\u5834\u5408\u306E\u8FD4\u308A\u5024\u306F\u672A\u5B9A\u7FA9\u3067\u3042\
    \u308B\u3002\n     * @param v \u9802\u70B9\u756A\u53F7 (0-index)\n     * @return\
    \ CostType \u8FBA\u306E\u91CD\u307F\n     */\n    CostType get_cost(Vertex v){\n\
    \        Validate(v);\n        return node_[v].cost;\n    }\n\n    /**\n     *\
    \ @brief \u9802\u70B9 `parent` \u304B\u3089\u9802\u70B9 `child` \u3078\u306E\u91CD\
    \u3055 `cost` \u306E\u8FBA\u3092\u5F35\u308B\u3002\n     * @note `cost` \u3092\
    \u7701\u7565\u3059\u308B\u3053\u3068\u3067\u91CD\u307F\u306A\u3057\u8FBA\u3092\
    \u5F35\u308B\u3053\u3068\u304C\u3067\u304D\u308B\u3002\n     * @param parent \u89AA\
    \u306E\u9802\u70B9\u756A\u53F7 (0-index)\n     * @param child \u5B50\u306E\u9802\
    \u70B9\u756A\u53F7 (0-index)\n     * @param cost \u8FBA\u306E\u91CD\u307F (default\
    \ = 1)\n     */\n    void AddEdge(Vertex parent, Vertex child, CostType cost =\
    \ 1){\n        Validate(parent);\n        Validate(child);\n        node_[parent].children.push_back(child);\n\
    \        node_[child].parent = parent;\n        node_[child].cost = cost;\n  \
    \  }\n\n    /**\n     * @brief `u v w` \u306E\u3088\u3046\u306A\u5165\u529B\u5F62\
    \u5F0F\u3092\u53D7\u3051\u53D6\u308B\u3002\n     * @param weighted \u91CD\u307F\
    \u4ED8\u304D\u306E\u6728\u3067\u3042\u308B\u304B (default = true)\n     * @param\
    \ one_index \u5165\u529B\u3055\u308C\u308B\u9802\u70B9\u756A\u53F7\u304C 1-index\
    \ \u304B\u3069\u3046\u304B (default = true)\n     */\n    void InputGraphFormat(bool\
    \ weighted = true, bool one_index = true){\n        vector<vector<pair<Vertex,\
    \ CostType>>> graph(vertex_size_);\n        for(int i = 0; i < vertex_size_ -\
    \ 1; ++i){\n            int u, v; cin >> u >> v;\n            if(one_index) --u,\
    \ --v;\n            CostType w = 1;\n            if(weighted) cin >> w;\n    \
    \        graph[u].emplace_back(v, w);\n            graph[v].emplace_back(u, w);\n\
    \        }\n        auto rec = [&](auto self, Vertex v, Vertex p) -> void {\n\
    \            for(auto [u, w] : graph[v]){\n                if(u == p) continue;\n\
    \                AddEdge(v, u, w);\n                self(self, u, v);\n      \
    \      }\n        };\n        rec(rec, root_vertex_, -1);\n    }\n\n    /**\n\
    \     * @brief `p_1 p_2 ... p_N` \u306E\u3088\u3046\u306A\u5165\u529B\u5F62\u5F0F\
    \u3092\u53D7\u3051\u53D6\u308B\u3002\n     * @attention weighted \u306E\u51E6\u7406\
    \u3092\u66F8\u3044\u3066\u3044\u306A\u3044\u306E\u3067\u3001`weighted` \u306E\u30D1\
    \u30E9\u30E1\u30FC\u30BF\u306B\u610F\u5473\u306F\u306A\u3044\n     * @param weighted\
    \ \u91CD\u307F\u4ED8\u304D\u306E\u6728\u3067\u3042\u308B\u304B (default = true)\n\
    \     * @param one_index \u5165\u529B\u3055\u308C\u308B\u9802\u70B9\u756A\u53F7\
    \u304C 1-index \u304B\u3069\u3046\u304B (default = true)\n     */\n    void InputRootedTreeFormat(bool\
    \ weighted = true, bool one_index = true){\n        assert(root_vertex_ == 0);\n\
    \        for(int i = 1; i < vertex_size_; ++i){\n            int p; cin >> p;\n\
    \            if(one_index) --p;\n            AddEdge(p, i);\n        }\n    }\n\
    \n    /**\n     * @brief \u9802\u70B9 `v` \u304C\u6839\u306E\u9802\u70B9\u304B\
    \u5224\u5B9A\u3059\u308B\u3002\n     * @param v \u5224\u5B9A\u3059\u308B\u9802\
    \u70B9\u756A\u53F7 (0-index)\n     */\n    bool RootVertex(Vertex v){\n      \
    \  Validate(v);\n        return node_[v].parent == -1;\n    }\n    \n    /**\n\
    \     * @brief \u9802\u70B9 `v` \u304C\u8449\u306E\u9802\u70B9\u304B\u5224\u5B9A\
    \u3059\u308B\u3002\n     * @param v \u5224\u5B9A\u3059\u308B\u9802\u70B9\u756A\
    \u53F7 (0-index)\n     */\n    bool LeafVertex(Vertex v){\n        Validate(v);\n\
    \        return node_[v].children.empty();\n    }\n\n    /**\n     * @brief \u6728\
    \u306E\u6839\u306E\u9802\u70B9\u3092\u6C42\u3081\u308B\u3002\n     * @attention\
    \ \u57FA\u672C\u7684\u306B\u306F\u4E0D\u8981\u3067\u3001\u6839\u306E\u9802\u70B9\
    \u756A\u53F7\u304C\u4E0E\u3048\u3089\u308C\u3066\u3044\u306A\u3044\u5834\u5408\
    \u306B\u7528\u3044\u308B\u3002\n     * @note Verify : https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/7/ALDS1_7_A\n\
    \     * @return Vertex \u6839\u306E\u9802\u70B9\u756A\u53F7\n     */\n    Vertex\
    \ FindRoot(){\n        for(int i = 0; i < vertex_size_; ++i){\n            if(RootVertex(i)){\n\
    \                root_vertex_ = i;\n                return i;\n            }\n\
    \        }\n        assert(false);\n    }\n\n    /**\n     * @brief \u6728\u306E\
    \u6839\u3092\u5909\u66F4\u3057\u3066\u518D\u69CB\u7BC9\u3059\u308B\u3002\n   \
    \  * @param root \u65B0\u3057\u3044\u6839\u306E\u9802\u70B9\u756A\u53F7 (0-index)\n\
    \     */\n    void Rerooting(Vertex root){\n        if(root == root_vertex_) return;\n\
    \        vector<Node> new_node_(vertex_size_);\n        auto rec = [&](auto self,\
    \ Vertex v, Vertex p, CostType c) -> void {\n            new_node_[v].parent =\
    \ p;\n            new_node_[v].cost = c;\n            if(node_[v].parent != p\
    \ && node_[v].parent != -1){\n                new_node_[v].children.push_back(node_[v].parent);\n\
    \                self(self, node_[v].parent, v, node_[v].cost);\n            }\n\
    \            for(Vertex u : node_[v].children){\n                if(u != p){\n\
    \                    new_node_[v].children.push_back(u);\n                   \
    \ self(self, u, v, node_[u].cost);\n                }\n            }\n       \
    \ };\n        rec(rec, root, -1, 0);\n        swap(new_node_, node_);\n      \
    \  root_vertex_ = root;\n    }\n\n    void Print(bool one_index = true) const\
    \ {\n        for(int i = 0; i < vertex_size_; ++i){\n            // fprintf(stderr,\
    \ \"# Vertex %d : parent = %d (cost = %d), children = [\", i + int(one_index),\
    \ get_parent(i) + int(one_index), node_[i].cost);\n            fprintf(stderr,\
    \ \"# Vertex %d : parent = %d (cost = \", i + int(one_index), get_parent(i) +\
    \ int(one_index));\n            cerr << node_[i].cost;\n            fprintf(stderr,\
    \ \"), children = [\");\n            for(int j = 0; j < node_[i].children.size();\
    \ ++j){\n                fprintf(stderr, \"%d\", node_[i].children[j] + int(one_index));\n\
    \                if(j + 1 < node_[i].children.size()){\n                    fprintf(stderr,\
    \ \", \");\n                }\n            }\n            fprintf(stderr, \"]\\\
    n\");\n        }\n    }\n\n    private:\n    inline void Validate(Vertex v) const\
    \ {\n        assert(0 <= v && v < vertex_size_);\n    }\n\n    int vertex_size_,\
    \ root_vertex_{-1};\n    vector<Node> node_;\n};\n\n/**\n * @brief \u6728 `tree`\
    \ \u306E\u5404\u9802\u70B9\u306E\u6DF1\u3055\u3092\u6C42\u3081\u308B\u3002\n *\
    \ @note \u6839\u306E\u9802\u70B9\u306F\u6DF1\u3055 0 \u3067\u3042\u308B\u3002\n\
    \ * @note Verify : https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/7/ALDS1_7_A\n\
    \ * @param tree \u6728\n * @param root \u6839\u306E\u9802\u70B9\u756A\u53F7 (default\
    \ = 0)\n * @return vector<int> \u5404\u9802\u70B9\u306E\u6DF1\u3055\n */\ntemplate<typename\
    \ CostType>\nvector<int> CalculateTreeDepth(RootedTree<CostType> &tree){\n   \
    \ int V = tree.get_vertex_size();\n    vector<int> ret(V, 0);\n    auto rec =\
    \ [&](auto self, Vertex v, int d) -> void {\n        ret[v] = d;\n        for(Vertex\
    \ u : tree.get_child(v)){\n            self(self, u, d + 1);\n        }\n    };\n\
    \    Vertex root = tree.get_root();\n    if(root < 0) root = tree.FindRoot();\n\
    \    rec(rec, root, 0);\n    return ret;\n}\n\n/**\n * @brief \u6728\u306E\u6839\
    \u304B\u3089\u5404\u9802\u70B9\u3078\u306E\u8FBA\u306E\u91CD\u307F\u306E\u7D2F\
    \u7A4D\u548C\u3092\u8A08\u7B97\u3059\u308B\u3002\n * @param tree \u6728\n * @return\
    \ vector<CostType> \u6839\u304B\u3089\u5404\u9802\u70B9\u3078\u306E\u91CD\u307F\
    \u306E\u7D2F\u7A4D\u548C\n */\ntemplate<typename CostType>\nvector<CostType> CalculateTreeCumlativeSum(RootedTree<CostType>\
    \ &tree){\n    Vertex root = tree.get_root();\n    int V = tree.get_vertex_size();\n\
    \    vector<CostType> ret(V, 0);\n    auto rec = [&](auto self, Vertex v, CostType\
    \ s) -> void {\n        ret[v] = s + tree.get_cost(v);\n        for(Vertex u :\
    \ tree.get_child(v)){\n            self(self, u, ret[v]);\n        }\n    };\n\
    \    rec(rec, root, 0);\n    return ret;\n}\n\n/**\n * @brief \u5404\u9802\u70B9\
    \u3092\u6839\u3068\u3059\u308B\u90E8\u5206\u6728\u306E\u30B5\u30A4\u30BA\u3092\
    \u6C42\u3081\u308B\u3002\n * @param tree \u6728\n * @return vector<int> \u5404\
    \u9802\u70B9\u3092\u6839\u3068\u3059\u308B\u90E8\u5206\u6728\u306E\u30B5\u30A4\
    \u30BA\n */\ntemplate<typename CostType>\nvector<int> CalculateSubtreeSize(RootedTree<CostType>\
    \ &tree){\n    Vertex root = tree.get_root();\n    int V = tree.get_vertex_size();\n\
    \    vector<int> ret(V, 1);\n    auto rec = [&](auto self, Vertex v) -> int {\n\
    \        for(Vertex u : tree.get_child(v)){\n            ret[v] += self(self,\
    \ u);\n        }\n        return ret[v];\n    };\n    rec(rec, root);\n    return\
    \ ret;\n}\n\n/**\n * @brief \u5404\u9802\u70B9\u3092\u884C\u304D\u304B\u3051\u9806\
    \u306B\u4E26\u3079\u305F\u3068\u304D\u306B\u4F55\u756A\u76EE\u306B\u76F8\u5F53\
    \u3059\u308B\u304B\u306E\u914D\u5217\u3092\u6C42\u3081\u308B\u3002\n * @param\
    \ tree \u6728\n * @return vector<int> \u5404\u9802\u70B9\u304C\u884C\u304D\u304B\
    \u3051\u9806\u3067\u4F55\u756A\u76EE\u306B\u306A\u308B\u304B (0-index)\n */\n\
    template<typename CostType>\nvector<int> CalculatePreOrder(RootedTree<CostType>\
    \ &tree){\n    Vertex root = tree.get_root();\n    int V = tree.get_vertex_size(),\
    \ time_stamp = 0;\n    vector<int> ret(V, -1);\n    auto rec = [&](auto self,\
    \ Vertex v) -> void {\n        ret[v] = time_stamp++;\n        for(Vertex u :\
    \ tree.get_child()){\n            self(self, u);\n        }\n    };\n    rec(rec,\
    \ root);\n    return ret;\n}\n#line 10 \"Library/Graph/TwoEdgeConnectedComponents.hpp\"\
    \n\ntemplate<typename CostType>\nclass TwoEdgeConnectedComponents{\n    public:\n\
    \    /**\n     * @brief \u30B0\u30E9\u30D5\u304B\u3089\u4E8C\u8FBA\u9023\u7D50\
    \u6210\u5206\u5206\u89E3\u3092\u884C\u3046\u3002\n     */\n    TwoEdgeConnectedComponents(Graph<CostType>\
    \ &graph) : G(graph){\n        LowLink<CostType> lowlink(G);\n        belong_components_.resize(G.get_vertex_size(),\
    \ -1);\n        vector<Edge<CostType>> bridges = lowlink.get_bridge();\n     \
    \   vector<bool> is_bridge(G.get_edge_size(), false);\n        for(Edge<CostType>\
    \ &es : bridges){\n            is_bridge[es.id] = true;\n        }\n        vector<bool>\
    \ visited(G.get_vertex_size(), false);\n        queue<Vertex> que;\n        for(int\
    \ s = 0; s < G.get_vertex_size(); ++s){\n            if(visited[s]) continue;\n\
    \            que.push(s);\n            visited[s] = true;\n            int component_index\
    \ = components_.size();\n            components_.push_back({});\n            while(que.size()){\n\
    \                Vertex v = que.front();\n                components_.back().push_back(v);\n\
    \                belong_components_[v] = component_index;\n                que.pop();\n\
    \                for(Edge<CostType> &es : G[v]){\n                    if(is_bridge[es.id])\
    \ continue;\n                    if(visited[es.to]) continue;\n              \
    \      que.push(es.to);\n                    visited[es.to] = true;\n        \
    \        }\n            }\n        }\n        adjacent_list_of_bridge_tree_.resize(components_.size());\n\
    \        for(int i = 0; i < bridges.size(); ++i){\n            if(is_bridge[bridges[i].id]){\n\
    \                Vertex u = get_belong_component(bridges[i].from);\n         \
    \       Vertex v = get_belong_component(bridges[i].to);\n                adjacent_list_of_bridge_tree_[u].emplace_back(v,\
    \ bridges[i].cost);\n                adjacent_list_of_bridge_tree_[v].emplace_back(u,\
    \ bridges[i].cost);\n            }\n        }\n    }\n\n    /**\n     * @brief\
    \ \u3059\u3079\u3066\u306E\u4E8C\u8FBA\u9023\u7D50\u6210\u5206\u3068\u305D\u308C\
    \u306B\u542B\u307E\u308C\u308B\u3059\u3079\u3066\u306E\u9802\u70B9\u3092\u5217\
    \u6319\u3059\u308B\u3002\n     */\n    vector<vector<Vertex>> &get_components(){\n\
    \        return components_;\n    }\n\n    /**\n     * @brief \u9802\u70B9 `v`\
    \ \u304C\u6240\u5C5E\u3059\u308B\u4E8C\u8FBA\u9023\u7D50\u6210\u5206\u306E\u30A4\
    \u30F3\u30C7\u30C3\u30AF\u30B9\u3092\u8FD4\u3059\u3002\n     */\n    int get_belong_component(Vertex\
    \ v) const {\n        return belong_components_[v];\n    }\n\n    /**\n     *\
    \ @brief \u4E8C\u8FBA\u9023\u7D50\u6210\u5206\u3092\u7E2E\u7D04\u3057\u305F\u6839\
    \u4ED8\u304D\u6728\u3092\u751F\u6210\u3059\u308B\u3002\n     * @note verify :\
    \ https://atcoder.jp/contests/arc039/tasks/arc039_d\n     * @return RootedTree<CostType>\
    \ \u4E8C\u8FBA\u9023\u7D50\u6210\u5206\u3092\u7E2E\u7D04\u3057\u305F\u6839\u4ED8\
    \u304D\u6728\n     */\n    RootedTree<CostType> ConstructBridgeTree() const {\n\
    \        int V = (int)components_.size();\n        RootedTree<CostType> ret(V);\n\
    \        auto dfs = [&](auto self, Vertex v, Vertex p) -> void {\n           \
    \ for(auto [u, c] : adjacent_list_of_bridge_tree_[v]){\n                if(u ==\
    \ p) continue;\n                ret.AddEdge(v, u, c);\n                self(self,\
    \ u, v);\n            }\n        };\n        dfs(dfs, 0, -1);\n        return\
    \ ret;\n    }\n    \n    private:\n    Graph<CostType> &G;\n\n    vector<vector<Vertex>>\
    \ components_;\n    vector<int> belong_components_;\n    vector<vector<pair<int,\
    \ CostType>>> adjacent_list_of_bridge_tree_;\n};\n#line 5 \"verify/LC-TwoEdgeConnectedComponents.test.cpp\"\
    \n\nint main(){\n    int N, M; cin >> N >> M;\n    Graph<int> G(N);\n    G.InputGraph(M,\
    \ false, false);\n\n    TwoEdgeConnectedComponents<int> tecc(G);\n    auto ans\
    \ = tecc.get_components();\n    cout << ans.size() << endl;\n    for(auto &vs\
    \ : ans){\n        cout << vs.size();\n        for(auto &v : vs){\n          \
    \  cout << \" \" << v;\n        }\n        cout << endl;\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/two_edge_connected_components\"\
    \n\n#include \"../Library/Template.hpp\"\n#include \"../Library/Graph/TwoEdgeConnectedComponents.hpp\"\
    \n\nint main(){\n    int N, M; cin >> N >> M;\n    Graph<int> G(N);\n    G.InputGraph(M,\
    \ false, false);\n\n    TwoEdgeConnectedComponents<int> tecc(G);\n    auto ans\
    \ = tecc.get_components();\n    cout << ans.size() << endl;\n    for(auto &vs\
    \ : ans){\n        cout << vs.size();\n        for(auto &v : vs){\n          \
    \  cout << \" \" << v;\n        }\n        cout << endl;\n    }\n}"
  dependsOn:
  - Library/Template.hpp
  - Library/Common.hpp
  - Library/Graph/TwoEdgeConnectedComponents.hpp
  - Library/Graph/LowLink.hpp
  - Library/Graph/Graph.hpp
  - Library/Tree/Tree.hpp
  isVerificationFile: true
  path: verify/LC-TwoEdgeConnectedComponents.test.cpp
  requiredBy: []
  timestamp: '2024-11-18 02:33:08+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/LC-TwoEdgeConnectedComponents.test.cpp
layout: document
redirect_from:
- /verify/verify/LC-TwoEdgeConnectedComponents.test.cpp
- /verify/verify/LC-TwoEdgeConnectedComponents.test.cpp.html
title: verify/LC-TwoEdgeConnectedComponents.test.cpp
---