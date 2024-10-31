#pragma once

#include <iostream>

using namespace:: std;

class Car {
private:
    int insuranceOption; // Варіант страхування
    bool confirmOrder;     // Підтверджено замовлення
    int damageLiability; // Відповідальність за пошкодження

public:
    string carModel;      // Модель автомобіля
    string IdCar; //номера машини
    int rentalPrice;   // Вартість оренди

    static int CarCount;

    Car(int iO, bool cO, int dL, string cM, string IdCar, int rP);
    Car();
    Car(const Car& other);
  /*  ~Car();*/


    int getInsuranceOption(); 
    bool getConfirmOrder(); 
    int getDamageLiability(); 
    string getCarModel(); 
    string getIdCar(); 
    int getRentalPrice(); 

    void saveToFile(const string& filename) const;
    void loadFromFile(const string& filename);
    void saveToStream(ofstream& outFile) const; 

    static void carCount();

    static Car createCar(int insuranceOption, bool confirmOrder, int damageLiability, string carModel, string idCar, int rentalPrice) {
        Car newCar(insuranceOption, confirmOrder, damageLiability, carModel, idCar, rentalPrice);
        return newCar;
    }

};
