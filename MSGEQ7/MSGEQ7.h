//msgeq7.h

#ifndef MSGEQ7_h
#define MSGEQ7_h

#include <Arduino.h>

class MSGEQ7 {
	public: 
		MSGEQ7 (uint8_t out, uint8_t strobe, uint8_t reset);

		void getMags(int pMags[]);

		

	private:
		uint8_t out;
		uint8_t strobe;
		uint8_t reset;


};

#endif