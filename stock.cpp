#include <iostream>
#include "data.h"
#include "color.h"
#include "text.h"
#include "stock.h"
using namespace std;
//fun��o do resumo
float carteirares(empresa factos[], int var) {
	exiba("                        Resumo da Carteira                     ", 26, preto, lilac);
	cout << endl;
	//T�tulos
	linha('-', 62, lilac, preto);
	cout << endl;
	exiba(" Empresa", 13, preto, lilac);
	exiba("   ", 1, preto, preto);
	exiba(" Ticker ", 1, preto, lilac);
	exiba("   ", 1, preto, preto);
	exiba(" Qtd. ", 1, preto, lilac);
	exiba("   ", 1, preto, preto);
	exiba(" Pre�o M�dio ", 1, preto, lilac);
	exiba("   ", 1, preto, preto);
	exiba(" Investido ", 1, preto, lilac);
	//Inicializando variaveis
	cout << endl;
	float MediaPre�o = 0;
	float TotalInvestimento = 0;
	float Total = 0;
	

	for (int i = 0; i < var; i++) {
		
		int qtda��es= 0;
		MediaPre�o = 0;
		TotalInvestimento = 0;
			
			
		for (int j = 0; j < factos[i].qtdTranz; j++)
		{
			
			TotalInvestimento += factos[i].ponteiro[j].qnt * factos[i].ponteiro[j].pre�o;
			qtda��es += factos[i].ponteiro[j].qnt;
			
		}	
		Total += TotalInvestimento;
		//Tabela
		cout << fixed; cout.precision(2);
		exiba(factos[i].nome, 17, branco, preto);
		exiba(factos[i].codiguin, 11, branco, preto);
		exibaint(qtda��es, 10, branco, preto);
		exibafloat(TotalInvestimento/qtda��es, 16, branco, preto);
		exibafloat(TotalInvestimento, 16, branco, preto);
		cout << endl;
			
	}
	//Parte de baixo que fica o total
	linha('-', 62, lilac, preto);
	cout << endl;
	exiba("Total investido:                                        ", 1, preto, lilac);
	exibafloat(Total, 1, preto, lilac);
	cout << endl;
	return Total;
}

