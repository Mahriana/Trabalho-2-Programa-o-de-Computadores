#include "color.h"
#include <iostream>
#include <cstring>
using namespace std;
//funçoes da biblioteca "color.h"
void linha(char line, int vague, colores dento, colores fora) {

	for (int i = 0; i <=vague; i++)
	{
		cout << "\033[38;5;" << dento << "m";
		cout << "\033[48;5;" << fora << "m";
		cout << line;
		cout << "\033[38;5;" << branco << "m";
		cout << "\033[48;5;" << preto << "m";
	}
}

void exiba(const char babado[], int numero, colores dento, colores fora) {
	cout << "\033[38;5;" << dento << "m";
	cout << "\033[48;5;" << fora << "m";
	cout << left; cout.width(numero);
	cout << babado;
	cout << "\033[38;5;" << branco << "m";
	cout << "\033[48;5;" << preto << "m";
	
}

void exibaint(int babado, int numero, colores dento, colores fora) {
	cout << "\033[38;5;" << dento << "m";
	cout << "\033[48;5;" << fora << "m";
	cout.width(numero);
	cout << babado;
	cout << "\033[38;5;" << branco << "m";
	cout << "\033[48;5;" << preto << "m";
}

void exibafloat(float babado, int numero, colores dento, colores fora) {
	cout << "\033[38;5;" << dento << "m";
	cout << "\033[48;5;" << fora << "m";
	cout.width(numero);
	cout << babado;
	cout << "\033[38;5;" << branco << "m";
	cout << "\033[48;5;" << preto << "m";
}

void texto(const char babado, colores dento, colores fora) {
	cout << "\033[38;5;" << dento << "m";
	cout << "\033[48;5;" << fora << "m";
	cout << babado;
	cout << "\033[38;5;" << branco << "m";
	cout << "\033[48;5;" << preto << "m";
}
void evita(char babado[]) {
	for (int i = 0; i < strlen(babado); i++)
	{
		babado[i] = toupper(babado[i]);
	}
}
