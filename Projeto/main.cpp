/**
 * @file main.cpp
 * @date 31-10
 * @brief Este ficheiro permite-nos inicializar o menu de modo a que o USER tenha acesso ao mesmo;
 *\mainpage Description
 * O nosso codigo serve como uma soluçao para os problemas que a gestão de horarios possa trazer;
 * Dispomos de um menu informativo e operacional no caso de querer fazer alguma mudança na sua turma ou horario;
 * Esperemos ser a solução para os vossos problemas;
*/

#include <iostream>
#include "Menu.h"
int main() {

    Menu menu = Menu();
    menu.showLoginScreen();
    return 0;

}
