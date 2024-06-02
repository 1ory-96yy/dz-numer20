#include <iostream>
#include <cstring>

class DomesticAnimal {
protected:
    std::string name;
    std::string characteristics;

public:
    DomesticAnimal(const std::string& _name, const std::string& _characteristics)
        : name(_name), characteristics(_characteristics) {}

    void displayInfo() const {
        std::cout << "Name: " << name << ", Characteristics: " << characteristics << std::endl;
    }
};

class Dog : public DomesticAnimal {
public:
    Dog(const std::string& _name, const std::string& _characteristics)
        : DomesticAnimal(_name, _characteristics) {}
};

class Cat : public DomesticAnimal {
public:
    Cat(const std::string& _name, const std::string& _characteristics)
        : DomesticAnimal(_name, _characteristics) {}
};

class Parrot : public DomesticAnimal {
public:
    Parrot(const std::string& _name, const std::string& _characteristics)
        : DomesticAnimal(_name, _characteristics) {}
};

class String {
protected:
    char* str;
    int length;

public:
    String() : str(nullptr), length(0) {}

    String(const char* s) {
        length = strlen(s);
        str = new char[length + 1];
        for (int i = 0; i <= length; ++i) {
            str[i] = s[i];
        }
    }

    String(const String& other) {
        length = other.length;
        str = new char[length + 1];
        for (int i = 0; i <= length; ++i) {
            str[i] = other.str[i];
        }
    }

    String& operator=(const String& other) {
        if (this == &other)
            return *this;

        delete[] str;
        length = other.length;
        str = new char[length + 1];
        for (int i = 0; i <= length; ++i) {
            str[i] = other.str[i];
        }
        return *this;
    }

    ~String() {
        delete[] str;
    }

    int getLength() const {
        return length;
    }

    void clear() {
        delete[] str;
        str = nullptr;
        length = 0;
    }
    String operator+(const String& other) const {
        String temp;
        temp.length = length + other.length;
        temp.str = new char[temp.length + 1];
        for (int i = 0; i < length; ++i) {
            temp.str[i] = str[i];
        }
        for (int i = 0; i <= other.length; ++i) {
            temp.str[length + i] = other.str[i];
        }
        return temp;
    }
    String& operator+=(const String& other) {
        *this = *this + other;
        return *this;
    }
    bool operator==(const String& other) const {
        return strcmp(str, other.str) == 0;
    }
    bool operator!=(const String& other) const {
        return !(*this == other);
    }
};

class BitString : public String {
public:
    BitString() : String() {}

    BitString(const char* s) {
        bool isValid = true;
        for (int i = 0; s[i] != '\0'; ++i) {
            if (s[i] != '0' && s[i] != '1') {
                isValid = false;
                break;
            }
        }

        if (isValid) {
            length = strlen(s);
            str = new char[length + 1];
            for (int i = 0; i <= length; ++i) {
                str[i] = s[i];
            }
        }
        else {
            str = new char[1];
            str[0] = '\0';
            length = 0;
        }
    }

    BitString(const String& other) : String(other) {}

    BitString& operator=(const String& other) {
        String::operator=(other);
        return *this;
    }
    bool operator==(const BitString& other) const {
        return strcmp(str, other.str) == 0;
    }
    bool operator!=(const BitString& other) const {
        return !(*this == other);
    }
};

int main() {
    Dog dog("Buddy", "Loyal");
    Cat cat("Whiskers", "Independent");
    Parrot parrot("Polly", "Talkative");

    dog.displayInfo();
    cat.displayInfo();
    parrot.displayInfo();

    BitString bitString("10101010");
    BitString anotherBitString("20202020");

    return 0;
}
