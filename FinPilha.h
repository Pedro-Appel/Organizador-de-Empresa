
#ifndef  FINPILHA_H
#define  FINPILHA_H


#include "FinAbb.h"

class FinPilha {

	private:
	FinAbb * finAbb;
	FinPilha * Fprox;

	public:
	FinPilha(FinAbb * no);
	FinAbb * getFinAbb();
	FinPilha * getFProx();
	void setFProx(FinPilha * no);

};

#endif
