#include "Faltas.h"

Faltas::Faltas(){}

/*
    Añadir una asignatura hace un acceso a la tabla de asignaturas
    para comprobar si existe (operación de tiempo constante en un hasmap).
    Si no existe, añade la asignatura y copia el hashmap de alumnos de la primera asignatura
    que exista en el hasmap de asignaturas 
*/
void Faltas::anadirAsignatura(const IdAsignatura& s){
    if(!listas_faltas.contains(s)) {
        //InfoAsignatura se construye copiando la InfoAsignatura con los valores a 0
        listas_faltas.insert(s,InfoAsignatura());
    }
}

void Faltas::anadirAlumno(const IdAlumno& a){
    if(!alumnos.contains(a))alumnos.insert(a,0);
    HashMap<IdAsignatura,InfoAsignatura>::Iterator itS = listas_faltas.begin();
    while(itS != listas_faltas.end() && !itS.value().contains(a)){
        itS.value().insert(a,0);
        itS.next();
    }
}

void Faltas::anadirFalta(const IdAlumno& a, const IdAsignatura& s){
    if(listas_faltas.contains(s) && listas_faltas[s].contains(a)){
        listas_faltas[s].tabla[a]++;
        listas_faltas[s].totalFaltas++;
        faltas[a]++;
    }
}

List<IdAlumno> Faltas::noFaltas(){
    List<IdAlumno> l;
    HashMap<IdAlumno,int>::Iterator itA = faltas.begin();
    while(itA!=faltas.end()){
        if(itA.value()==0) 
            l.push_back(itA.key());
        itA.next();
    }
}

int Faltas::totalFaltas(const IdAlumno& a){
    if (faltas.contains(a))
    return faltas[a];
    else return -1;
}

IdAsignatura Faltas::maxFaltas(){
    HashMap<IdAsignatura,InfoAsignatura>::constIterator itS = listas_faltas.cbegin();
    int maxF=0;
    IdAsignatura id = IdAsignatura();
    while(itS!=listas_faltas.cend()){
        id = (maxF<itS.value().totalFaltas)?itS.key():id;
        maxF=(maxF<itS.value().totalFaltas)?itS.value().totalFaltas:maxF;
    }
    return id;
}