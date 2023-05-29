class ParkingSystem {
public:
int a,b,c;
    ParkingSystem(int big, int medium, int small) {
        a=big,b=medium,c=small;
    }
    
    bool addCar(int car) {
        if(car==1 and a>=1)
        {
            a--;
            return true;
        }
        else if(car==2 and b>=1)
        {
            b--;
            return true;
        }
        else if(car==3 and c>=1)
        {
            c--;
            return true;
        }
        return false;
    }
};

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */