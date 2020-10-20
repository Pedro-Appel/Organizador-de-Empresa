
#ifndef TADABB_H
#define TADABB_H

#include <iostream>
#include "FinAbb.h"
#include "NoAbb.h"

using namespace std;

class TadAbb {

	private:
	NoAbb * raiz;
	FinAbb * Rraiz;
	int qtdno;

	public:
	FinAbb * getraiz();
	void Compara(NoAbb * no, FinAbb * raiz);
	void insereFin(FinAbb * raiz);
	void ImprimeAcima(float i);
	void CriaAbb(float min, float max);
	TadAbb();
	bool vazia();
	string incluirNo(string frase);
	string localizarNo(int vl);
	void excluirNo(int vl);
	string imprimirPreOrdem();
  	void imprimirEmOrdem();
  	void imprimirPosOrdem();
};

#endif
