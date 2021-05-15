/*
 * @Descroption: LeetCode 1603. 设计停车系统
 * @Author: EmoryHuang
 * @Date: 2021-03-19 14:48:36
 * @解题思路:
 * 好吧，经典浪费时间
 */

class ParkingSystem {
   public:
    ParkingSystem(int big, int medium, int small) {
        numBig = big;
        numMedium = medium;
        numSmall = small;
    }
    bool addCar(int carType) {
        if (carType == 1 && numBig) {
            numBig--;
            return true;
        } else if (carType == 2 && numMedium) {
            numMedium--;
            return true;
        } else if (carType == 3 && numSmall) {
            numSmall--;
            return true;
        }
        return false;
    }

   private:
    int numBig = 0, numMedium = 0, numSmall = 0;
};

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */