#include <emscripten/val.h>
#include <stdio.h>
#include <math.h>

using namespace emscripten;

// based on the excellent WebAudio tutorial at
// http://stuartmemo.com/making-sine-square-sawtooth-and-triangle-waves/

int main() {
    val AudioContext = val::global("AudioContext");
    if (!AudioContext.as<bool>()) {
        printf("No global AudioContext, trying webkitAudioContext\n");
        AudioContext = val::global("webkitAudioContext");
    }
    printf("Got an AudioContext\n");
    val context = AudioContext.new_();
    val oscillator = context.call<val>("createOscillator");

    printf("Configuring oscillator\n");
    oscillator.set("type", val("triangle"));
    oscillator["frequency"].set("value", val(261.63)); // Middle C

    printf("Playing\n");
    oscillator.call<void>("connect", context["destination"]);
    oscillator.call<void>("start", 0);

    printf("All done!\n");
}
