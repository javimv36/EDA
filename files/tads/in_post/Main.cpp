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
Arbin<int> reconstruirArbol(List<int> post, List<int> in)
{

	if (post.empty() || in.empty())
	{
		return Arbin<int>();
	}
	List<int>::ConstIterator it_post = post.cbegin();
	List<int>::ConstIterator it_in = in.cbegin();

	int raiz = post.back();
	List<int> post_iz, post_dr, in_iz, in_dr;
	Arbin<int> arbol;
	while (it_in.elem() != raiz)
	{
		post_iz.push_back(it_post.elem());
		in_iz.push_back(it_in.elem());
		it_post.next();
		it_in.next();
	}
	it_in.next();
	while (it_post.elem() != raiz)
	{
		post_dr.push_back(it_post.elem());
		in_dr.push_back(it_in.elem());
		it_post.next();
		it_in.next();
	}
	Arbin<int> iz = reconstruirArbol(post_iz, in_iz);
	Arbin<int> dr = reconstruirArbol(post_dr, in_dr);
	return Arbin<int>(iz, raiz, dr);
}

int main()
{

	int a;

	
	List<int> post, in, *niveles;

	do
	{
		post = List<int>();
		in = List<int>();
		cin >> a;
		while (a != -1)
		{
			post.push_back(a);
			cin >> a;
		}
		cin >> a;
		while (a != -1)
		{
			in.push_back(a);
			cin >> a;
		}
		Arbin<int> arb = reconstruirArbol(post, in);
		mostrar(arb.niveles());
	} while (!post.empty());

	return 0;
}