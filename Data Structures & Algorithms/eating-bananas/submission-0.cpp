class Solution {
public:
    int maxElement(vector<int>& piles) {
        int maxE = INT_MIN;
        for (int i=0;i<piles.size();i++) {
            maxE = max(piles[i],maxE);
        }
        return maxE;
    }

    int totalHours(vector<int>& piles, int mid) {
        int totalH = 0;
        for (int i=0;i<piles.size();i++) {
            totalH += ceil((double)piles[i]/(double)mid);
        }
        return totalH;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1;
        int r = maxElement(piles);

        while(l<=r) {
            int mid = (l+r)/2;
            int total_hours =  totalHours(piles,mid);
            if(total_hours<=h) {
                r = mid -1;
            } else {
                l = mid +1;
            }
        }
        return l;
    }
};
