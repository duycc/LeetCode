/**
 * @file     lc_0703.cpp
 * @brief    https://leetcode-cn.com/problems/kth-largest-element-in-a-stream/
 * @author   YongDu
 * @date     2021-09-11
 */
class KthLargest {
  public:
    KthLargest(int k, vector<int>& nums) {
        this->k_ = k;
        for (int n : nums) {
            priQue_.push(n);
            if (priQue_.size() > k_) {
                priQue_.pop();
            }
        }
    }

    int add(int val) {
        priQue_.push(val);
        if (priQue_.size() > k_) {
            priQue_.pop();
        }
        return priQue_.top();
    }

  private:
    std::priority_queue<int, std::vector<int>, std::greater<int>> priQue_;
    int k_;
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */