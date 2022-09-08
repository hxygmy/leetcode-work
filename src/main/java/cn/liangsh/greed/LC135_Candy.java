package cn.liangsh.greed;

/**
 * @author Liangsh
 * @description 分发糖果
 * @date 2022/8/15 8:51
 */
public class LC135_Candy {
    public static void main(String[] args) {
        int[] ratings = {1, 0, 2};

        System.out.println(new LC135_Candy().candy(ratings));
    }

    public int candy(int[] ratings) {
        int[] candies = new int[ratings.length];
        // 给第一个先发一个糖果
        candies[0] = 1;

        // 从左往右遍历
        for (int i = 1; i < ratings.length; i++) {
            // 右边比左边大，则右边的糖果 + 1
            if (ratings[i] > ratings[i - 1]) {
                candies[i] = candies[i - 1] + 1;
            } else {
                candies[i] = 1;
            }

        }

        // 从右往左遍历,利用之前的比较结果
        for (int i = ratings.length - 2; i >= 0; i--) {
            // 左边比右边大，则在右边值 + 1 和左边原有值中取最大，保证i的值比两边大
            if (ratings[i] > ratings[i + 1]) {
                candies[i] = Math.max(candies[i + 1] + 1, candies[i]);
            }

        }

        // 计算结果
        int result = 0;
        for (int candy : candies) {
            result += candy;
        }
        return result;
    }

}
