class Solution {
public:
    int next(int i){
        int ret = 0;
        while(i){
            int aux = i % 10;
            ret += aux * aux;
            i /= 10;
        }
        return ret;
    }
    bool isHappy(int n) {
        int slow = n, fast = next(n);
        while(slow != fast){
            slow = next(slow);
            fast = next(next(fast));
        }
        return slow == 1;
    }
};
