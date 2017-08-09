#include <unistd.h>
#include <Graphics/GdiContext.h>
#include <thread>
#include <atomic>
void thread(std::atomic_bool * exited)
{
	sleep(4);
	*exited = true;
}

int main() 
{
	Graphics::GdiContext gdiCtx;
	gdiCtx.startUp(1024, 576);
	std::atomic_bool exited ( false );
	std::thread t(thread, &exited );
	while( ! exited )
	{
		gdiCtx.clearRender();
		gdiCtx.swapRender();
	}
	t.join();
	gdiCtx.shutDown();
	return 0;
}
