function minChanges(s: string): number {
     let cnt=0;
    for(let i=1;i<s.length;i+=2){
        if(s[i]!=s[i-1]) cnt++;
    }
    return cnt;
};