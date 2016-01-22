class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int coin_size = coins.size();
        sort(coins.begin(), coins.end());
        vector<int> num(amount+1, -1);
        num[0] = 0;
        for (int i=1; i<=amount; i++) {
            int number = INT_MAX;
            for (int j=0; j<coin_size; j++) {
                if (coins[j] > i) break;
                if (num[i-coins[j]] != -1 && num[i-coins[j]]+1 < number) number = num[i-coins[j]]+1;
            }
            num[i] = number==INT_MAX ? -1 : number;
        }
        return num[amount];
    }
};
