#include "Car.h"
#include "SportsCar.h"

int main() {
    Car c1(60, (char*)"아반떼", 3);
    c1.display();

    c1.speedUp();
    c1.display();

    printf("\n");

    
    SportsCar s1;

    s1.setSpeed(80);
    s1.changeGear(2);
    s1.setName((char*)"페라리");
    s1.setTurbo(true);

    s1.display();

    s1.speedUp();
    s1.display();

    printf("\n");

    s1.setTurbo(false);
    s1.speedUp();
    s1.display();

    return 0;
}
