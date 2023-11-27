#include <string>
#include <iostream>
#include <Windows.h>
#include <iomanip>

using namespace std;

enum Spec {
    RI = 1,
    KN,
    IT,
    ME,
    FIT,
    WT
};

struct Student {
    int id;
    std::string surname;
    int course;
    Spec spec;
    union {
        int physics;
        int math;
        int it;
        int programming;
        int num_methods;
        int pedagogy;
    };
};


void Create(Student* students, const int N) {
    int spec;

    for (int i = 0; i < N; i++) {
        cout << "������� � " << i + 1 << ":" << endl;
        cin.get();
        cin.sync();
        students[i].id = i + 1;

        std::cout << "�������: "; std::cin >> students[i].surname;
        std::cout << "����: "; std::cin >> students[i].course;
        std::cout << "������������ (" <<
            "в: " << RI << ", " <<
            "��: " << KN << ", " <<
            "��: " << IT << ", " <<
            "���: " << ME << ", " << 
            "��: " << FIT << ", " <<
            "��: " << WT << "):" << std::endl;

        std::cin >> spec;
        students[i].spec = (Spec)spec;
        cout << "Գ����: "; cin >> students[i].physics;
        cout << "����������: "; cin >> students[i].math;
        switch (students[i].spec) {
        case KN:
            cout << "�������������: "; cin >> students[i].programming;
            break;
        case IT:
            cout << "������� ������: "; cin >> students[i].num_methods;
            break;
        case ME:
        case WT:
        case FIT:
            cout << "���������: "; cin >> students[i].pedagogy;
        }
       cout << endl;

    }
}

std::string getSpecStr(Spec s) {
    switch (s) {
    case RI:
        return "в";
    case KN:
        return "��";
    case IT:
        return "��";
    case ME:
        return "���";
    case FIT:
        return "��";
    case WT:
        return "��";
    default:
        return "�������";
    }
    
}

void PrintHeader() {
    cout << "========================================================================================================="
        << endl;
    cout << "| �  | ������� | ���� | ������������ | Գ���� | ���������� | ������������� | ���. ������ | ��������� |"
        << endl;
    cout << "========================================================================================================="
        << endl;
}

void Print(const Student* p, int N) {
    PrintHeader();

    for (int i = 0; i < N; i++)
    {
        cout << "| " << setw(2) << right << i + 1 << " ";
        cout
            << "| " << setw(8) << right << p[i].surname << " "
            << "| " << setw(5) << left << p[i].course
            << "| " << setw(14) << left << getSpecStr(p[i].spec)
            << "| " << setw(7) << right << p[i].physics
            << "| " << setw(11) << right << p[i].math;
            switch (p[i].spec) {
            case KN:
                cout << "| " << setw(14) << right << p[i].programming << "|" << setw(14) << "|" << setw(13) << "|" << endl;
                break;
            case IT:
                cout << "| " << setw(15) << "|" << setw(13) << right << p[i].num_methods << "|" << setw(13) << "|" << endl;
                break;
            case ME:
            case FIT:
            case WT:
                cout << "| " << setw(15) << "|" << setw(14) << "|" << setw(12) << right << p[i].pedagogy << "|" << endl;
                break;
            }
        cout << "---------------------------------------------------------------------------------------------------------";
        cout << endl;
    }
    cout << endl;
}

double average1(Student& p) {
    return ((double)p.physics + (double)p.it + (double)p.math) / 3.0;
}

double Tusk1(Student* p, int n) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (average1(p[i]) > 4.5) {
            count++;
        }
    }

    return ((double)count / n) * 100;
}

void Tusk2(Student* p, int n) {
    bool found = false;
    for (int i = 0; i < n; i++) {
        if (p[i].physics == 5
            && p[i].math == 5 
            && p[i].it == 5
            && p[i].num_methods == 5
            && p[i].pedagogy == 5
            && p[i].programming == 5) {
            cout << p[i].surname << endl;
            found = true;
        }
    }
    if (!found) {
        cout << "³������� ����" << endl;
    }
}

int main()

{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int N;
    cout << "������ N: "; cin >> N;
    cout << endl;

    Student* a = new Student[N];

    Create(a, N);

    Print(a, N);

    cout << "% �������� � ���� ������� ��� ������ �� 4.5: " << Tusk1(a, N) << endl << endl;

    Tusk2(a, N);

    delete[] a;
    return 0;

}