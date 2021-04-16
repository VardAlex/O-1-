#include <iostream>
#include <algorithm>

class Container {
private:
    int *buf;
    int *f;
    int setAllBuf;
    int setAllF;
    int size;
public:
    explicit Container(int s) : buf(nullptr), f(nullptr), setAllBuf(0), size(s), setAllF(0) { init(); };

    void init() {
        if (buf == nullptr) {
            buf = new int[size];
        }
        if (f == nullptr) {
            f = new int[size];
        }
        std::fill(buf, buf + size, 0);
        std::fill(f, f + size, 0);
        setAllBuf = 0;
        setAllF = 0;
    }

    void set(int pos, int value) {
        buf[pos] = value;
        f[pos] = setAllF + 1;
    }

    int get(int pos) {
        return setAllF >= f[pos] ? setAllBuf : buf[pos];
    }

    void setAll(int value) {
        setAllBuf = value;
        setAllF++;
    }

    void print() {
        for (int i = 1; i <= size; ++i) {
            std::cout << get(i - 1) << " ";
            if (i % 10 == 0) std::cout << std::endl;
        }
        std::cout << std::endl;
    }
};

int main() {
    Container test(30);

    test.init();
    std::cout << "test.init();\n";
    test.print();

    test.set(1,1);
    test.set(5,2);
    test.set(15,3);
    test.set(23,4);
    std::cout << "test.set(1,1);\n"
                 "test.set(5,2);\n"
                 "test.set(15,3);\n"
                 "test.set(23,4);\n";
    test.print();

    test.setAll(5);
    std::cout << "test.setAll(5);\n";
    test.print();

    test.set(1,6);
    test.set(5,7);
    test.set(16,8);
    test.set(24,9);
    std::cout << "test.set(1,6);\n"
                 "test.set(5,7);\n"
                 "test.set(16,8);\n"
                 "test.set(24,9);\n";
    test.print();

    test.setAll(2);
    test.setAll(1);
    std::cout << "test.setAll(2);\n"
                 "test.setAll(1);\n";
    test.print();

    test.set(0,0);
    test.set(1,0);
    test.set(2,0);
    test.set(3,0);
    test.set(4,0);
    test.set(5,0);
    std::cout << "test.set(0,0);\n"
                 "test.set(1,0);\n"
                 "test.set(2,0);\n"
                 "test.set(3,0);\n"
                 "test.set(4,0);\n"
                 "test.set(5,0);\n";
    test.print();

    return 0;
}
