#include "data.h"
//struct das trans��es
struct trans {
	dates datetrans;
	int qnt;
	//esse � do pre�o
	float pre�o;
};
//struct das empresas 
struct empresa {
	char nome[20];
	char codiguin[10];
	int qtdTranz;
	trans* ponteiro;

};
float carteirares(empresa[], int);
