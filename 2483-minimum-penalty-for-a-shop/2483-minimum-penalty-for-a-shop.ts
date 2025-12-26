function bestClosingTime(customers: string): number {
     let n = customers.length;
    
        let penalty=0;
        let minP=penalty, minI=0;
        for (let i=1; i <= n; i++) {
            let y=customers[i-1] == 'Y'?1:-1;
            penalty-=y;
            if (minP> penalty) {
                minP=penalty;
                minI=i;
            }
        }
        return minI;
    
};

