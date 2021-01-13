#pragma once
#ifndef CIR_PSUCAP
#define CIR_PSUCAP 999999
#endif

#define CIR_AMDRYZEN95950X CircuitElement(3.0,105)
#define CIR_PSU(x) CircuitElement(1, x, CIR_PSUCAP)