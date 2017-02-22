//Cabecera SetOfInts
private:

public:
  SetOfInts();
  void add(int x) throw (Error);
  bool cointains(int x) const;
  void remove(int x);
  void linSearch(int x, int i, int s, bool f, int pos);
