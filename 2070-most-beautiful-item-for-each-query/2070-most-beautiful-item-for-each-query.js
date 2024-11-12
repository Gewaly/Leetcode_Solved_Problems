/**
 * @param {number[][]} items
 * @param {number[]} queries
 * @return {number[]}
 */
var maximumBeauty = function(items, queries) {
    // items.sort((a, b) => a[0] == b[0] ? b[1] - a[1] : a[0] - b[0]);
    items.sort((a, b) =>a[0] - b[0]);

    let queriesWithOrder = [];
    queries.map((value, index) => {
        queriesWithOrder.push([value, index]);
    })
    queriesWithOrder.sort((a, b) => a[0] - b[0]);

    let result = new Array(queries.length).fill(0);

    let index = 0;
    let maximum = 0;
    queriesWithOrder.forEach((item) => {
        for(i = index; i < items.length; i++, index++){
            if(items[i][0] <= item[0]){
                maximum = Math.max(maximum, items[i][1]);
                continue;
            }
            break
        }
        result[item[1]] = maximum;
    });

    return result;
};