/**
 * @file Uc_turma.cpp
 * @date 31-10
 * @brief Permite-nos utilizar informação relativa aos estudantes (uc_code, class_code)
 */
#include "Uc_turma.h"

Uc_turma::Uc_turma(string uc_code, string class_code) {

    this -> uc_code = uc_code;
    this -> class_code = class_code;
}

string Uc_turma::get_uc_code() const {
    return this -> uc_code;
}

string Uc_turma::get_class_code() const {
    return this -> class_code;
}

void Uc_turma::update_class_code(string class_code) {
    this -> class_code = class_code;
}
