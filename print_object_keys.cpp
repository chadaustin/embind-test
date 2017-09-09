#include <stdio.h>
#include <emscripten/val.h>

using emscripten::val;

int main() {
    val window = val::global("window");
    val keys = val::global("Object").call<val>("keys", window);
    int length = keys["length"].as<int>();
    for (int i = 0; i < length; ++i) {
        printf("%s\n", keys[i].as<std::string>().c_str());
    }
}
