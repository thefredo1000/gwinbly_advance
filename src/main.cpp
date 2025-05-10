#include "bn_core.h"
#include "bn_keypad.h"
#include "bn_regular_bg_ptr.h"
#include "bn_music.h"
#include "bn_color.h"
#include "bn_bg_palettes.h"

#include "bn_music_items.h"
#include "bn_sprite_items_gwimbly.h"
#include "bn_sprite_animate_actions.h"
#include "bn_regular_bg_items_background.h"

inline int convert_color(int color)
{
    return (color * 32) >> 8;
}
namespace
{
    void sprite_scene()
    {
        bn::music_items::erotic.play(0.5);
        bn::sprite_ptr gwimbly_sprite = bn::sprite_items::gwimbly.create_sprite(0, 16);

        bn::sprite_animate_action<8> action = bn::create_sprite_animate_action_forever(
            gwimbly_sprite, 16, bn::sprite_items::gwimbly.tiles_item(), 0, 1);

        int direction = 0; // 0 is left, 1 is right
        bool is_idle = true;

        while (true)
        {

            if (bn::keypad::right_held())
            {
                if (direction != 1)
                {
                    action = bn::create_sprite_animate_action_forever(
                        gwimbly_sprite, 4, bn::sprite_items::gwimbly.tiles_item(), 2, 3, 2, 4);
                }
                gwimbly_sprite.set_position(gwimbly_sprite.x() + 1, 16);
                direction = 1;
                is_idle = false;
            }
            else if (bn::keypad::left_held())
            {
                if (direction != 0)
                {
                    action = bn::create_sprite_animate_action_forever(
                        gwimbly_sprite, 4, bn::sprite_items::gwimbly.tiles_item(), 7, 8, 7, 9);
                }
                gwimbly_sprite.set_position(gwimbly_sprite.x() - 1, 16);
                direction = 0;
                is_idle = false;
            }
            else
            {
                if (!is_idle)
                {
                    if (direction != 0)
                    {
                        action = bn::create_sprite_animate_action_forever(
                            gwimbly_sprite, 16, bn::sprite_items::gwimbly.tiles_item(), 0, 1);
                    }
                    else
                    {
                        action = bn::create_sprite_animate_action_forever(
                            gwimbly_sprite, 16, bn::sprite_items::gwimbly.tiles_item(), 5, 6);
                    }
                }
                is_idle = true;
            }
            action.update();
            bn::core::update();
        }
    }
}

int main()
{
    bn::core::init();

    // TODO: Change to a good background
    bn::bg_palettes::set_transparent_color(
        bn::color(
            convert_color(23),
            convert_color(195),
            convert_color(178)));

    bn::regular_bg_ptr background =
        bn::regular_bg_items::background.create_bg(8, 48);

    sprite_scene();
    while (true)
    {
        bn::core::update();
    }
}
