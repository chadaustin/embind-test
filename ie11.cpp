#include <emscripten/bind.h>

using namespace emscripten;

class SampleClass {
};

std::shared_ptr<SampleClass> newSampleClass() {
    return std::make_shared<SampleClass>();
}

EMSCRIPTEN_BINDINGS(ie11) {
    class_<SampleClass>("SampleClass")
        .smart_ptr<std::shared_ptr<SampleClass>>("SampleClassSPtr")
        ;

    function("newSampleClass", &newSampleClass);
}
