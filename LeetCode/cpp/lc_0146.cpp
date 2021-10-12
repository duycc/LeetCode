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
  LRUCache(int capacity_) : capacity(capacity_) {}

  int get(int key) {
    int ret = -1;
    auto &&iter = cacheMap.find(key);
    if (iter != cacheMap.end()) {
      ret = iter->second->second;
      cacheList.splice(cacheList.begin(), cacheList, iter->second);
      cacheMap[key] = cacheList.begin();
    }
    return ret;
  }

  void put(int key, int value) {
    auto &&iter = cacheMap.find(key);
    if (iter != cacheMap.end()) { // key存在
      iter->second->second = value;
      cacheList.splice(cacheList.begin(), cacheList, iter->second);
      cacheMap[key] = cacheList.begin();
      return;
    }
    // key不存在
    if (cacheList.size() == capacity) {
      cacheMap.erase(cacheList.back().first);
      cacheList.pop_back();
    }
    cacheList.emplace_front(std::make_pair(key, value));
    cacheMap[key] = cacheList.begin();
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
