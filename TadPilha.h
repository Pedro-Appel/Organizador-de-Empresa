#ifndef TADPILHA_H
#define TADPILHA_H

#include "NoPilha.h"
#include "FinPilha.h"
#include "NoAbb.h"
#include "FinAbb.h"

class TadPilha {

	private:
	NoPilha * topo;
	FinPilha * Ftopo;

	public:
	TadPilha();
	bool vazia();
	bool Fvazia();
	void push(NoAbb * noAbb);
	void Fpush(FinAbb * finAbb);
  	NoPilha * gettopo();
	NoPilha * pop();
	FinPilha * Fgettopo();
	FinPilha * Fpop();
};

#endif
