/**
 * @file     lc_0705.cpp
 * @brief    https://leetcode-cn.com/problems/design-hashset/
 * @author   YongDu
 * @date     2021-09-11
 */

class MyHashSet {
  public:
    MyHashSet() : data_(kBase) {}

    void add(int key) {
        if (contains(key)) {
            return;
        }
        data_[hash(key)].emplace_back(key);
    }

    void remove(int key) {
        if (contains(key)) {
            data_[hash(key)].remove(key);
        }
    }

    bool contains(int key) {
        int h = hash(key);
        for (int num : data_[h]) {
            if (num == key) {
                return true;
            }
        }
        return false;
    }

  private:
    std::vector<std::list<int>> data_;
    static const int kBase = 769;
    static int hash(int key) { return key % kBase; }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */
