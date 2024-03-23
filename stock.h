#include "data.h"
//struct das transções
struct trans {
	dates datetrans;
	int qnt;
	//esse é do preço
	float preço;
};
//struct das empresas 
struct empresa {
	char nome[20];
	char codiguin[10];
	int qtdTranz;
	trans* ponteiro;

};
float carteirares(empresa[], int);
