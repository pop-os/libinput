/*
 * Copyright © 2015 Red Hat, Inc.
 *
 * Permission to use, copy, modify, distribute, and sell this software and its
 * documentation for any purpose is hereby granted without fee, provided that
 * the above copyright notice appear in all copies and that both that copyright
 * notice and this permission notice appear in supporting documentation, and
 * that the name of the copyright holders not be used in advertising or
 * publicity pertaining to distribution of the software without specific,
 * written prior permission.  The copyright holders make no representations
 * about the suitability of this software for any purpose.  It is provided "as
 * is" without express or implied warranty.
 *
 * THE COPYRIGHT HOLDERS DISCLAIM ALL WARRANTIES WITH REGARD TO THIS SOFTWARE,
 * INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS, IN NO
 * EVENT SHALL THE COPYRIGHT HOLDERS BE LIABLE FOR ANY SPECIAL, INDIRECT OR
 * CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE,
 * DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER
 * TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR PERFORMANCE
 * OF THIS SOFTWARE.
 */

#if HAVE_CONFIG_H
#include "config.h"
#endif

#include "litest.h"
#include "litest-int.h"

/* Recording from https://bugs.freedesktop.org/show_bug.cgi?id=89783
 * This is the second of 4 devices exported by this keyboard, the first is
 * just a basic keyboard that is identical to the normal litest-keyboard.c
 * file.
 */

static void litest_blackwidow_setup(void)
{
	struct litest_device *d = litest_create_device(LITEST_KEYBOARD_BLACKWIDOW);
	litest_set_current_device(d);
}

static struct input_id input_id = {
	.bustype = 0x3,
	.vendor = 0x1532,
	.product = 0x11b,
};

static int events[] = {
	EV_REL, REL_HWHEEL,
	EV_KEY, KEY_ESC,
	EV_KEY, KEY_1,
	EV_KEY, KEY_2,
	EV_KEY, KEY_3,
	EV_KEY, KEY_4,
	EV_KEY, KEY_5,
	EV_KEY, KEY_6,
	EV_KEY, KEY_7,
	EV_KEY, KEY_8,
	EV_KEY, KEY_9,
	EV_KEY, KEY_0,
	EV_KEY, KEY_MINUS,
	EV_KEY, KEY_EQUAL,
	EV_KEY, KEY_BACKSPACE,
	EV_KEY, KEY_TAB,
	EV_KEY, KEY_Q,
	EV_KEY, KEY_W,
	EV_KEY, KEY_E,
	EV_KEY, KEY_R,
	EV_KEY, KEY_T,
	EV_KEY, KEY_Y,
	EV_KEY, KEY_U,
	EV_KEY, KEY_I,
	EV_KEY, KEY_O,
	EV_KEY, KEY_P,
	EV_KEY, KEY_LEFTBRACE,
	EV_KEY, KEY_RIGHTBRACE,
	EV_KEY, KEY_ENTER,
	EV_KEY, KEY_LEFTCTRL,
	EV_KEY, KEY_A,
	EV_KEY, KEY_S,
	EV_KEY, KEY_D,
	EV_KEY, KEY_F,
	EV_KEY, KEY_G,
	EV_KEY, KEY_H,
	EV_KEY, KEY_J,
	EV_KEY, KEY_K,
	EV_KEY, KEY_L,
	EV_KEY, KEY_SEMICOLON,
	EV_KEY, KEY_APOSTROPHE,
	EV_KEY, KEY_GRAVE,
	EV_KEY, KEY_LEFTSHIFT,
	EV_KEY, KEY_BACKSLASH,
	EV_KEY, KEY_Z,
	EV_KEY, KEY_X,
	EV_KEY, KEY_C,
	EV_KEY, KEY_V,
	EV_KEY, KEY_B,
	EV_KEY, KEY_N,
	EV_KEY, KEY_M,
	EV_KEY, KEY_COMMA,
	EV_KEY, KEY_DOT,
	EV_KEY, KEY_SLASH,
	EV_KEY, KEY_RIGHTSHIFT,
	EV_KEY, KEY_KPASTERISK,
	EV_KEY, KEY_LEFTALT,
	EV_KEY, KEY_SPACE,
	EV_KEY, KEY_CAPSLOCK,
	EV_KEY, KEY_F1,
	EV_KEY, KEY_F2,
	EV_KEY, KEY_F3,
	EV_KEY, KEY_F4,
	EV_KEY, KEY_F5,
	EV_KEY, KEY_F6,
	EV_KEY, KEY_F7,
	EV_KEY, KEY_F8,
	EV_KEY, KEY_F9,
	EV_KEY, KEY_F10,
	EV_KEY, KEY_NUMLOCK,
	EV_KEY, KEY_SCROLLLOCK,
	EV_KEY, KEY_KP7,
	EV_KEY, KEY_KP8,
	EV_KEY, KEY_KP9,
	EV_KEY, KEY_KPMINUS,
	EV_KEY, KEY_KP4,
	EV_KEY, KEY_KP5,
	EV_KEY, KEY_KP6,
	EV_KEY, KEY_KPPLUS,
	EV_KEY, KEY_KP1,
	EV_KEY, KEY_KP2,
	EV_KEY, KEY_KP3,
	EV_KEY, KEY_KP0,
	EV_KEY, KEY_KPDOT,
	EV_KEY, KEY_ZENKAKUHANKAKU,
	EV_KEY, KEY_102ND,
	EV_KEY, KEY_F11,
	EV_KEY, KEY_F12,
	EV_KEY, KEY_RO,
	EV_KEY, KEY_KATAKANA,
	EV_KEY, KEY_HIRAGANA,
	EV_KEY, KEY_HENKAN,
	EV_KEY, KEY_KATAKANAHIRAGANA,
	EV_KEY, KEY_MUHENKAN,
	EV_KEY, KEY_KPJPCOMMA,
	EV_KEY, KEY_KPENTER,
	EV_KEY, KEY_RIGHTCTRL,
	EV_KEY, KEY_KPSLASH,
	EV_KEY, KEY_SYSRQ,
	EV_KEY, KEY_RIGHTALT,
	EV_KEY, KEY_HOME,
	EV_KEY, KEY_UP,
	EV_KEY, KEY_PAGEUP,
	EV_KEY, KEY_LEFT,
	EV_KEY, KEY_RIGHT,
	EV_KEY, KEY_END,
	EV_KEY, KEY_DOWN,
	EV_KEY, KEY_PAGEDOWN,
	EV_KEY, KEY_INSERT,
	EV_KEY, KEY_DELETE,
	EV_KEY, KEY_MUTE,
	EV_KEY, KEY_VOLUMEDOWN,
	EV_KEY, KEY_VOLUMEUP,
	EV_KEY, KEY_POWER,
	EV_KEY, KEY_KPEQUAL,
	EV_KEY, KEY_PAUSE,
	EV_KEY, KEY_KPCOMMA,
	EV_KEY, KEY_HANGEUL,
	EV_KEY, KEY_HANJA,
	EV_KEY, KEY_YEN,
	EV_KEY, KEY_LEFTMETA,
	EV_KEY, KEY_RIGHTMETA,
	EV_KEY, KEY_COMPOSE,
	EV_KEY, KEY_STOP,
	EV_KEY, KEY_AGAIN,
	EV_KEY, KEY_PROPS,
	EV_KEY, KEY_UNDO,
	EV_KEY, KEY_FRONT,
	EV_KEY, KEY_COPY,
	EV_KEY, KEY_OPEN,
	EV_KEY, KEY_PASTE,
	EV_KEY, KEY_FIND,
	EV_KEY, KEY_CUT,
	EV_KEY, KEY_HELP,
	EV_KEY, KEY_MENU,
	EV_KEY, KEY_CALC,
	EV_KEY, KEY_SLEEP,
	EV_KEY, KEY_WAKEUP,
	EV_KEY, KEY_FILE,
	EV_KEY, KEY_WWW,
	EV_KEY, KEY_COFFEE,
	EV_KEY, KEY_MAIL,
	EV_KEY, KEY_BOOKMARKS,
	EV_KEY, KEY_BACK,
	EV_KEY, KEY_FORWARD,
	EV_KEY, KEY_EJECTCD,
	EV_KEY, KEY_NEXTSONG,
	EV_KEY, KEY_PLAYPAUSE,
	EV_KEY, KEY_PREVIOUSSONG,
	EV_KEY, KEY_STOPCD,
	EV_KEY, KEY_RECORD,
	EV_KEY, KEY_REWIND,
	EV_KEY, KEY_PHONE,
	EV_KEY, KEY_CONFIG,
	EV_KEY, KEY_HOMEPAGE,
	EV_KEY, KEY_REFRESH,
	EV_KEY, KEY_EXIT,
	EV_KEY, KEY_EDIT,
	EV_KEY, KEY_SCROLLUP,
	EV_KEY, KEY_SCROLLDOWN,
	EV_KEY, KEY_KPLEFTPAREN,
	EV_KEY, KEY_KPRIGHTPAREN,
	EV_KEY, KEY_NEW,
	EV_KEY, KEY_F13,
	EV_KEY, KEY_F14,
	EV_KEY, KEY_F15,
	EV_KEY, KEY_F16,
	EV_KEY, KEY_F17,
	EV_KEY, KEY_F18,
	EV_KEY, KEY_F19,
	EV_KEY, KEY_F20,
	EV_KEY, KEY_F21,
	EV_KEY, KEY_F22,
	EV_KEY, KEY_F23,
	EV_KEY, KEY_F24,
	EV_KEY, KEY_CLOSE,
	EV_KEY, KEY_PLAY,
	EV_KEY, KEY_FASTFORWARD,
	EV_KEY, KEY_BASSBOOST,
	EV_KEY, KEY_PRINT,
	EV_KEY, KEY_CAMERA,
	EV_KEY, KEY_CHAT,
	EV_KEY, KEY_SEARCH,
	EV_KEY, KEY_FINANCE,
	EV_KEY, KEY_BRIGHTNESSDOWN,
	EV_KEY, KEY_BRIGHTNESSUP,
	EV_KEY, KEY_KBDILLUMTOGGLE,
	EV_KEY, KEY_SAVE,
	EV_KEY, KEY_DOCUMENTS,
	EV_KEY, KEY_UNKNOWN,
	EV_KEY, KEY_VIDEO_NEXT,
	EV_KEY, KEY_BRIGHTNESS_AUTO,
	EV_KEY, BTN_0,
	EV_KEY, KEY_SELECT,
	EV_KEY, KEY_GOTO,
	EV_KEY, KEY_INFO,
	EV_KEY, KEY_PROGRAM,
	EV_KEY, KEY_PVR,
	EV_KEY, KEY_SUBTITLE,
	EV_KEY, KEY_ZOOM,
	EV_KEY, KEY_KEYBOARD,
	EV_KEY, KEY_PC,
	EV_KEY, KEY_TV,
	EV_KEY, KEY_TV2,
	EV_KEY, KEY_VCR,
	EV_KEY, KEY_VCR2,
	EV_KEY, KEY_SAT,
	EV_KEY, KEY_CD,
	EV_KEY, KEY_TAPE,
	EV_KEY, KEY_TUNER,
	EV_KEY, KEY_PLAYER,
	EV_KEY, KEY_DVD,
	EV_KEY, KEY_AUDIO,
	EV_KEY, KEY_VIDEO,
	EV_KEY, KEY_MEMO,
	EV_KEY, KEY_CALENDAR,
	EV_KEY, KEY_RED,
	EV_KEY, KEY_GREEN,
	EV_KEY, KEY_YELLOW,
	EV_KEY, KEY_BLUE,
	EV_KEY, KEY_CHANNELUP,
	EV_KEY, KEY_CHANNELDOWN,
	EV_KEY, KEY_LAST,
	EV_KEY, KEY_NEXT,
	EV_KEY, KEY_RESTART,
	EV_KEY, KEY_SLOW,
	EV_KEY, KEY_SHUFFLE,
	EV_KEY, KEY_PREVIOUS,
	EV_KEY, KEY_VIDEOPHONE,
	EV_KEY, KEY_GAMES,
	EV_KEY, KEY_ZOOMIN,
	EV_KEY, KEY_ZOOMOUT,
	EV_KEY, KEY_ZOOMRESET,
	EV_KEY, KEY_WORDPROCESSOR,
	EV_KEY, KEY_EDITOR,
	EV_KEY, KEY_SPREADSHEET,
	EV_KEY, KEY_GRAPHICSEDITOR,
	EV_KEY, KEY_PRESENTATION,
	EV_KEY, KEY_DATABASE,
	EV_KEY, KEY_NEWS,
	EV_KEY, KEY_VOICEMAIL,
	EV_KEY, KEY_ADDRESSBOOK,
	EV_KEY, KEY_MESSENGER,
	EV_KEY, KEY_DISPLAYTOGGLE,
	EV_KEY, KEY_SPELLCHECK,
	EV_KEY, KEY_LOGOFF,
	EV_KEY, KEY_MEDIA_REPEAT,
	EV_KEY, KEY_IMAGES,
	EV_KEY, KEY_BUTTONCONFIG,
	EV_KEY, KEY_TASKMANAGER,
	EV_KEY, KEY_JOURNAL,
	EV_KEY, KEY_CONTROLPANEL,
	EV_KEY, KEY_APPSELECT,
	EV_KEY, KEY_SCREENSAVER,
	EV_KEY, KEY_VOICECOMMAND,
	EV_KEY, KEY_BRIGHTNESS_MIN,
	EV_KEY, KEY_BRIGHTNESS_MAX,
	EV_MSC, MSC_SCAN,
	-1 , -1,
};

