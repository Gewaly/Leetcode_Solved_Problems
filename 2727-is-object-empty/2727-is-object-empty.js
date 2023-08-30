/**
 * @param {Object | Array} obj
 * @return {boolean}
 */
var isEmpty = function(obj) {
    let cnt=0;
    for (const k in obj  ) cnt++;
   return (cnt==0);
    
};