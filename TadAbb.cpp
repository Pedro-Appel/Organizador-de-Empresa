#include <sstream>

#include "TadAbb.h"
#include "TadPilha.h"
#include "FinAbb.h"

using namespace std;

TadAbb::TadAbb(){
	this->raiz = NULL;
	qtdno = 0;
}

bool TadAbb::vazia(){
	return this->raiz == NULL;
}

FinAbb * TadAbb::getraiz(){
	return this->Rraiz;
}

string TadAbb::incluirNo(string frase){
	string * vetor = new string[15];

	string limite = ";";
	
	int posicao = 0;
	string chave;
	int i = 0;
  
	while ((posicao = frase.find(limite)) != std::string::npos) {
	    chave = frase.substr(0, posicao);
	    vetor[i] = chave;
	    i++;
	    frase.erase(0, posicao + limite.length());
	}
	vetor[i] = frase;
  	string * v = vetor;

	NoAbb * no = new NoAbb(v);

	NoAbb * cursor = this->raiz;

	TadPilha pilha;
	
	string vl = vetor[3];
	  
	if (cursor == NULL) {
		raiz = no;
		qtdno++;
		//cout<< "Arvore vazia. Inserido na raiz.";
	}
	
	else {
		string vlAux;
		while (true) {
	      
			vlAux = cursor->getNome();
	
			if (vlAux == vl) {
	        	int a;
				a = cursor->attqtd(0);
				cursor->adcVenc(vetor);
				cursor->adcEnc(vetor);
				cursor->adcBen(vetor);
	        	break;
			}
	
			else if (vl < vlAux) {
	
				if (cursor->getFilhoEsq() == NULL) {
					cursor->setFilhoEsq(no);
	
				break;
				}
	        
	        	else {
					cursor = cursor->getFilhoEsq();
				}
			}
	
				else if (vl > vlAux) {
					if (cursor->getFilhoDir() == NULL) {
						cursor->setFilhoDir(no);
						break;
					}
					else {
						cursor = cursor->getFilhoDir();
					}
	
				}
			}
		qtdno++;
	    int a = cursor->getqtd();
		//cout<<vl<<" Trabalhou "<<a<<" Meses"<<endl;
		}
	return v[4];
}

void TadAbb::imprimirEmOrdem(){
	system("cls");
	if (vazia()) {
		cout << "*** Arvore vazia ***";
	} 
  	else {
    	TadPilha pilha;
    	pilha.push(this->raiz);
    	NoPilha * no = pilha.gettopo();
    	NoAbb * noAbb = no->getNoAbb();
    	while(!pilha.vazia()){
      		while(noAbb->getFilhoEsq() != NULL){
        		noAbb = noAbb->getFilhoEsq();
        		pilha.push(noAbb);
      		}
      
    		while(noAbb->getFilhoDir() == NULL){
	     	 	no = pilha.pop();
			  	noAbb = no->getNoAbb();
	      		cout << noAbb->getNome() <<endl;
	      		if(pilha.vazia()){
	       			break;
				}
				else{
	    			no = pilha.pop();
					noAbb = no->getNoAbb();
					pilha.push(noAbb);
			  	}
	    	}	
      	
	      	if(noAbb->getFilhoDir() != NULL){
		        no = pilha.pop();
				noAbb = no->getNoAbb(); 
		        cout << noAbb->getNome() <<endl;      
		        noAbb = noAbb->getFilhoDir();
		        pilha.push(noAbb);  
      		}
    	}
		cout << "\nFIM"<<endl;
  }
}

void TadAbb::CriaAbb(float min, float max){
	
	FinAbb * no = new FinAbb(min, max);
	
	FinAbb * cursor = this->Rraiz;
	
	if (cursor == NULL) {
		Rraiz = no;
	}
	else {
		float vlMax = 0;
		float vlMin = 0;

		while (true) {

			vlMax = cursor->getMax();
			vlMin = cursor->getMin();
			if (max <= vlMin) {
				if (cursor->getFilhoEsq() == NULL) {
					cursor->setFilhoEsq(no);
					break;
				}
	        
	        	else {
					cursor = cursor->getFilhoEsq();
				}
			}
	
				else if (min >= vlMax) {
					if (cursor->getFilhoDir() == NULL) {
						cursor->setFilhoDir(no);
						break;
					}
					else {
						cursor = cursor->getFilhoDir();
					}
	
				}
		}
	}
}

