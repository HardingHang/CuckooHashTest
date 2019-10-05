#include <iostream>
#include <random>
#include "install/include/libcuckoo/cuckoohash_map.hh"
#include "lock-free-cuckoo/lock_free_cuckoo.hpp"

int main() {

    cuckoohash_map<int, std::string> test_table;
    const int max = 999999;
    const int min = 100000;
    int key_num = 1000;

    const static int TABLE_SIZE = 600000 ;
    auto *myHash = new class lockFreeCuckoo<int>(TABLE_SIZE, TABLE_SIZE);

    std::random_device rd;
    std::default_random_engine rnd(rd());
    std::uniform_int_distribution<int> uniDis(min,max);

    clock_t start,finish;
    double totaltime;

    start = clock();
    for (int i = 0; i < key_num; i++) {
        int tmp = uniDis(rnd);
        test_table.insert(tmp, "1");
        //myHash->Insert("1",tmp);
    }
    finish = clock();
    totaltime = (double)(finish-start)/CLOCKS_PER_SEC;
    std::cout << totaltime << std::endl;

    start = clock();
    for (int i = 0; i < key_num; i++) {
        int tmp = uniDis(rnd);
        //test_table.insert(tmp, "1");
        myHash->Insert("1",tmp);
    }
    finish = clock();
    totaltime = (double)(finish-start)/CLOCKS_PER_SEC;
    std::cout << totaltime << std::endl;




    start = clock();
    for(int i = 0;i<100000;i++){
        test_table.contains(uniDis(rnd));
    }
    finish = clock();
    totaltime = (double)(finish-start)/CLOCKS_PER_SEC;
    std::cout << totaltime << std::endl;

    start = clock();
    for(int i = 0;i<100000;i++){
        myHash->Contains(uniDis(rnd));
    }
    finish = clock();
    totaltime = (double)(finish-start)/CLOCKS_PER_SEC;
    std::cout << totaltime << std::endl;

    return 0;
}