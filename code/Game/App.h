#ifndef GAME_APP_DEF
#define GAME_APP_DEF
/*
 * (C) Copytight 2017 Marek Bielawski
 * Game::App
 */
#include <X11/X.h>
#include <X11/Xlib.h>
#include <thread>
#include <mutex>
namespace Graphics {class GdiContext;}
namespace Game
{
	class App
	{
		std::thread updateThread_;
		std::thread eventThread_;
		Display* display_ = nullptr;
		Window window_ = 0;
		unsigned int width_ = 1024;
		unsigned int height_ = 576;
		bool exiting_;
		Graphics::GdiContext* gdiContext = nullptr;
		std::mutex exitingMutex_;

		void _initWindow();
		void _updateThreadFunc();
		void _eventThreadFunc();
		static void _UpdateThreadFunc(App* _ths){_ths->_updateThreadFunc();}
		static void _EventThreadFunc(App* _ths){_ths->_eventThreadFunc();}
	public:
		void startUp();
		void shutDown();
	};
}

#endif
