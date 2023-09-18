/**
 * @file Menu.cpp
 * @date 31-10
 * @brief A partir deste ficheiro podemos navegar pelo menu
 */

#include "Menu.h"

Menu::Menu(){
    gestorHorarios=GestorHorarios();
    gestorHorarios.read_info_students();
    gestorHorarios.read_info_classes();
    gestorHorarios.read_info_uc();
}

void Menu::showLoginScreen() {

    char input;

    bool done = false;

    while (!done) {
        cout << endl;
        cout << "**********************" << endl;
        cout << "* Horários LEIC *" << endl;
        cout << "**********************" << endl;
        cout << endl;
        cout << "0 - Sair e gravar" << endl;
        cout << "1 - Informações gerais" << endl;
        cout << "2 - Informações sobre o horário" << endl;
        cout << "3 - Efetuar pedidos de alteração gerais" << endl;
        cout << "4 - Terminar dia" << endl;
        cout << endl;
        cout << "> Escolha o que pretende fazer:" << endl;
        cout << "> ";
        cin >> input;
        cin.ignore();

        input = tolower(input);
        done = false;

        switch (input) {
            case '1':
                showMenu1();
                break;
            case '2':
                showMenu2();
                break;
            case '3':
                showMenu3();
                break;
            case '4':
                cout << endl;
                cout << "A terminar dia..." << endl;
                exit(0);
            default:
                cout << endl;
                cout << "> Introduziu uma opção inválida. Tente novamente:" << endl;
                cout << "> ";
                done = false;
                break;
        }
    }

}

void Menu::showMenu1() {

    int input;
    bool done = false;

    while(!done)
    {
        cout << endl;
        cout << "0 - Voltar" << endl;
        cout << "1 - Número estudantes numa turma" << endl;
        cout << "2 - Estudantes numa determinada turma" << endl;
        cout << "3 - Estudantes numa determinada Uc" << endl;
        cout << "4 - Estudantes num determinado ano" << endl;
        cout << endl;
        cout << "> O que pretende fazer?" << endl;
        cout << "> ";
        cin >> input;

        switch(input)
        {
            case 0:
                done = true;
                showLoginScreen();
                break;
            case 1:
                show_num_alunos_turma();
                break;
            case 2:
                show_estudantes_numa_turma();
                break;
            case 3:
                show_estudantes_numa_uc();
                break;
            case 4:
                show_estudantes_ano();
                break;
            default:
                cout << endl;
                cout << "> Introduziu uma opção inválida. Tente novamente:" << endl;
                cout << "> ";

        }


    }

}


void Menu::showMenu2() {

    int input;
    bool done = false;
    while (!done) {

        cout << endl;
        cout << "0 - Voltar" << endl;
        cout << "1 - Horário de um estudante" << endl;
        cout << "2 - Horário de uma turma" << endl;
        cout << "3 - Horário de uma unidade curricular" << endl;
        cout << "4 - Horário de uma turma numa determinada unidade curricular" << endl;
        cout << endl;
        cout << "> O que pretende fazer?" << endl;
        cout << "> ";
        cin >> input;

        switch(input)
        {
            case 0:
                done = true;
                showLoginScreen();
                break;
            case 1:
                showHorarioEstudante();
                break;
            case 2:
                showHorarioTurma();
                break;
            case 3:
                showHorarioUc();
                break;
            case 4:
                showHorarioTurma_numa_Uc();
                break;
            default:
                cout << endl;
                cout << "> Introduziu uma opção inválida. Tente novamente:" << endl;
                cout << "> ";

        }
    }

}


