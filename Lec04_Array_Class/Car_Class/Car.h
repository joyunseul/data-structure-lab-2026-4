#pragma once
#include <cstdio>
#include <string.h>


class Car {
protected:
	int speed;
	char name[40];
public:
	int gear;
	Car() {
			speed = 0;
			gear = 1;
			strcpy_s(name, sizeof(name), "미정");
	}
	~Car(){ }
	Car(int s, char* n, int g)
		: speed(s),gear(g) {
		strcpy_s(name, sizeof(name), "내 자동차");
	}
	void changeGear(int g = 4) {
		gear = g;
	}
	void speedUp() {
		speed += 5;
	}
	void display() {
		printf("[%s] : 기어=%d단 속도=%dkmph\n", name, gear, speed);
	}
	void whereAmI() { printf("객체 주소 = %x\n", this); }
};
