#include "CPU.hpp"
void CPU::initializeCPU(){
	Acc = 0;
	PC = 0;
	for (int i = 0;i<4096;i++){
		DataMem[i] = 0;
	}
}
void CPU::loadInst(){
	Instruction Inst;
	int i = 0;
	string z;
	while (cin >> Inst){
		if (i < 4096){
			
			InstMem[i] = Inst;
			//cout << "read " << Inst;
			i++;
		}
		else {
			break;
		}
	}
}

void CPU::TesterPrintInst(){
	for(int i = 0;i<4096;i++){
		cout << InstMem[i] << endl;
	}
}
ostream& operator<<(ostream& out, Instruction Inst){
	out << Inst.opcode << " " << Inst.operand;
	return out;
}
istream& operator>>(istream& in,Instruction& Inst){
	in >> Inst.opcode;
	in >> Inst.operand;
	//cout << Inst.opcode << " " << Inst.operand;
	return in;
}