var maximumLength = function(s) {
   const n = s.length;
        const mp = new Map();
        for (let i = 0; i < n; i++) {
            for (let j = i; j < n; j++) {
                let str = "";
                for (let k = i; k <= j; k++) {
                    str += s[k];
                }
                const uniqueChars = new Set(str);
                if (uniqueChars.size === 1) {
                    mp.set(str, (mp.get(str) || 0) + 1);
                }
            }
        }
        let maxi = -1;
        for (const [key, value] of mp.entries()) {
            if (value >= 3) {
                maxi = Math.max(maxi, key.length);
            }
        }
        return maxi;
};