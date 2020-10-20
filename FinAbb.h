
#ifndef FINABB_H
#define FINABB_H

using namespace std;

class FinAbb {

	private:
  		//Atributos base do código
		float valorMin;
		float valorMax;
		FinAbb * filhoEsq;
		FinAbb * filhoDir;
  		int qtd;
  		string * vetor;
  		

	public:
		
  		int attqtd(int i);
  		int getqtd();
		FinAbb();
		void insVetor(string x);
		void printaVet();
		FinAbb(float vmin, float vmax);
		void setFilhoEsq(FinAbb * no);
		FinAbb * getFilhoEsq();
		void setFilhoDir(FinAbb * no);
		FinAbb * getFilhoDir();
		float getMax();
		float getMin();
};

#endif
