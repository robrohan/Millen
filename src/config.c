// Evil and Nasty Configuration File Reader for KenBuild
// by Jonathon Fowler

#include "build.h"
#include "editor.h"
#include "osd.h"
#include "scriptfile.h"
#include "keys.h"

#ifdef RENDERTYPEWIN
#include "winlayer.h"
#endif
#include "baselayer.h"

static int vesares[13][2] = {{320,200},{360,200},{320,240},{360,240},{320,400},
				{360,400},{640,350},{640,400},{640,480},{800,600},
				{1024,768},{1280,1024},{1600,1200}};

extern short brightness;
extern int fullscreen;
extern char option[8];
extern double msens;

enum {
	type_bool = 0,	//int
	type_double = 1,
	type_int = 2,
	type_hex = 3,
};

static int tmprenderer = 3;
static int tmpbrightness = -1;

static struct {
	const char *name;
	int type;
	void *store;
	const char *doc;
} configspec[] = {
	{ "forcesetup", type_bool, &forcesetup,
		"; Always show configuration options on startup\n"
		";   0 - No\n"
		";   1 - Yes\n"
    },
	{ "fullscreen", type_bool, &fullscreen,
		"; Video mode selection\n"
		";   0 - Windowed\n"
		";   1 - Fullscreen\n"
	},
	{ "xdim2d", type_int, &xdim2d,
		"; Video resolution\n"
	},
	{ "ydim2d", type_int, &ydim2d, NULL },
	{ "xdim3d", type_int, &xdimgame, NULL },
	{ "ydim3d", type_int, &ydimgame, NULL },
	{ "bpp",    type_int, &bppgame,
		"; 3D-mode colour depth\n"
	},
#if USE_POLYMOST
	{ "renderer", type_int, &tmprenderer,
		"; 3D-mode renderer type\n"
		";   0  - classic\n"
		";   2  - software Polymost\n"
		";   3  - OpenGL Polymost\n"
	},
#endif
	{ "brightness", type_int, &tmpbrightness,
		"; 3D mode brightness setting\n"
		";   0  - lowest\n"
		";   15 - highest\n"
	},
#if USE_POLYMOST && USE_OPENGL
	{ "glusetexcache", type_bool, &glusetexcache,
		"; OpenGL mode options\n"
	},
#endif
#ifdef RENDERTYPEWIN
	{ "maxrefreshfreq", type_int, &maxrefreshfreq,
		"; Maximum OpenGL mode refresh rate (Windows only, in Hertz)\n"
	},
#endif
	{ "mousesensitivity", type_double, &msens,
		"; Mouse sensitivity\n"
	},
	{ NULL, 0, NULL, NULL }
};

int loadsetup(const char *fn)
{
	scriptfile *cfg;
	char *token;
	int item;

	cfg = scriptfile_fromfile(fn);
	if (!cfg) {
		return -1;
	}

	scriptfile_clearsymbols();

	option[0] = 1;	// vesa all the way...
	option[1] = 1;	// sound all the way...
	option[4] = 0;	// no multiplayer
	option[5] = 0;

	while (1) {
		token = scriptfile_gettoken(cfg);
		if (!token) break;	//EOF

		for (item = 0; configspec[item].name; item++) {
			if (!Bstrcasecmp(token, configspec[item].name)) {
				// Seek past any = symbol.
				token = scriptfile_peektoken(cfg);
				if (!Bstrcasecmp("=", token)) {
					scriptfile_gettoken(cfg);
				}

				switch (configspec[item].type) {
					case type_bool: {
						int value = 0;
						if (scriptfile_getnumber(cfg, &value)) break;
						*(int*)configspec[item].store = (value != 0);
						break;
					}
					case type_int: {
						int value = 0;
						if (scriptfile_getnumber(cfg, &value)) break;
						*(int*)configspec[item].store = value;
						break;
					}
					case type_hex: {
						int value = 0;
						if (scriptfile_gethex(cfg, &value)) break;
						*(int*)configspec[item].store = value;
						break;
					}
					case type_double: {
						double value = 0.0;
						if (scriptfile_getdouble(cfg, &value)) break;
						*(double*)configspec[item].store = value;
						break;
					}
					default: {
						buildputs("loadsetup: unhandled value type\n");
						break;
					}
				}
				break;
			}
		}
		if (!configspec[item].name) {
			buildprintf("loadsetup: error on line %d\n", scriptfile_getlinum(cfg, cfg->ltextptr));
			continue;
		}
	}

#if USE_POLYMOST
	if (tmprenderer >= 0) {
		setrendermode(tmprenderer);
	}
#endif
	if (tmpbrightness >= 0) {
		brightness = min(max(tmpbrightness,0),15);
	}
	OSD_CaptureKey(KEY_PIPE);

	scriptfile_close(cfg);
	scriptfile_clearsymbols();

	return 0;
}

int writesetup(const char *fn)
{
	BFILE *fp;
	int item;

	fp = Bfopen(fn,"wt");
	if (!fp) return -1;

	tmpbrightness = brightness;
#if USE_POLYMOST
	tmprenderer = getrendermode();
#endif

	for (item = 0; configspec[item].name; item++) {
		if (configspec[item].doc) {
			if (item > 0) fputs("\n", fp);
			fputs(configspec[item].doc, fp);
		}
		fputs(configspec[item].name, fp);
		fputs(" = ", fp);
		switch (configspec[item].type) {
			case type_bool: {
				fprintf(fp, "%d\n", (*(int*)configspec[item].store != 0));
				break;
			}
			case type_int: {
				fprintf(fp, "%d\n", *(int*)configspec[item].store);
				break;
			}
			case type_hex: {
				fprintf(fp, "%X\n", *(int*)configspec[item].store);
				break;
			}
			case type_double: {
				fprintf(fp, "%g\n", *(double*)configspec[item].store);
				break;
			}
			default: {
				fputs("?\n", fp);
				break;
			}
		}
	}

	Bfclose(fp);

	return 0;
}
