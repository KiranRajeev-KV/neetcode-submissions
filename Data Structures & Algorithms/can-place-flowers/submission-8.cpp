class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        if (n == 0) return true;

        int count = 0;
        int sz = flowerbed.size();

        if (sz == 1) {
            if (flowerbed[0] == 0) count++;
            return count >= n;
        }

        for (int i = 0; i < sz; i++) {

            if (flowerbed[i] == 1)
                continue;

            if (i == 0) {
                if (flowerbed[i + 1] == 0) {
                    flowerbed[i] = 1;
                    count++;
                }
            }
            else if (i == sz - 1) {
                if (flowerbed[i - 1] == 0) {
                    flowerbed[i] = 1;
                    count++;
                }
            }
            else {
                if (flowerbed[i - 1] == 0 &&
                    flowerbed[i + 1] == 0) {
                    flowerbed[i] = 1;
                    count++;
                }
            }

            if (count >= n)
                return true;
        }

        return false;
    }
};