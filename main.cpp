/**
 * \file main.cpp    
 * 
 * Audio Engine for Our CoronaGame
 * We have  different functions to be played when we want to inculcate them into our 
 * main game.
 *
 * \author Daniyal Kabir Dar
 */

#define SFML_STATIC
#include <SFML/Graphics.hpp>
#include "SFML/Audio.hpp"

#pragma comment(lib, "gdi32.lib")
#pragma comment(lib, "winmm.lib")
#pragma comment(lib, "opengl32.lib")
#pragma comment(lib, "openal32.lib")
#pragma comment(lib, "flac.lib")
#pragma comment(lib, "vorbisenc.lib")
#pragma comment(lib, "vorbisfile.lib")
#pragma comment(lib, "vorbis.lib")
#pragma comment(lib, "ogg.lib")

#ifdef _DEBUG
#pragma comment(lib, "sfml-system-s-d.lib")
#pragma comment(lib, "sfml-window-s-d.lib")
#pragma comment(lib, "sfml-graphics-s-d.lib")
#pragma comment(lib, "sfml-audio-s-d.lib")
#else
#pragma comment(lib, "sfml-system-s.lib")
#pragma comment(lib, "sfml-window-s.lib")
#pragma comment(lib, "sfml-graphics-s.lib")
#pragma comment(lib, "sfml-audio-s.lib")

#endif





class Audio {


public:

	auto BackMusic() -> void;
	auto SpraySound() -> void;
	auto DieSound() -> void;

	
};

// Member functions definitions

auto Audio::BackMusic()->void {
	sf::RenderWindow window(sf::VideoMode(800, 600), "CoronaGame!");
		sf::Music music;
	
	music.openFromFile("audio/frogs-io.ogg");   // name of audio file available locally for background going to play constantly
	music.setVolume(50);

	music.play();

	sf::Clock clock;
	while (window.isOpen())
	{
		sf::Time dt = clock.restart();
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
			music.stop();
		}

		window.clear(sf::Color::White);
		window.display();

	}

}



// just play the spray sound
auto Audio::SpraySound() -> void {
	
	sf::Music spraymusic;

	spraymusic.openFromFile("audio/frogs-io.ogg");   // play the audio file that has the spray sound
	spraymusic.setVolume(70);     /// sound should be more than background volume

	spraymusic.play();    // how to set timer to stop?  
	
}

auto Audio::DieSound() -> void {


	sf::Music diemusic;
	
	//change audio/frogs-io.ogg to whatever file we are using for the dying sound

	diemusic.openFromFile("audio/frogs-io.ogg");   // play the audio file that has the spray sound
	diemusic.setVolume(70);     /// sound should be more than background volume

	diemusic.play();    // how to set timer to stop?  
}



int main()
{

	Audio s;
	s.BackMusic();
	s.DieSound();
	s.SpraySound();


}