/* oshwbind.h: Binds the generic module to the SDL3 OS/hardware layer.
 * 
 * Copyright (C) 2026 by suve under the GNU General Public License.
 * No warranty. See COPYING for details.
 */

#ifndef	HEADER_sdl3_oshwbind_h_
#define	HEADER_sdl3_oshwbind_h_

#include <stdint.h>

/*
 * Constants
 */
#define TW_ALPHA_TRANSPARENT 0
#define TW_ALPHA_OPAQUE 0

enum {
	TWK_BACKSPACE,
	TWK_TAB,
	TWK_RETURN,
	TWK_KP_ENTER,
	TWK_ESCAPE,
	TWK_UP,
	TWK_LEFT,
	TWK_DOWN,
	TWK_RIGHT,
	TWK_KP8,
	TWK_KP4,
	TWK_KP2,
	TWK_KP6,
	TWK_INSERT,
	TWK_DELETE,
	TWK_HOME,
	TWK_END,
	TWK_PAGEUP,
	TWK_PAGEDOWN,
	TWK_F1,
	TWK_F2,
	TWK_F3,
	TWK_F4,
	TWK_F5,
	TWK_F6,
	TWK_F7,
	TWK_F8,
	TWK_F9,
	TWK_F10,
	TWK_LSHIFT,
	TWK_RSHIFT,
	TWK_LCTRL,
	TWK_RCTRL,
	TWK_LALT,
	TWK_RALT,
	TWK_LMETA,
	TWK_RMETA,
	TWK_CAPSLOCK,
	TWK_NUMLOCK,
	TWK_SCROLLLOCK,
	TWK_MODE,
	TWK_CTRL_C,
	TWK_LAST
};

enum {
	TW_BUTTON_LEFT,
	TW_BUTTON_RIGHT,
	TW_BUTTON_MIDDLE,
	TW_BUTTON_WHEELUP,
	TW_BUTTON_WHEELDOWN
};

/*
 * Types
 */
typedef struct{int x,y,w,h;} TW_Rect;
typedef struct{int w,h,pitch; uint8_t *pixels;} TW_Surface;
 
/*
 * Functions
 */
#define TW_NewSurface ((TW_Surface*(*)(int,int,int))0)
#define TW_FreeSurface ((void(*)(TW_Surface*))0)
#define TW_MUSTLOCK ((int(*)(TW_Surface*))0)
#define TW_LockSurface ((void(*)(TW_Surface*))0)
#define TW_UnlockSurface ((void(*)(TW_Surface*))0)
#define TW_FillRect ((void(*)(TW_Surface*,TW_Rect*,uint32_t))0)
#define TW_BlitSurface ((int(*)(TW_Surface*,TW_Rect*,TW_Surface*,TW_Rect*))0)
#define TW_SetColorKey ((void(*)(TW_Surface*,uint32_t))0)
#define TW_ResetColorKey ((void(*)(TW_Surface*))0)
#define TW_EnableAlpha ((void(*)(TW_Surface*))0)
#define TW_DisplayFormat ((TW_Surface*(*)(TW_Surface*))0)
#define TW_DisplayFormatAlpha ((TW_Surface*(*)(TW_Surface*))0)
#define TW_BytesPerPixel ((int(*)(TW_Surface*))0)
#define TW_PixelAt ((uint32_t(*)(TW_Surface*,int,int))0)
#define TW_MapRGB ((uint32_t(*)(TW_Surface*,int,int,int))0)
#define TW_MapRGBA ((uint32_t(*)(TW_Surface*,int,int,int,int))0)
#define TW_LoadBMP ((TW_Surface*(*)(const char*,int))0)
#define TW_GetKeyState ((uint8_t*(*)(int*))0)
#define TW_GetTicks ((uint32_t(*)(void))0)
#define TW_Delay ((void*(*)(int))0)
#define TW_GetError ((char*(*)(void))0)

#endif
