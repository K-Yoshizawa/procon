/**
 * @file LowLink.hpp
 * @brief LowLink - 橋と関節点
 * @version 1.0
 * @date 2024-09-02
 */

#include "Graph.hpp"

template<typename CostType>
class LowLink{
    public:
    enum class EdgeClass{
        kTreeEdge,
        kBackEdge,
        kForwardEdge,
        kCrossEdge,
    };

    LowLink() = default;

    LowLink(Graph<CostType> &graph) :
            graph_(graph), ord_(graph.get_vertex_size()), low_(graph.get_vertex_size()),
            child_(graph.get_vertex_size()), state_(graph.get_vertex_size(), 0){
        for(int i = 0; i < graph.get_vertex_size(); ++i){
            if(!state_[i]) dfs(i, -1, 0);
        }
    }

    /**
     * @brief 頂点 `v` の `ord[v]` を返す。
     * @param v 頂点番号 (0-index)
     * @return int 
     */
    int get_ord(Vertex v) const {
        graph_.Validate(v);
        return ord_[v];
    }

    /**
     * @brief 頂点 `v` の `low[v]` を返す。
     * @param v 頂点番号 (0-index)
     * @return int 
     */
    int get_low(Vertex v) const {
        graph_.Validate(v);
        return low_[v];
    }

    /**
     * @brief 関節点を列挙する。
     * @note 関節点 : その頂点を除くと連結成分が増えるような頂点
     * @return vector<Vertex> 関節点の頂点番号 (0-index)
     */
    vector<Vertex> EnumrateArticulationVertex() const {
        vector<Vertex> ret;
        for(int u = 0; u < graph_.get_vertex_size(); ++u){
            if(state_[u] == 2){
                if(child_[u].size() > 1) ret.push_back(u);
                continue;
            }
            bool exist = false;
            for(Vertex v : child_[u]){
                exist |= (get_ord(u) <= get_low(v));
            }
            if(exist) ret.push_back(u);
        }
        return ret;
    }

    /**
     * @brief 橋を列挙する。
     * @note 橋 : その辺を除くと連結成分が増えるような頂点
     * @return vector<Edge<CostType>> 橋である辺
     */
    vector<Edge<CostType>> EnumrateBridge() const {
        vector<Edge<CostType>> ret;
        auto es = GraphConvertEdgeSet(graph_, false);
        for(Edge<CostType> e : es){
            Vertex u = e.from, v = e.to;
            if(get_ord(u) >= get_ord(v)) swap(u, v);
            if(get_ord(u) < get_low(v)) ret.push_back(e);
        }
        return ret;
    }

    private:
    bool dfs(Vertex v, Vertex p, int order){
        if(state_[v] != 0) return false;
        state_[v] = 1 + (p != -1);
        ord_[v] = low_[v] = order;
        for(Edge<CostType> &e : graph_[v]){
            if(e.to == p) continue;
            if(dfs(e.to, v, order + 1)){
                child_[v].push_back(e.to);
                low_[v] = min(low_[v], low_[e.to]);
            }
            else{
                low_[v] = min(low_[v], ord_[e.to]);
            }
        }
        return true;
    }

    Graph<CostType> &graph_;
    vector<int> ord_, low_, state_;
    vector<vector<Vertex>> child_;
};