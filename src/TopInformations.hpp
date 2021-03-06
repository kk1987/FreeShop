#ifndef FREESHOP_TOPINFORMATIONS_HPP
#define FREESHOP_TOPINFORMATIONS_HPP

#include <cpp3ds/Graphics/Drawable.hpp>
#include <cpp3ds/Graphics/Text.hpp>
#include <cpp3ds/Window/Event.hpp>
#include "TweenObjects.hpp"
#include "TitleKeys.hpp"
#include <TweenEngine/Tween.h>

namespace FreeShop {

class TopInformations : public cpp3ds::Drawable, public util3ds::TweenTransformable<cpp3ds::Transformable> {
public:
	void update();

	TopInformations();
	~TopInformations();

protected:
	virtual void draw(cpp3ds::RenderTarget& target, cpp3ds::RenderStates states) const;

private:
	cpp3ds::Text m_textSD;
	cpp3ds::Text m_textSDStorage;
	cpp3ds::Text m_textNAND;
	cpp3ds::Text m_textNANDStorage;
	util3ds::TweenText m_textClock;

	gui3ds::NinePatch m_backgroundNAND;
	gui3ds::NinePatch m_backgroundSD;
	cpp3ds::RectangleShape m_progressBarNAND;
	cpp3ds::RectangleShape m_progressBarSD;

};

} // namespace FreeShop

#endif // FREESHOP_TOPINFORMATIONS_HPP
