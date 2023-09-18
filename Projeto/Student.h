/**
 * @file Student.h
 * @date 31-10
 * @brief Neste ficheiro implementamos todas as funções e metodos auxiliares necessários para o ficheiro Student.cpp
 */

#ifndef UNTITLED_STUDENT_H
#define UNTITLED_STUDENT_H
#include <string>
#include <vector>
#include "Uc_turma.h"
using namespace std;

class Student {

private:
    string up;
    string name;
    vector<Uc_turma> horario;

public:

    Student();
    Student(string up);

    void set_student_name(string name);

    void add_uc_turma(string uc_code, string class_code);

    const string get_student_up() const;

    string get_student_name() const;

    vector<Uc_turma> get_Uc_turma() const;

    bool check_class(string uc_code, string class_code) const;

    bool check_uc(string uc_code) const; // vẽ se o estudante tem a uc

    bool check_ano(char ano) const; // vê se o estudante frequenta o ano

    bool operator==(Student student);

    bool operator<(const Student& student);

    void update_class_code(string class_code, string uc_code);


};

namespace std{
    template<>
    struct less<Student>{
        bool operator() (const Student &lhs, const Student &rhs) {
            return lhs.get_student_up() < rhs.get_student_up();
        }};
}

#endif //UNTITLED_STUDENT_H
