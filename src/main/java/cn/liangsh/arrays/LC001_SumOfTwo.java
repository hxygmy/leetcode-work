package cn.liangsh.arrays;

import java.util.HashMap;
import java.util.Map;

/**
 * @author Liangsh
 * @description
 * @date 2022/5/23 13:52
 */
public class LC001_SumOfTwo {


    public int[] twoSum(int[] nums, int target) {
        // 用map存储元素及其索引
        Map<Integer, Integer> map = new HashMap<>();
        int[] res = new int[2];

        for (int i = 0; i < nums.length; i++) {
            // 判断两数之和
            if (map.containsKey(target - nums[i])) {
                res[0] = i;
                res[1] = map.get(target - nums[i]);
            } else {
                map.put(nums[i], i);
            }
        }

        return res;
    }
}
