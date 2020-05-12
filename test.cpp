#include "CPU.hpp"

int main(){
	CPU test1;
	test1.initializeCPU();
	test1.loadInst();
	test1.CleanupInstMem();
	test1.PerformDataSetup();
	test1.TesterPrintData();
}