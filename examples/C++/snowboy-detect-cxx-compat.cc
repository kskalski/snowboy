#undef _GLIBCXX_USE_CXX11_ABI
#define _GLIBCXX_USE_CXX11_ABI 0

#include "include/snowboy-detect-cxx-compat.h"

static snowboy::SnowboyDetect* c(void* p) { return reinterpret_cast<snowboy::SnowboyDetect*>(p); }
static const snowboy::SnowboyDetect* c(const void* p) {
  return reinterpret_cast<const snowboy::SnowboyDetect*>(p);
}

Snowboy::Snowboy(const char* resource_name, Model model, float audio_gain)
    : detector_(new snowboy::SnowboyDetect(resource_name, model.filename)) {
  // Initializes Snowboy detector.
  // If you have multiple hotword models (e.g., 2), you should set
  // <model_filename> and <sensitivity_str> as follows:
  //   model_filename = "resources/snowboy.umdl,resources/alexa.pmdl";
  //   sensitivity_str = "0.4,0.4";
  c(detector_)->SetSensitivity(std::to_string(model.sensitivity));
  c(detector_)->SetAudioGain(audio_gain);
  c(detector_)->ApplyFrontend(true);
}

int Snowboy::SampleRate() const { return c(detector_)->SampleRate(); }

int Snowboy::NumChannels() const { return c(detector_)->NumChannels(); }

int Snowboy::BitsPerSample() const { return c(detector_)->BitsPerSample(); }

int Snowboy::RunDetection(const int16_t* data, int num_samples) {
  return c(detector_)->RunDetection(data, num_samples);
}
