/**
 * @param {number} left
 * @param {number} right
 * @return {number}
 */
var rangeBitwiseAnd = function(left, right) {
    let res=0;
        while(left!=right){
            left>>=1; right>>=1;
            res++;
         }
        return left<<res;
};