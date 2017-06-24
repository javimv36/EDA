#include "HashMap.h"
#include "TreeMap.h"

class Faltas{
    public:
        Faltas();
        void anadirAlumno(const IdAlumno& a);
        void anadirFalta(const IdAlumno& a, const IdAsignatura& s);
        void anadirAsignatura(const IdAsignatura& s);

    private:
        typedef string IdAlumno;
        typedef string IdAsignatura;
        typedef struct {
            HashMap<IdAlumno,int> tabla;
            int totalFaltas;
        }InfoAsignatura;
        HashMap<IdAsignatura,InfoAsignatura> listas_faltas;
        HashMap<IdAlumno,int> alumnos;
}