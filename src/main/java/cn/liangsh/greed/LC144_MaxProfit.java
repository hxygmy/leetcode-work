package cn.liangsh.greed;

/**
 * @author Liangsh
 * @description 买卖股票的最佳时机||
 * @date 2022/8/10 8:48
 */
public class LC144_MaxProfit {

    public int maxProfit(int[] prices) {
        int result = 0;
        // 从第二天开始计算利润
        for (int i = 1; i < prices.length; i++) {
            result += Math.max(prices[i] - prices[i - 1], 0);
        }

        return result;
    }
}
