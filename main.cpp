#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Window.hpp>

#include <math.h>
#include <limits.h>

#include <iostream>
#include <string>
#include <exception>
#include <stdexcept>
#include <vector>

#include "RingBuffer.hpp"
#include "GuitarString.hpp"

#define CONCERT_A 220.0
#define SAMPLES_PER_SEC 44100

using namespace std;

vector<int16_t> makeSamplesFromString(GuitarString guitarString) 
{
  vector<int16_t> samples;

  guitarString.pluck();
  int duration = 8;
  int i;
  for (i= 0; i < SAMPLES_PER_SEC * duration; i++) 
  {
    guitarString.tic();
    samples.push_back(guitarString.sample());
  }

  return samples;
}

int main() 
{
  sf::RenderWindow window(sf::VideoMode(500, 500), "SFML Guitar Hero Lite");
  sf::Event event;
  double freq;
  string keyboard = "q2we4r5ty7u8i9op-[=zxdcfvgbnjmk,.;/' ";

  vector<vector<int16_t> > samples(37);
  vector<sf::Sound> sounds(37);
  vector<sf::SoundBuffer> soundBuffers(37);

  for(int i = 0; i < 37; i++) 
  {
    freq = 440 * pow(2, (i - 24) / 12.0);
    GuitarString guitarString(freq);
    samples[i] = makeSamplesFromString(guitarString);
    
    if (!soundBuffers[i].loadFromSamples(&samples[i][0], samples[i].size(), 2,
                                         SAMPLES_PER_SEC))
      throw std::runtime_error("Cant load the samples");
    
    sounds[i].setBuffer(soundBuffers[i]);
  }
  
  while (window.isOpen()) 
  {
    while (window.pollEvent(event)) 
	{
      switch (event.type) 
	  {
      case sf::Event::Closed:
        window.close();
        break;

      case sf::Event::TextEntered:
        if (event.text.unicode < 128) 
		{
          string temp;
          temp += static_cast<char>(event.text.unicode);
          cout << "Playing sound using the key: " << temp << endl;
          int index = keyboard.find(temp);
          sounds[index].play();
        }
        break;
      default:
        break;
      }  
      
    
      window.clear();
      window.display();
    }
  }

  return 0;
}
