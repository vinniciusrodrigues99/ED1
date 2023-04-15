#include <iostream>
using namespace std;

int main(int argc, char** argv)
{
	int i;
	double d;
	char c;
	string s;

	cout << "Digite um valor int: ";
	cin >> i;
	cout << "Valor int digitado: " << i << endl;
	cout << "Tamanho do i: " << sizeof(i) << endl;

	cout << "Digite um valor double: ";
	cin >> d;
	cout << "Valor int digitado: " << d << endl;
	cout << "Tamanho do d: " << sizeof(d) << endl;

	c = 65;
	cout << "Valor char: " << c << endl;
	cout << "Tamanho do c: " << sizeof(c) << endl;

	s = "Teste de string";
	cout << "Valor string: " << s << endl;
	cout << "Tamanho do s: " << s.size() << endl;


	return 0;
}