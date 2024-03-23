//tive que usar o pragma once nessa biblioteca
#pragma once
#include <iostream>

using namespace std;
//struct das datas 
 struct dates {
	short dia;
	short mes;
	short ano;
};
//função do lab 12
istream& operator>>(istream& is, dates& d);

ostream& operator<<(ostream& os, dates& d);
