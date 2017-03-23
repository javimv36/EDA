#include "Error.h"
class Hora {
	// Conjuntos de enteros representados como vectores ordenados sin repeticiones
	private:
		int _horas;
        int _minutos;
        int _segundos;

        /*
		bool isFull() const;
		void binSearch(int x,bool& found,int& pos) const;
		int binSearchAux(int x, int a, int b) const;
		void shiftRightFrom(int i);
		void shiftLeftFrom(int i);
        */

	public:
		Hora();
		void setHora(int h, int m, int s) throw (Error);
		void write(ostream &sOut);
		friend istream& operator>>(istream& sIn,Hora& hora);
		friend ostream& operator<<(ostream& sOut,Hora& hora);
		/*bool operator==(const SetOfInts3& s)const;
		bool operator<(const Hora& hora)const;
		*/
};