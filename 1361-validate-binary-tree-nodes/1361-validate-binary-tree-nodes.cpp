class Solution {
    bool dfs(int node, vector<int>&leftChild, vector<int>&rightChild, vector<bool>&visit){
        int n = leftChild.size() ;
        if(node == -1) return true ;
        if(visit[node]) return false;
        visit[node] = true ;
        int leftNode, rightNode ;
        leftNode = leftChild[node] ;
        rightNode = rightChild[node] ;
        return dfs(leftNode, leftChild, rightChild, visit) && dfs(rightNode, leftChild, rightChild, visit) ;
    }
public:
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        vector<bool>visit(n+1, false) ;
        vector<int>indegree(n,0) ;
        for(int i=0; i<n; i++){
            int leftNode = leftChild[i], rightNode = rightChild[i] ;
            if(leftNode != -1) indegree[leftNode]++ ;
            if(rightNode != -1) indegree[rightNode]++ ;
        }
        int root = -1 ;
        for(int i = 0; i<n ; i++) if(indegree[i] == 0) root = i ;
        if(root == -1) return false ;
        bool ok = dfs(root, leftChild, rightChild, visit) ;
        for(int i =0; i< n; i++) if(!visit[i]) return false ; 
        return ok ;
    }
};