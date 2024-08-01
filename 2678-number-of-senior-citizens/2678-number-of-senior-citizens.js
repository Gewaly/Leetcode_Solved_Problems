/**
 * @param {string[]} details
 * @return {number}
 */
var countSeniors = function(details) {
    let count = 0;

    for(let detail of details){
        let age = detail.substring(11, 13);
        if(age > 60){
            count+=1;
        }
    }

    return count;
};