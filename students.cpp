#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <iomanip>
#include <algorithm>

using namespace std;


class Course {
private:
    string courseName;
    string courseNumber;
    int creditHours;
    char grade;

public:
    Course(string cName = "", string cNumber = "", int cHours = 0, char cGrade = 'F')
        : courseName(cName), courseNumber(cNumber), creditHours(cHours), grade(cGrade) {}

    void setCourse(string cName, string cNumber, int cHours, char cGrade) {
        courseName = cName;
        courseNumber = cNumber;
        creditHours = cHours;
        grade = cGrade;
    }

    string getCourseName() const { return courseName; }
    string getCourseNumber() const { return courseNumber; }
    int getCreditHours() const { return creditHours; }
    char getGrade() const { return grade; }

    void printCourse() const {
        cout << setw(10) << courseNumber << setw(15) << courseName
            << setw(10) << creditHours << setw(10) << grade << endl;
    }
};

class personType {
protected:
    string firstName;
    string lastName;

public:
    personType(string fName = "", string lName = "") : firstName(fName), lastName(lName) {}

    void setName(string fName, string lName) {
        firstName = fName;
        lastName = lName;
    }

    string getName() const {
        return firstName + " " + lastName;
    }
};

class studentType : public personType {
private:
    int studentID;
    bool isTuitionPaid;
    vector<Course> courses;
    int tuitionPerCreditHour;

public:
    studentType(string fName = "", string lName = "", int id = 0, bool tuitionPaid = false, int tuitionRate = 0)
        : personType(fName, lName), studentID(id), isTuitionPaid(tuitionPaid), tuitionPerCreditHour(tuitionRate) {}

    void setStudentInfo(string fName, string lName, int id, bool tuitionPaid, int tuitionRate) {
        setName(fName, lName);
        studentID = id;
        isTuitionPaid = tuitionPaid;
        tuitionPerCreditHour = tuitionRate;
    }

    void addCourse(Course course) {
        courses.push_back(course);
    }

    void sortCourses() {
        sort(courses.begin(), courses.end(), [](const Course& a, const Course& b) {
            return a.getCourseNumber() < b.getCourseNumber();
            });
    }

    double calculateGPA() const {
        double totalPoints = 0.0;
        int totalCredits = 0;

        for (const Course& course : courses) {
            totalCredits += course.getCreditHours();
            switch (course.getGrade()) {
            case 'A': totalPoints += course.getCreditHours() * 4.0; break;
            case 'B': totalPoints += course.getCreditHours() * 3.0; break;
            case 'C': totalPoints += course.getCreditHours() * 2.0; break;
            case 'D': totalPoints += course.getCreditHours() * 1.0; break;
            default: break;
            }
        }

        return (totalCredits == 0) ? 0.0 : totalPoints / totalCredits;
    }

    int calculateBill() const {
        int totalCredits = 0;
        for (const Course& course : courses) {
            totalCredits += course.getCreditHours();
        }
        return totalCredits * tuitionPerCreditHour;
    }

    void printReport(ofstream& out) const {
        out << "Student Name: " << getName() << endl;
        out << "Student ID: " << studentID << endl;

        if (isTuitionPaid) {
            out << "Number of courses enrolled: " << courses.size() << endl;
            out << setw(10) << "Course No" << setw(15) << "Course Name"
                << setw(10) << "Credits" << setw(10) << "Grade" << endl;

            for (const Course& course : courses) {
                out << setw(10) << course.getCourseNumber()
                    << setw(15) << course.getCourseName()
                    << setw(10) << course.getCreditHours()
                    << setw(10) << course.getGrade() << endl;
            }

            out << "Total number of credits: " << calculateBill() / tuitionPerCreditHour << endl;
            out << "Mid-Semester GPA: " << fixed << setprecision(2) << calculateGPA() << endl;
        }
        else {
            out << "Tuition not paid. Bill: $" << calculateBill() << endl;
        }
        out << "-------------------------" << endl;
    }
};

int main() {
   
    const string inputPath = "C:\\Users\\AğaBaba\\OneDrive\\Masaüstü\\input.txt";
    const string outputPath = "C:\\Users\\AğaBaba\\OneDrive\\Masaüstü\\output.txt";

    ifstream inputFile(inputPath);
    ofstream outputFile(outputPath);

    if (!inputFile.is_open() || !outputFile.is_open()) {
        cerr << "Error opening file! Please check the file paths." << endl;
        return 1;
    }

    int numStudents, tuitionRate;
    inputFile >> numStudents >> tuitionRate;

    vector<studentType> students;

    for (int i = 0; i < numStudents; ++i) {
        string fName, lName, courseName, courseNumber;
        int studentID, numCourses, creditHours;
        char grade, tuitionPaid;

        inputFile >> fName >> lName >> studentID >> tuitionPaid >> numCourses;

        studentType student(fName, lName, studentID, tuitionPaid == 'Y', tuitionRate);

        for (int j = 0; j < numCourses; ++j) {
            inputFile >> courseName >> courseNumber >> creditHours >> grade;
            student.addCourse(Course(courseName, courseNumber, creditHours, grade));
        }

        student.sortCourses();
        students.push_back(student);
    }

    for (const studentType& student : students) {
        student.printReport(outputFile);
    }

    inputFile.close();
    outputFile.close();

    cout << "Reports generated successfully in " << outputPath << endl;

    return 0;
}
