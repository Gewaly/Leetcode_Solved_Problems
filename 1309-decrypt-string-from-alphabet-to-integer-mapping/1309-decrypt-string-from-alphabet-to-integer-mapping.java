 class Solution {
    public String freqAlphabets(String s) {
        String rtnAns = "";
        int index = 0;
        while(index<s.length()){
            if(index < s.length() - 2 && s.charAt(index + 2) == '#'){
                int num = Integer.parseInt(s.substring(index, index + 2));
                rtnAns += (char)(num + 96);
                index = index + 3;
                continue;
            }
            rtnAns += (char)(97 + s.charAt(index) - '1');
            index++;
        }
        return rtnAns;
    }
}