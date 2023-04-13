/**
 * @param {number[]} pushed
 * @param {number[]} popped
 * @return {boolean}
 */
var validateStackSequences = (pushed, popped) => {
  let stack = [];
  let i = 0;
  for (let num of pushed) {
    stack.push(num); 
    console.log(stack);
    while (stack.length > 0 && stack[stack.length - 1] == popped[i]) {
      stack.pop(); 

      i++;
    }
  }
  return stack.length == 0;
};