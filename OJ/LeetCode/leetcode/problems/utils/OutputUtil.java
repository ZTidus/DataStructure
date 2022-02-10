package utils;

/**
 * 辅助 debug
 */
public class OutputUtil {
    private OutputUtil() {} // ban new this class
    public static final String ONE_SPACE = "";
    /**
     * print int[] type arrays
     * @param nums
     * @return
     */
    public static void printIntArray(int[] nums) {
        String res = "[{0}]";
        String temp = "";
        for (int i = 0; i < nums.length; i++) {
            temp += nums[i];
            temp += ONE_SPACE;
        }
        System.out.println(String.format(res, temp));
    }

}
