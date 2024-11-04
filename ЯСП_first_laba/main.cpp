//17. Написать программу для кодирования данного текста с помощью азбуки Морзе.
//Пекшин Степан 9 группа 


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
    " "      // Пробел
};

std::string morse(std::string text) {


    std::string morse_text;
    for (char ch : text) {
        ch = toupper(ch); // Преобразуем символ в верхний регистр перед кодированием
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
//кодирование в морзе

int entering_num( std::string message, int upper, int lower)
{
    int choice = lower - 1;
    std::cout << message;
    while (choice < lower || choice > upper)
    {
        std::cin >> choice;
        if (choice < lower || choice > upper || isalpha(choice))
        {
            std::cout << "Введите корректное значение\n";  
        }
        std::cin.ignore(std::cin.rdbuf()->in_avail());
    }
    return choice;
} 
//проверка на валидность воода чисел

void outplace(std::string text)
{

    int choice = entering_num("Куда вывести текст\n1.В консоль\n2.В файл\n->", 2, 1);

    if (choice == 1)
    {
        std::cout << "Текст в азбуке Морзе: " << morse(text) << "\n\n\n"; //выводим текст на азбуке морзе
    }
    else
    {
        std::ofstream out_file("out_file.txt");
        out_file << morse(text);
        out_file.close();
        std::cout << "Результат был записан в файл\n\n\n\n " ;

    }
}
//вывод ответа

std::string entering_file_name() 
{
    std::string file_name;
    bool flag = false;
    std::ifstream file;

    do
    {
        std::cout << "Введите название файла: ";
        std::getline(std::cin, file_name);
        file_name += ".txt";
        file.open(file_name);
        if (!file.is_open())
        {
            std::cout << "ошибка открытия файла, попробуйте еще раз" << std::endl;
        }
        else
            flag = true; 
         std::cin.ignore(std::cin.rdbuf()->in_avail());
    } while (!flag);
    file.close();
    return file_name;
}
//считывание имени файла и проверка is_open

std::string file_reading()
{
    std::string file_name = entering_file_name();

    std::ifstream file;
    file.open(file_name);

    std::string text; //строка с текстом из файла
    std::string line;

    while (std::getline(file, line))
    {
        text += line + '\n';
    }

    file.close();
    return text;
}
//считывание текста из файла

int main() {

    setlocale(LC_ALL, "Russian");
    int choice = 0; 

    while (choice != 3)
    {
        choice = entering_num("Выберите действие\n1.Ввести текст для кодирования вручную\n2.Считать текст для кодирования из файла\n3.Завершить работу программы\n->", 3, 1);
        std::string text;
        switch (choice)
        {
        case 1:
        {
            std::cout << "Введите текст на латинице для кодирования в азбуку Морзе: ";
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