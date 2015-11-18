
#include "renderer.h"


namespace engine2d {


void drawBox(const Vec2f& pos, const Vec2f& scale,
             const Color& color,
             const float angle, const Vec2f& origin) {
  drawFillBox(pos.x(), pos.y(), 1.0f, 1.0f,
              color, angle, scale, origin);
}


void drawCircle(const Vec2f& pos, const Vec2f& scale,
                const int div, const Color& color,
                const float angle, const Vec2f& origin) {
  drawFillCircle(pos.x(), pos.y(), 1.0f, 1.0f,
                 div, color, angle, scale, origin);
}


void drawSprite(const Vec2f& pos, const Vec2f& scale,
                const Vec2f& cut, const Vec2f& size,
                const Texture& sprite, const Color& color,
                const float angle, const Vec2f& origin) {
  drawTextureBox(pos.x(), pos.y(), 1.0f, 1.0f,
                 cut.x(), cut.y(), size.x(), size.y(),
                 sprite, color, angle, scale, origin);
}


void drawString(const std::string& str, const Vec2f& pos,
                const Color& color, Font& font) {
  font.draw(str, pos, color);
}


void drawStringCenter(const std::string& str, const Vec2f& pos,
                      const Color& color, Font& font) {
  Vec2f offset = font.drawSize(str) * 0.5f;
  font.draw(str, pos - offset, color);
}


}
