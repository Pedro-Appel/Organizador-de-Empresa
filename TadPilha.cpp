
#include <iostream>

#include "TadPilha.h"

TadPilha::TadPilha() {
	this->topo = NULL;
	this->Ftopo = NULL;
}

bool TadPilha::vazia() {
	return this->topo == NULL;
}
bool TadPilha::Fvazia() {
	return this->Ftopo == NULL;
}


void TadPilha::push(NoAbb * noAbb) {
	NoPilha * no = new NoPilha(noAbb);
	if (!this->vazia()) {
		no->setProx(this->topo);
	}
	this->topo = no;
}
void TadPilha::Fpush(FinAbb * finAbb) {
	FinPilha * no = new FinPilha(finAbb);
	if (!this->Fvazia()) {
		no->setFProx(this->Ftopo);
		
	}
	this->Ftopo = no;
}

NoPilha * TadPilha::pop() {
	if (vazia()) {
		return NULL;
	}
	NoPilha * noRetorno = this->topo;
	this->topo = noRetorno->getProx();
	return noRetorno;
}
FinPilha * TadPilha::Fpop() {
	if (Fvazia()) {
		return NULL;
	}
	FinPilha * noFetorno = this->Ftopo;
	this->Ftopo = noFetorno->getFProx();
	return noFetorno;
}

NoPilha * TadPilha::gettopo(){
  return this->topo;
}

FinPilha * TadPilha::Fgettopo(){
  return this->Ftopo;
}
