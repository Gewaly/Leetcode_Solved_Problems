/**
 * @param {number[][]} grid
 * @return {number}
 */
function maxMoves(grid) {
  const m = grid.length, n = grid[0].length;
  const memo = Array.from({ length: m }, () => Array(n).fill(-1));
  const directions = [[-1, 1], [0, 1], [1, 1]];

  const dfs = (r, c) => memo[r][c] !== -1 ? memo[r][c] :
    (memo[r][c] = Math.max(0, ...directions
      .map(([dr, dc]) => r + dr >= 0 && r + dr < m && c + dc < n && grid[r + dr][c + dc] > grid[r][c]
        ? 1 + dfs(r + dr, c + dc) : 0)));

  return Math.max(...Array.from({ length: m }, (_, i) => dfs(i, 0)));
}