/* surface.c: SDL3 surface handling
 * 
 * Copyright (C) 2026 by suve
 * This code is made available under the GNU General Public License.
 * No warranty. See COPYING for details.
 */

#include "oshwbind.h"

TW_Surface* TW_NewSurface(int w, int h, int transparent) {
	/* TODO: Use the same pixel format as the window */
    /* TODO: Set transparency */
	return SDL_CreateSurface(w, h, SDL_PIXELFORMAT_RGB24);
}

void TW_SetColorKey(SDL_Surface *surface, uint32_t color) {
	SDL_SetSurfaceColorKey(surface, true, color);
}

void TW_ResetColorKey(SDL_Surface *surface) {
	SDL_SetSurfaceColorKey(surface, false, 0);
}

void TW_EnableAlpha(SDL_Surface *surface) {
	SDL_SetSurfaceBlendMode(surface, SDL_BLENDMODE_BLEND);
}

int TW_BytesPerPixel(TW_Surface *surface) {
	return SDL_BYTESPERPIXEL(surface->format);
}

uint32_t TW_PixelAt(TW_Surface *surface, int x, int y) {
	uint8_t r, g, b, a;
	SDL_ReadSurfacePixel(surface, x, y, &r, &g, &b, &a);
	return SDL_MapSurfaceRGBA(surface, r, g, b, a);
}
