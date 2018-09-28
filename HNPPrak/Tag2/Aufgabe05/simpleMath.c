#include "simpleMath.h"

int is_negative(int zahl){
	if (zahl <= 0) {
		return 1;
	} else {
		return 0;
	}
}

int absolute_add(int zahl1, int zahl2){
	if(is_negative(zahl1)) {
		if(is_negative(zahl2)) {
			return (-1*zahl1) + (-1*zahl2);
		} else {
			return (-1*zahl1) + (-1*zahl2);
		}
	} else {
		if(is_negative(zahl2)) {
			return zahl1 + (-1*zahl2);
		} else {
			return zahl1 + zahl2;
		}
	}
}

int absolute(int zahl) {
	if(is_negative(zahl)) {
		return -1*zahl;
	} else {
		return zahl;
	}
}
