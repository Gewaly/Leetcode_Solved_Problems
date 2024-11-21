/**
 * @param {number} m
 * @param {number} n
 * @param {number[][]} guards
 * @param {number[][]} walls
 * @return {number}
 */
var countUnguarded = function (m, n, guards, walls) {
    const arr = Array.from({ length: m }, () => new Array(n).fill(0));
    let result = 0;

    walls.forEach(([i, j]) => (arr[i][j] = -1));
    guards.forEach(([i, j]) => (arr[i][j] = -2));

    for(let i = 0 ;i< m; i++) {
        let isGuarded = false;

        for(let j = 0; j< n ;j++){
            if(arr[i][j] === -2) isGuarded = true;
            else if(arr[i][j] === -1) isGuarded = false;
            else if(isGuarded) arr[i][j] = 1;
        }

        isGuarded = false;

         for(let j = n-1; j>=0 ;j--){
            if(arr[i][j] === -2) isGuarded = true;
            else if(arr[i][j] === -1) isGuarded = false;
            else if(isGuarded) arr[i][j] = 1;
        }

    }

    for(let j = 0 ;j< n; j++) {
        let isGuarded = false;

        for(let i = 0; i< m ;i++){
            if(arr[i][j] === -2) isGuarded = true;
            else if(arr[i][j] === -1) isGuarded = false;
            else if(isGuarded) arr[i][j] = 1;
        }

        isGuarded = false;

         for(let i = m-1; i>=0 ;i--){
            if(arr[i][j] === -2) isGuarded = true;
            else if(arr[i][j] === -1) isGuarded = false;
            else if(isGuarded) arr[i][j] = 1;
        }

    }

    for (let i = 0; i < m; i++) {
        for (let j = 0; j < n; j++) {
            if (arr[i][j] === 0) result++;
        }
    }

    return result;
};