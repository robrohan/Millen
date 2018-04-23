// "Build Engine & Tools" Copyright (c) 1993-1997 Ken Silverman
// Ken Silverman's official web site: "http://www.advsys.net/ken"
// See the included license file "BUILDLIC.TXT" for license info.

#ifndef __editor_h__
#define __editor_h__

#ifdef __cplusplus
extern "C" {
#endif

#define NUMBUILDKEYS 20
enum {
    KEY_ESCAPE,

    // Basic movement.
    KEY_FORWARD,
    KEY_BACKWARD,
    KEY_TURN_LEFT,
    KEY_TURN_RIGHT,
    KEY_RUN,
    KEY_STRAFE,
    KEY_STAND_HIGH,
    KEY_STAND_LOW,
    KEY_STRAFE_LEFT,
    KEY_STRAFE_RIGHT,

    // Editor functionality.
    KEY_SWITCH_3D,
    KEY_1WAY,
    KEY_BOTTOM_SWAP,
    KEY_DELETE_POINT,
    KEY_COPY,
    KEY_SHOW_SECTINFO,
    KEY_SHOW_WALLSPRINFO,

    MAX_KEYS
};
enum {
    KEYMOD_LSHIFT = 0x0100,
    KEYMOD_RSHIFT = 0x0200,
    KEYMOD_LALT   = 0x0400,
    KEYMOD_RALT   = 0x0800,
    KEYMOD_LCTRL  = 0x1000,
    KEYMOD_RCTRL  = 0x2000,
    KEYMOD_SHIFTS = (KEYMOD_LSHIFT | KEYMOD_RCTRL),
    KEYMOD_ALTS = (KEYMOD_LALT | KEYMOD_RALT),
    KEYMOD_CTRLS = (KEYMOD_LCTRL | KEYMOD_RCTRL),

    KEYOPT_IGNOREMODS = 0x80,
    KEYOPT_ANYMODS = 0x40,
};

int map_key(int keyid, unsigned char scan, unsigned short mods, unsigned short opts);
int map_key_by_configname(const char *configname, unsigned char scan, unsigned short mods, unsigned short opts);

int key_check(int keyid);
int key_clear(int keyid);
int key_set(int keyid, int state);

extern int qsetmode;
extern short searchsector, searchwall, searchstat;
extern int zmode, kensplayerheight;
extern short defaultspritecstat;
extern int posx, posy, posz, horiz;
extern short ang, cursectnum;
extern short ceilingheinum, floorheinum;
extern int zlock;
extern short editstatus, searchit;
extern int searchx, searchy;                          //search input

extern short temppicnum, tempcstat, templotag, temphitag, tempextra;
extern unsigned char tempshade, temppal, tempxrepeat, tempyrepeat;
extern unsigned char somethingintab;
extern char names[MAXTILES][25];

extern int buildkeys[NUMBUILDKEYS];

extern int ydim16, xdimgame, ydimgame, bppgame, xdim2d, ydim2d, forcesetup;

struct startwin_settings {
    int fullscreen;
    int xdim2d, ydim2d;
    int xdim3d, ydim3d, bpp3d;
    int forcesetup;
};

extern int ExtInit(void);
extern void ExtUnInit(void);
extern void ExtPreCheckKeys(void);
#ifdef SUPERBUILD
extern void ExtAnalyzeSprites(void);
#endif
extern void ExtCheckKeys(void);
extern void ExtPreLoadMap(void);
extern void ExtLoadMap(const char *mapname);
extern void ExtPreSaveMap(void);
extern void ExtSaveMap(const char *mapname);
extern const char *ExtGetSectorCaption(short sectnum);
extern const char *ExtGetWallCaption(short wallnum);
extern const char *ExtGetSpriteCaption(short spritenum);
extern void ExtShowSectorData(short sectnum);
extern void ExtShowWallData(short wallnum);
extern void ExtShowSpriteData(short spritenum);
extern void ExtEditSectorData(short sectnum);
extern void ExtEditWallData(short wallnum);
extern void ExtEditSpriteData(short spritenum);


int loadsetup(const char *fn);	// from config.c
int writesetup(const char *fn);	// from config.c

void editinput(void);
void clearmidstatbar16(void);

short getnumber256(char namestart[80], short num, int maxnumber, char sign);
short getnumber16(char namestart[80], short num, int maxnumber, char sign);
void printmessage256(char name[82]);
void printmessage16(char name[82]);

void getpoint(int searchxe, int searchye, int *x, int *y);
int getpointhighlight(int xplc, int yplc);

#ifdef __cplusplus
}
#endif

#endif
