/**
 * Definition for singly-linked list.
 * function ListNode(val, next) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.next = (next===undefined ? null : next)
 * }
 */
/**
 * @param {ListNode} head
 * @return {ListNode}
 */
var removeZeroSumSublists = function(head) {
    const valArray = []
    let curr = head
    while (curr) {
        valArray.push(curr.val)
        curr = curr.next
    }
    while (true) {
        let prefixSum = 0,
            isDone = false
        const sumFreq = {}
        for (let i = 0; i < valArray.length; i++) {
            prefixSum += valArray[i]
            if (prefixSum === 0) {
                valArray.splice(0, i + 1)
                break
            } else if (sumFreq[prefixSum] > -1) {
                valArray.splice(sumFreq[prefixSum] + 1, i - sumFreq[prefixSum])
                break
            } else {sumFreq[prefixSum] = i}
            if (i === valArray.length - 1) isDone = true
        }
        if (isDone || valArray.length === 0) break
    }

    if (valArray.length === 0) return null
    const newHead = new ListNode(valArray[0])
    let currNode = newHead
    for (let i = 1; i < valArray.length; i++) {
        const next = new ListNode(valArray[i])
        currNode.next = next
        currNode = next
    }
    return newHead
};