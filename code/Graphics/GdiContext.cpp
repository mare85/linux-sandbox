#include <Graphics/GdiContext.h>

#include <iostream>

bool Graphics::GdiContext::startUp( unsigned int width, unsigned int height)
{
	display_ = XOpenDisplay(NULL);
	if(display_)
	{
		Window root = DefaultRootWindow(display_);
		int visualParams[] = {GLX_RGBA,GLX_DOUBLEBUFFER, GLX_DEPTH_SIZE,24, 0};
		XVisualInfo* visInfo = glXChooseVisual( display_, 0,visualParams); 
		if( ! visInfo )
		{
			std::cout<<"Display not complatible"<<std::endl;
			return -1;
		}
		Colormap colormap = XCreateColormap( display_, root, visInfo->visual, AllocNone);
		XSetWindowAttributes desc;
		desc.colormap = colormap;
		desc.event_mask = ExposureMask|KeyPressMask;
		window_ = XCreateWindow( display_, root,
				0, 0, width, height, 0, visInfo->depth, InputOutput, visInfo->visual, 
				CWColormap | CWEventMask, &desc );
		XMapWindow(display_, window_ );
		XStoreName(display_, window_, "Linux Sandbox - mare");
		glxContext_ = glXCreateContext(display_, visInfo, nullptr, GL_TRUE);
		glXMakeCurrent(display_, window_, glxContext_);
		return true;
	}
	return false;
}


void Graphics::GdiContext::shutDown()
{
	if(display_)
	{
		XCloseDisplay(display_);
		display_ = nullptr;
	}
}
