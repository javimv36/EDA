#include <iostream>

class Hora
{
  public:
    Hora(){
        _horas=0;
        _minutos=0;
        _segundos=0;
    }

    void write(std::ostream& sOut) {
		sOut << _horas << ":" << _minutos << ":" << _segundos << std::endl;
	}

     void read(std::istream& sIn) {
        int n, h, m, s;
        sIn.get(n);
        h = 10 * n;
        sIn.get(n);
        h += n;
        sIn.get(n);
        sIn.get(n);
        m = 10 * n;
        sIn.get(n);
        m += n;
        sIn.get(n);
        sIn.get(n);
        s = 10 * n;
        sIn.get(n);
        s += n;
        if (0 <= h && h <= 23 && 0 <= m && m <= 59 && 0 <= s && s <= 59)
        {
            _horas = h;
            _minutos = m;
            _segundos = s;
        }
        else
            throw "Error";
    }

  private:
    int _horas;
    int _minutos;
    int _segundos;

    std::ostream& operator<<(std::ostream& sOut, Hora& h) {
	    h.write(sOut);
        return sOut;
    }

    std::istream& operator>>(std::istream& sIn, Hora& h)
    {
        h.read(sIn);
        return sIn;
    }   
};
//tema8 FP