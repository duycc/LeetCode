/**
 * @file     lc_0460.cpp
 * @brief    https://leetcode-cn.com/problems/lfu-cache/
 * @author   YongDu
 * @date     2021-09-11
 */
// 最近最少使用 按使用频次淘汰
struct CacheNode {
  int _key;   // 键
  int _value; // 值
  int _freq;  // 频数

  CacheNode(int key, int value, int freq = 1) : _key(key), _value(value), _freq(freq) {}
};

class LFUCache {
  using CacheList = std::list<CacheNode>;

public:
  LFUCache(int capacity) : capacity(capacity) {}

  int get(int key) {
    if (keyToCacheNode.find(key) != keyToCacheNode.end()) {
      int value = keyToCacheNode[key]->_value;
      update(key, value);
      return value;
    }
    return -1;
  }

  void put(int key, int value) {
    if (0 == capacity) {
      return;
    }
    if (keyToCacheNode.find(key) != keyToCacheNode.end()) { // key存在
      update(key, value);
      return;
    }

    if (keyToCacheNode.size() == capacity) { // key不存在且缓存容量已满
      int delKey = freqToCacheList[minFreq].back()._key;
      freqToCacheList[minFreq].pop_back();
      if (freqToCacheList[minFreq].empty()) {
        freqToCacheList.erase(minFreq);
      }
      keyToCacheNode.erase(delKey);
    }

    CacheNode newNode(key, value);
    freqToCacheList[1].emplace_front(std::move(newNode));
    minFreq = 1;
    keyToCacheNode[key] = freqToCacheList[1].begin();
    return;
  }

private:
  int capacity; // 缓存容量
  int minFreq;  // 最小频数

  std::unordered_map<int, CacheList::iterator> keyToCacheNode; // key -> CacheNode
  std::unordered_map<int, CacheList> freqToCacheList;          // freq -> CacheList

  void update(int key, int value) {
    auto &oldNode = keyToCacheNode[key];
    int oldFreq = oldNode->_freq;
    // 删除旧节点
    freqToCacheList[oldFreq].erase(oldNode);
    if (freqToCacheList[oldFreq].empty()) {
      freqToCacheList.erase(oldFreq);
      if (oldFreq == minFreq) {
        ++minFreq;
      }
    }
    // 插入新节点
    int newFreq = oldFreq + 1;
    CacheNode newNode(key, value, newFreq);
    freqToCacheList[newFreq].emplace_front(std::move(newNode));
    // 更新
    keyToCacheNode[key] = freqToCacheList[newFreq].begin();
    return;
  }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
