#ifndef GRAPHICS_GDICONTEXT_DEF
#define GRAPHICS_GDICONTEXT_DEF

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
		bool startUp( unsigned int width, unsigned int height);
		void shutDown();
		void clearRender();
		void swapRender();
		
	};
}

#endif
