package cn.liangsh.backtracking;

import java.util.*;

/**
 * @author Liangsh
 * @description 重新安排行程
 * @date 2022/7/25 9:13
 */
public class LC332_FindItinerary {

    /**
     * 存储航班起始位置以及目的地和剩余次数
     */
    Map<String, Map<String, Integer>> map = new HashMap<>();
    List<String> result = new ArrayList<>();


    public List<String> findItinerary(List<List<String>> tickets) {

        for (List<String> ticket : tickets) {
            Map<String, Integer> temp;
            // 有过航班记录
            if (map.containsKey(ticket.get(0))) {
                temp = map.get(ticket.get(0));
                // 将当前航班次数+1
                temp.put(ticket.get(1), temp.getOrDefault(ticket.get(1), 0) + 1);
            } else {
                temp = new TreeMap<>();
                temp.put(ticket.get(1), 1);
            }

            map.put(ticket.get(0), temp);
        }
        result.add("JFK");
        backtracking(tickets.size());

        return result;
    }

    private boolean backtracking(int ticketNum) {
        if (result.size() == ticketNum + 1) {
            return true;
        }

        String last = result.get(result.size() - 1);
        // 防止null
        if (map.containsKey(last)) {
            for (Map.Entry<String, Integer> s : map.get(last).entrySet()) {
                int count = s.getValue();
                if (count > 0) {
                    result.add(s.getKey());
                    s.setValue(count - 1);
                    if (backtracking(ticketNum)) {
                        return true;
                    }
                    result.remove(result.size() - 1);
                    s.setValue(count);
                }

            }
        }

        return false;
    }

}
