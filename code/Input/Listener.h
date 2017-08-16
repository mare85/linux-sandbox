#ifndef INPUT_LISTENER_DEF
#define INPUT_LISTENER_DEF

#include <X11/X.h>
#include <X11/Xlib.h>
/*
 * (C) Copytight 2017 Marek Bielawski
 * Input::Listener
 */
namespace Input
{
	class Listener
	{
		Display* display_ = nullptr;
	public:
		void startUp( Display* disp );
		void shutDown();
		void update();
	};
}
#endif
