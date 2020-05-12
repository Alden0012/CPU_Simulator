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
	short DataMem[4096];
	Instruction InstMem[4096];
	public:
	void initializeCPU();
	void loadInst();
	void TesterPrintInst();
};

ostream& operator<<(ostream& out, Instruction Inst);
istream& operator>>(istream& in, Instruction& Inst);


#endif