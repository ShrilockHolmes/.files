/* See LICENSE file for copyright and license details. */

/* appearance */
static const unsigned int systraypinning = 0;   /* 0: sloppy systray follows selected monitor, >0: pin systray to monitor X */
static const unsigned int systrayonleft = 1;    /* 0: systray in the right corner, >0: systray on left of status text */
static const unsigned int systrayspacing = 2;   /* systray spacing */
static const int systraypinningfailfirst = 1;   /* 1: if pinning fails, display systray on the first monitor, False: display systray on the last monitor*/
static const int showsystray        = 1;        /* 0 means no systray */
static const unsigned int borderpx = 0; /* border pixel of windows */
static const unsigned int snap = 20;    /* snap pixel */
static const int showbar = 1;           /* 0 means no bar */
static const int topbar = 0;            /* 0 means bottom bar */
static const char *fonts[] = {"JetBrainsMono Nerd Font"};
static const char normbordercolor[] = "#3B4252";
static const char normbgcolor[] = "#2E3440";
static const char normfgcolor[] = "#D8DEE9";
static const char selbordercolor[] = "#434C5E";
static const char selbgcolor[] = "#434C5E";
static const char selfgcolor[] = "#ECEFF4";


const char *startit[] = {
 "feh --no-fehbg --bg-scale ~/Pictures/favwallpaper/*", 
  "~/.local/bin/autostart.sh",
  "nm-applet --indicator &",
  "~/.local/bin/status &"
};
static const char *colors[][3] = {
    /*               fg           bg           border   */
    [SchemeNorm] = {normfgcolor, normbgcolor, normbordercolor},
    [SchemeSel] = {selfgcolor, selbgcolor, selbordercolor},
};

/* tagging */
static const char *tags[] = {"1", "2", "3", "4"};

static const Rule rules[] = {
    /* xprop(1):
     *	WM_CLASS(STRING) = instance, class
     *	WM_NAME(STRING) = title
     */
    /* class      instance    title       tags mask     isfloating   monitor */
    {"Gimp", NULL, NULL, 0, 1, -1},
    {"brave-browser", NULL, NULL, 1 << 8, 0, -1},
};

/* layout(s) */
static const float mfact = 0.50; /* factor of master area size [0.05..0.95] */
static const int nmaster = 1;    /* number of clients in master area */
static const int resizehints =
    1; /* 1 means respect size hints in tiled resizals */
static const int lockfullscreen =
    1; /* 1 will force focus on the fullscreen window */

static const Layout layouts[] = {
    /* symbol     arrange function */
    {"[]=", tile}, /* first entry is default */
    {"><>", NULL}, /* no layout function means floating behavior */
    {"[M]", monocle},
};

/* key definitions */
#define MODKEY Mod4Mask
#define alt Mod1Mask
#define TAGKEYS(KEY, TAG)                                                      \
  {MODKEY, KEY, view, {.ui = 1 << TAG}},                                       \
      {MODKEY | ControlMask, KEY, toggleview, {.ui = 1 << TAG}},               \
      {MODKEY | ShiftMask, KEY, tag, {.ui = 1 << TAG}},                        \
      {MODKEY | ControlMask | ShiftMask, KEY, toggletag, {.ui = 1 << TAG}},

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd)                                                             \
  {                                                                            \
    .v = (const char *[]) { "/bin/sh", "-c", cmd, NULL }                       \
  }

/* commands */
static const char *launch[] = {"rofi", "-show", "drun", NULL};
static const char *termcmd[] = {"alacritty", NULL};

static const Key keys[] = {
    /* modifier                     key        function        argument */
    {MODKEY, XK_d, spawn, {.v = launch}},
    {MODKEY, XK_x, spawn, {.v = termcmd}},
    {MODKEY, XK_b, spawn, SHCMD("xdg-open https://")},
    {MODKEY | ShiftMask, XK_p, spawn, SHCMD("~/.local/bin/power.sh")},
    //{ MODKEY|ControlMask,           XK_p,                      spawn, SHCMD
    //("flameshot gui --clipboard")},
    {MODKEY, XK_e, spawn, SHCMD("pcmanfm")},
    {0, XF86XK_MonBrightnessUp, spawn, SHCMD("~/.local/bin/brightness.sh up")},
    {0, XF86XK_MonBrightnessDown, spawn,
     SHCMD("~/.local/bin/brightness.sh down")},
    {0, XF86XK_AudioLowerVolume, spawn, SHCMD("~/.local/bin/audio.sh down")},
    {0, XF86XK_AudioMute, spawn, SHCMD("~/.local/bin/audio.sh mute")},
    {0, XF86XK_AudioRaiseVolume, spawn, SHCMD("~/.local/bin/audio.sh up")},

    {MODKEY, XK_f, togglebar, {0}},
    {MODKEY, XK_l, focusstack, {.i = +1}},
    {MODKEY, XK_h, focusstack, {.i = -1}},
    {MODKEY, XK_i, incnmaster, {.i = +1}},
    {alt | ShiftMask, XK_h, setmfact, {.f = -0.05}},
    {alt | ShiftMask, XK_l, setmfact, {.f = +0.05}},
    {MODKEY, XK_Return, zoom, {0}},
    {MODKEY, XK_Tab, view, {0}},
    {MODKEY, XK_q, killclient, {0}},
    {MODKEY|ShiftMask, XK_t, setlayout, {.v = &layouts[0]}},
    {MODKEY|ShiftMask, XK_y, setlayout, {.v = &layouts[1]}},
    //{MODKEY, XK_m, setlayout, {.v = &layouts[2]}},
    {MODKEY, XK_space, setlayout, {0}},
    {MODKEY | ShiftMask, XK_space, togglefloating, {0}},
    {MODKEY, XK_0, view, {.ui = ~0}},
    {MODKEY | ShiftMask, XK_0, tag, {.ui = ~0}},
    TAGKEYS(XK_1, 0) TAGKEYS(XK_2, 1) TAGKEYS(XK_3, 2) TAGKEYS(XK_4, 3)
        TAGKEYS(XK_5, 4) TAGKEYS(XK_6, 5) TAGKEYS(XK_7, 6) TAGKEYS(XK_8, 7)
            //TAGKEYS(XK_9, 8){MODKEY | ShiftMask, XK_q, quit, {0}},
};

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle,
 * ClkClientWin, or ClkRootWin */
static const Button buttons[] = {
    /* click                event mask      button          function argument */
    {ClkLtSymbol, 0, Button1, setlayout, {0}},
    {ClkLtSymbol, 0, Button3, setlayout, {.v = &layouts[2]}},
    {ClkWinTitle, 0, Button2, zoom, {0}},
    {ClkStatusText, 0, Button2, spawn, {.v = termcmd}},
    {ClkClientWin, MODKEY, Button1, movemouse, {0}},
    {ClkClientWin, MODKEY, Button2, togglefloating, {0}},
    {ClkClientWin, MODKEY, Button3, resizemouse, {0}},
    {ClkTagBar, 0, Button1, view, {0}},
    {ClkTagBar, 0, Button3, toggleview, {0}},
    {ClkTagBar, MODKEY, Button1, tag, {0}},
    {ClkTagBar, MODKEY, Button3, toggletag, {0}},
};
