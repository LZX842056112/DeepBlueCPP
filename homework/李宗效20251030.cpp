#include <iostream>

class Cuboid {
private:
    double l, w, h;

public:
    Cuboid(double l, double w, double h) : l(l), w(w), h(h) {
    }

    ~Cuboid() {
    }

    friend void getInfo(const Cuboid &cuboid);

    friend Cuboid add(const Cuboid &c1, const Cuboid &c2);
};

void getInfo(const Cuboid &cuboid) {
    std::cout << "长: " << cuboid.l << ",宽: " << cuboid.w << ",高: " << cuboid.h << std::endl;
}

Cuboid add(const Cuboid &c1, const Cuboid &c2) {
    return {c1.l + c2.l, c1.w + c2.w, c1.h + c2.h};
}

int main() {
    Cuboid c1(10.1, 20.2, 30.3);
    Cuboid c2(1.1, 2.2, 3.3);
    Cuboid c3 = add(c1, c2);
    getInfo(c3);

    return 0;
}
