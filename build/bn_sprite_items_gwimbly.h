#ifndef BN_SPRITE_ITEMS_GWIMBLY_H
#define BN_SPRITE_ITEMS_GWIMBLY_H

#include "bn_sprite_item.h"

//{{BLOCK(gwimbly_bn_gfx)

//======================================================================
//
//	gwimbly_bn_gfx, 32x640@4, 
//	+ palette 16 entries, not compressed
//	+ 320 tiles not compressed
//	Total size: 32 + 10240 = 10272
//
//	Time-stamp: 2024-07-02, 00:23:35
//	Exported by Cearn's GBA Image Transmogrifier, v0.9.2
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_GWIMBLY_BN_GFX_H
#define GRIT_GWIMBLY_BN_GFX_H

#define gwimbly_bn_gfxTilesLen 10240
extern const bn::tile gwimbly_bn_gfxTiles[320];

#define gwimbly_bn_gfxPalLen 32
extern const bn::color gwimbly_bn_gfxPal[16];

#endif // GRIT_GWIMBLY_BN_GFX_H

//}}BLOCK(gwimbly_bn_gfx)

namespace bn::sprite_items
{
    constexpr inline sprite_item gwimbly(sprite_shape_size(sprite_shape::TALL, sprite_size::HUGE), 
            sprite_tiles_item(span<const tile>(gwimbly_bn_gfxTiles, 320), bpp_mode::BPP_4, compression_type::NONE, 10), 
            sprite_palette_item(span<const color>(gwimbly_bn_gfxPal, 16), bpp_mode::BPP_4, compression_type::NONE));
}

#endif

