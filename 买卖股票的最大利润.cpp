//https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock/
int maxProfit(vector<int>& prices) {
	int last = 0, profit = 0;
	for (int i = 0; i < (int)prices.size() - 1; ++i) {
		last = max(0, last + prices[i + 1] - prices[i]);
		profit = max(profit, last);
	}
	return profit;
}