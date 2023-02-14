#include <iostream>
#include <thread>
#include <mutex>
#include <windows.h>
#include <vector>

struct Data{
    int counter = 1;
    std::mutex lock;
};


void displayEven(Data & counter, int n){
    while(counter.counter < n){
        counter.lock.lock();
        if(counter.counter%2 == 0){
            std::cout<<counter.counter<<" ";
            counter.counter++;
        }
        counter.lock.unlock();
    }
}

void displayOdd(Data & counter,int n){
    while(counter.counter < n){
        counter.lock.lock();
        if(counter.counter%2 != 0){
            std::cout<<counter.counter<<" ";
            counter.counter++;
        }
        counter.lock.unlock();
    }
}

int doTheThing(int a, int b){
    return a * b;
}

int main() {
    // 1.
    /*int a[3][3] = {
            1,2,3,
            2,3,4,
            4,5,6
    };
    int b[3][3] = {
            1,2,3,
            2,3,4,
            4,5,6
    };

    int res[3][3] = {
            0,0,0,
            0,0,0,
            0,0,0
    };

    std::vector<std::thread> threads{};
    int som = 0;
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j ++){
            for(int k = 0; k < 3; k++){
                std::thread t(
                        [&res, a, b, i , k, j](){
                            res[i][j] += doTheThing(a[i][k],b[k][j]);
                        }
                        );
                threads.push_back(std::move(t));
                //res[i][j] += a[i][k] * b[k][j];
            }
            som = 0;
        }
    }

    for(auto & thread : threads){
        thread.join();
    }

    for(int i = 0; i < 3; i++ ){
        for(int j = 0; j < 3; j ++){
            std::cout << res[i][j] << " ";
        }
        std::cout <<std::endl;
    }*/
    // 2.
    Data counter;
    int numberToCount = 100;

    std::thread t1([&counter, numberToCount]() {
        displayEven(counter, numberToCount);
    });
    std::thread t2([&counter, numberToCount]() {
        displayOdd(counter, numberToCount);
    });
    t1.join();
    t2.join();
    return 0;
}
