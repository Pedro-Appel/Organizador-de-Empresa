#include <iostream>
#include <string>
#include <cstdlib>
#include "NoAbb.h"
#include <bits/stdc++.h>
using namespace std;

float converter(string x){
  string i = x;
  int tam = i.length();
  char juventos[tam+1];
  strcpy(juventos, i.c_str());
  float k = atof(juventos);
  return k;
}

NoAbb::NoAbb(string * v) {
	this->filhoEsq = NULL;
	this->filhoDir = NULL;  
	qtd = 1;
	profDir = 0;
	profEsq = 0;
	nome = v[3];
	cargo = v[4];
	lotacao = v[5];
	admissao = v[6];
	nascimento = v[7];
	  
	vencimentos = converter(v[8]);
	encargos = converter(v[9]);
	beneficios = converter(v[10]);
	

}

float NoAbb::getRec(){
	float rec;
	rec = ((vencimentos + beneficios) - encargos) / qtd;
	return rec;
}

void NoAbb::adcVenc(string * v){
	float i = converter(v[8]);
	vencimentos = vencimentos + i;	
	
}

void NoAbb::adcEnc(string * v){
	float i = converter(v[9]);
	encargos = encargos + i;
	
}

void NoAbb::adcBen(string * v){
	float i = converter(v[10]);
	beneficios = beneficios + i;
	
}

string NoAbb::getNome(){
  return nome;
}

int NoAbb::getqtd(){
  return qtd;
}

int NoAbb::attqtd(int i){
    qtd++; 
    return qtd;
}

void NoAbb::setFilhoEsq(NoAbb * no) {
	this->filhoEsq = no;
}

NoAbb * NoAbb::getFilhoEsq() {
	return this->filhoEsq;
}

void NoAbb::setFilhoDir(NoAbb * no) {
	this->filhoDir = no;
}

NoAbb * NoAbb::getFilhoDir() {
	return this->filhoDir;
}
