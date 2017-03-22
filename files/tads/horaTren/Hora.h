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
		void add(int x) throw (Error);
		void remove(int x);
		friend istream& operator>>(istream& sIn,SetOfInts3& set);
		friend ostream& operator<<(ostream& sOut,SetOfInts3& set);
		bool operator==(const SetOfInts3& s)const;
		bool operator<(const SetOfInts3& s)const;
};