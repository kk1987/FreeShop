#ifndef FREESHOP_DOWNLOADQUEUE_HPP
#define FREESHOP_DOWNLOADQUEUE_HPP

#include <bits/unique_ptr.h>
#include <cpp3ds/Window/Event.hpp>
#include <TweenEngine/TweenManager.h>
#include "Download.hpp"
#include "AppItem.hpp"
#include "Installer.hpp"

namespace FreeShop {

class DownloadQueue : public cpp3ds::Drawable, public util3ds::TweenTransformable<cpp3ds::Transformable> {
public:
	~DownloadQueue();

	static DownloadQueue &getInstance();

	void addDownload(AppItem* app);
	void cancelDownload(AppItem* app);
	void restartDownload(AppItem* app);
	bool isDownloading(AppItem* app);

	void suspend();
	void resume();
	void save();

	void sendTop(Download* download);

	size_t getCount();
	size_t getActiveCount();

	void update(float delta);
	bool processEvent(const cpp3ds::Event& event);

protected:
	DownloadQueue();
	void load();
	void realign();
	virtual void draw(cpp3ds::RenderTarget& target, cpp3ds::RenderStates states) const;

	// Go through list make sure only top item is downloading and rest are suspended if necessary
	void refresh();

private:
	std::vector<std::pair<AppItem*, Download*>> m_downloads;
	std::vector<std::pair<AppItem*, Installer*>> m_installers;
	TweenEngine::TweenManager m_tweenManager;

	cpp3ds::Thread m_threadRefresh;
	cpp3ds::Mutex m_mutexRefresh;
	cpp3ds::Clock m_clockRefresh;
	volatile bool m_refreshEnd;
};

} // namespace FreeShop

#endif // FREESHOP_DOWNLOADQUEUE_HPP
