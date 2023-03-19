#include <iostream>
#include <vector>

using namespace std;

class ComputerComponent {
public:
    virtual void printDescription() const = 0;
};

// Процессор
class Processor : public ComputerComponent {
public:
    Processor(string brand, string model, int cores) : m_brand(brand), m_model(model), m_cores(cores) {}

    virtual void printDescription() const override {
        cout << "Processor: " << m_brand << " " << m_model << ", " << m_cores << " cores" << endl;
    }

private:
    string m_brand;
    string m_model;
    int m_cores;
};

// Память
class Memory : public ComputerComponent {
public:
    Memory(string brand, string model, int capacity) : m_brand(brand), m_model(model), m_capacity(capacity) {}

    virtual void printDescription() const override {
        cout << "Memory: " << m_brand << " " << m_model << ", " << m_capacity << " GB" << endl;
    }

private:
    string m_brand;
    string m_model;
    int m_capacity;
};

// Системная плата
class Motherboard : public ComputerComponent {
public:
    Motherboard(string brand, string model, int maxMemory) : m_brand(brand), m_model(model), m_maxMemory(maxMemory) {}

    virtual void printDescription() const override {
        cout << "Motherboard: " << m_brand << " " << m_model << ", max memory: " << m_maxMemory << " GB" << endl;
    }

private:
    string m_brand;
    string m_model;
    int m_maxMemory;
};

// Устройство ввода/вывода
class IODevice : public ComputerComponent {
public:
    IODevice(string name) : m_name(name) {}

    virtual void printDescription() const override {
        cout << "I/O device: " << m_name << endl;
    }

private:
    string m_name;
};

// Класс, описывающий персональный компьютер
class PersonalComputer {
public:
    PersonalComputer() {}

    // Добавление компонента к компьютеру
    void addComponent(ComputerComponent* component) {
        m_components.push_back(component);
    }

    // Вывод описания компьютера
    void printDescription() const {
        cout << "Personal computer components:" << endl;
        for (const auto& component : m_components) {
            component->printDescription();
        }
    }

private:
    vector<ComputerComponent*> m_components;
};

int main() {
    // Создание компонентов
    Processor* processor = new Processor("Intel", "Core i7", 4);
    Memory* memory = new Memory("Kingston", "HyperX", 16);
    Motherboard* motherboard = new Motherboard("Asus", "Z270", 64);
    IODevice* keyboard = new IODevice("Keyboard");
    IODevice* mouse = new IODevice("Mouse");

    // Создание компьютера
    PersonalComputer pc;
    pc.addComponent(processor);
    pc.addComponent(memory);
    pc.addComponent(motherboard);
    pc.addComponent(keyboard);
    pc.addComponent(mouse);

    // Вывод описания компьютера
    pc.printDescription();
}

