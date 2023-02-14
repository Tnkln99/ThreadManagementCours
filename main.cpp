#include <iostream>
#include <thread>
#include <windows.h>
#include <vector>


void sayHello(){
    std::cout << "executed 1 ";
    Sleep(2000);
    std::cout << "finished 1 ";
}

void sayHello2(){
    std::cout << "executed 2 ";
    std::cout << "finished 2 ";
}

int doTheThing(int a, int b){
    return a * b;
}

int main() {
    int a[3][3] = {
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
    }
    return 0;
}
