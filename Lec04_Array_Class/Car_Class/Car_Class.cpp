#include "Car.h"
class SportsCar : public Car
{
public:
	bool bTurbo;
	void setTurbo(bool bTur) { bTurbo = bTur; }
	void speedUp() {
		if (bTurbo) speed += 20;
		else Car::speedUp();
	}
};


int main() {
	SportsCar myCar;
	myCar.setTurbo(true);
	myCar.speedUp();
	myCar.display();

	myCar.whereAmI();
	return 0;
}
