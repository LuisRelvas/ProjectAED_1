/**
 * @file Uc_turma.h
 * @date 31-10
 * @brief Neste ficheiro implementamos todas as funções e metodos auxiliares necessários para o ficheiro Uc_turma.cpp
 */

#ifndef UNTITLED_UC_TURMA_H
#define UNTITLED_UC_TURMA_H
#include <string>
using namespace std;

class Uc_turma {

private:
    string uc_code;
    string class_code;

public:

    Uc_turma(string uc_code, string class_code);

    string get_uc_code() const;
    string get_class_code() const;
    void update_class_code(string class_code);

};


#endif //UNTITLED_UC_TURMA_H
