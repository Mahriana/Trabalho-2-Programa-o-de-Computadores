#include "data.h"
//peguei do lab12
istream& operator>>(istream& is, dates& d)
{
	is >> d.dia;
	is.get();
	is >> d.mes;
	is.get();
	is >> d.ano;
	return is;
}

// exibir
ostream& operator<<(ostream& os, dates& d)
{
	os << d.dia;
	os << '/';
	os << d.mes;
	os << '/';
	os << d.ano;
	return os;
}
