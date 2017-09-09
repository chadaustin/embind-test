#include <emscripten/bind.h>

using namespace emscripten;

float addTwo(float x, float y) {
    return x + y;
}

struct MyClass {
    void setString(const std::string& s) {
        string = s;
    }

    void printString() {
        printf("%s\n", string.c_str());
    }

    std::string string;
};

EMSCRIPTEN_BINDINGS(test) {
    function("addTwo", &addTwo);
    class_<MyClass>("MyClass")
        .constructor<>()
        .function("printString", &MyClass::printString)
        .function("setString", &MyClass::setString)
        ;
}
