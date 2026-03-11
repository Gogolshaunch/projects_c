#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

void encryption(char password, string file) {
    vector<char> buffer;
    ifstream inFile(file, ios::in | ios::binary);

    if (inFile.is_open())
    {
        char ch;
        while (inFile.get(ch)) 
        {
            buffer.push_back(ch ^ password);
        }
        inFile.close();
    }
    else
    {
        cout << "Error opening file!" << endl;
        return;
    }

    string new_file = "C:...";
    if (new_file == file) { return; }

    ofstream outFile1(new_file, ios::out | ios::trunc);

    if (outFile1.is_open())
    {
        for (int i = 0; i < buffer.size(); i++)
        {
            outFile1 << buffer[i];
        }
        outFile1.close();
        cout << "Сообщение зашифровано. Результат сохранен в 'new_file_encr.txt'" << endl;
    }
    else
    {
        cout << "Error opening file!" << endl;
        return;
    }
}

void decryption(char password, string file) {
    vector<char> buffer;
    ifstream inFile(file, ios::in | ios::binary);

    if (inFile.is_open())
    {
        char ch;
        while (inFile.get(ch))
        {
            buffer.push_back(ch ^ password);
        }
        inFile.close();
    }
    else
    {
        cout << "Error opening file!" << endl;
        return;
    }

    string new_file = "C:....";
    if (new_file == file) { return; }

    ofstream outFile1(new_file, ios::out | ios::trunc);

    if (outFile1.is_open())
    {
        for (int i = 0; i < buffer.size(); i++)
        {
            outFile1 << buffer[i];
        }
        outFile1.close();
        cout << "Сообщение расшифровано. Результат сохранен в 'new_file_dencr.txt'" << endl;
    }
    else
    {
        cout << "Error opening file!" << endl;
    }
}

int main(int argc, char* argv[])
{
    setlocale(LC_ALL, "RU");
    if (argc < 3) {
        cout << "Ошибка: Недостаточно данных" << endl;
        return 0;
    }

    string oper = argv[1];
    char password = argv[2][0];
    cout << argv[3];

    if (oper == "1") {
        encryption(password, argv[3]);
    }
    else if (oper == "2") {
        decryption(password, argv[3]);
    }
    else {
        cout << "Ошибка: Неверная операция. Используйте '1' для шифрования или '2' для дешифрования" << endl;
    }
    return 0;

}
