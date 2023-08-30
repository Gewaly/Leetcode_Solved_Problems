/**
 * @param {Array} arr1
 * @param {Array} arr2
 * @return {Array}
 */
var join = function(arr1, arr2) {
    const arrOneIds = {}

    for (const obj of arr1) {
        arrOneIds[obj.id] = obj
    }

    for (const obj of arr2) {
        arrOneIds[obj.id] = arrOneIds[obj.id] ? {...arrOneIds[obj.id], ...obj} : obj
    }

    return Object.values(arrOneIds)
};