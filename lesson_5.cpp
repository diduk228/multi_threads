#include <iostream>
#include <thread>
#include <chrono>
class MyClass
{
public:
    void do_work1()
    {
        for(int i = 0; i < 10; i++)
        {
         int k = 2*2;
         std::this_thread::sleep_for(std::chrono::milliseconds(1000));
         std::cout << std::this_thread::get_id() << " Now thread id\n";
        }
    }
    void do_work(int k)
    {
        for(int i = 0; i < 2; i++)
        {
         int t = 2*2;
         std::this_thread::sleep_for(std::chrono::milliseconds(1000));
         std::cout << std::this_thread::get_id() << " Now thread id\n";
        }
        std::cout << "Значения параметра " << k ;
    }
};
int main()
{
    MyClass my;
    std::thread th(&MyClass::do_work, my,2); // или std::thread th([&](){my.do_work();});
    th.join();
    for(int i = 0; i < 10; i++)
    {
     int k = 2*2;
     std::this_thread::sleep_for(std::chrono::milliseconds(500));
     std::cout << std::this_thread::get_id() << " Now thread id\n";
    }
    return 0;
}
