#include <unistd.h>
#include <Graphics/GdiContext.h>
int main() 
{
	Graphics::GdiContext gdiCtx;
	gdiCtx.startUp(1024, 576);
	sleep(4);
	gdiCtx.shutDown();
	return 0;
}
