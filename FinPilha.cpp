
#include <iostream>

#include "FinPilha.h"
#include "FinAbb.h"


FinPilha::FinPilha(FinAbb * no) {
	this->finAbb = no;
	this->Fprox = NULL;
}

void FinPilha::setFProx(FinPilha * no) {
	this->Fprox = no;
}

FinPilha * FinPilha::getFProx(){
	return this->Fprox;
}

FinAbb * FinPilha::getFinAbb(){
	return this->finAbb;
}