void Menu::showHorarioEstudante() {

    string input;
    bool done = false, flag = true;
    vector<Class> horario;

    while (!done) {
        cout << endl;
        cout << "*****************************************" << endl;
        cout << "* Visualização de horários (estudantes) *" << endl;
        cout << "*****************************************" << endl;
        cout << endl;
        cout << "> Introduza o seu número de estudante:" << endl; // depois de meter o número de estudante tem de aparecer o horário dele
        cout << "> ";
        cin >> input;

        while(flag)
        {
            if(gestorHorarios.find_student(input))
            {
                horario = gestorHorarios.horario_estudante(input);
                flag = false;
            }
            else
            {
                cout << endl;
                cout << "> Número de estudante inválido! Tente novamente:" << endl;
                cout << "> ";
                cin >> input;
                cout << endl;
            }
        }

        cout << endl;
        cout << "HORÁRIO:" << endl;

        for(Class& aula : horario)
        {
            cout << aula.get_class_code() << " " << aula.get_uc_code() << " " << aula.get_week_day() << " " << aula.get_start_time() << " " << aula.get_duration() << " " << aula.get_type() << endl;
        }

        char input1;
        cout << endl;
        cout << "> Deseja:" << endl;
        cout << "1. Ver outro horário" << endl;
        cout << "2. Voltar ao menu inicial" << endl;
        cout << endl;
        cout << "> ";
        cin >> input1;

        switch (input1) {
            case '1':
                showMenu2();
                break;
            case '2':
                showLoginScreen();
                break;
        }
    }

}

void Menu::showHorarioTurma() {

    string input;
    bool done = false, flag = true;
    vector<Class> horario;

    while (!done) {
        cout << endl;
        cout << "*************************************" << endl;
        cout << "* Visualização de horários (turmas) *" << endl;
        cout << "*************************************" << endl;
        cout << endl;
        cout << "> Introduza a turma:" << endl;
        cout << "> ";
        cin >> input;


        while(flag)
        {
            if(gestorHorarios.find_class_code( input))
            {
                horario = gestorHorarios.horario_turma(input);
                flag = false;
            }
            else
            {
                cout << endl;
                cout << "> Turma inválida! Tente novamente:" << endl;
                cout << "> ";
                cin >> input;
            }
        }

        cout << endl;
        cout << "HORÁRIO:" << endl;

        for(Class& aula : horario)
        {
            cout << aula.get_uc_code() << " " << aula.get_week_day() << " " << aula.get_start_time() << " " << aula.get_duration() << " " << aula.get_type() << endl;
        }

        char input1;
        cout << endl;
        cout << "> Deseja:" << endl;
        cout << "1. Ver outro horário" << endl;
        cout << "2. Voltar ao menu inicial" << endl;
        cout << endl;
        cout << "> ";
        cin >> input1;

        switch (input1) {
            case '1':
                showMenu2();
                break;
            case '2':
                showLoginScreen();
                break;
        }
    }

}


void Menu::showHorarioUc() {

    string input;
    bool done = false, flag = true;
    vector<Class> horario;

    while (!done) {
        cout << endl;
        cout << "*************************************" << endl;
        cout << "* Visualização de horários (Uc's) *" << endl;
        cout << "*************************************" << endl;
        cout << endl;
        cout << "> Introduza o código da Uc:" << endl;
        cout << "> ";
        cin >> input;


        while(flag)
        {
            if(gestorHorarios.find_uc(input))
            {
                horario = gestorHorarios.horario_Uc(input);
                flag = false;
            }
            else
            {
                cout << endl;
                cout << "> Código da Uc inválido! Tente novamente:" << endl;
                cout << "> ";
                cin >> input;
            }
        }

        cout << endl;
        cout << "HORÁRIO:" << endl;

        for(Class& aula : horario)
        {
            cout << aula.get_week_day() << " " << aula.get_start_time() << " " << aula.get_duration() << " " << aula.get_type() << endl;
        }

        char input1;
        cout << endl;
        cout << "> Deseja:" << endl;
        cout << "1. Ver outro horário" << endl;
        cout << "2. Voltar ao menu inicial" << endl;
        cout << endl;
        cout << "> ";
        cin >> input1;

        switch (input1) {
            case '1':
                showMenu2();
                break;
            case '2':
                showLoginScreen();
                break;
        }
    }

}


