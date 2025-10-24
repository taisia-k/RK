#include <iostream>
#include <vector>
#include <string>
#include <cmath>
using namespace std;

int main() {
    setlocale(LC_ALL, "rus");
    vector<string> batches;
    string line;
    vector<string> ids;
    vector<vector<double>> dims;


    while (getline(cin, line)) 
    {
        if (line.empty()) break;
        batches.push_back(line);
    }


    for (int i = 0; i < batches.size(); i++) 
    {
        string t = batches[i];
        char* str = &t[0];
        string id = "";
        while (*str != ';') {
            id += *str;
            str++;
        }
        str++;
        ids.push_back(id);
        vector<double> sizes;
        string num = "";


        while (*str != '\0') 
        {
            if (*str == ';') 
            {
                sizes.push_back(stod(num));
                num = "";
            }
            else
            {
                num += *str;
            }
            str++;
        }
        sizes.push_back(stod(num));
        dims.push_back(sizes);
    }


    vector<double> sred;
    for (int i = 0; i < dims.size(); i++) 
    {
        double sum = 0;
        for (int j = 0; j < dims[i].size(); j++) {
            sum += dims[i][j];
        }
        double sred_p = sum / dims[i].size();
        sred.push_back(sred_p);
    }


    int c_da = 0;
    for (int i = 0; i < sred.size(); i++) 
    {
        if (sred[i] >= 12.2 && sred[i] <= 12.6) c_da++;
    }

    double percent = (c_da * 100.0) / batches.size();


    for (int i = 0; i < ids.size(); i++) 
    {
        cout << ids[i] << " среднее: " << sred[i];
        if (sred[i] >= 12.2 && sred[i] <= 12.6) {
            cout << " (входит)" << endl;
        }
        else {
            cout << " (не входит)" << endl;
        }
    }
    cout << "Прошло проверку: " << percent << "%" << endl;
    return 0;
}