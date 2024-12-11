---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: "Compress - \u5EA7\u6A19\u5727\u7E2E"
    links: []
  bundledCode: "#line 1 \"Library/unauthenticated/Compress.hpp\"\n/**\n * @file Compress.hpp\n\
    \ * @author log_K (lX57)\n * @brief Compress - \u5EA7\u6A19\u5727\u7E2E\n * @version\
    \ 2.0\n * @date 2024-02-04\n */\n\n#include <bits/stdc++.h>\nusing namespace std;\n\
    \ntemplate<typename T>\nstruct Compress{\n    private:\n    size_t size_;\n  \
    \  int offset_;\n    vector<T> value_;\n\n    public:\n    /**\n     * @brief\
    \ \u914D\u5217 `value` \u3092\u521D\u671F\u5024\u3068\u3057\u3066\u767B\u9332\u3059\
    \u308B\u3002\n     * @param values \u521D\u671F\u914D\u5217\n     * @param offset\
    \ \u5EA7\u6A19\u5727\u7E2E\u5F8C\u306E\u5148\u982D\u306E\u5024 (default = 0)\n\
    \     */\n    Compress(vector<T> &values, int offset = 0) : value_(values), offset_(offset){}\n\
    \n    /**\n     * @brief \u5EA7\u6A19\u5727\u7E2E\u3092\u5B9F\u884C\u3059\u308B\
    \u3002\n     */\n    void build(){\n        sort(value_.begin(), value_.end());\n\
    \        value_.erase(unique(value_.begin(), value_.end()), value_.end());\n \
    \       size_ = value_.size();\n    }\n\n    vector<int> convert(vector<T> &v){\n\
    \        vector<int> ret;\n        for(auto x : v) ret.push_back(to_index(x));\n\
    \        return ret;\n    }\n\n    /**\n     * @brief \u914D\u5217\u306B\u5024\
    \u3092\u52A0\u3048\u308B\u3002\n     * @param value \u52A0\u3048\u308B\u5024\n\
    \     */\n    void add(T value){\n        value_.push_back(value);\n    }\n\n\
    \    /**\n     * @brief `value` \u3092\u5BFE\u5FDC\u3059\u308B `index` \u306B\u5909\
    \u63DB\u3059\u308B\u3002\n     */\n    int to_index(T value){\n        int ret\
    \ = (int)(lower_bound(value_.begin(), value_.end(), value) - value_.begin());\n\
    \        assert(ret < size_);\n        return ret + offset_;\n    }\n\n    /**\n\
    \     * @brief `index` \u3092\u5BFE\u5FDC\u3059\u308B `value` \u306B\u5909\u63DB\
    \u3059\u308B\u3002 \n     */\n    T to_value(int index){\n        return value_.at(index\
    \ - offset_);\n    }\n\n    int operator[](T value){\n        return to_index(value);\n\
    \    }\n\n    size_t size(){\n        return size_;\n    }\n};\n"
  code: "/**\n * @file Compress.hpp\n * @author log_K (lX57)\n * @brief Compress -\
    \ \u5EA7\u6A19\u5727\u7E2E\n * @version 2.0\n * @date 2024-02-04\n */\n\n#include\
    \ <bits/stdc++.h>\nusing namespace std;\n\ntemplate<typename T>\nstruct Compress{\n\
    \    private:\n    size_t size_;\n    int offset_;\n    vector<T> value_;\n\n\
    \    public:\n    /**\n     * @brief \u914D\u5217 `value` \u3092\u521D\u671F\u5024\
    \u3068\u3057\u3066\u767B\u9332\u3059\u308B\u3002\n     * @param values \u521D\u671F\
    \u914D\u5217\n     * @param offset \u5EA7\u6A19\u5727\u7E2E\u5F8C\u306E\u5148\u982D\
    \u306E\u5024 (default = 0)\n     */\n    Compress(vector<T> &values, int offset\
    \ = 0) : value_(values), offset_(offset){}\n\n    /**\n     * @brief \u5EA7\u6A19\
    \u5727\u7E2E\u3092\u5B9F\u884C\u3059\u308B\u3002\n     */\n    void build(){\n\
    \        sort(value_.begin(), value_.end());\n        value_.erase(unique(value_.begin(),\
    \ value_.end()), value_.end());\n        size_ = value_.size();\n    }\n\n   \
    \ vector<int> convert(vector<T> &v){\n        vector<int> ret;\n        for(auto\
    \ x : v) ret.push_back(to_index(x));\n        return ret;\n    }\n\n    /**\n\
    \     * @brief \u914D\u5217\u306B\u5024\u3092\u52A0\u3048\u308B\u3002\n     *\
    \ @param value \u52A0\u3048\u308B\u5024\n     */\n    void add(T value){\n   \
    \     value_.push_back(value);\n    }\n\n    /**\n     * @brief `value` \u3092\
    \u5BFE\u5FDC\u3059\u308B `index` \u306B\u5909\u63DB\u3059\u308B\u3002\n     */\n\
    \    int to_index(T value){\n        int ret = (int)(lower_bound(value_.begin(),\
    \ value_.end(), value) - value_.begin());\n        assert(ret < size_);\n    \
    \    return ret + offset_;\n    }\n\n    /**\n     * @brief `index` \u3092\u5BFE\
    \u5FDC\u3059\u308B `value` \u306B\u5909\u63DB\u3059\u308B\u3002 \n     */\n  \
    \  T to_value(int index){\n        return value_.at(index - offset_);\n    }\n\
    \n    int operator[](T value){\n        return to_index(value);\n    }\n\n   \
    \ size_t size(){\n        return size_;\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: Library/unauthenticated/Compress.hpp
  requiredBy: []
  timestamp: '2024-09-04 01:04:48+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Library/unauthenticated/Compress.hpp
layout: document
redirect_from:
- /library/Library/unauthenticated/Compress.hpp
- /library/Library/unauthenticated/Compress.hpp.html
title: "Compress - \u5EA7\u6A19\u5727\u7E2E"
---