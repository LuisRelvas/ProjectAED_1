/**
 * @file Class.cpp
 * @date 31-10
 * @brief Permite-nos armazenar a informação relativa a cada estudante (uc_Code, class_code, horario)
 */
#include "Class.h"

Class::Class(string class_code) {

    this -> class_code = class_code;
}

void Class::set_uc_code(string uc_code) {

    this -> uc_code = uc_code;
}

void Class::set_week_day(string week_day) {
    this -> week_day = week_day;
}

void Class::set_start_time(double start_time) {
    this -> start_time = start_time;
}

void Class::set_duration(double duration) {
    this -> duration = duration;
}

void Class::set_type(string type) {
    this -> type = type;
}

string Class::get_class_code() const {
    return this -> class_code;
}

string Class::get_uc_code() const {
    return this -> uc_code;
}

bool Class::operator<(Class aula) {
    return this -> start_time < aula.get_start_time();
}

string Class::get_week_day() const {
    return this -> week_day;
}

double Class::get_start_time() const {
    return this -> start_time;
}

double Class::get_duration() const {
    return this -> duration;
}

string Class::get_type() const {
    return this -> type;
}

Class::Class() {}
