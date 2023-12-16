function isAnagram(s: string, t: string): boolean {
    t=t.split("").sort().join("");
        s=s.split("").sort().join("");
        if(s==t) return true;
        return false;
    
};