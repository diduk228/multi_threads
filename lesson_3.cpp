#include <iostream>
#include <thread>
#include <chrono>

void double2(int &k)
{
    k = 2*k;
}
int main()
{
    int k = 2;
    std::thread th(double2, std::ref(k)); //возвращаем данные по ссылки, std::ref(x) превращает значение в ccылку
    th.join();
    std::cout << k;
    return 0;
}
