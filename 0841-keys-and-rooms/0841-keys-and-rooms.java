class Solution {
    public boolean canVisitAllRooms(List<List<Integer>> rooms) {
        boolean[] vis = new boolean[rooms.size()];
        vis[0] = true;
        Stack<Integer> stack = new Stack<>();
        stack.push(0);
        int count = 1;
        while (stack.size() > 0)
            for (int k : rooms.get(stack.pop()))
                if (!vis[k]) {
                    stack.push(k);
                    vis[k] = true;
                    count++;
                }
        return rooms.size() == count;
    }
}