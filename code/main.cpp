#include <X11/X.h>
#include <X11/Xlib.h>
#include <unistd.h>
#include <GL/gl.h>
#include <GL/glx.h>
#include <iostream>
int main() 
{

	Display *display = nullptr;
	display = XOpenDisplay(NULL);
	if(display)
	{
		Window root = DefaultRootWindow(display);
		//Window window = XCreateWindow( 
				//display, 
				//0,0,1024,576, 0, CopyFromParent, CopyFromParent, CopyFromParent, 0, 0
		//XFlush(display);
		int visualParams[] = {GLX_RGBA,GLX_DOUBLEBUFFER, GLX_DEPTH_SIZE,24, 0};
		XVisualInfo* visInfo = glXChooseVisual( display, 0,visualParams); 
		if( ! visInfo )
		{
			std::cout<<"Display not complatible"<<std::endl;
			return -1;
		}
		Colormap colormap = XCreateColormap( display, root, visInfo->visual, AllocNone);
		XSetWindowAttributes desc;
		desc.colormap = colormap;
		desc.event_mask = ExposureMask|KeyPressMask;
		Window window = XCreateWindow( display, root,
				0, 0, 1024, 576, 0, visInfo->depth, InputOutput, visInfo->visual, 
				CWColormap | CWEventMask, &desc );
		XMapWindow(display, window );
		XStoreName(display, window, "Linux Sandbox - mare");
		GLXContext glxContet = glXCreateContext(display, visInfo, nullptr, GL_TRUE);
		glXMakeCurrent(display, window, glxContet);
		//XFlush(display);
		sleep(4);
	}
	XCloseDisplay(display);
	return 0;
}
