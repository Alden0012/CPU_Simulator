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
	short Acc; //Accumulator
	short PC; //Program Counter
	Instruction IR;// Instruction register
	short DataMem[4096];
	Instruction InstMem[4096];
	Instruction DataSetup[4096];
	short DSPC; // Data Setup Program Counter
	public:
	void initializeCPU();
	void loadInst();
	void TesterPrintInst();
	void TesterPrintData();
	void UpdatePC();
	void UpdateIR();
	void CleanupInstMem();
	void PerformDataSetup();
	bool ExecuteCurrentIR();
};

ostream& operator<<(ostream& out, Instruction Inst);
istream& operator>>(istream& in, Instruction& Inst);


#endif