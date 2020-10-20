#include "TadAbb.h"
#include <iostream>
#include <stdlib.h>

/*
Pedro Appel - TIA 31934064
Lucca Raposo - TIA 31941754
Danilo Lassabia - TIA 31938221
*/
using namespace std;

int verifica(string vetor[], int i, string aux){
	int loop = 0;
	for(int k = 0; k <= i; k++){
		if(vetor[k] == aux){
			loop = 1;
		}
	}
	return loop;
}

int main() {
	
	TadAbb abb;
	TadAbb valores;

	// --------------------------LE E CRIA ARVORE DE FUNCIONARIOS------------------------------]
	string * vetor = new string[50];
	
	for (int i = 0; i<50; i++){
		vetor[i] = "-1";
	}
	
	int i = 0;
	int loop = 0;
	
	int tamanhoMax = 300; //* tamanho maximo de uma linha em caracteres
	FILE * pFile; //* ponteiro para o arquivo a ser aberto
	char linha[tamanhoMax]; //* variavel para armazenamento da linha lida do arquivo
	string linhaStr;
	
	pFile = fopen ("spcine.csv" , "r"); //* abre o arquivo para leitura
	
	if (pFile == NULL) cout << ("Erro na abertura do arquivo");
	    else {
	    	fgets (linha , tamanhoMax , pFile);
		    while ( fgets (linha , tamanhoMax , pFile) != NULL ) { //* "fgets" le uma linha e armazena em "linha"
			    linhaStr = linha; //* conversao automatica de char para string
            	//cout << "[string] = " << linhaStr << endl;
				string aux = abb.incluirNo(linhaStr);
				loop = verifica(vetor, i, aux);
					if (loop != 1){
						vetor[i] = aux;
						i++;
				}			
		   }
		  	fclose (pFile);
	  }
	// --------------------------LE E CRIA ARVORE DE VALORES------------------------------]
	
	float V[18] = {7.6,10.0,2.5,5.0,12.5,15.0,1.0,2.5,5.0,7.5,10.0,12.5,15.0,17.5,0,1.0,17.5,1000.0};
	int a = 0;
	for(int sas = 0; sas < 18; sas++){
		valores.CriaAbb(V[sas], V[sas+1]);
		sas++;
	}
	
	FinAbb * raiz = valores.getraiz();
	abb.insereFin(raiz);
	
	int opc;
	while (true) {
		system("cls");    //retirar caso queira ver as inserções com meses trabalhados
		cout << "\n------------------------------------------------------------"<<endl;
		cout << "\n                ARVORE BINARIA DE BUSCA";
		cout << "\n------------------------------------------------------------"<<endl;
		cout << "\n0 - Sair";
		cout << "\n1 - Listar funcionarios em ordem alfabetica";
		cout << "\n2 - Listar funcionarios que recebem média mensal acima de determinado valor";
		cout << "\n5 - Listar lista de cargos"<<endl;
		cout<<"Opcao : ";
  		cin >> opc;
	if (opc == 0) {
			break;
		}
		
  	else if (opc == 1) {
		abb.imprimirEmOrdem();
  	}
  	else if (opc == 2) {
  		float i;
  		cout<<"Listar os funcionarios que recebem acima do valor inteiro = ";
  		cin>>i;
  		system("cls");
		valores.ImprimeAcima(i);
		cout<<"\n\n\n"<<endl;
		cout<<"Funcionarios com media salarial acima de "<<i<<"\n\n\n"<<endl;
  	}
  	
  	else if (opc == 5){
		for(int k = 0; k <= 50; k++){
			if(vetor[k] != "-1"){
				cout << vetor[k]<<endl;
			}else{
				break;
			}
		}
  	}
  	system("pause");
  }
  
	cout << "\n\nObrigado e ate' breve.\n\n";
	return 0;
}

