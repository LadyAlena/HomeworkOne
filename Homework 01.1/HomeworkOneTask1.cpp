#include <iostream>
#include <fstream>

int main(int argc, char** argv)
{
    setlocale(LC_ALL, "ru");

    int SizeFirstArr = 0;
    int SizeSecondArr = 0;

    std::fstream FileIn("in.txt");
    std::ofstream FileOut("out.txt");

    /*Чтение из файла*/
    if (!FileIn.is_open()) {
        std::cout << "Файл не открылся!" << std::endl;
        return 0;
    }

    //Чтение 1ого массива
    if (!(FileIn >> SizeFirstArr)) {
        std::cout << "Размер первого массива не считался!" << std::endl;
        return 0;
    }

    if (SizeFirstArr == 0 || SizeFirstArr < 0) {
        std::cout << "Размер массива не может быть меньше или равен нулю..." << std::endl;
        return 0;
    }

    int* FirstArr = new int[SizeFirstArr] {false};

    for (int i = 0; i < SizeFirstArr; ++i) {
        if (!(FileIn >> FirstArr[i])) {
            std::cout << i << " элемент первого массива не считался!" << std::endl;
        }
    }

    //Чтение 2ого массива
    if (!(FileIn >> SizeSecondArr)) {
        std::cout << "Размер второго массива не считался!" << std::endl;
        return 0;
    }

    if (SizeSecondArr == 0 || SizeSecondArr < 0) {
        std::cout << "Размер массива не может быть меньше или равен нулю..." << std::endl;
        return 0;
    }

    int* SecondArr = new int[SizeSecondArr] {false};

    for (int i = 0; i < SizeSecondArr; ++i) {
        if (!(FileIn >> SecondArr[i])) {
            std::cout << i << " элемент второго массива не считался!" << std::endl;
        }
    }

    FileIn.close();

    /*Запись в файл*/

    FileOut << SizeSecondArr << std::endl;
    for (int i = 0; i < SizeSecondArr; ++i) {
        if (!i) { 
            FileOut << SecondArr[SizeSecondArr - 1] << " "; 
        }
        else {
            FileOut << SecondArr[i - 1] << (i < SizeSecondArr - 1 ? " " : "\n");
        }
    }

    FileOut << SizeFirstArr << std::endl;
    for (int i = 0; i < SizeFirstArr; ++i) {
        if (i != SizeFirstArr - 1) {
            FileOut << FirstArr[i + 1] << " ";
        }
        else {
            FileOut << FirstArr[0] << std::endl;
        }
    }

    FileOut.close();

    delete[] FirstArr;
    delete[] SecondArr;
    
    return 0;
}