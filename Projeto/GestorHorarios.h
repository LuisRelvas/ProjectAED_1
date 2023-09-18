/**
 * @file GestorHorarios.h
 * @date 31-10
 * @brief Neste ficheiro implementamos todas as funções e metodos auxiliares necessários para o ficheiro GestorHorarios.cpp
 */

#ifndef UNTITLED_GESTORHORARIOS_H
#define UNTITLED_GESTORHORARIOS_H
#include "Student.h"
#include "Class.h"
#include "Uc_turma.h"
#include <map>
#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;


class GestorHorarios {
private:
    set<Student> students;
    vector<Class> classes;
    vector<Uc_turma> ucs;

public:

    static inline const map<string, int> weekDays{
            {"Monday", 1}, {"Tuesday", 2}, {"Wednesday", 3}, {"Thursday",4}, {"Friday",5}
    };
    void read_info_students();
    void read_info_classes();
    void read_info_uc();
    int numero_estudantes_turma(string class_code, string uc_code); //aqui considero que para cada aula existe um turma
    vector<Class> horario_estudante(string up);
    vector<Class> horario_turma(string class_code);
    vector<Class> horario_Uc(string uc_code);
    vector<Class> horario_turma_Uc(string class_code, string uc_code);
    bool find_student(string up);
    bool find_uc(string uc_code);
    bool find_turma(string uc_code, string class_code); //verifica se a turma existe (turma = cada aula uma turma)
    bool find_class_code(string class_code);
    vector<Student> estudantes_numa_uc(string uc_code);
    vector<Student> estudantes_numa_turma(string class_code, string uc_code);
    vector<Student> estudantes_num_ano(char ano);
    void change_class(string upcode,string class_code, string uc_code);

};


#endif //UNTITLED_GESTORHORARIOS_H
