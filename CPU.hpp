#ifndef CPU_hpp
#define CPU_hpp
#include <vector>
#include <iostream>
#include <string>
using namespace std;
struct Instruction{
	string opcode;
	short operand;
};
class CPU{
	short Acc;
	short PC;
	Instruction IR;
	short DataMem[4096];
	Instruction InstMem[4096];
	Instruction DataSetup[4096];
	short DSPC;
	public:
	void initializeCPU();
	void loadInst();
	void TesterPrintInst();
	void TesterPrintData();
	void UpdatePC();
	void UpdateIR();
	void CleanupInstMem();
	void PerformDataSetup();
};

ostream& operator<<(ostream& out, Instruction Inst);
istream& operator>>(istream& in, Instruction& Inst);


#endif