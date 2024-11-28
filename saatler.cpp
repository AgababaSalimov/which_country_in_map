#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <iomanip>
#include <unordered_map>

using namespace std;

class Time {
public:
    Time() {
        timeOffsets["Azerbaycan"] = 1;
        timeOffsets["Japonya"] = 6;
        timeOffsets["Amerika"] = -8;
        timeOffsets["Almanya"] = -1;
        timeOffsets["İngiltere"] = -2;
    }

    void convertFile(const string& filename, const string& country) {
        ifstream file(filename);
        if (!file.is_open()) {
            cout << "Dosya acilamadi: " << filename << endl;
            return;
        }


        if (timeOffsets.find(country) == timeOffsets.end()) {
            cout << "Ulke icin saat farki bulunamadi: " << country << endl;
            return;
        }

        int offset = timeOffsets[country];

        string line;
        while (getline(file, line)) {
            int hour, minute, second;
            if (parseTime(line, hour, minute, second)) {
                convertToLocalTime(hour, minute, offset);
                printTime(hour, minute, second);
            }
            else {
                cout << "Gecersiz saat formati: " << line << endl;
            }
        }

        file.close();
    }

private:
    unordered_map<string, int> timeOffsets;

    bool parseTime(const string& timeStr, int& hour, int& minute, int& second) {
        istringstream ss(timeStr);
        char colon;
        if (!(ss >> hour >> colon >> minute >> colon >> second)) {
            return false;
        }
        return true;
    }

    void convertToLocalTime(int& hour, int& minute, int offset) {
        hour = (hour + offset) % 24;
    }

    void printTime(int hour, int minute, int second) {
        cout << setfill('0') << setw(2) << hour << ":"
            << setfill('0') << setw(2) << minute << ":"
            << setfill('0') << setw(2) << second << endl;
    }
};

int main() {
    string filename = "C:\\Users\\AğaBaba\\OneDrive\\Masaüstü\\saatler.txt";
    string country;

    cout << "Lutfen bir ülke adi girin (ornek, Azerbaycan, Japonya, Amerika, Almanya, İngiltere): ";
    cin >> country;

    Time converter;
    converter.convertFile(filename, country);

    return 0;
}
