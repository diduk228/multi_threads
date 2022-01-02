#include <iostream>
#include <thread>
#include <chrono>

int double2(int k)
{
    return 2*k;
}
int main()
{
    int k = 3;
    std::thread th([&k]() {k = double2(k);}); //возвращаем данные через лямда выражения
    th.join();
    std::cout << k;
    return 0;
}
