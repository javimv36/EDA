class Fecha{
    private:
        int dia;
        int hora;
        int minuto;
    public:
        Fecha();
        Fecha(int d, int h, int m);
        int getDia() const;
        int getHora() const;
        int getMinutos() const;
        bool operator<(const &Fecha f) const;
};