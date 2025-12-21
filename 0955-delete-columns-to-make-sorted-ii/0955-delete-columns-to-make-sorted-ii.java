class Solution {
    public int minDeletionSize(String[] strs) {
       int n=strs.length;
        int count=0;
        boolean[] ans=new boolean[n];
        for(int i=0;i<strs[0].length();i++){
            int j=0;
            for(;j<strs.length-1;j++){
                if(!ans[j] && strs[j].charAt(i)>strs[j+1].charAt(i)){
                    count++;
                    break;
                }
            }
            if(j<strs.length-1){
                continue;
            }
            j=0;
            for( ;j<strs.length-1;j++){
                if(strs[j].charAt(i)<strs[j+1].charAt(i)){
                    ans[j]=true;
                }
            }
        }
        
        return count;
    }
    
}