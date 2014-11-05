#pragma once
#ifdef _WIN32
	#include <windows.h>
	#include <winsock2.h>
#else
	#include <arpa/inet.h>
#endif

#define SGE_Main(scene) IF_WIN(int WinMain(HINSTANCE, HINSTANCE, LPSTR, int),int main(int argc, char const *argv[])){\
	std::string name(IF_WIN(GetCommandLine(),argv[0]));\
	const char *title = &name[0] + 1 + name.find_last_of(IF_WIN("\\","/"));\
	*(&name[0] + name.find_last_of(".")) = 0;\
	chdir(&name[0]);\
	return SGE::GEK::main(title,scene);\
}

#include <cmath>
#include <vector>
#include <cstdint>
#include <functional>
#include <unordered_map>
#include <Meta.hpp>
#include <uSDL.hpp>

namespace SGE{
	#include <Vector2.hpp>
	#include <Scene.hpp>
	#include <GEK.hpp>
	#include <Surface.hpp>
	#include <Sprite.hpp>
	#include <TMX.hpp>
	#include <Object.hpp>
	#include <CMWC.hpp>
	#include <UDP.hpp>
}