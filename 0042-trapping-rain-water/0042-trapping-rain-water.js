/**
 * @param {number[]} height
 * @return {number}
 */
var trap = function(height) {
    
    let max1 = 0;
    let left = [height.length];
    for(let i = 0; i < height.length; i++) { 
        if(max1 < height[i]) {
            max1 = height[i];
        }
        left[i] = max1;
    }
        
    let max2 = 0;
    
    let right = [height.length];
    for(let i = height.length-1; i >= 0; i--){
        if(max2 < height[i]) {
            max2 = height[i];
        }
        right[i] = max2;
    }
        
    let trap = 0;
    for(let i = 0; i  < height.length; i++) {
        trap += Math.min(left[i], right[i]) - height[i];
    }
    return trap;        
};