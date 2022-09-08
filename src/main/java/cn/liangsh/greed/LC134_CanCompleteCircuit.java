package cn.liangsh.greed;

/**
 * @author Liangsh
 * @description 加油站
 * @date 2022/8/12 10:36
 */
public class LC134_CanCompleteCircuit {

    public int canCompleteCircuit(int[] gas, int[] cost) {
        // 当前剩余油量和总油量
        int cur = 0;
        int total = 0;
        // 起始位置
        int start = 0;
        for (int i = 0; i < cost.length; i++) {
            cur += gas[i] - cost[i];
            total += gas[i] - cost[i];

            if (cur < 0) {
                // 若当前位置剩余油量小于0，则说明从start开始的位置不能使用
                start = (i + 1) % cost.length;
                cur = 0;
            }
        }

        if (total < 0) {
            // 总油量不足
            return -1;
        }

        return start;
    }
}
