class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        priority_queue<int> maxB;
    
        int i=0, diff =0; 
        for(i=0; i<heights.size()-1; i++){ 
            
            diff = heights[i+1]-heights[i];
            
            if(diff <= 0){
                continue;
            }

            bricks -= diff; 
            maxB.push(diff); 
       
            if(bricks < 0){
                bricks += maxB.top(); 
                maxB.pop(); 
                ladders--;
            }

          
            if(ladders < 0) break;
        }
        
        
        return i;
    }
};