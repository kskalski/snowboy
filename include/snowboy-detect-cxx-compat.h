#pragma once

#include <cstdint>

#include "snowboy-detect.h"

class Snowboy {
 public:
  struct Model {
    const char* filename;
    float sensitivity;
  };

  Snowboy(const char* resource_name, Model model, float audio_gain);

  int SampleRate() const;
  int NumChannels() const;
  int BitsPerSample() const;

  int RunDetection(const int16_t* data, int num_samples);

 private:
  void* detector_;
};
