#include <iostream>
#include<fstream>
#include <cstring>
#include "car.h"
#include "admin.h"
#include "order.h"

using namespace std;

void availableСars(const Car& c) {
    cout << c.carModel << endl;
    cout << c.IdCar << endl;
    cout <<c.rentalPrice << endl;
}

int main() {
    Car cars[5] = {
        Car(1, 1, 1000, "Skoda Oktavia", "BX1991BX", 500),
        Car(1, 0, 1000, "Skoda Fabia", "BX1234BX", 600),
        Car(1, 1, 1000, "Skoda Enyaq", "BX1939BX", 2000),
        Car(2, 0, 1000, "Zhiguli VAZ-2101", "BX1906BX", 52),
        Car(2, 0, 1000, "Zaporozhets ZAZ-965A", "BX1488BX", 52)
    };

    for (int i = 0; i < 5; i++) {
        cout << cars[i].getCarModel() << " ";
        cout << (cars[i].getInsuranceOption() == 200 ? "1 (200)" : "2 (500)") << " "; 
        cout << (cars[i].getConfirmOrder() ? "Yes" : "No") << " "; 
        cout << cars[i].getDamageLiability() << " ";
        cout << cars[i].getIdCar() << " ";
        cout << cars[i].getRentalPrice() << " " << endl;
    }

    Car* car = new Car[5];


    car[0] = Car(1, 0, 500, "Toyota Camry", "BX2101BX", 1000);
    car[1] = Car(2, 0, 300, "Honda Accord", "BX3001BX", 600);
    car[2] = Car(1, 1, 200, "Ford Focus", "BX1703BX", 500);
    car[3] = Car(2, 1, 400, "BMW 3 Series", "BX1740BX", 1500);
    car[4] = Car(1, 1, 250, "Audi A4", "BX1501BX", 1200);

    for (int i = 0; i < 5; i++) {
        cout << car[i].getCarModel() << " ";
        cout << (car[i].getInsuranceOption() == 200 ? "1 (200)" : "2 (500)") << " ";
        cout << (car[i].getConfirmOrder() ? "Yes" : "No") << " ";
        cout << car[i].getDamageLiability() << " ";
        cout << car[i].getIdCar() << " ";
        cout << car[i].getRentalPrice() << " " << endl ;
    }


    Car* carPointer = &car[0];  // Покажчик на перший автомобіль у динамічному масиві
    cout << carPointer->getCarModel() << " ";
    cout << (carPointer->getInsuranceOption() == 200 ? "1 (200)" : "2 (500)") << " ";
    cout << (carPointer->getConfirmOrder() ? "Yes" : "No") << " ";
    cout << carPointer->getDamageLiability() << " ";
    cout << carPointer->getIdCar() << " ";
    cout << carPointer->getRentalPrice() << endl;

    delete[] car;

    ofstream outFile("cars.txt"); // Відкриваємо файл для запису
    if (outFile.is_open()) {
        for (int i = 0; i < 5; i++) {
            cars[i].saveToStream(outFile);// Викликаємо метод для запису в потік
        }
        outFile.close(); // Закриваємо файл після запису всіх об'єктів
    }
    else {
        cout << "Помилка відкриття файлу для запису!" << endl;
    }

    Car supernova;
    supernova.carModel="Fiat";
    supernova.IdCar = "BH5688BA";
    supernova.rentalPrice = 2000;
    cout << supernova.getCarModel() << " ";
    cout << supernova.getIdCar() << " ";
    cout << supernova.getRentalPrice() << endl;
    Car superCar(1, 0, 500, "Kia", "BX2101BX", 1000);
    Car novaCar=superCar;
    cout << "superCar:" << endl;
    cout << superCar.getCarModel() << " ";
    cout << superCar.getInsuranceOption() << " "; 
    cout << superCar.getConfirmOrder() << " "; 
    cout << superCar.getDamageLiability() << " "; 
    cout << superCar.getIdCar() << " "; 
    cout << superCar.getRentalPrice() << endl;
    cout << "novaCar:" << endl;
    cout << novaCar.getCarModel() << " ";
    cout << novaCar.getInsuranceOption() << " ";
    cout << novaCar.getConfirmOrder() << " ";
    cout << novaCar.getDamageLiability() << " ";
    cout << novaCar.getIdCar() << " ";
    cout << novaCar.getRentalPrice() << endl;//конструктори класу Car

    Admin newAdmin("Olesya Hainoha", "confirmed");
    cout << newAdmin.requestStatus << endl;



    Car::carCount();

    availableСars(cars[1]);

    Car myCar = Car::createCar(1, true, 100, "Toyota", "AX1234", 500);

    return 0;
}