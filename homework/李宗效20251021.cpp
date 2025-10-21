#include <iostream>
#include <string>

class Vehicle {
public:
    Vehicle(const std::string &name, const int speed) : model_name_(name), max_speed_(speed) {
    }

    ~Vehicle() {
    }

    void display_info() const {
        std::cout << "型号名称: " << model_name_ << ", 最大速度: " << max_speed_ << std::endl;
    }

protected:
    std::string model_name_;
    int max_speed_;
};

class LandVehicle : virtual public Vehicle {
public:
    LandVehicle(const std::string &name, const int speed,
                const int wheels) : Vehicle(name, speed), num_wheels_(wheels) {
    }

    ~LandVehicle() {
    }

    void display_info() const {
        Vehicle::display_info();
        std::cout << "轮子数量: " << num_wheels_ << std::endl;
    }

protected:
    int num_wheels_;
};

class WaterVehicle : virtual public Vehicle {
public:
    WaterVehicle(const std::string &name, const int speed, const double displacement) : Vehicle(name, speed),
        displacement_(displacement) {
    }

    ~WaterVehicle() {
    }

    void display_info() const {
        Vehicle::display_info();
        std::cout << "排水量: " << displacement_ << std::endl;
    }

    void sail() {
        std::cout << "水上交通工具正在航行" << std::endl;
    }

protected:
    double displacement_;
};


class AmphibiousVehicle : public LandVehicle, public WaterVehicle {
public:
    // AmphibiousVehicle(const std::string &name, const int speed, const int wheels,
    //                   const double displacement) : LandVehicle(name, speed, wheels),
    //                                                WaterVehicle(name, speed, displacement) {
    // }
    AmphibiousVehicle(const std::string &name, const int speed, const int wheels,
                      const double displacement) : Vehicle(name, speed), LandVehicle(name, speed, wheels),
                                                   WaterVehicle(name, speed, displacement) {
    }

    ~AmphibiousVehicle() {
    }

    void display_info() const {
        // LandVehicle::display_info();
        // std::cout << displacement_ << std::endl;

        std::cout << "型号名称: " << model_name_ <<
                ", 最大速度: " << max_speed_ <<
                ", 轮子数量: " << num_wheels_ <<
                ", 排水量: " << displacement_ << std::endl;
    }

    void sail() {
        std::cout << "两栖交通工具正在航行" << std::endl;
    }
};

int main() {
    AmphibiousVehicle av("One", 100, 10, 2);
    av.display_info();
    av.sail();

    return 0;
}
