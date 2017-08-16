#include <Graphics/GdiContext.h>

#include <iostream>
/*
 * (C) Copytight 2017 Marek Bielawski
 * Graphics::GdiContext 
 */
namespace Graphics {

XVisualInfo* GdiContext::GetVisualInfo(Display* display)
{
		int visualParams[] = {GLX_RGBA,GLX_DOUBLEBUFFER, GLX_DEPTH_SIZE,24, 0};
		return glXChooseVisual( display, 0,visualParams); 
}

GdiContext::GdiContext( Display* display, Window window)
{
	display_ = display;
	window_ = window;
	glxContext_ = glXCreateContext(display_, GetVisualInfo(display_), nullptr, GL_TRUE);
	glXMakeCurrent(display_, window_, glxContext_);
		//int version[2];
		//glGetIntegerv(GL_MAJOR_VERSION, version);
		//glGetIntegerv(GL_MINOR_VERSION, version + 1);
		//std::cout<<"opengl version " << version[0] << "." << version[1] << std::endl;
}


GdiContext::~GdiContext()
{
}

void GdiContext::clearRender()
{
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void GdiContext::swapRender()
{
	glXSwapBuffers(display_, window_ );
}

}
