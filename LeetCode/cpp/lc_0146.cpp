/**
 * @file     lc_0146.cpp
 * @brief    https://leetcode-cn.com/problems/lru-cache/
 * @author   YongDu
 * @date     2021-09-11
 */
// 最近最久未使用，按访问时间淘汰
class LRUCache {
  using CacheList = std::list<std::pair<int, int>>;

public:
  LRUCache(int capacity) : capacity(capacity) {}

  int get(int key) {
    int retVal = -1;
    auto &&iter = cacheMap.find(key);
    if (iter != cacheMap.end()) {
      auto &needMove = iter->second;
      retVal = needMove->second;
      cacheList.emplace_front(std::move(*needMove));
      cacheList.erase(needMove);
      cacheMap[key] = cacheList.begin();
    }
    return retVal;
  }

  void put(int key, int value) {
    auto &&iter = cacheMap.find(key);
    if (iter != cacheMap.end()) {
      auto &needMove = iter->second;
      needMove->second = value;
      cacheList.emplace_front(std::move(*needMove));
      cacheList.erase(needMove);
      cacheMap[key] = cacheList.begin();
      return;
    }
    if (cacheMap.size() == static_cast<size_t>(capacity)) {
      int needDelKey = cacheList.back().first;
      cacheList.pop_back();
      cacheMap.erase(needDelKey);
    }
    cacheList.emplace_front(std::make_pair(key, value));
    cacheMap[key] = cacheList.begin();
    return;
  }

private:
  int capacity;
  CacheList cacheList;
  std::unordered_map<int, CacheList::iterator> cacheMap;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
