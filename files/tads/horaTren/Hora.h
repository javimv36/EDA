#include "Error.h"
class Hora {
	private:
		int _horas;
        int _minutos;
        int _segundos;

	public:
		Hora();
		void setHora(int h, int m, int s) throw (Error);
		void write(ostream &sOut);
		int getHH() const;
		int getMM() const;
		int getSS() const;
		bool operator<(const Hora& hora)const;
		friend istream& operator>>(istream& sIn,Hora& hora);
		friend ostream& operator<<(ostream& sOut,Hora& hora);
};