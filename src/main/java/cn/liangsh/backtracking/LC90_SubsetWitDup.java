package cn.liangsh.backtracking;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

/**
 * @author Liangsh
 * @description 子集去重
 * @date 2022/7/19 10:34
 */
public class LC90_SubsetWitDup {

    List<List<Integer>> result = new ArrayList<>();
    List<Integer> path = new ArrayList<>();

    public List<List<Integer>> subsetsWithDup(int[] nums) {

        Arrays.sort(nums);
        backtracking(nums, 0);

        return result;
    }

    private void backtracking(int[] nums, int startIndex) {
        // 每次记录节点
        result.add(new ArrayList<>(path));
        if (startIndex >= nums.length) {
            return;
        }

        for (int i = startIndex; i < nums.length; i++) {
            // 去重
            if (i > startIndex && nums[i] == nums[i - 1]) {
                continue;
            }
            path.add(nums[i]);
            backtracking(nums, i + 1);
            // 回溯
            path.remove(path.size() - 1);
        }

    }
}
