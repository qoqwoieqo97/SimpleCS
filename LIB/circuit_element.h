#pragma once
/*
* voltage br = Volt
* resistance br = Ohm
* current br = A
* capacity br = A/h
*/

#include <vector>


class CircuitElement
{
public:
	float r = 1 /* Ohm */, voltage /* Volt */, capacity /* A/h */, tempature /* Celsius */; bool isBat = false;

	CircuitElement(float Resistance = 1.0, float Voltage = 2, float Capacity = 0)
	{
		r = Resistance; voltage = Voltage; capacity = Capacity; isBat = capacity > 0; tempature = 25;
	}
	void work(float &current, float &voltage, float reqCurrent)
	{
		if (capacity <= 0 && !isBat)
			current -= voltage / r;
		else
		{
			if (current < reqCurrent && capacity > 0)
			{
				float c = reqCurrent - current;
				capacity -= c; current = reqCurrent;
			}
		}
		tempature = (tempature + (voltage * r / 2)) / 2;
		
	}
};
