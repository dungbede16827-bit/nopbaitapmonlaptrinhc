#include <iostream>
#include <vector>
#include <string>
using namespace std;

/* ===== LOP CHA (ABSTRACT) ===== */
class Manager {
public:
    virtual void display() = 0;
    virtual void add() = 0;
    virtual void remove() = 0;
    virtual void update() = 0;
    virtual ~Manager() {}
};

/* ===== DOI TUONG LOP HOC ===== */
class ClassRoom {
private:
    string classId;
    string className;
    string major;
    string type; // CNTT / Ngoai ngu

public:
    ClassRoom(string id, string name, string major, string type) {
        this->classId = id;
        this->className = name;
        this->major = major;
        this->type = type;
    }

    string getId() {
        return classId;
    }

    void display() {
        cout << "Ma lop: " << classId
             << " | Ten lop: " << className
             << " | Chuyen nganh: " << major
             << " | Phan loai: " << type << endl;
    }

    void update() {
        cout << "Nhap ten lop moi: ";
        getline(cin, className);
        cout << "Nhap chuyen nganh moi: ";
        getline(cin, major);
        cout << "Nhap phan loai moi (CNTT/Ngoai ngu): ";
        getline(cin, type);
    }
};

/* ===== QUAN LY LOP HOC ===== */
class ClassManager : public Manager {
private:
    vector<ClassRoom> classes;

public:
    void display() override {
        if (classes.empty()) {
            cout << "Danh sach lop trong!\n";
            return;
        }
        for (auto &c : classes) {
_attach
            c.display();
        }
    }

    void add() override {
        string id, name, major, type;
        cin.ignore();
        cout << "Ma lop: ";
        getline(cin, id);
        cout << "Ten lop: ";
        getline(cin, name);
        cout << "Chuyen nganh: ";
        getline(cin, major);
        cout << "Phan loai (CNTT/Ngoai ngu): ";
        getline(cin, type);

        classes.push_back(ClassRoom(id, name, major, type));
        cout << "Them lop thanh cong!\n";
    }

    void remove() override {
        string id;
        cin.ignore();
        cout << "Nhap ma lop can xoa: ";
        getline(cin, id);

        for (auto it = classes.begin(); it != classes.end(); ++it) {
            if (it->getId() == id) {
                classes.erase(it);
                cout << "Xoa lop thanh cong!\n";
                return;
            }
        }
        cout << "Khong tim thay lop!\n";
    }

    void update() override {
        string id;
        cin.ignore();
        cout << "Nhap ma lop can cap nhat: ";
        getline(cin, id);

        for (auto &c : classes) {
            if (c.getId() == id) {
                c.update();
                cout << "Cap nhat thanh cong!\n";
                return;
            }
        }
        cout << "Khong tim thay lop!\n";
    }
};

/* ===== DOI TUONG SINH VIEN ===== */
class Student {
private:
    string id;
    string name;
    string dob;
    string email;
    string phone;

public:
    Student(string id, string name, string dob, string email, string phone) {
        this->id = id;
        this->name = name;
        this->dob = dob;
        this->email = email;
        this->phone = phone;
    }

    string getId() {
        return id;
    }

    void display() {
        cout << "Ma SV: " << id
             << " | Ten: " << name
             << " | Ngay sinh: " << dob
             << " | Email: " << email
             << " | SDT: " << phone << endl;
    }

    void update() {
        cout << "Nhap ten moi: ";
        getline(cin, name);
        cout << "Nhap ngay sinh moi: ";
        getline(cin, dob);
        cout << "Nhap email moi: ";
        getline(cin, email);
        cout << "Nhap so dien thoai moi: ";
        getline(cin, phone);
    }
};

/* ===== QUAN LY SINH VIEN ===== */
class StudentManager : public Manager {
private:
    vector<Student> students;

public:
    void display() override {
        if (students.empty()) {
            cout << "Danh sach sinh vien trong!\n";
            return;
        }
        for (auto &s : students) {
            s.display();
        }
    }

    void add() override {
        string id, name, dob, email, phone;
        cin.ignore();
        cout << "Ma SV: ";
        getline(cin, id);
        cout << "Ten SV: ";
        getline(cin, name);
        cout << "Ngay sinh: ";
        getline(cin, dob);
        cout << "Email: ";
        getline(cin, email);
        cout << "SDT: ";
        getline(cin, phone);

        students.push_back(Student(id, name, dob, email, phone));
        cout << "Them sinh vien thanh cong!\n";
    }

    void remove() override {
        string id;
        cin.ignore();
        cout << "Nhap ma SV can xoa: ";
        getline(cin, id);

        for (auto it = students.begin(); it != students.end(); ++it) {
            if (it->getId() == id) {
                students.erase(it);
                cout << "Xoa sinh vien thanh cong!\n";
                return;
            }
        }
        cout << "Khong tim thay sinh vien!\n";
    }

    void update() override {
        string id;
        cin.ignore();
        cout << "Nhap ma SV can cap nhat: ";
        getline(cin, id);

        for (auto &s : students) {
            if (s.getId() == id) {
                s.update();
                cout << "Cap nhat thanh cong!\n";
                return;
            }
        }
        cout << "Khong tim thay sinh vien!\n";
    }
};

/* ===== MENU CON ===== */
void subMenu(Manager *manager) {
    int choice;
    do {
        cout << "\n1. Hien thi\n2. Them moi\n3. Xoa\n4. Cap nhat\n0. Quay lai\nChon: ";
        cin >> choice;
        switch (choice) {
        case 1: manager->display(); break;
        case 2: manager->add(); break;
        case 3: manager->remove(); break;
        case 4: manager->update(); break;
        }
    } while (choice != 0);
}

/* ===== MAIN ===== */
int main() {
    ClassManager classManager;
    StudentManager studentManager;

    int choice;
    do {
        cout << "\n===== HE THONG QUAN LY RIKKEI EDU =====\n";
        cout << "1. Quan ly lop hoc\n";
        cout << "2. Quan ly sinh vien\n";
        cout << "0. Thoat\nChon: ";
        cin >> choice;

        if (choice == 1)
            subMenu(&classManager);
        else if (choice == 2)
            subMenu(&studentManager);

    } while (choice != 0);

    cout << "Thoat chuong trinh!\n";
    return 0;
}

