class Solution {
    public int uniqueMorseRepresentations(String[] words) {
        Set<String> s = new HashSet<>();
        String[] morse = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        
        Map mp = new HashMap<Character, String>();
        for (int i = 0; i < 26; i++) {
            char x = (char)(i + 'a');
            mp.put(x, morse[i]);
        }
        
        for (String str : words) {
            String temp = "";
            char[] charArray = str.toCharArray();
            for (char c : charArray) {
                temp += mp.get(c);
            }
            s.add(temp);
        }
        return s.size();
    }
}
