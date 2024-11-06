// Question: 1431. Kids With the Greatest Number of Candies

// Meaning of question
// Compute if array[i] add a number will be the greatest number of this array.

// ------------------------------ code ------------------------------

//class Solution {
//    public List<Boolean> kidsWithCandies(int[] candies, int extraCandies) {
//        List<Boolean> res = new ArrayList<>();
//
//        int maxV = Arrays.stream(candies).max().getAsInt();
//
//        for (int i = 0; i < candies.length; i++) {
//            if ((candies[i] + extraCandies) >= maxV) {
//                res[i] = true;
//            } else {
//                res[i] = false;
//            }
//        }
//
//        return res;
//    }
//}

// RunTime: 2ms

// ------------------------------ code ------------------------------

//class Solution {
//    public List<Boolean> kidsWithCandies(int[] candies, int extraCandies) {
//
//        int maxV = -1;
//
//        // compute max
//        for (int i = 0; i < candies.length; i++) {
//            maxV = Math.max(candies[i], maxV);
//        }
//
//        List<Boolean> res = new ArrayList<>();
//        for (int i = 0; i < candies.length; i++) {
//            res.add((candies[i] + extraCandies) >= maxV);
//        }
//        return res;
//    }
//}

// RunTime: 1ms

