#include <MSGEQ7.h>


MSGEQ7::MSGEQ7(uint8_t outpin, uint8_t strobepin, uint8_t rstpin) {
	out = outpin;
	strobe = strobepin;
	reset = rstpin;
	digitalWrite(reset, LOW);
	digitalWrite(strobe, HIGH);

}

void MSGEQ7::getMags(int pMags[]) {

	digitalWrite(reset, HIGH);
	digitalWrite(reset, LOW);
	delayMicroseconds(30);

	for(byte i = 0; i<7; i++) {
		digitalWrite(strobe, LOW);
		delayMicroseconds(30);
		pMags[i] = analogRead(out) - 30;
		delayMicroseconds(50);
		digitalWrite(strobe, HIGH);

	}



	}