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
void CPU::TesterPrintData(){
	for(int i = 0;i<4096;i++){
		cout << DataMem[i] << endl;
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
void CPU::UpdatePC(){
	if (PC > 4095){
		PC = 0;
	}
	else{
		PC++;
	}
}
void CPU::UpdateIR(){
	IR = InstMem[PC];
}
void CPU::CleanupInstMem(){
	int z = 0;
	for(int i = 0;i<4096;i++){
		if (InstMem[i].opcode == "ORG" || InstMem[i].opcode == "DCW"){
			DataSetup[z] = InstMem[i];
			for(int j = i;j<4095;j++){
				InstMem[j] = InstMem[j+1];
			}
			InstMem[4095] = {"",0};
			z++;
			i--;
		}
	}
}

void CPU::PerformDataSetup(){
	DSPC = 0;
	for(int i=0;i<4096;i++){

		if(DataSetup[i].opcode == "ORG"){
				DSPC = DataSetup[i].operand;
				//cout << DSPC << endl;
		}
		else if(DataSetup[i].opcode == "DCW"){
				DataMem[DSPC] = DataSetup[i].operand;
				if(DSPC == 4095){
					DSPC = 0;
				}
				else{
					DSPC++;
				}
			}
		}
	}