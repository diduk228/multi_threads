#include <QCoreApplication>
#include <thread>
#include <chrono>
#include <iostream>
using namespace std;

void two_thread()
{
    for(int i =0; i < 10; i++)
    {
        //преостанавливает поток
        this_thread::sleep_for(chrono::milliseconds(1000));
        std::cout << "Second thread, id thread: " <<this_thread::get_id() << " itereation: " << i << std::endl;
    }
}
int main()
{
    //Узнать id потока
    //cout << this_thread::get_id();
    thread th(two_thread);
    for(int i =0; i < 10; i++)
    {
        //преостанавливает поток
        this_thread::sleep_for(chrono::milliseconds(1000));
        std::cout << "First thread, id thread: " <<this_thread::get_id() << " itereation: " << i << std::endl;
    }
}
