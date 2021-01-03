#include <iostream>     // std::cout
#include <algorithm>    // std::sort
#include <vector>       // std::vector

bool myfunction (int i,int j) { 
    return i < j; 
}

int main () {
    int myints[] = {32, 71, 12, 45, 26, 80, 53, 33};
    int myints_len = sizeof(myints) / sizeof(myints[0]);
    std::vector<int> myvector(myints, myints + myints_len);    // 32 71 12 45 26 80 53 33
    
    // using function as comp
    std::sort (myvector.begin(), myvector.end(), myfunction);   //(12 26 32 33 45 53 71 80)
    std::cout << "myvector contains:";

    for (std::vector<int>::iterator it = myvector.begin(); it != myvector.end(); ++ it)
        std::cout << ' ' << *it;
    std::cout << std::endl;

    return 0;
}
