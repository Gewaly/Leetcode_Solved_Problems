/**
 * @param {number[]} prices
 * @return {number[]}
 */
var finalPrices = function(prices) {
let final = [];
for(let i=0; i<prices.length; i++){
let difference = 0;
for(let j=i+1; j<prices.length; j++){
if(prices[j]<=prices[i]){
difference = prices[j];
break;
}
}
final.push(prices[i]-difference);
}
return final;
};