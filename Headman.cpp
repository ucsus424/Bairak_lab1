#include "Headman.h"
#include <iostream>

BayrakHeadman::BayrakHeadman() : BayrakStudent(), phone(L""), headmanYears(0)
{
}

BayrakHeadman::~BayrakHeadman()
{
}

void BayrakHeadman::readFromConsole()
{
    BayrakStudent::readFromConsole();
    phone = inputLine(L"Телефон: ");
    headmanYears = inputInt(L"Стаж старостой (лет): ", 0, 10);
}

void BayrakHeadman::printToConsole() const
{
    std::wcout << L"[Староста] " << name
               << L", возраст: " << age
               << L", средний балл: " << averageGrade
               << L", телефон: " << phone
               << L", стаж старостой: " << headmanYears << std::endl;
}

int BayrakHeadman::getType() const
{
    return TYPE_HEADMAN;
}

void BayrakHeadman::readFromFile(std::wifstream& in)
{
    BayrakStudent::readFromFile(in);
    std::getline(in >> std::ws, phone);
    in >> headmanYears;
}

void BayrakHeadman::writeToFile(std::wofstream& out) const
{
    BayrakStudent::writeToFile(out);
    out << phone << L'\n'
        << headmanYears << L'\n';
}
