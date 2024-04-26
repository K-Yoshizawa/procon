#pragma once

/**
 * @file UnionFind.hpp
 * @author log K (lX57)
 * @brief UnionFind - 素集合データ構造
 * @version 3.0
 * @date 2024-04-26
 */

#include <bits/stdc++.h>
using namespace std;

template<typename T = int>
struct UnionFind{
    private:
    vector<int> m_data;

    public:
    /**
     * @brief 要素数 `Size` でUnionFindを初期化する。
     * @param Size 要素数
     */
    UnionFind(int Size) : m_data(Size, -1){}

    /**
     * @brief 要素 `k` の親を返す。ついでに経路圧縮をする。
     * @param k 探索する要素
     * @return int 親要素の番号
     */
    int find(int k){
        if(m_data[k] < 0) return k;
        int r = find(m_data[k]);
        return m_data[k] = r;
    }

    /**
     * @brief 要素 `x` と要素 `y` が同じ集合に属しているかを判定する。
     */
    bool same(int x, int y){
        return find(x) == find(y);
    }

    /**
     * @brief 要素 `x` と要素 `y` を併合する。
     * @return 併合済の場合は `false` を返す。
     */
    bool unite(int x, int y){
        x = find(x), y = find(y);
        if(x == y) return false;
        if(m_data[x] > m_data[y]) swap(x, y);
        m_data[x] += m_data[y];
        m_data[y] = x;
        return true;
    }

    vector<vector<int>> group(){
        vector<vector<int>> ret(m_data.size());
        for(int i = 0; i < m_data.size(); ++i){
            ret[find(i)].emplace_back(i);
        }
        ret.erase(remove_if(begin(ret), end(ret), [&](vector<int> &v){
            return v.empty();
        }), end(ret));
        return ret;
    }
};