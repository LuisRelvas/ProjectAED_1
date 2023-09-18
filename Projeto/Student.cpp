/**
 * @file Student.cpp
 * @date 31-10
 * @brief Permite-nos armazenar/verificar a informação relativa a cada estudante;
 */

#include "Student.h"

Student::Student(string up) {
    this -> up = up;
}

void Student::set_student_name(string name) {
    this -> name = name;
}

void Student::add_uc_turma(string uc_code, string class_code) {

    Uc_turma temp = Uc_turma(uc_code, class_code);
    horario.push_back(temp);
}

bool Student::check_class(string uc_code, string class_code) const { //verificar se o aluno está em determinada aula/turma

    bool flag = false;

    for(Uc_turma aula : horario)
    {
        if((aula.get_uc_code() == uc_code) && (aula.get_class_code() == class_code))
        {
            flag = true;
            return flag;
        }
        else continue;
    }

    return flag;
}

const string Student::get_student_up() const {
    return this -> up;
}

bool Student::operator==(Student student) {

    return this -> up == student.get_student_up();

}

Student::Student() {}

vector<Uc_turma> Student::get_Uc_turma() const {
    return this -> horario;
}

bool Student::operator<(const Student& student) {
    return this -> up < student.up;
}

bool Student::check_uc(string uc_code) const{

    bool flag = false;

    for(const Uc_turma& aula : horario)
    {
        if((aula.get_uc_code() == uc_code))
        {
            flag = true;
            return flag;
        }
        else continue;
    }

    return flag;
}

string Student::get_student_name() const {
    return this -> name;
}

bool Student::check_ano(char ano) const {

    bool flag = false;

    for(const Uc_turma& aula : horario)
    {
        if(aula.get_class_code()[0] == ano)
        {
            flag = true;
            return flag;
        }
        else continue;
    }

    return flag;

}
void Student::update_class_code(string class_code, string uc_code) {
    for ( Uc_turma& student_class : horario){
        if(student_class.get_uc_code() == uc_code){
            student_class.update_class_code(class_code);
            break;
        }
    }
}




