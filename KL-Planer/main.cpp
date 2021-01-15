//
// Created by Johnny Imminger, Felix Steinke and Florian Grabowski
//

#include "ReadInput.h"
#include "Algorithm.h"
#include <io.h>
#include <chrono>

void createOutputFiles(Algorithm &alg);

int main() {
    using namespace chrono;
    milliseconds start = duration_cast<milliseconds>(system_clock::now().time_since_epoch());

    ReadInput data;
    data.init();
    Algorithm alg = Algorithm(data);
    alg.initTage();
    alg.run();

    createOutputFiles(alg);

    milliseconds end = duration_cast<milliseconds>(system_clock::now().time_since_epoch());
    cout << "executed in " << (end - start).count() / 1000 << 's' << endl;

    return 0;
}

void createOutputFiles(Algorithm &alg) {
    mkdir("../../KL-Planer/output");

    cout << ">>printing results" << endl;
    alg.printResultByExams("../../KL-Planer/output/result.csv");
    alg.printResultByRooms("../../KL-Planer/output/raumPlanListe.csv");
    alg.printResultByProfs("../../KL-Planer/output/profPlanListe.csv");
    alg.printResultByStudent("../../KL-Planer/output/studentPlanListe.csv");
}