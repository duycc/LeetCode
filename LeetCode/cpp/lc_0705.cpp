/**
 * @file     lc_0705.cpp
 * @brief    https://leetcode-cn.com/problems/design-hashset/
 * @author   YongDu
 * @date     2021-09-11
 */
class MyHashSet {
public:
  /** Initialize your data structure here. */
  MyHashSet() : data(base) {}

  void add(int key) {
    int h = hash(key);
    for (auto iter = data[h].begin(); iter != data[h].end(); ++iter) {
      if ((*iter) == key) {
        return;
      }
    }
    data[h].emplace_back(key);
  }

  void remove(int key) {
    int h = hash(key);
    for (auto iter = data[h].begin(); iter != data[h].end(); ++iter) {
      if ((*iter) == key) {
        data[h].erase(iter);
        return;
      }
    }
    return;
  }

  /** Returns true if this set contains the specified element */
  bool contains(int key) {
    int h = hash(key);
    for (auto iter = data[h].begin(); iter != data[h].end(); ++iter) {
      if ((*iter) == key) {
        return true;
      }
    }
    return false;
  }

private:
  vector<list<int>> data;
  static const int base = 769;
  static int hash(int key) { return key % base; }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */
