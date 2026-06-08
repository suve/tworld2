/* oshw.h: Platform-specific functions that talk with the OS/hardware.
 *
 * Copyright (C) 2001-2017 by Brian Raiter, Madhav Shanbhag, and Eric Schmidt
 * Copyright (C) 2026 by suve
 * This code is made availabke under the GNU General Public License.
 * No warranty. See COPYING for details.
 */

#include <stdarg.h>

#include "../generic/generic.h"
#include "../oshw.h"

genericglobals  geng;

int oshwinitialize(
	int silence,
	int soundbufsize,
	int showhistogram,
	int fullscreen
) {}

int setkeyboardrepeat(int enable) {}
int loadfontfromfile(char const *filename, int complain) {}
void freefont(void) {}
int creategamedisplay(void) {}
void setcolors(long bkgnd, long text, long bold, long dim) {}
void cleardisplay(void) {}

int displaygame(
	struct gamestate const *state,
	int timeleft,
	int besttime,
	int showinitstate
) {}

int displayendmessage(
	int basescore,
	int timescore,
	long totalscore,
	int completed
) {}

int setdisplaymsg(
	char const *msg,
	int msecs,
	int bold
) {}

int displaylist(
	char const *title,
	tablespec const *table,
	int *index,
	DisplayListType listtype,
	int (*inputcallback)(int*)
) {}

int displayinputprompt(
	char const *prompt,
	char *input,
	int maxlen,
	InputPromptType inputtype,
	int (*inputcallback)(void)
) {}

int setaudiosystem(int active) {}
int loadsfxfromfile(int index, char const *filename) {}
void playsoundeffects(unsigned long sfx) {}
void setsoundeffects(int action) {}
int setvolume(int volume, int display) {}
int changevolume(int delta, int display) {}
void freesfx(int index) {}
void ding(void) {}
void setsubtitle(char const *subtitle) {}

void usermessage(
	int action,
	char const *prefix,
	char const *cfile,
	unsigned long lineno,
	char const *fmt,
	va_list args
) {}

int displaytiletable(
	char const *title,
	tiletablerow const *rows,
	int count,
	int completed
) {}

int displaytable(
	char const *title,
	tablespec const *table,
	int completed
) {}

void readextensions(struct gameseries *series) {}
int getreplaysecondstoskip(void) {}
void copytoclipboard(char const *text) {}

int main(int argc, char *argv[])
{
    return tworld(argc, argv);
}
