class Faltas{
    public:
        void anadirAlumno(const IdAlumno& a);
        void anadirFalta(const IdAlumno& a, const IdAsignatura& s);
        void anadirAsignatura(const IdAsignatura& s);

    private:
        Diccionario<IdAsignatura, Diccionario<IdAlumno,int> > listas_faltas;
        typedef string IdAlumno;
        typedef string IdAsignatura;
        
}