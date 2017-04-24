#include "Hora.h"
class Pelicula
{
private:
  Hora _horaInicio;
  Hora _duracion;
  Hora _horaFin;
  string _nombre;

public:
  Pelicula();
  void setDatos(Hora horaInicio, Hora duracion, string nombre);
  void write(ostream &sOut);
  Hora getHora() const;
  Hora getDuracion() const;
  Hora getFin() const;
  string getNombre() const;
  bool operator<(const Pelicula &p) const;
  friend istream &operator>>(istream &sIn, Pelicula &p);
  friend ostream &operator<<(ostream &sOut, Pelicula &p);
};