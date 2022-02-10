import com.sun.xml.internal.ws.api.message.Message;
import utils.OutputUtil;

import java.util.HashMap;
import java.util.Map;

public class NextGreaterElementI {
    public int[] nextGreaterElement(int[] nums1, int[] nums2) {
        Map<Integer, Integer> nums2Map = new HashMap<>();
        // put {num: index} into map
        for (int i = 0; i < nums2.length; i++) {
            if (nums2Map.containsKey(nums2[i])) {
                // nothing to do
            } else {
                nums2Map.put(nums2[i], i);
            }
        }
        int[] res = new int[nums1.length];
        for (int i = 0; i < nums1.length; i++) {
            int start = nums2Map.get(nums1[i]) + 1;
            if (start == nums2.length) {
                res[i] = -1;
            }
            int has = -1;
            for (int j = start; j < nums2.length; j++) {
                if (nums1[i] < nums2[j]) {
                    has = nums2[j];
                    break;
                }
            }
            res[i] = has;
        }
        return res;
    }

    public static void main(String[] args) {
        NextGreaterElementI solution = new NextGreaterElementI();
        int[] nums1 = new int[]{4, 1, 2};
        int[] nums2 = new int[]{1,3,4,2};
        int[] res = solution.nextGreaterElement(nums1, nums2);
        OutputUtil.printIntArray(res);


    }

}
