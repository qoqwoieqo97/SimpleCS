#include <iostream>
#include "LIB/circuit.h"
#include "LIB/ComputerDefines.h"

#define CIR_PSUCAP 200

int main()
{
	CircuitElement ampul(25.0, 2.0);
	Circuit c;
	//Computer lol
	c.addElement(CIR_PSU(125)); c.addElement(CIR_AMDRYZEN95950X);
	int mCounter = 0;
	while (true)
	{
		std::cout << "---------------" << std::endl; mCounter++; std::cout << "Work:" << mCounter << std::endl;
		c.work();
		std::vector<CircuitElement> batteries = c.getActiveBatteries(), wob = c.getElements(); int batc=0, co = batc;
		for (auto c : batteries)
		{
			batc++; co++; std::cout << "Battery " << batc << " capacity:" << c.capacity << "A/h" << " Tempature:" << c.tempature << "C" << std::endl;
		}
		for (auto w : wob)
		{
			co++; std::cout << "Element " << co << " capacity:" << w.capacity << "A/h" << " Tempature:" << w.tempature << "C" << std::endl;
		}


		std::cout << "Volts:" << c.calcVoltage() << "V" << std::endl << "Current:" << c.calcCurrent() << "A" << std::endl;
		if (batc == 0) break;
	}
}