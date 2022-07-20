package cn.liangsh.backtracking;

import java.util.ArrayList;
import java.util.List;

/**
 * @author Liangsh
 * @description 寻找递增子序列
 * @date 2022/7/20 8:56
 */
public class LC491_FindSubsequences {

    List<List<Integer>> result = new ArrayList<>();
    List<Integer> path = new ArrayList<>();


    public List<List<Integer>> findSubsequences(int[] nums) {

        backtracking(nums, 0);
        return result;
    }

    private void backtracking(int[] nums, int startIndex) {
        // 记录每个节点，并将序列长度大于1的记录结果
        if (path.size() > 1) {
            result.add(new ArrayList<>(path));
        }

        // 数组记录重复使用过的元素
        int[] used = new int[201];
        for (int i = startIndex; i < nums.length; i++) {
            if (!path.isEmpty() && nums[i] < path.get(path.size() - 1)
                    || used[nums[i] + 100] == 1) {
                continue;
            }

            used[nums[i] + 100] = 1;
            path.add(nums[i]);

        }


    }
}
