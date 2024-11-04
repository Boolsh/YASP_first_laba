//17. �������� ��������� ��� ����������� ������� ������ � ������� ������ �����.
//������ ������ 9 ������ 


#include <iostream>
#include <fstream>
#include <string>
#include <cctype>

std::string morse_code[] = {
    ".-",    // A
    "-...",  // B
    "-.-.",  // C
    "-..",   // D
    ".",     // E
    "..-.",  // F
    "--.",   // G
    "....",  // H
    "..",    // I
    ".---",  // J
    "-.-",   // K
    ".-..",  // L
    "--",    // M
    "-.",    // N
    "---",   // O
    ".--.",  // P
    "--.-",  // Q
    ".-.",   // R
    "...",   // S
    "-",     // T
    "..-",   // U
    "...-",  // V
    ".--",   // W
    "-..-",  // X
    "-.--",  // Y
    "--..",  // Z
    "-----", // 0
    ".----", // 1
    "..---", // 2
    "...--", // 3
    "....-", // 4
    ".....", // 5
    "-....", // 6
    "--...", // 7
    "---..", // 8
    "----.", // 9
    " "      // ������
};

std::string morse(std::string text) {


    std::string morse_text;
    for (char ch : text) {
        ch = toupper(ch); // ����������� ������ � ������� ������� ����� ������������
        if (isalnum(ch) || ch == ' ') {
            if (ch == ' ') {
                morse_text += morse_code[36] + " ";
            }
            else {
                morse_text += morse_code[ch - (isalpha(ch) ? 'A' : '0')];
            }
        }
        else {
            morse_text += ch;
        }
    }

    return morse_text;
}
//����������� � �����

int entering_num( std::string message, int upper, int lower)
{
    int choice = lower - 1;
    std::cout << message;
    while (choice < lower || choice > upper)
    {
        std::cin >> choice;
        if (choice < lower || choice > upper || isalpha(choice))
        {
            std::cout << "������� ���������� ��������\n";  
        }
        std::cin.ignore(std::cin.rdbuf()->in_avail());
    }
    return choice;
} 
//�������� �� ���������� ����� �����

void outplace(std::string text)
{

    int choice = entering_num("���� ������� �����\n1.� �������\n2.� ����\n->", 2, 1);

    if (choice == 1)
    {
        std::cout << "����� � ������ �����: " << morse(text) << "\n\n\n"; //������� ����� �� ������ �����
    }
    else
    {
        std::ofstream out_file("out_file.txt");
        out_file << morse(text);
        out_file.close();
        std::cout << "��������� ��� ������� � ����\n\n\n\n " ;

    }
}
//����� ������

std::string entering_file_name() 
{
    std::string file_name;
    bool flag = false;
    std::ifstream file;

    do
    {
        std::cout << "������� �������� �����: ";
        std::getline(std::cin, file_name);
        file_name += ".txt";
        file.open(file_name);
        if (!file.is_open())
        {
            std::cout << "������ �������� �����, ���������� ��� ���" << std::endl;
        }
        else
            flag = true; 
         std::cin.ignore(std::cin.rdbuf()->in_avail());
    } while (!flag);
    file.close();
    return file_name;
}
//���������� ����� ����� � �������� is_open

std::string file_reading()
{
    std::string file_name = entering_file_name();

    std::ifstream file;
    file.open(file_name);

    std::string text; //������ � ������� �� �����
    std::string line;

    while (std::getline(file, line))
    {
        text += line + '\n';
    }

    file.close();
    return text;
}
//���������� ������ �� �����

int main() {

    setlocale(LC_ALL, "Russian");
    int choice = 0; 

    while (choice != 3)
    {
        choice = entering_num("�������� ��������\n1.������ ����� ��� ����������� �������\n2.������� ����� ��� ����������� �� �����\n3.��������� ������ ���������\n->", 3, 1);
        std::string text;
        switch (choice)
        {
        case 1:
        {
            std::cout << "������� ����� �� �������� ��� ����������� � ������ �����: ";
            std::getline(std::cin, text);
            break;
        }
        case 2:
        {

            text = file_reading();
            break;
        }
        }
        if (choice != 3)
            outplace(text);    
    }



    return 0;
}