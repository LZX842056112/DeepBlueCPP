#include <iostream>

double conversion_f(double f) {
    return (f - 32) * 5 / 9;
}

double conversion_c(double c) {
    return c * 9 / 5 + 32;
}

int main() {
    int num;
    double f, c;
    std::cout << "��ѡ��ת������ (1. ����ת����, 2. ����ת����)��";
    std::cin >> num;
    switch (num) {
        case 1:
            std::cout << "�����뻪���¶ȣ�";
            std::cin >> f;
            std::cout << "��Ӧ�������¶�Ϊ��" << conversion_f(f) << " ���϶�" << std::endl;
            break;
        case 2:
            std::cout << "�����������¶ȣ�";
            std::cin >> c;
            std::cout << "��Ӧ�Ļ����¶�Ϊ��" << conversion_c(c) << " ���϶�" << std::endl;
            break;
        default:
            std::cout << "����������!(1. ����ת����, 2. ����ת����)";
    }
}
