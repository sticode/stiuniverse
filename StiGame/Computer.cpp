#include "Computer.h"

namespace StiGame
{

int Computer::SystemRAM(void)
{
	return SDL_GetSystemRAM();
}

std::string Computer::CurrentVideoDriver(void)
{
	std::string driver = "";
	driver = SDL_GetCurrentVideoDriver();
	return driver;
}

std::string Computer::CurrentAudioDriver(void)
{
	std::string driver = "";
	driver = SDL_GetCurrentAudioDriver();
	return driver;
}

std::list<std::string> Computer::GetAudioDrivers(void)
{
	int nb = SDL_GetNumAudioDrivers();
	std::list<std::string> drivers;
	
	for(int i=0; i<nb; i++)
	{
		std::string driver = SDL_GetAudioDriver(i);
		drivers.push_back(driver);
	}
	
	return drivers;
}

std::list<std::string> Computer::GetVideoDrivers(void)
{
	int nb = SDL_GetNumVideoDrivers();
	std::list<std::string> drivers;
	
	for(int i=0; i<nb; i++)
	{
		std::string driver = SDL_GetVideoDriver(i);
		drivers.push_back(driver);
	}
	
	return drivers;
}


Computer::Computer() {}
Computer::~Computer() {}

}