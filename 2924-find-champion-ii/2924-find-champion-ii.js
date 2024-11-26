/**
 * @param {number} n
 * @param {number[][]} edges
 * @return {number}
 */
var findChampion = function(n, edges) {
    let weakerTeam = new Set();
    for([strong,weak] of edges){
        weakerTeam.add(weak);
    }
    let res = [];
    for(let i=0;i<n;i++){
       if(!weakerTeam.has(i)){
        res.push(i);
       }
    }
    return res.length === 1 ? res[0] :-1;
};