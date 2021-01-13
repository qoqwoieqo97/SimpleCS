#pragma once
#include "circuit_element.h"
class Circuit
{
private:
	std::vector<CircuitElement> elements;
public:
	void addElement(CircuitElement element)
	{
		elements.push_back(element);
	}

	std::vector<CircuitElement> getActiveBatteries()
	{
		std::vector<CircuitElement> result;
		for (CircuitElement c : elements) if (c.capacity > 0) result.push_back(c);
		return result;
	}

	std::vector<CircuitElement> getElements()
	{
		std::vector<CircuitElement> result;
		for (CircuitElement c : elements) if (c.capacity <= 0) result.push_back(c);
		return result;
	}

	float calcVoltage()
	{
		float result = 0;
		for (CircuitElement c : getActiveBatteries()) result += c.voltage;
		return result;
	}

	float calcCurrent(int counter = 0)
	{
		float voltage = calcVoltage(), current = 0;
		for (int i = counter; i < elements.size();i++) if (elements[i].capacity == 0) current += voltage / elements[i].r;
		return current;
	}

	// Calculate batteries
	int hmbit(int start)
	{
		for (int i = start; i < elements.size(); i++)
		{
			if (elements[i].capacity <= 0) return i - start;
		}
		return elements.size() - start;
	}

	void work()
	{
		float v = calcVoltage(), c = 0;
		for (int i = 0; i < elements.size(); i++)
		{
			int start = i;
			// Batteries
			while (elements[i].capacity > 0)
			{
				elements[i].work(c, v, (calcCurrent(i) / hmbit(start)) * (i - start+1));
				i++;
			}
			// Other elements
			elements[i].work(c, v,0);
		}
	}
};