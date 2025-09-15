#include<iostream>
#include<string>

using namespace std;

//real life car

class SportsCar{
    
    private:
    //characters
    string brand;
    string model;
    bool isEngineOn;
    int currentSpeed;
    int currentGear;

    public:
    SportsCar(string b, string m){
        this->brand = b;
        this->model = m;
        isEngineOn = false;
        currentSpeed = 0;
        currentGear = 0;
    }


    //getters and setters
    int getCurrentSpeed(){
        return this->currentSpeed;
    }

    void setCurrentSpeed(int speed){
        this->currentSpeed= speed;
    }

    //behaviours -> methods
    void startEngine(){
        isEngineOn = true;
        cout<<brand<<" "<<model<<": Engine starts with a roar!"<<endl;
    }

    void shiftGear(int gear){
        if(!isEngineOn){
            cout<<brand<<" "<<model<<": Engine is off! Cannot shift gear"<<endl;
            return;
        }
        currentGear = gear;
        cout<<brand<<" "<<model<<": Shifted to gear "<<currentGear<<endl;
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
        cout<<brand<<" "<<model<<": Braking! speed is now"<<currentSpeed<<"km/h"<<endl;
    }

    void stopEngine(){
        isEngineOn = false;
        currentGear=0;
        currentSpeed = 0;
        cout<<brand<<" "<<model<<": Engine turned Off"<<endl;
    }
};

int main(){
    
    SportsCar* myCar = new SportsCar("Ford","Mustang");

    myCar->startEngine();
    myCar->shiftGear(1);
    myCar->accelerate();
    myCar->shiftGear(2);
    myCar->accelerate();
    myCar->brake();
    myCar->stopEngine();

    //setting arbitary value to speed
    //myCar->currentSpeed = 500;

    myCar->setCurrentSpeed(80);
    cout<<"current speed of my sports car is set to "<<myCar->getCurrentSpeed()<<endl;

    delete myCar;

    return 0;
}