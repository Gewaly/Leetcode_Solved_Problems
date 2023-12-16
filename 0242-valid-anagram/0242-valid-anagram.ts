function isAnagram(s: string, t: string): boolean {
    t=t.split("").sort().join("");
        s=s.split("").sort().join("");
        return s==t;
    
};