void Menu::showHorarioTurma_numa_Uc() {

    string input, input1;
    bool done = false, flag = true;
    vector<Class> horario;

    while (!done) {

        cout << endl;
        cout << "*************************************" << endl;
        cout << "* Visualização de horários (Turma numa Uc) *" << endl;
        cout << "*************************************" << endl;
        cout << endl;
        cout << "> Introduza a turma:" << endl;
        cout << "> ";
        cin >> input;
        cout << endl;
        cout << "> Introduza o código da cadeira:" << endl;
        cout << "> ";
        cin >> input1;



        while(flag)
        {
            if(gestorHorarios.find_turma(input1, input))
            {
                horario = gestorHorarios.horario_turma_Uc(input, input1);
                flag = false;
            }
            else
            {
                cout<< endl;
                cout<< "> Turma/aula inválida! Tente novamente:" << endl;
                cout<< endl;
                cout<< "> Introduza a turma:" << endl;
                cout<< "> ";
                cin >> input;
                cout << endl;
                cout << "> Introduza o código da cadeira:" << endl;
                cout << "> ";
                cin >> input1;
            }
        }

        cout << endl;
        cout << "HORÁRIO:" << endl;

        for(Class& aula : horario)
        {
            cout << aula.get_week_day() << " " << aula.get_start_time() << " " << aula.get_duration() << " " << aula.get_type() << endl;
        }
        char input2;
        cout<<endl;
        cout << "> Deseja:" << endl;
        cout<< "1. Ver outro horário" << endl;
        cout<< "2. Voltar ao menu inicial" << endl;
        cout<< endl;
        cout<< "> ";
        cin>> input2;
        switch (input2) {
            case '1':
                showMenu2();
                break;
            case '2':
                showLoginScreen();
                break;
        }
    }
}



void Menu::show_num_alunos_turma() {

    string input, input1;

    cout << endl;
    cout << "> Introduza a turma:" << endl;
    cout << "> ";
    cin >> input;
    cout << endl;
    cout << "> Introduza o código da cadeira:" << endl; // depois de meter o número de estudante tem de aparecer o horário dele
    cout << "> ";
    cin >> input1;
    cout << endl;
    cout << "Número estudantes:" << endl;
    cout << gestorHorarios.numero_estudantes_turma(input, input1);
    cout << endl;
}
void Menu::showOcupacaoTurmas() {

    vector<string> turmas;
}

void Menu::show_estudantes_numa_uc() {

    string input;
    bool done = false, flag = true;
    vector<Student> estudantes_numa_uc ;

    while (!done) {


        cout << endl;
        cout << "****************************" << endl;
        cout << "* Lista estudantes numa Uc *" << endl;
        cout << "****************************" << endl;
        cout << endl;
        cout << "> Introduza o código da Uc:" << endl;
        cout << "> ";
        cin >> input;


        while(flag)
        {
            if(gestorHorarios.find_uc(input))
            {
                estudantes_numa_uc = gestorHorarios.estudantes_numa_uc(input);
                flag = false;
            }
            else
            {
                cout << endl;
                cout << "> Código da Uc inválido! Tente novamente:" << endl;
                cout << "> ";
                cin >> input;
                cout << endl;
            }
        }

        cout << endl;
        cout << "Estudantes em determinada Uc:" << endl;

        for(Student& student : estudantes_numa_uc)
        {
            cout << student.get_student_up() << " " << student.get_student_name() << endl;
        }

        showMenu1();

    }


}

