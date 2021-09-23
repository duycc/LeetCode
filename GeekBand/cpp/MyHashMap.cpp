/**
 * @file     MyHashMap.cpp
 * @brief    https://leetcode-cn.com/problems/design-hashmap/
 * @author   YongDu
 * @date     2021-09-05
 */
class MyHashMap {
public:
  /** Initialize your data structure here. */
  MyHashMap() : data(base) {}

  /** value will always be non-negative. */
  void put(int key, int value) {
    int h = hash(key);
    for (auto &&iter = data[h].begin(); iter != data[h].end(); ++iter) {
      if ((*iter).first == key) {
        (*iter).second = value;
        return;
      }
    }
    data[h].emplace_back(std::make_pair(key, value));
  }

  /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
  int get(int key) {
    int h = hash(key);
    for (auto &&iter = data[h].begin(); iter != data[h].end(); ++iter) {
      if ((*iter).first == key) {
        return (*iter).second;
      }
    }
    return -1;
  }

  /** Removes the mapping of the specified value key if this map contains a mapping for the key */
  void remove(int key) {
    int h = hash(key);
    for (auto &&iter = data[h].begin(); iter != data[h].end(); ++iter) {
      if ((*iter).first == key) {
        data[h].erase(iter);
        return;
      }
    }
    return;
  }

private:
  vector<list<pair<int, int>>> data;
  static const int base = 769;
  static int hash(int key) { return key % base; }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */
