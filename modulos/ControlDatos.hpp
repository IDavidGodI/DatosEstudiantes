#pragma once
#include <fstream>
#include <string>
#include ".\funciones.hpp"
#include ".\Nodo.hpp"
#define SEPARADOR ";"

#define ARCHIVO "notas_estudiantes"

bool Guardar(Nodo* cab,const char* nombre = ARCHIVO){
  std::ofstream archivo(std::string("./Datos/"+std::string(nombre)).c_str());
  if (!archivo) return false;

  while (cab!=NULL){
    archivo<<cab->id<<SEPARADOR<<cab->nota<<std::endl;
    cab = cab->sig;
  }
  archivo.close();
  return true;
}
Nodo* Cargar(const char* nombre = ARCHIVO){
  std::ifstream archivo(std::string("./Datos/"+std::string(nombre)).c_str());
  if (!archivo) return NULL;
  Nodo* cab = NULL;
  std::string linea;
  long id;
  float nota;
  while(!archivo.eof()){
    std::getline(archivo,linea);
    int sep = linea.find_first_of(SEPARADOR);
    
    if (sep != std::string::npos){
      id = std::atoi(linea.substr(0,sep).c_str());
      nota = std::atoi(linea.substr(sep+1, linea.length()-sep).c_str());
      colaMeter(cab,id,nota);
    }
  }
  return cab; 
}
