#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

double remap(int& a) {
    a = (3 * a / 4) - 1.75;
    return a;
}

int main()
{
    // Apro i file 
    ifstream dataFile("./data.txt");
    ofstream fout("./result.txt");

    // Controllo che sia presente l'input
    if (dataFile.fail()){
        cerr << "Impossibile aprire il file" << endl;
        return 1;
    }
    
    double val = 0;
    unsigned int nVal = 0;
    double sumVal = 0;
    double mean = 0;

    fout << scientific << setprecision(16) 
            << "# N Mean" << endl;

    while(dataFile >> val)
    {
        // val = 3 * val/4 - 1.75;
        sumVal += val;
        mean = sumVal/++nVal;
        fout << nVal << " " 
              << mean << endl;
    }

    dataFile.close();
    fout.close();

    return 0;
}
