#define _SILENCE_CXX17_CODECVT_HEADER_DEPRECATION_WARNING
#define _CRTDBG_MAP_ALLOC
#include <cstdlib>
#include <crtdbg.h>
#include <io.h>
#include <fcntl.h>
#include <cstdio>
#include <iostream>
#include <fstream>
#include <locale>
#include <codecvt>
#include "Group.h"
#include "Headman.h"

static void showMenu()
{
    std::wcout << L"\n===== Картотека группы =====\n"
               << L"1. Добавить элемент\n"
               << L"2. Показать список\n"
               << L"3. Сохранить в файл\n"
               << L"4. Загрузить из файла\n"
               << L"5. Очистить список\n"
               << L"0. Выход\n";
}

static void addElement(BayrakGroup& group)
{
    std::wcout << L"Тип элемента:\n1. Студент\n2. Староста\n";
    int type = BayrakStudent::inputInt(L"Ваш выбор: ", 1, 2);

    BayrakStudent* s = nullptr;
    if (type == 1)
        s = new BayrakStudent();
    else
        s = new BayrakHeadman();

    s->readFromConsole();
    group.add(s);
    std::wcout << L"Элемент добавлен." << std::endl;
}

int main()
{
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

    _setmode(_fileno(stdout), _O_U16TEXT);
    _setmode(_fileno(stdin), _O_U16TEXT);

    const std::locale utf8(std::locale::classic(), new std::codecvt_utf8<wchar_t>);

    BayrakGroup group;
    bool running = true;

    while (running)
    {
        showMenu();
        int choice = BayrakStudent::inputInt(L"Выберите пункт: ", 0, 5);

        switch (choice)
        {
        case 1:
            addElement(group);
            break;

        case 2:
            group.print();
            break;

        case 3:
        {
            std::wstring fileName = BayrakStudent::inputLine(L"Имя файла для сохранения: ");
            std::wofstream out;
            out.imbue(utf8);
            out.open(fileName.c_str());
            if (!out)
            {
                std::wcout << L"Не удалось открыть файл." << std::endl;
                break;
            }
            group.save(out);
            std::wcout << L"Сохранено элементов: " << group.size() << std::endl;
            break;
        }

        case 4:
        {
            std::wstring fileName = BayrakStudent::inputLine(L"Имя файла для загрузки: ");
            std::wifstream in;
            in.imbue(utf8);
            in.open(fileName.c_str());
            if (!in)
            {
                std::wcout << L"Не удалось открыть файл." << std::endl;
                break;
            }
            if (group.load(in))
                std::wcout << L"Загружено элементов: " << group.size() << std::endl;
            else
                std::wcout << L"Ошибка формата файла. Загружено элементов: "
                           << group.size() << std::endl;
            break;
        }

        case 5:
            group.clear();
            std::wcout << L"Список очищен." << std::endl;
            break;

        case 0:
            running = false;
            break;
        }
    }

    return 0;
}
