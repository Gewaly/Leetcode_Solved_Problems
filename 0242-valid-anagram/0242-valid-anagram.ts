function isAnagram(s: string, t: string): boolean {
    t=t.split("").sort().join("");
        s=s.split("").sort().join("");
    console.log(s," ",t);
        if(s==t) return true;
        return false;
    
};