//https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock/
//int maxProfit(vector<int>& prices) {
//	int last = 0, ret = 0;
//	for (int i = 0; i < (int)prices.size() - 1; ++i) {
//		last = max(0, last + prices[i + 1] - prices[i]);
//		ret = max(profit, last);
//	}
//	return profit;
//}
//
//https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-ii/
//int maxProfit(vector<int>& prices) {
//	int ret = 0;
//	for (int i = 1; i<prices.size(); i++){
//		if (prices[i] > prices[i - 1])
//			ret += prices[i] - prices[i - 1];
//	}
//	return ret;
//}