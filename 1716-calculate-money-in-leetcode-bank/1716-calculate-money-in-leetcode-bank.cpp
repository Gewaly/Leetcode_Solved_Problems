class Solution {
public:
    int totalMoney(int n) {
        int money = 0, count = 1, i = 0, counter = 1;
        while(n > 0){
            if(i == 7){ counter++; count = counter; i = 0;  }
            money += count;
            i++;
            count++;
            n--;
        }
        return money;
    }
};