void Menu::show_estudantes_numa_turma() {

    string input, input1;
    bool done = false, flag = true;
    vector<Student> estudantes_numa_turma;

    while (!done) {


        cout << endl;
        cout << "*******************************" << endl;
        cout << "* Lista estudantes numa turma *" << endl;
        cout << "*******************************" << endl;
        cout << endl;
        cout << "> Introduza o código da aula:" << endl;
        cout << "> ";
        cin >> input;
        cout << endl;
        cout << "> Introduza o código da Uc:" << endl;
        cout << "> ";
        cin >> input1;


        while (flag) {
            if (gestorHorarios.find_turma(input1, input)) {
                estudantes_numa_turma = gestorHorarios.estudantes_numa_turma(input, input1);
                flag = false;
            } else {
                cout << endl;
                cout << "> Turma inválida! Tente novamente:" << endl;
                cout << endl;
                cout << "> Introduza o código da aula:" << endl;
                cout << "> ";
                cin >> input;
                cout << endl;
                cout << "> Introduza o código da Uc:" << endl;
                cout << "> ";
                cin >> input1;
            }
        }

        cout << endl;
        cout << "Estudantes numa determinada turma:" << endl;

        for (Student& student: estudantes_numa_turma) {
            cout << student.get_student_up() << " " << student.get_student_name() << endl;
        }

        showMenu1();
        done = true;
    }

}

void Menu::show_estudantes_ano() {

    char input;
    bool done = false, flag = true;
    vector<Student> estudantes_num_ano;

    while (!done) {


        cout << endl;
        cout << "****************************" << endl;
        cout << "* Lista estudantes num ano *" << endl;
        cout << "****************************" << endl;
        cout << endl;
        cout << "> Introduza o ano: (1,2 ou 3)" << endl;
        cout << "> ";
        cin >> input;


        while (flag) {
            if (input == '1' || input == '2' || input == '3') {
                estudantes_num_ano = gestorHorarios.estudantes_num_ano(input);
                flag = false;
            } else {
                cout << endl;
                cout << "> Ano inválido! Tente novamente:" << endl;
                cout << endl;
                cout << "> Introduza o ano:" << endl;
                cout << "> ";
                cin >> input;

            }
        }

        cout << endl;
        cout << "Estudantes em determinado ano:" << endl;

        for (Student& student: estudantes_num_ano) {
            cout << student.get_student_up() << " " << student.get_student_name() << endl;
        }

        showMenu1();
        done = true;
    }

}
void Menu::showMenu3() {

    string input,input1,input_3;
    bool done=false, flag=true;
    vector<Class> horario;

    while (!done) {

        cout<<endl;
        cout<< "*************************************" << endl;
        cout<< "* Mudança de turma numa dada UC *" << endl;
        cout<< "*************************************" << endl;
        cout<< endl;
        cout<< "Introduza seu número de estudante:" << endl;
        cout<< ">";
        cin>> input_3;
        cout<< endl;
        cout<< "> Introduza a turma que se quer mudar:" << endl;
        cout<< "> ";
        cin>> input;
        cout<< endl;
        cout<< "> Introduza o código da cadeira:" << endl;
        cout<< "> ";
        cin>>input1;

        while(flag)
        {
            if(gestorHorarios.find_turma(input1,input))
            {
                horario =gestorHorarios.horario_turma_Uc(input, input1);
                flag= false;
            }
            else
            {
                cout << endl;
                cout << "> Turma/aula inválida! Tente novamente:" << endl;
                cout << endl;
                cout << "> Introduza a turma:" << endl;
                cout << "> ";
                cin >> input;
                cout << endl;
                cout << "> Introduza o código da cadeira:" << endl;
                cout << "> ";
                cin >> input1;
            }
        }
        if (gestorHorarios.find_student(input_3)){
            gestorHorarios.change_class(input_3, input, input1);
        }

        char input2;
        cout << endl;
        cout << "> Deseja:" << endl;
        cout << "1. Fazer outra mudança de turma?" << endl;
        cout << "2. Voltar ao menu inicial" << endl;
        cout << endl;
        cout << "> ";
        cin >> input2;

        switch (input2) {
            case '1':
                showMenu3();
                break;
            case '2':
                showLoginScreen();
                break;
        }
    }
}








