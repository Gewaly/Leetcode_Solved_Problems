/**
 * Definition for singly-linked list.
 * function ListNode(val, next) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.next = (next===undefined ? null : next)
 * }
 */
/**
 * @param {ListNode} list1
 * @param {number} a
 * @param {number} b
 * @param {ListNode} list2
 * @return {ListNode}
 */
var mergeInBetween = function(list1, a, b, list2) {
    let cur=list1,pivot=null,pos=0
   while(cur.next){
    if(pos==a-1){
        pivot=cur.next
        cur.next=list2
    }
    pos++
    cur=cur.next
   }
   for(let i=a;i<b+1;i++){
    pivot=pivot.next
   }

    cur.next=pivot


    return list1
};