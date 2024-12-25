#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

class Student {
private:
    vector<string> names;
    vector<string> studentNumbers;
    vector<float> midterms;
    vector<float> secondExams;
    vector<float> assignments;
    vector<float> finals;
    vector<int> attendance;

public:

    Student() {
        cout << "Student sınıfı oluşturuldu.\n";
    }

    ~Student() {
        cout << "Student sınıfı yok edildi.\n";
    }

    void readFromCSV(const string& fileName) {
        ifstream file(fileName);
        if (!file.is_open()) {
            cout << "Dosya acilamadi: " << fileName << endl;
            return;
        }

        string line;
        while (getline(file, line)) {
            stringstream ss(line);
            string value;

            string name, studentNumber;
            float midterm = 0, secondExam = 0, assignment = 0, finalExam = 0;
            int attend = 0;

            getline(ss, value, ',');
            name = value;

            getline(ss, value, ',');
            studentNumber = value;

            try {
                getline(ss, value, ',');
                midterm = value.empty() ? 0 : stof(value);

                getline(ss, value, ',');
                secondExam = value.empty() ? 0 : stof(value);

                getline(ss, value, ',');
                assignment = value.empty() ? 0 : stof(value);

                getline(ss, value, ',');
                finalExam = value.empty() ? 0 : stof(value);

                getline(ss, value, ',');
                attend = value.empty() ? 0 : stoi(value);
            }
            catch (const invalid_argument&) {
                cout << "Hata: Geçersiz sayı formatı.\n";
                continue;
            }
            catch (const out_of_range&) {
                cout << "Hata: Sayı aralık dışında.\n";
                continue;
            }

            names.push_back(name);
            studentNumbers.push_back(studentNumber);
            midterms.push_back(midterm);
            secondExams.push_back(secondExam);
            assignments.push_back(assignment);
            finals.push_back(finalExam);
            attendance.push_back(attend);
        }

        file.close();
    }

    float average(int index) {
        return midterms[index] * 0.2f +
            secondExams[index] * 0.2f +
            assignments[index] * 0.2f +
            finals[index] * 0.4f;
    }

    // Öğrenci listesini yazdırma (ekrana veya dosyaya)
    void print(const string& fileName = "", int filter = -1) {
        // Eğer dosya adı verilmişse dosyaya yaz
        if (!fileName.empty()) {
            ofstream file(fileName);
            if (!file.is_open()) {
                cout << "Dosya açılmadı: " << fileName << endl;
                return;
            }

            if (filter == -1) {
                file << "Tüm Öğrenciler:\n";
            }
            else if (filter == 0) {
                file << "Kalan Öğrenciler (Ortalama < 50):\n";
            }
            else if (filter == 1) {
                file << "Geçen Öğrenciler (Ortalama >= 50):\n";
            }

            for (size_t i = 0; i < names.size(); ++i) {
                float avg = average(i);
                if ((filter == -1) || (filter == 0 && avg < 50) || (filter == 1 && avg >= 50)) {
                    file << "Ad: " << names[i]
                        << ", No: " << studentNumbers[i]
                        << ", Ortalama: " << avg
                        << ", Devam Sayisi: " << attendance[i] << "\n";
                }
            }

            file.close();
            cout << "Sonuçlar dosyaya yazıldı: " << fileName << endl;
        }

        else {
            cout << "\n=====================================\n";
            if (filter == -1) {
                cout << "Tüm Öğrenciler:\n";
            }
            else if (filter == 0) {
                cout << "Kalan Öğrenciler (Ortalama < 50):\n";
            }
            else if (filter == 1) {
                cout << "Geçen Öğrenciler (Ortalama >= 50):\n";
            }
            cout << "=====================================\n";

            for (size_t i = 0; i < names.size(); ++i) {
                float avg = average(i);
                if ((filter == -1) || (filter == 0 && avg < 50) || (filter == 1 && avg >= 50)) {
                    cout << "Ad: " << names[i]
                        << ", No: " << studentNumbers[i]
                        << ", Ortalama: " << avg
                        << ", Devam Sayisi: " << attendance[i] << endl;
                }
            }
            cout << "=====================================\n";
        }
    }
};

int main() {
    // Student sınıfından bir nesne oluştur
    Student student;

    // Öğrenci verilerini dosyadan oku
    student.readFromCSV("C:\\Users\\LEGEND\\Desktop\\oop-again\\proje\\girdi.cvs");

    // Tüm öğrenciler ekrana yazdır
    student.print();

    // Geçen öğrenciler ekrana yazdır
    student.print("", 1);

    // Kalan öğrenciler ekrana yazdır
    student.print("", 0);

    // Tüm öğrenciler dosyaya yazdır
    student.print("tum_ogrenciler.txt");

    // Geçen öğrenciler dosyaya yazdır
    student.print("gecen_ogrenciler.txt", 1);

    // Kalan öğrenciler dosyaya yazdır
    student.print("kalan_ogrenciler.txt", 0);

    return 0;
}
