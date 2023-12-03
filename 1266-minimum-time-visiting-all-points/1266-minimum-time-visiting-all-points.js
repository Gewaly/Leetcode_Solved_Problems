/**
 * @param {number[][]} points
 * @return {number}
 */
var minTimeToVisitAllPoints = function(points) {
    let result = 0;
    
    for(let i = 0;i < points.length-1; i++){
        let xi = points[i][0], yi = points[i][1];
        let xi2 = points[i+1][0], yi2 = points[i+1][1];
        result+= Math.max(Math.abs(xi2-xi), Math.abs(yi2-yi));
    }

    return result;
};