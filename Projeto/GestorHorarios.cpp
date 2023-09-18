/**
 *@file GestorHorarios.cpp
 *@date 31-10
 *@brief Este ficheiro permite-nos processar a informação relativa a cada estudante
 */

#include "GestorHorarios.h"

void GestorHorarios::read_info_students()
{

    ifstream in;
    in.open("C:\\Users\\LuisRelvas\\Desktop\\shedule\\students_classes.csv");
    string line,word, word1;

    getline(in, line);

    getline(in, line);
    stringstream str(line);

    getline(str, word, ',');
    Student student = Student(word);

    getline(str, word, ',');
    student.set_student_name(word);

    getline(str, word, ',');
    getline(str, word1, '\r');
    student.add_uc_turma(word, word1);

    while(getline(in, line))
    {

        stringstream str(line);

        getline(str, word, ',');
        if(word == student.get_student_up())
        {
            getline(str, word, ',');
            getline(str, word, ',');
            getline(str, word1, '\r');
            student.add_uc_turma(word, word1);
        }
        else
        {
            students.insert(student);
            Student student1 = Student(word);

            getline(str, word, ',');
            student1.set_student_name(word);

            getline(str, word, ',');
            getline(str, word1, '\r');
            student1.add_uc_turma(word, word1);
            student = student1;
        }

    }

}

void GestorHorarios::read_info_classes() {

    fstream in("C:\\Users\\LuisRelvas\\Desktop\\shedule\\classes.csv");
    string line, word, number;


    if(in.is_open())
    {
        getline(in, line); //primeira linha que não interessa

        while(getline(in,line))
        {
            stringstream str(line);

            getline(str, word, ',');
            Class aula = Class(word);

            getline(str, word, ',');
            aula.set_uc_code(word);

            getline(str, word, ',');
            aula.set_week_day(word);

            getline(str, number, ',');
            aula.set_start_time(stod(number));

            getline(str, number, ',');
            aula.set_duration(stod(number));

            getline(str, word, '\r');
            aula.set_type(word);


            classes.push_back(aula);
        }
    }
}

void GestorHorarios::read_info_uc() {

    fstream in("C:\\Users\\LuisRelvas\\Desktop\\shedule\\classes_per_uc.csv");
    string line, word, word1;


    if(in.is_open())
    {
        getline(in, line);//primeira linha que não interessa

        while(getline(in, line))
        {
            stringstream str(line);

            getline(str, word, ',');
            getline(str, word1, '\r');

            Uc_turma uc = Uc_turma(word, word1);

            ucs.push_back(uc);

        }
    }
}

int GestorHorarios::numero_estudantes_turma(string class_code, string uc_code) {

    int count = 0;

    for(Student student : students)
    {
        if(student.check_class(uc_code, class_code))
        {
            count++;
        }
        else continue;
    }
    return count;
}

vector<Class> GestorHorarios::horario_estudante(string up) { // COMPLEXIDADE N² !!!!!!!

    Student estudante;
    vector<Class> horario_estudante;

    for(const Student& student : students)
    {
        if(student.get_student_up()  == up)
        {
            estudante = student;
        }
    }

    for(const Uc_turma& item : estudante.get_Uc_turma())
    {
        for(const Class& aula : classes)
        {
            if((aula.get_class_code() == item.get_class_code()) && (aula.get_uc_code() == item.get_uc_code()))
            {
                horario_estudante.push_back(aula);
            }
            else continue;
        }
    }

    sort(horario_estudante.begin(), horario_estudante.end(), [](Class& aula1, Class& aula2)
    {
        if(weekDays.find(aula1.get_week_day())->second == weekDays.find(aula2.get_week_day())->second)
        {
            return aula1.get_start_time() < aula2.get_start_time();
        }
        return weekDays.find(aula1.get_week_day())->second < weekDays.find(aula2.get_week_day())->second;
    }); //sort segundo os dias da semana

    return horario_estudante;

}

bool GestorHorarios::find_student(string up) {

    for(const Student& student : students)
    {
        if(student.get_student_up()  == up)
        {
            return true;
        }
        else continue;
    }

    return false;
}

vector<Student> GestorHorarios::estudantes_numa_uc(string uc_code) {

    vector<Student> estudantes_uc;

    for(const Student& student : students)
    {
        if(student.check_uc(uc_code))
        {
            estudantes_uc.push_back(student);
        }
        else continue;
    }

    sort(estudantes_uc.begin(), estudantes_uc.end());
    return estudantes_uc;
}

