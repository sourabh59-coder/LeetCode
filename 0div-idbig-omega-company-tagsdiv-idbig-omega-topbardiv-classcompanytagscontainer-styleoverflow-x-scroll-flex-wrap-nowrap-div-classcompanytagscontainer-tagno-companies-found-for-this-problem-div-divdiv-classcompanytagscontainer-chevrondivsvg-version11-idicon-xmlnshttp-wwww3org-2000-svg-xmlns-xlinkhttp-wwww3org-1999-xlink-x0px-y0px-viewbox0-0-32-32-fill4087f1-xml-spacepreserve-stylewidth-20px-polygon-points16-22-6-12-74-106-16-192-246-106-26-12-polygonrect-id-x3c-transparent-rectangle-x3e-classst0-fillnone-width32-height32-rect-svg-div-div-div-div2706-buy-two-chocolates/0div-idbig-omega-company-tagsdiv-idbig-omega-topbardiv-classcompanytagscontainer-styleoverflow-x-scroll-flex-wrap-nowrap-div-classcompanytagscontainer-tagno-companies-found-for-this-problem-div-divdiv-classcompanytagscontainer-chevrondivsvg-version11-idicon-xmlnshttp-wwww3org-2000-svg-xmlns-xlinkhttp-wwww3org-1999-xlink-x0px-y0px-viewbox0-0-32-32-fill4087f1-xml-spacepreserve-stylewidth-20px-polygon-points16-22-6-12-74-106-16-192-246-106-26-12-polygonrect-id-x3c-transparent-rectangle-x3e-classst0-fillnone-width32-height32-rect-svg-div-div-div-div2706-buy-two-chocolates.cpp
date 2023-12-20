class Solution {
public:
    int buyChoco(vector<int>& chocolatePrices, int availableMoney) {
        int minPrice = min(chocolatePrices[0], chocolatePrices[1]);
        int secondMinPrice = max(chocolatePrices[0], chocolatePrices[1]);

        for (int i = 2; i < chocolatePrices.size(); i++) {
            if (chocolatePrices[i] < minPrice) {
                secondMinPrice = minPrice;
                minPrice = chocolatePrices[i];
            } else if (chocolatePrices[i] < secondMinPrice) {
                secondMinPrice = chocolatePrices[i];
            }
        }

        int minCost = minPrice + secondMinPrice;
        return (minCost <= availableMoney)? availableMoney - minCost:availableMoney;
        
    }
};
