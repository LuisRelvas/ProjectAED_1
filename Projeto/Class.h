/**
 * @file Class.h
 * @date 31-10
 * @brief Neste ficheiro implementamos todas as funções e metodos auxiliares necessários para o ficheiro Class.cpp
 */

#ifndef UNTITLED_CLASS_H
#define UNTITLED_CLASS_H
#include <string>
using namespace std;

class Class {

private:
    string class_code;
    string uc_code;
    string week_day;
    double start_time;
    double duration;
    string type;

public:

    Class();
    Class(string class_code);
    string get_class_code() const;
    string get_uc_code() const;
    string get_week_day() const;
    double get_start_time() const;
    double get_duration() const;
    string get_type() const;
    void set_uc_code(string uc_code);
    void set_week_day(string week_day);
    void set_start_time(double start_time);
    void set_duration(double duration);
    void set_type(string type);
    bool operator<(Class aula);


};


#endif //UNTITLED_CLASS_H
