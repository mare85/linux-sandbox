#include <Game/App.h>
/*
 * (C) Copytight 2017 Marek Bielawski
 * Game::App
 */

#include <GL/glx.h>
#include <iostream>
#include <assert.h>
#include <Graphics/GdiContext.h>

namespace Game
{

void App::_initWindow()
{
	display_ = XOpenDisplay(NULL);
	if(display_)
	{
		Window root = DefaultRootWindow(display_);
		XVisualInfo* visInfo = Graphics::GdiContext::GetVisualInfo(display_);
		if( ! visInfo )
		{
			std::cout<<"Display not complatible"<<std::endl;
			assert(false);
		}
		Colormap colormap = XCreateColormap( display_, root, visInfo->visual, AllocNone);
		XSetWindowAttributes desc;
		desc.colormap = colormap;
		desc.event_mask = KeyPressMask;
		window_ = XCreateWindow( display_, root,
				0, 0, width_, height_, 0, visInfo->depth, InputOutput, visInfo->visual, 
				CWColormap | CWEventMask, &desc );
		XMapWindow(display_, window_ );
		XStoreName(display_, window_, "Linux Sandbox - mare");
	}
}
void App::_updateThreadFunc()
{

}

void App::_eventThreadFunc()
{

}

void App::startUp()
{
	_initWindow();
}

void App::shutDown()
{
	if(display_)
	{
		XCloseDisplay(display_);
		display_ = nullptr;
	}
}

}
