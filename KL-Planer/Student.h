//
// Created by Johnny Imminger, Felix Steinke and Florian Grabowski
//

#ifndef KL_PLANNER_STUDENT_H
#define KL_PLANNER_STUDENT_H

#include "Utility.h"

using namespace std;

class Student {
public:
    /*
     * Konstruktoren und toString();
     */

    Student();

    Student(int matikelNr, string studiengang);

    friend std::ostream &operator<<(std::ostream &out, const Student &student);

    /*
     * Getter und Setter
     */

    int getDataIndex() const;

    int getMatrikelNr() const;

    const string &getStudiengang() const;

    int getAmountExams() const;

    const vector<int> &getExamDataIndizes() const;

    void setIndex(int index);

    /*_____________________________________
     * Methoden:
     */

    //Methode added nur die Referenz aus dem Exam-Vektor zu dem Studenten
    void addKlausur(int klausurDataIndex);

private:
    /*
     * Attribute
     */

    int dataIndex;
    int matrikelNr;
    string studiengang;
    int amountExams;
    vector<int> examDataIndizes; //speicherindex der Exam im Pruefungsarray

};

#endif //KL_PLANNER_STUDENT_H
