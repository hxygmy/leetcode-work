package cn.liangsh.greed;

/**
 * @author Liangsh
 * @description 买卖股票的最佳时机含手续费
 * @date 2022/9/5 9:04
 */
public class LC714_MaxProfit {

    public int maxProfit(int[] prices, int fee) {
        int profit = 0;
        int minPrice = prices[0];

        for (int i = 0; i < prices.length; i++) {

            if (prices[i] < minPrice) {
                // 重新买入
                minPrice = prices[i];
            }

            if (prices[i] > minPrice && prices[i] <= minPrice + fee) {
                // 不做操作
                continue;
            }

            if (prices[i] > minPrice + fee) {
                // 可以卖出
                profit += prices[i] - minPrice - fee;
                // 连续获利，后续利润需要抵消手续费
                minPrice = prices[i] - fee;
            }
        }

        return profit;
    }
}
