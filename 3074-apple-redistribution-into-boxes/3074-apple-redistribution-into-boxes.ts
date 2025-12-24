function minimumBoxes(apple: number[], capacity: number[]): number {
    let sum = 0,cnt=0;
    for (let i = 0; i < apple.length; i++) {
        sum += apple[i];
    }
    capacity.sort(function(a, b){return b-a});
    // console.log(sum);
    for (let i = 0; i < capacity.length; i++) {
          console.log(capacity[i]);
            // console.log(sum);
        if(sum<=0) break;
        else{
            sum-=capacity[i];
            cnt++;
        }
    }
return cnt;
};