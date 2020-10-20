
#ifndef NO_H
#define NO_H

using namespace std;

class NoAbb {

	private:
  		//Atributos base do código
		int valor;
		NoAbb * filhoEsq;
		NoAbb * filhoDir;
  		int profDir;
  		int profEsq;
  		int qtd; // Meses
  		//Atributos do SPCine
  		string nome;
  		string cargo;
  		string lotacao;
  		string admissao;
  		string nascimento;
  		float vencimentos;
  		float encargos;
  		float beneficios;

	public:
		float getRec();
		void adcVenc(string * v);
		void adcEnc(string * v);
		void adcBen(string * v);
  		string getNome();
  		int attqtd(int i);
  		int getqtd();
		NoAbb();
		NoAbb(string * v);
		void setFilhoEsq(NoAbb * no);
		NoAbb * getFilhoEsq();
		void setFilhoDir(NoAbb * no);
		NoAbb * getFilhoDir();

};

#endif
