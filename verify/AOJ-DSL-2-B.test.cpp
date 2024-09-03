#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_B"

#include "../Library/Template.hpp"
#include "../Library/DataStructure/SegmentTree.hpp"

int main(){
    int n, q; cin >> n >> q;

    SegmentTree<int> seg(n, [](int l, int r){return l + r;}, 0, false);
    seg.Build();
    while(q--){
        int com, x, y; cin >> com >> x >> y;
        if(com == 0){
            seg.Update(x, seg[x] + y);
        }
        else{
            cout << seg.Query(x, y + 1) << endl;
        }
    }
}