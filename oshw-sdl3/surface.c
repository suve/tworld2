/* surface.c: SDL3 surface handling
 * 
 * Copyright (C) 2026 by suve
 * This code is made available under the GNU General Public License.
 * No warranty. See COPYING for details.
 */

#include "oshwbind.h"

TW_Surface* TW_NewSurface(int w, int h, int transparent) {
	/* TODO: Use alpha-enabled pixel format if `transparent` is 1 */
	return SDL_CreateSurface(w, h, SDL_GetWindowPixelFormat(sdl3wnd));
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

TW_Surface* TW_DisplayFormat(SDL_Surface *surface) {
	return SDL_ConvertSurface(surface, SDL_GetWindowPixelFormat(sdl3wnd));
}

TW_Surface* TW_DisplayFormatAlpha(SDL_Surface *surface) {
	/* TODO: Needs ensuring that pixel format includes alpha */
	return TW_DisplayFormat(surface);
}

uint32_t TW_PixelAt(TW_Surface *surface, int x, int y) {
	uint8_t r, g, b, a;
	SDL_ReadSurfacePixel(surface, x, y, &r, &g, &b, &a);
	return SDL_MapSurfaceRGBA(surface, r, g, b, a);
}

TW_Surface *TW_LoadBMP(char const *filename, int setscreenpalette) {
	const SDL_Surface *newSurf = SDL_LoadBMP(filename);
	if((newSurf != NULL) && (setscreenpalette)) {
		const SDL_Palette *palette = SDL_GetSurfacePalette(newSurf);
		if(palette != NULL) {
			const SDL_Surface *windowSurf = SDL_GetWindowSurface(sdl3wnd);
			if(windowSurf != NULL) {
				SDL_SetSurfacePalette(windowSurf, palette);
			}
		}
	}
	return newSurf;
}
