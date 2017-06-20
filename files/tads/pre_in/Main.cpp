#include <iostream>
#include <algorithm>
#include "Arbin.h"
#include "List.h"

using namespace std;

void mostrar(List<int> *niveles)
{
	List<int>::ConstIterator it_niveles = niveles->cbegin();
	while (it_niveles != niveles->cend())
	{
		cout << it_niveles.elem() << " ";
		it_niveles.next();
	}
	cout << endl;
}
Arbin<int> reconstruirArbol(List<int> pre, List<int> in)
{
	if (pre.empty() || in.empty())
	{
		return Arbin<int>();
	}
	List<int>::ConstIterator it_pre = pre.cbegin();
	List<int>::ConstIterator it_in = in.cbegin();

	int raiz = pre.front();
	List<int> pre_iz, pre_dr, in_iz, in_dr;
	Arbin<int> arbol;
	it_pre.next();
	while (it_in.elem() != raiz)
	{
		pre_iz.push_back(it_pre.elem());
		in_iz.push_back(it_in.elem());
		it_pre.next();
		it_in.next();
	}
	it_in.next();
	while (it_pre != pre.cend())
	{
		pre_dr.push_back(it_pre.elem());
		in_dr.push_back(it_in.elem());
		it_pre.next();
		it_in.next();
	}
	Arbin<int> iz = reconstruirArbol(pre_iz, in_iz);
	Arbin<int> dr = reconstruirArbol(pre_dr, in_dr);
	return Arbin<int>(iz, raiz, dr);
}

int main()
{
	int a;
	List<int> pre, in, *niveles;
	do
	{
		pre = List<int>();
		in = List<int>();
		cin >> a;
		while (a != -1)
		{
			pre.push_back(a);
			cin >> a;
		}
		cin >> a;
		while (a != -1)
		{
			in.push_back(a);
			cin >> a;
		}
		Arbin<int> arb = reconstruirArbol(pre, in);
		mostrar(arb.niveles());
	} while (!pre.empty());

	return 0;
}