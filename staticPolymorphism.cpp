#include<iostream>
#include<string>

using namespace std;

class ManualCar{

    private:
    public:
    string brand;
    string model;
    bool isEngineOn;
    int currentSpeed;
    int currentGear;

    public:
    ManualCar(string brand, string model){
        this->brand = brand;
        this->model = model;
        isEngineOn = false;
        currentSpeed = 0;
        currentGear = 0;
    }

    void startEngine(){
        isEngineOn = true;
        cout<<brand<<" "<<model<<": Engine starts with a roar!"<<endl;
    }

    void stopEngine(){
        isEngineOn = false;
        currentGear=0;
        currentSpeed = 0;
        cout<<brand<<" "<<model<<": Engine turned Off"<<endl;
    }

    //method overloading
    void accelerate(){
        if(!isEngineOn){
            cout<<brand<<" "<<model<<": Engine is off! Cannot accelerate"<<endl;
        }
        currentSpeed+=20;
        cout<<brand<<" "<<model<<": Accelerating to "<<currentSpeed<<" km/h"<<endl;
    }

    void accelerate(int speed){
        if(!isEngineOn){
            cout<<brand<<" "<<model<<": Engine is off! Cannot accelerate"<<endl;
        }
        currentSpeed+=speed;
        cout<<brand<<" "<<model<<": Accelerating to "<<currentSpeed<<" km/h"<<endl;
    }
};


int main(){
    ManualCar* myManualCar = new ManualCar("Suzuki","WagonR");
    myManualCar->startEngine();
    myManualCar->accelerate();
    myManualCar->accelerate(40);
    myManualCar->stopEngine();

    delete myManualCar;

    return 0;
}