static struct input_absinfo absinfo[] = {
	{ ABS_VOLUME, 0, 572, 0, 0, 0 },
	{ ABS_MISC, 0, 255, 0, 0, 0 },
	{ 0x29, 0, 255, 0, 0, 0 },
	{ 0x2a, 0, 255, 0, 0, 0 },
	{ 0x2b, 0, 255, 0, 0, 0 },
	{ 0x2c, 0, 255, 0, 0, 0 },
	{ 0x2d, 0, 255, 0, 0, 0 },
	{ 0x2e, 0, 255, 0, 0, 0 },
	{ 0x2f, 0, 255, 0, 0, 0 },
	{ 0x30, 0, 255, 0, 0, 0 },
	{ 0x31, 0, 255, 0, 0, 0 },
	{ 0x32, 0, 255, 0, 0, 0 },
	{ 0x33, 0, 255, 0, 0, 0 },
	{ 0x34, 0, 255, 0, 0, 0 },
	{ 0x35, 0, 255, 0, 0, 0 },
	{ 0x36, 0, 255, 0, 0, 0 },
	{ 0x37, 0, 255, 0, 0, 0 },
	{ 0x38, 0, 255, 0, 0, 0 },
	{ 0x39, 0, 255, 0, 0, 0 },
	{ 0x3a, 0, 255, 0, 0, 0 },
	{ 0x3b, 0, 255, 0, 0, 0 },
	{ 0x3c, 0, 255, 0, 0, 0 },
	{ 0x3d, 0, 255, 0, 0, 0 },
	{ 0x3e, 0, 255, 0, 0, 0 },
	{ 0x3f, 0, 255, 0, 0, 0 },
	{ .value = -1 },
};

struct litest_test_device litest_keyboard_blackwidow_device = {
	.type = LITEST_KEYBOARD_BLACKWIDOW,
	.features = LITEST_KEYS | LITEST_WHEEL,
	.shortname = "blackwidow",
	.setup = litest_blackwidow_setup,
	.interface = NULL,

	.name = "Razer Razer BlackWidow 2013",
	.id = &input_id,
	.absinfo = absinfo,
	.events = events,
};
