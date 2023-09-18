/**
 * @file Menu.h
 * @date 31-10
 * @brief Mostra ao USER todas as funcionalidades do menu
 */

#ifndef UNTITLED_MENU_H
#define UNTITLED_MENU_H
#include <iostream>
#include "GestorHorarios.h"

using namespace std;

class Menu {
private:
    GestorHorarios gestorHorarios;

public:

    Menu();

    void showLoginScreen();

    void showMenu1();

    void showMenu2();

    void showMenu3();

    void show_estudantes_numa_uc();

    void show_estudantes_numa_turma();

    void show_estudantes_ano();

    void showHorarioEstudante();

    void showHorarioTurma();

    void showHorarioUc();

    void showHorarioTurma_numa_Uc();

    void show_num_alunos_turma();

    void showOcupacaoTurmas();

};


#endif //UNTITLED_MENU_H