bool GestorHorarios::find_uc(string uc_code) {

    for(const Uc_turma& uc : ucs)
    {
        if(uc.get_uc_code()  == uc_code)
        {
            return true;
        }
        else continue;
    }

    return false;
}

vector<Student> GestorHorarios::estudantes_numa_turma(string class_code, string uc_code) {

    vector<Student> estudantes_numa_turma;
    for(const Student& student : students)
    {
        if(student.check_class(uc_code, class_code))
        {
            estudantes_numa_turma.push_back(student);
        }
        else continue;
    }

    sort(estudantes_numa_turma.begin(), estudantes_numa_turma.end());
    return estudantes_numa_turma;
}

bool GestorHorarios::find_turma(string uc_code, string class_code) {

    bool flag = false;

    for(Class& aula : classes)
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

vector<Student> GestorHorarios::estudantes_num_ano(char ano) {

    vector<Student> estudantes_num_ano;

    for(const Student& student : students)
    {
        if(student.check_ano(ano))
        {
            estudantes_num_ano.push_back(student);
        }
        else continue;
    }

    sort(estudantes_num_ano.begin(),estudantes_num_ano.end());
    return estudantes_num_ano;

}

vector<Class> GestorHorarios::horario_turma(string class_code) {


    vector<Class> horario_turma;

    for(const Class& aula : classes)
    {
        if(aula.get_class_code()  == class_code)
        {
            horario_turma.push_back(aula);
        }
    }

    sort(horario_turma.begin(), horario_turma.end(), [](Class& aula1, Class& aula2)
    {
        if(weekDays.find(aula1.get_week_day())->second == weekDays.find(aula2.get_week_day())->second)
        {
            return aula1.get_start_time() < aula2.get_start_time();
        }
        return weekDays.find(aula1.get_week_day())->second < weekDays.find(aula2.get_week_day())->second;
    }); //sort segundo os dias da semana

    return horario_turma;

}

bool GestorHorarios::find_class_code(string class_code) {

    bool flag = false;

    for(Class& aula : classes)
    {
        if(aula.get_class_code() == class_code)
        {
            flag = true;
            return flag;
        }
        else continue;
    }
    return flag;
}

vector<Class> GestorHorarios::horario_Uc(string uc_code) {

    vector<Class> horario_Uc;

    for(const Class& aula : classes)
    {
        if(aula.get_uc_code()  == uc_code)
        {
            horario_Uc.push_back(aula);
        }
    }

    sort(horario_Uc.begin(), horario_Uc.end(), [](Class& aula1, Class& aula2)
    {
        if(weekDays.find(aula1.get_week_day())->second == weekDays.find(aula2.get_week_day())->second)
        {
            return aula1.get_start_time() < aula2.get_start_time();
        }
        return weekDays.find(aula1.get_week_day())->second < weekDays.find(aula2.get_week_day())->second;
    }); //sort segundo os dias da semana

    return horario_Uc;

}

vector<Class> GestorHorarios::horario_turma_Uc(string class_code, string uc_code) {

    vector<Class> horario_turma_Uc;

    for(const Class& aula : classes)
    {
        if((aula.get_class_code()  == class_code) && (aula.get_uc_code() == uc_code))
        {
            horario_turma_Uc.push_back(aula);
        }
    }

    sort(horario_turma_Uc.begin(), horario_turma_Uc.end(), [](Class& aula1, Class& aula2)
    {
        if(weekDays.find(aula1.get_week_day())->second == weekDays.find(aula2.get_week_day())->second)
        {
            return aula1.get_start_time() < aula2.get_start_time();
        }
        return weekDays.find(aula1.get_week_day())->second < weekDays.find(aula2.get_week_day())->second;
    }); //sort segundo os dias da semana

    return horario_turma_Uc;
}

void GestorHorarios::change_class(string upcode, string class_code, string uc_code) {
    Student student(upcode);
    if(student.get_student_up()  == upcode)
    {
        auto px= students.find(student);
        Student student_temp = *px;
        cout << student_temp.get_student_up() << " cujo nome é " << student_temp.get_student_name() << " foi mudado de turma com sucesso!"<< endl;
        students.erase(px);
        if(px==students.end()) cout << "error finding student";
        student_temp.update_class_code(class_code, uc_code);
        students.insert(student_temp);
    }
}