void TadAbb::Compara(NoAbb * no, FinAbb * raiz){
	
	FinAbb * cursor = raiz;
	
	float aux = no->getRec();
	aux = aux / 1000;
	

	float vlMax;
	float vlMin;
	while (true) {
		vlMax = cursor->getMax();
		vlMin = cursor->getMin();	
		if (aux <= cursor->getMax() and aux >= cursor->getMin()) {
			cursor->insVetor(no->getNome());
			break;
		}
		else{
			if(aux < vlMin) {
				cursor = cursor->getFilhoEsq();

				}
			else {
				if(aux > vlMax) {
					cursor = cursor->getFilhoDir();
				}
			}
		}
	}
}

void TadAbb::insereFin(FinAbb * raiz){	
	if (vazia()) {
		cout << "*** Arvore vazia ***";
		system("pause");
	} 

  	else {
    	TadPilha pilha;
    	pilha.push(this->raiz);
    	NoPilha * no = pilha.gettopo();
    	NoAbb * noAbb = no->getNoAbb();
    while(!pilha.vazia()){
      while(noAbb->getFilhoEsq() != NULL){
        noAbb = noAbb->getFilhoEsq();
        pilha.push(noAbb);
      }
      
    	while(noAbb->getFilhoDir() == NULL){
	      	no = pilha.pop();
			noAbb = no->getNoAbb();
	      	Compara(noAbb, raiz);
	      	if(pilha.vazia()){
	       	break;
			}
			else{
	      		no = pilha.pop();
				noAbb = no->getNoAbb();
				pilha.push(noAbb);
			  }
	    }	
      	
      if(noAbb->getFilhoDir() != NULL){
        no = pilha.pop();
		    noAbb = no->getNoAbb(); 
        Compara(noAbb, raiz);
        noAbb = noAbb->getFilhoDir();
        pilha.push(noAbb);  
      }
    }
    cout << "\nInserido Os valores na Tabela Valor"<<endl;
  }
}

void TadAbb::ImprimeAcima(float i){

    TadPilha Fpilha;
    Fpilha.Fpush(this->Rraiz);
    FinPilha * no = Fpilha.Fgettopo();
    FinAbb * finAbb = no->getFinAbb();
    int vezes = 0;
    while(!Fpilha.Fvazia()){
    	while(i<finAbb->getMin()){
	      	while(finAbb->getFilhoDir() != NULL){
	      		finAbb = finAbb->getFilhoDir();
	      		Fpilha.Fpush(finAbb);
			}
			while(finAbb->getFilhoEsq() == NULL){
				no = Fpilha.Fpop();
				finAbb = no->getFinAbb();
				finAbb->printaVet();

	      		if(Fpilha.Fvazia()){
	       			break;
				}
				else{
					no = Fpilha.Fpop();
					finAbb = no->getFinAbb();
					Fpilha.Fpush(finAbb);
				}
			}
			if(finAbb->getFilhoEsq() != NULL){
				no = Fpilha.Fpop();
				finAbb = no->getFinAbb();
				finAbb->printaVet();
				finAbb = finAbb->getFilhoEsq();
				Fpilha.Fpush(finAbb);
				
			}
	    
		}
		while(i<=finAbb->getMax()){
			while(finAbb->getFilhoDir() != NULL){
	      		finAbb = finAbb->getFilhoDir();
	      		Fpilha.Fpush(finAbb);
			}
			while(finAbb->getFilhoEsq() == NULL){
				no = Fpilha.Fpop();
				finAbb = no->getFinAbb();
				finAbb->printaVet();

	      		if(Fpilha.Fvazia()){
	       			break;
				}
				else{
					no = Fpilha.Fpop();
					finAbb = no->getFinAbb();
					Fpilha.Fpush(finAbb);
				}
			}
			if(finAbb->getFilhoEsq() != NULL){
				no = Fpilha.Fpop();
				finAbb = no->getFinAbb();
				finAbb->printaVet();
				finAbb = finAbb->getFilhoEsq();
				Fpilha.Fpush(finAbb);
				
			}
	    
		}
		Fpilha.Fpop();
	}
}



