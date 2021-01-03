#include <iostream>     // std::cout
#include <algorithm>    // std::max_element
#include <vector>       // std::vector
#include <assert.h> 

class Bitmap {
private:
    std::vector<uint32_t> _bits; 
    uint32_t _max_num = 0;
public:
    Bitmap(uint32_t max_num);
    void Set(uint32_t num);
    void Reset(uint32_t num);
    bool Test(uint32_t num);
    ~Bitmap();
};

bool myfunction (uint32_t i, uint32_t j) { 
    return i < j; 
}

int32_t main () {
    std::cout << (1 << 3) << std::endl;

    uint32_t myints[] = {32, 71, 12, 45, 26, 80, 53, 33};
    uint32_t myints_len = sizeof(myints) / sizeof(myints[0]);
    std::vector<int> myvector (myints, myints + myints_len);    // 32 71 12 45 26 80 53 33

    // using function as comp
    uint32_t max = *std::max_element(myvector.begin(), myvector.end());
    std::sort (myvector.begin(), myvector.end(), myfunction);   //(12 26 32 33 45 53 71 80)
    std::cout << "myvector contains:";

    for (std::vector<int>::iterator it = myvector.begin(); it != myvector.end(); ++ it) {
        std::cout << ' ' << *it;
    }
    std::cout << std::endl;

    return 0;
}

Bitmap::Bitmap(uint32_t max_num) {
    uint32_t size = max_num / 32 + 1;
    _bits.resize(size, 0);
    _max_num = max_num;
}

Bitmap::~Bitmap() {
}

void Bitmap::Set(uint32_t num) {
    assert(num <= _max_num);
    uint32_t idx = num / 32;
    uint32_t offset = num % 32;
    _bits[idx] |= (1 << offset);
}

void Bitmap::Reset(uint32_t num) {
    assert(num <= _max_num);
    uint32_t idx = num / 32;
    uint32_t offset = num % 32;
    _bits[idx] &= ~(1 << offset);
}

bool Bitmap::Test(uint32_t num) {
    assert(num <= _max_num);
    uint32_t idx = num / 32;
    uint32_t offset = num % 32;
    return static_cast<bool>(_bits[idx] & (1 << offset));
}
