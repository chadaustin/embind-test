#include <emscripten/emscripten.h>
#include <emscripten/bind.h>
#include <emscripten/val.h>
#include <math.h>

using namespace emscripten;

const double PI = atan(1) * 4;

int main() {
    //EM_ASM("debugger");
    val AudioContext = val::global("AudioContext");
    //EM_ASM("debugger");
    printf("Got global AudioContext\n"); fflush(stdout);
    if (!AudioContext.as<bool>()) {
        printf ("Got here 1\n"); fflush(stdout);
        AudioContext = val::global("webkitAudioContext");
    }
    printf ("Got here 2\n"); fflush(stdout);
    //EM_ASM("debugger");
    val context = AudioContext.new_();
    printf ("Got here 3\n"); fflush(stdout);

    int duration = 2;
    int sampleRate = 44100;

    int numberOfFrames = duration * sampleRate;

    val buffer = context.call<val>("createBuffer", 1, numberOfFrames, sampleRate);
    val data = buffer.call<val>("getChannelData", 0);
    
    for (int i = 0; i < numberOfFrames; ++i) {
        data.set(i, val(sin(440.0 * PI * i / sampleRate)));
    }
    
    auto source = context.call<val>("createBufferSource");
    source.set("buffer", buffer);
    source.call<void>("connect", context["destination"]);
    source.call<void>("start", 0);
    printf("It worked!\n");
}
