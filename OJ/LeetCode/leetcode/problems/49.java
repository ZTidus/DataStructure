import java.util.*;

class GroupAnagrams {
    public List<List<String>> groupAnagrams(String[] strs) {
        if (strs.length == 0)
            return new ArrayList();
        Map<String, List> mp = new HashMap<String, List>();

        for (String s : strs) {
            char[] ca = s.toCharArray();
            Arrays.sort(ca);
            String key = String.valueOf(ca);
            if (!mp.containsKey(key))
                mp.put(key, new ArrayList());
            mp.get(key).add(s);
        }

        return new ArrayList(mp.values());
    }
}
