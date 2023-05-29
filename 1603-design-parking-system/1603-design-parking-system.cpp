class ParkingSystem {
    int B,M,S;
    int bc=0,mc=0,sc=0;
public:
    ParkingSystem(int big, int medium, int small) 
    {
        B=big,M=medium,S=small; 
    }
    
    bool addCar(int carType) 
    {
        switch(carType)
        {
            case 1:if(bc==B)return 0;
                    bc++;
                break;
            case 2:if(mc==M)return 0;
                mc++;
                break;
            case 3:if(sc==S)return 0;
                sc++;
                break;
        }
        return 1;
    }
};

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */