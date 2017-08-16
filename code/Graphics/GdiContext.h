#ifndef GRAPHICS_GDICONTEXT_DEF
#define GRAPHICS_GDICONTEXT_DEF
/*
 * (C) Copytight 2017 Marek Bielawski
 * Graphics::GdiContext 
 */

#include <X11/X.h>
#include <X11/Xlib.h>
#include <GL/gl.h>
#include <GL/glx.h>

namespace Graphics
{
	class GdiContext 
	{
		Display* display_ = nullptr;
		Window window_;
		GLXContext glxContext_;
	public:
		static XVisualInfo* GetVisualInfo(Display* display);
		GdiContext( Display* display, Window window);
		~GdiContext();
		void clearRender();
		void swapRender();
		
	};
}

#endif
