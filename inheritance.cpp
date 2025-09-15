#include<iostream>
#include<string>

using namespace std;

class Car{
protected:
    string brand;
    string model;
    bool isEngineOn;
    int currentSpeed;


public:
    Car(string b, string m){
        this->brand = b;
        this->model = m;
        isEngineOn = false;
        currentSpeed = 0;
    }

    //common methods for all cars
    void startEngine(){
        isEngineOn = true;
        cout<<brand<<" "<<model<<": Engine starts with a roar!"<<endl;
    }

    void accelerate(){
        if(!isEngineOn){
            cout<<brand<<" "<<model<<": Engine is off! Cannot accelerate"<<endl;
        }
        currentSpeed+=20;
        cout<<brand<<" "<<model<<": Accelerating to "<<currentSpeed<<endl;
    }

    void brake(){
        currentSpeed=-20;
        if(currentSpeed<0) currentSpeed=0;
        cout<<brand<<" "<<model<<": Braking! speed is now "<<currentSpeed<<"km/h"<<endl;
    }

    void stopEngine(){
        isEngineOn = false;
        currentSpeed = 0;
        cout<<brand<<" "<<model<<": Engine turned Off"<<endl;
    }

    virtual ~Car() {}

};


class ManualCar: public Car{//inherits from Car
private:
    int currentGear; //specific to manual car

public:
    ManualCar(string b, string m): Car(b,m){
        currentGear = 0;
    }

    //specialized for manual car
    void shiftGear(int gear){
        currentGear=gear;
        cout<<brand<<" "<<model<<" :shifted to gear "<<currentGear<<endl;
    }
};


class ElectricCar: public Car{
private:
    int batteryLevel;

public:
    ElectricCar(string b, string m): Car(b,m){
        batteryLevel=100;
    }

    void chargeBattery(){
        batteryLevel=100;
        cout<<brand<<" "<<model<<" :Battery fully charged!"<<endl;
    }
};


int main(){
    ManualCar* myManualCar = new ManualCar("Suzuki", "WagonR");
    myManualCar->startEngine();
    myManualCar->shiftGear(1);
    myManualCar->accelerate();
    myManualCar->brake();
    myManualCar->stopEngine();
    delete myManualCar;


    cout<<"---------------------"<<endl;

    ElectricCar* myElectricCar = new ElectricCar("Tesla", "Model S"); 
    myElectricCar->chargeBattery();
    myElectricCar->startEngine();
    myElectricCar->accelerate();
    myElectricCar->brake();
    myElectricCar->stopEngine();
    delete myElectricCar;

}