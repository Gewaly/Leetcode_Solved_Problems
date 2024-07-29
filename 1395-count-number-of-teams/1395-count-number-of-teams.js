/**
 * @param {number[]} rating
 * @return {number}
 */
var numTeams = function(rating) {
    let n=rating.length;
    let ans=0;
    for(let i=1;i<n-1;i++){
        let greaterLeft=0,greaterRight=0,lessLeft=0,lessRight=0;
        for(let j=0;j<i;j++){
            if(rating[i]<rating[j]) greaterLeft++;
            if(rating[i]>rating[j]) lessLeft++;
        }
        for(let j=i+1;j<n;j++){
            if(rating[i]<rating[j]) greaterRight++;
            if(rating[i]>rating[j]) lessRight++;
        }
        ans+=lessLeft * greaterRight + greaterLeft * lessRight
    }
    return ans;
    
};