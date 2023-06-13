#pragma once

/**
 * @brief Lazy Segment Tree - 遅延評価セグメント木
 */

#include <bits/stdc++.h>
using namespace std;

template <typename Monoid, typename OperatorMonoid = Monoid>
struct LazySegmentTree{
    private:
    using F = function<Monoid(Monoid, Monoid)>;
    using G = function<Monoid(Monoid, OperatorMonoid)>;
    using H = function<OperatorMonoid(OperatorMonoid, OperatorMonoid)>;

    int sz, height;
    vector<Monoid> data;
    vector<OperatorMonoid> lazy;
    const F f;
    const G g;
    const H h;
    const Monoid M1;
    const OperatorMonoid OM0;

    void propagate(int k){
        if(lazy[k] != OM0){
            lazy[2 * k + 0] = h(lazy[2 * k + 0], lazy[k]);
            lazy[2 * k + 1] = h(lazy[2 * k + 1], lazy[k]);
            data[k] = reflect(k);
            lazy[k] = OM0;
        }
    }

    Monoid reflect(int k){
        return lazy[k] == OM0 ? data[k] : g(data[k], lazy[k]);
    }

    void recalc(int k){
        while(k >>= 1) data[k] = f(reflect(2 * k + 0), reflect(2 * k + 1));
    }

    void thrust(int k){
        for(int i = height; i > 0; --i) propagate(k >> i);
    }

    public:
    /**
     * @brief Construct a new Lazy Segment Tree object
     * @param n セグ木のサイズ
     * @param f 区間取得の二項演算(Monoid - Monoid)
     * @param g 遅延評価の二項演算(Monoid - OperatorMonoid)
     * @param h 区間更新の二項演算(OperatorMonoid - OperatorMonoid)
     * @param M1 区間取得の単位元
     * @param OM0 区間更新の単位元
     */
    LazySegmentTree(int n, const F f, const G g, const H h, const Monoid &M1, const OperatorMonoid &OM0) : f(f), g(g), h(h), M1(M1), OM0(OM0){
        sz = 1, height = 0;
        while(sz < n) sz <<= 1, ++height;
        data.assign(2 * sz, M1);
        lazy.assign(2 * sz, OM0);
    }

    /**
     * @brief 0-indexのk番目の要素に値xをセットする。
     * @attention build前に呼び出すこと！
     * @param k セットする要素番号
     * @param x セットする値
     */
    void set(int k, const Monoid &x){
        data[k + sz] = x;
    }

    /**
     * @brief セグメント木を構築する。
     * @attention setで各要素の初期値はセットしましたか？
     */
    void build(){
        for(int k = sz - 1; k > 0; --k){
            data[k] = f(data[2 * k + 0], data[2 * k + 1]);
        }
    }

    /**
     * @brief 0-index半開区間[a, b)を値xを更新処理する。
     * @param a 半開区間の左端
     * @param b 半開区間の右端
     * @param x 更新する値x
     */
    void update(int a, int b, const OperatorMonoid &x){
        thrust(a += sz);
        thrust(b += sz - 1);
        for(int l = a, r = b + 1; l < r; l >>= 1, r >>= 1){
            if(l & 1) lazy[l] = h(lazy[l], x), ++l;
            if(r & 1) --r, lazy[r] = h(lazy[r], x);
        }
        recalc(a);
        recalc(b);
    }

    /**
     * @brief 0-index半開区間[a, b)に対するクエリを処理する。
     * @param a 半開区間の左端
     * @param b 半開区間の右端
     * @return Monoid クエリの結果
     */
    Monoid query(int a, int b){
        thrust(a += sz);
        thrust(b += sz - 1);
        Monoid L = M1, R = M1;
        for(int l = a, r = b + 1; l < r; l >>= 1, r >>= 1){
            if(l & 1) L = f(L, reflect(l++));
            if(r & 1) R = f(reflect(--r), R);
        }
        return f(L, R);
    }

    /**
     * @brief 0-indexの1点kに対するクエリを処理する。
     * @param k 取得したい要素
     * @return Monoid クエリの結果
     */
    Monoid query(int k){
        return query(k, k + 1);
    }

    /**
     * @brief 現在の要素kの値を得る。
     * @param k 取得したい要素
     * @return Monoid 要素の値
     */
    Monoid operator[](const int &k){
        return query(k);
    }

    /**
     * @brief 半開区間[a, b)を出力する。
     * @param a 半開区間の左端
     * @param b 半開区間の右端
     */
    void print(int a, int b){
        cerr << "LST Data [" << a << ", " << b <<") : [";
        for(int i = a; i < b; ++i) cerr << query(i) << " ]"[i == b - 1];
        cerr << endl;
    }
};