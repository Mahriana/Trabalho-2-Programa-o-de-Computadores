#include <iostream>
#include <cctype>
#include "color.h"
#include "data.h"
#include "stock.h"
#include "text.h"
using namespace std;

int main() {
	
	exiba(" Carteira de ações \n", 2, preto, lforte);
	int qtdEmpresas, i,j{};
	exiba(" Quantidade de empresas [ ]\b\b", 1, lilac, preto);
	cin >> qtdEmpresas;
	empresa* companias = new empresa[qtdEmpresas];
//Leitor de dados da empresas
	for (i = 0; i < qtdEmpresas; i++) {
		exiba(" Empresa:  ", 1, lilac, preto);
		cin.ignore();
		cin.getline(companias[i].nome, 69);
		exiba(" Ticker: ", 1, lilac, preto);
		cin >> companias[i].codiguin;
		exiba(" Transações:  ", 1, lilac, preto);
		cin >> companias[i].qtdTranz;
		exiba(" ----------------------------\n", 1, lforte, preto);
	}
	char barra;

	//Tabela das transaçoes
	exiba(" Transações realizadas \n", 11, preto, lforte);

	for (i = 0; i < qtdEmpresas; i++) {
		cout << " ";
		exiba(companias[i].nome, 2, lforte, preto);
		exiba(" - ", 2, lforte, preto);
		evita(companias[i].codiguin);
		exiba(companias[i].codiguin, 2, lforte, preto);
		cout << endl;

		companias[i].ponteiro = new trans[companias[i].qtdTranz];

		for (int y = 0; y < companias[i].qtdTranz; y++) {
			cout << endl;
			
			exiba(" Data: ", 1, lilac, preto);
			cin >> companias[i].ponteiro[y].datetrans.dia >> barra >> companias[i].ponteiro[y].datetrans.mes >> barra >> companias[i].ponteiro[y].datetrans.ano;
			exiba(" Quantidade: ", 1, lilac, preto);
			cin >> (companias[i].ponteiro)[y].qnt;
			exiba(" Preço: ", 1, lilac, preto);
			cin >> (companias[i].ponteiro)[y].preço;
			cout << endl;

		};
	};

	
	//Resumo da Carteira
	 system("cls");
	float Total = carteirares(companias, qtdEmpresas);
	
	float aporte;
	float rendimentoanual;
	//Leitor dos novos dados
	exiba("Aporte anual [    ]\b\b\b\b\b", 1, lilac, preto);
	cin >> aporte;
	exiba("Redimento anual estimado  [  ]%\b\b\b\b", 1, lilac, preto);
	cin >> rendimentoanual;
	
	exiba("                      Rentabilidade da carteira                ", 26, preto, lforte);
	rendimentoanual = rendimentoanual / 100;
	cout << endl;

	float investido[21] = { Total };
	float rendimento[21] = { 0 };
	float acumulado[21] = {Total};
	float tamanho[21] = { 0 };
	for (i = 1; i < 21; i++)
	{
		investido[i] = investido[i - 1] + aporte;
		rendimento[i] = rendimentoanual *(acumulado[i - 1] + aporte);
		acumulado[i] = acumulado[i-1] + aporte+  rendimento[i];

	}
	linha('-', 67, lforte, preto);
	cout << endl;
	exiba(" Ano  Investido   Rendimento   Acumulado          Gráfico           ", 1, preto, lforte);
	cout << endl;
	exiba(" ", 1, preto, lforte);
	exiba("0 ", 3, preto, lforte);
	exiba("  ", 1, preto, preto);
	exibafloat(investido[0], 11, branco, preto);
	exibafloat(rendimento[0], 13, branco, preto);
	exibafloat(acumulado[0], 13, branco, preto);
	cout << endl;
	
	for (short i = 0; i < 21; i++) {
		tamanho[i] = (acumulado[i] / acumulado[20] * 21);
	}

	for (short i = 1,j=0; i < 21; i++,j--)
	{
		exiba(" ", 1,preto,lforte);
		exibaint(i, 3, preto, lforte);
		cout << "  ";
		cout << fixed; cout.precision(2);
		exibafloat(investido[i], 11, branco, preto);
		exibafloat(rendimento[i], 13, branco, preto);
		exibafloat(acumulado[i],13 , branco, preto);
		for (short x = 0; x < 21; x++)
		{
			if (i>= (21 -tamanho[x]))
			{
				cout << char(254);
			}
			else
			{
				cout << " ";
			}


		}
		cout << endl;

		
	}
	for ( i = 0; i < qtdEmpresas; i++)
	{
		delete[]companias[i].ponteiro;
	}
	delete[]companias;
	}

