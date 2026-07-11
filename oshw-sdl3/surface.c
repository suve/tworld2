/* surface.c: SDL3 surface handling
 * 
 * Copyright (C) 2026 by suve
 * This code is made available under the GNU General Public License.
 * No warranty. See COPYING for details.
 */

#include "oshwbind.h"

static SDL_PixelFormat pickPixelFormat(int transparent) {
	SDL_PixelFormat windowFormat = SDL_GetWindowPixelFormat(sdl3wnd);
	if(!transparent) return windowFormat;

	const SDL_PixelFormatDetails *detes = SDL_GetPixelFormatDetails(windowFormat);
	if((detes != NULL) && (detes->Abits > 0)) return windowFormat;

	switch(windowFormat) {
		case SDL_PIXELFORMAT_RGB24:
			return SDL_PIXELFORMAT_RGBA32;
		case SDL_PIXELFORMAT_BGR24:
			return SDL_PIXELFORMAT_BGRA32;
		case SDL_PIXELFORMAT_RGB48:
			return SDL_PIXELFORMAT_RGBA64;
		case SDL_PIXELFORMAT_BGR48:
			return SDL_PIXELFORMAT_BGRA64;

		case SDL_PIXELFORMAT_RGB48_FLOAT:
			return SDL_PIXELFORMAT_RGBA64_FLOAT;
		case SDL_PIXELFORMAT_BGR48_FLOAT:
			return SDL_PIXELFORMAT_BGRA64_FLOAT;
		case SDL_PIXELFORMAT_RGB96_FLOAT:
			return SDL_PIXELFORMAT_RGBA128_FLOAT;
		case SDL_PIXELFORMAT_BGR96_FLOAT:
			return SDL_PIXELFORMAT_BGRA128_FLOAT;

		// welp, gotta pick something
		default:
			return SDL_PIXELFORMAT_RGBA32;
	}
}

TW_Surface* TW_NewSurface(int w, int h, int transparent) {
	return SDL_CreateSurface(w, h, pickPixelFormat(transparent));
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
	return SDL_ConvertSurface(surface, pickPixelFormat(0));
}

TW_Surface* TW_DisplayFormatAlpha(SDL_Surface *surface) {
	return SDL_ConvertSurface(surface, pickPixelFormat(1));
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
