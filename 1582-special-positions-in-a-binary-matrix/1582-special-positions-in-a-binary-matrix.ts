function numSpecial(mat: number[][]): number {
    let count = 0;
    for (let i = 0; i < mat.length; i++) {
        for (let j = 0; j < mat[i].length; j++) {
            if (mat[i][j] && isSpecial(mat, i, j)) {
                count++;
            }
        }
    }
    return count;
}

function isSpecial(mat: number[][], vi: number, vj: number): boolean {
    for (let j = 0; j < mat[0].length; j++) {
        if (j !== vj && mat[vi][j]) {
            return false;
        }
    }
    
    for (let i = 0; i < mat.length; i++) {
        if (i !== vi && mat[i][vj]) {
            return false;
        }
    }
    
    return true;
}