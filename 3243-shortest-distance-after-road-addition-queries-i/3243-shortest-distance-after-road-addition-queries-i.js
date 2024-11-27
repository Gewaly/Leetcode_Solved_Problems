/**
 * @param {number} n
 * @param {number[][]} queries
 * @return {number[]}
 */
var shortestDistanceAfterQueries = function(n, queries) {
    const graph = Array.from({ length: n }, (_, i) => new Set ([i + 1]));
    const distances = [];

    for (let i = 0; i < queries.length; i++) {
        const [u, v] = queries[i];

        graph[u].add(v);

        distances.push(bfs());
    }

    function bfs() {
        const queue = [[0, 0]];
        const visited = new Set();

        while (queue.length) {
            const [city, distance] = queue.shift();

            if (city === n - 1) return distance;

            for (neighbor of graph[city]) {
                if (visited.has(neighbor)) continue;

                queue.push([neighbor, distance + 1]);
                visited.add(neighbor);
            }
        }
    }

    return distances;
};