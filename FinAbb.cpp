#include <iostream>
#include <string>
#include <cstdlib>
#include "FinAbb.h"
#include "TadAbb.h"
#include "TadPilha.h"
#include <bits/stdc++.h>
using namespace std;

string * aloca(string * vetor){
	for (int i = 0; i<20; i++){
		vetor[i] = "-1";
	}
	return vetor;
}

FinAbb::FinAbb(float vmin, float vmax) {
	this->filhoEsq = NULL;
	this->filhoDir = NULL;
	this->valorMin = vmin;
	this->valorMax = vmax;
  	qtd = 0;
  	vetor = new string[50];
  	vetor = aloca(vetor);
}
void FinAbb::insVetor(string x){
	vetor[qtd] = x;
	qtd++;
}

void FinAbb::printaVet(){
	for(int k = 0; k <= 20; k++){
		if(vetor[k] != "-1"){
			cout << vetor[k]<<endl;
		}else{
			break;
		}
	}
}
int FinAbb::getqtd(){
  return qtd;
}

int FinAbb::attqtd(int i){
    qtd++; 
    return qtd;
}

void FinAbb::setFilhoEsq(FinAbb * no) {
	this->filhoEsq = no;
}

FinAbb * FinAbb::getFilhoEsq() {
	return this->filhoEsq;
}

void FinAbb::setFilhoDir(FinAbb * no) {
	this->filhoDir = no;
}

FinAbb * FinAbb::getFilhoDir() {
	return this->filhoDir;
}

float FinAbb::getMax(){
	return valorMax;
}

float FinAbb::getMin(){
	return valorMin;
}
