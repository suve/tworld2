/* oshwbind.h: Binds the generic module to the SDL3 OS/hardware layer.
 * 
 * Copyright (C) 2001-2010 by Brian Raiter and Madhav Shanbhag,
 * Copyright (C) 2026 by suve
 * This code is made available under the GNU General Public License.
 * No warranty. See COPYING for details.
 */

#ifndef	HEADER_sdl3_oshwbind_h_
#define	HEADER_sdl3_oshwbind_h_

#include <stdint.h>
#include <SDL3/SDL.h>

/*
 * Constants
 */
#define TW_ALPHA_TRANSPARENT 0
#define TW_ALPHA_OPAQUE 0

enum {
	TWK_BACKSPACE = SDLK_BACKSPACE,
	TWK_TAB = SDLK_TAB,
	TWK_RETURN = SDLK_RETURN,
	TWK_KP_ENTER = SDLK_KP_ENTER,
	TWK_ESCAPE = SDLK_ESCAPE,
	TWK_UP = SDLK_UP,
	TWK_LEFT = SDLK_LEFT,
	TWK_DOWN = SDLK_DOWN,
	TWK_RIGHT = SDLK_RIGHT,
	TWK_KP8 = SDLK_KP_8,
	TWK_KP4 = SDLK_KP_4,
	TWK_KP2 = SDLK_KP_2,
	TWK_KP6 = SDLK_KP_6,
	TWK_INSERT = SDLK_INSERT,
	TWK_DELETE = SDLK_DELETE,
	TWK_HOME = SDLK_HOME,
	TWK_END = SDLK_END,
	TWK_PAGEUP = SDLK_PAGEUP,
	TWK_PAGEDOWN = SDLK_PAGEDOWN,
	TWK_F1 = SDLK_F1,
	TWK_F2 = SDLK_F2,
	TWK_F3 = SDLK_F3,
	TWK_F4 = SDLK_F4,
	TWK_F5 = SDLK_F5,
	TWK_F6 = SDLK_F6,
	TWK_F7 = SDLK_F7,
	TWK_F8 = SDLK_F8,
	TWK_F9 = SDLK_F9,
	TWK_F10 = SDLK_F10,
	TWK_LSHIFT = SDLK_LSHIFT,
	TWK_RSHIFT = SDLK_RSHIFT,
	TWK_LCTRL = SDLK_LCTRL,
	TWK_RCTRL = SDLK_RCTRL,
	TWK_LALT = SDLK_LALT,
	TWK_RALT = SDLK_RALT,
	TWK_LMETA = SDLK_LMETA,
	TWK_RMETA = SDLK_RMETA,
	TWK_CAPSLOCK = SDLK_CAPSLOCK,
	TWK_NUMLOCK = SDLK_NUMLOCKCLEAR,
	TWK_SCROLLLOCK = SDLK_SCROLLLOCK,
	TWK_MODE = SDLK_MODE,
	TWK_CTRL_C = '\003',
	TWK_LAST = SDLK_MODE+1
};

enum {
	TW_BUTTON_LEFT = SDL_BUTTON_LEFT,
	TW_BUTTON_RIGHT = SDL_BUTTON_RIGHT,
	TW_BUTTON_MIDDLE = SDL_BUTTON_MIDDLE,
	TW_BUTTON_WHEELUP = -1,
	TW_BUTTON_WHEELDOWN = -2
};

/*
 * Types
 */
typedef SDL_Rect TW_Rect;
typedef SDL_Surface TW_Surface;
 
/*
 * Functions
 */
extern TW_Surface* TW_NewSurface(int w, int h, int transparency);
extern void TW_SetColorKey(TW_Surface *surface, uint32_t color);
extern void TW_ResetColorKey(TW_Surface *surface);
extern void TW_EnableAlpha(TW_Surface *surface);
extern int TW_BytesPerPixel(TW_Surface *surface);
extern TW_Surface* TW_DisplayFormat(TW_Surface *surface);
extern TW_Surface* TW_DisplayFormatAlpha(TW_Surface *surface);
extern uint32_t TW_PixelAt(TW_Surface *surface, int x, int y);
extern TW_Surface* TW_LoadBMP(const char *filename, int setscreenpallette);

#define TW_FreeSurface SDL_DestroySurface
#define TW_MUSTLOCK SDL_MUSTLOCK
#define TW_LockSurface SDL_LockSurface
#define TW_UnlockSurface SDL_UnlockSurface
#define TW_FillRect SDL_FillSurfaceRect
#define TW_BlitSurface SDL_BlitSurface
#define TW_MapRGB SDL_MapSurfaceRGB
#define TW_MapRGBA SDL_MapSurfaceRGBA
#define TW_GetKeyState ((uint8_t*(*)(int*))0)

#define TW_GetTicks SDL_GetTicks
#define TW_Delay SDL_Delay
#define TW_GetError SDL_GetError

/*
 * Global vars
 */
extern SDL_Window *sdl3wnd;

#endif
