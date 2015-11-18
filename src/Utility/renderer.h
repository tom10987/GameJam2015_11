
#pragma once
#include "../engine2d.hpp"
#include "../lib/font.hpp"
#include <sstream>


namespace engine2d {


/* 塗りつぶし矩形の描画
 * pos : 座標
 * scale : サイズ
 * color : 色
 * angle : 回転角（省略可：0）
 * origin : 描画の原点（省略可：(0, 0) 矩形の左下）
 */
void drawBox(const Vec2f& pos, const Vec2f& scale,
             const Color& color,
             const float angle = 0.0f,
             const Vec2f& origin = Vec2f::Zero());


/* 塗りつぶし円の描画
 * pos : 座標
 * scale : サイズ
 * div : 円の分割数（値が大きいほどキレイな円）
 * color : 色
 * angle : 回転角（省略可：0）
 * origin : 描画の原点（省略可：(0, 0) 円の中心）
 */
void drawCircle(const Vec2f& pos, const Vec2f& scale,
                const int div, const Color& color,
                const float angle = 0.0f,
                const Vec2f& origin = Vec2f::Zero());


/* 画像付き矩形の描画
 * pos : 座標
 * scale : サイズ
 * cut : 切り出し開始位置
 * size : 切り取りサイズ
 * sprite : 画像
 * color : 色（省略可：白）
 * angle : 回転角（省略可：0）
 * origin : 描画の原点（省略可：(0, 0) 矩形の左下）
 */
void drawSprite(const Vec2f& pos, const Vec2f& scale,
                const Vec2f& cut, const Vec2f& size,
                const Texture& sprite,
                const Color& color = Color::white,
                const float angle = 0.0f,
                const Vec2f& origin = Vec2f::Zero());


/* 文字列の描画
 * str : 文字列
 * pos : 座標
 * color : 文字の色
 * font : 使用するフォント
 */
void drawString(const std::string& str, const Vec2f& pos,
                const Color& color, Font& font);


/* 文字列の描画（文字列全体の中央を原点にする）
 * str : 文字列
 * pos : 座標
 * color : 文字の色
 * font : 使用するフォント
 */
void drawStringCenter(const std::string& str, const Vec2f& pos,
                      const Color& color, Font& font);


}
