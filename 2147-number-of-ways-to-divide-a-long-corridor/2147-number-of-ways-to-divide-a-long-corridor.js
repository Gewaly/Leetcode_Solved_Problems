/**
 * @param {string} corridor
 * @return {number}
 */
var numberOfWays = function(corridor) {
    var pos=[]
    for(let i=0;i<corridor.length;i++){
        if(corridor[i]=='S')
            pos.push(i)
        
    }
    //console.log('pos=',pos)
    if(pos.length%2!=0 || pos.length==0) return 0
    
    if(pos.length==2){
        return 1
    }
    var combo=1
    for(let i = 1;i<pos.length-2;i+=2){
        //console.log('i=',i)
        let diff = pos[i+1]-pos[i]
        combo = (combo*diff)%1000000007
        //console.log('diff=',diff,'combo=',combo)
    }
    return combo
    


};