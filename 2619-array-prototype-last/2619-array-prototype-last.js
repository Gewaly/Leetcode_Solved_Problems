Array.prototype.last = function() {
    return this[this.length-1]?? -1;
    
};
//   return this[this.length - 1] ?? -1;
/**
 * const arr = [1, 2, 3];
 * arr.last(); // 3
 */