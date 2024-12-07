/* See LICENSE file for copyright and license details. */
#include "movestack.c"
/* appearance */
static const unsigned int refresh_rate =
    60; /* matches dwm's mouse event processing to your monitor's refresh rate
           for smoother window interactions */
static const unsigned int enable_noborder =
    1; /* toggles noborder feature (0=disabled, 1=enabled) */
static const unsigned int borderpx = 0; /* border pixel of windows */
static const unsigned int snap = 26;    /* snap pixel */
// static const int swallowfloating              = 1;   /* 1 means swallow
// floating windows by default */
static const unsigned int systraypinning =
    1; /* 0: sloppy systray follows selected monitor, >0: pin systray to monitor
          X */
static const unsigned int systrayonleft =
    0; /* 0: systray in the right corner, >0: systray on left of status text */
static const unsigned int systrayspacing = 5; /* systray spacing */
static const int systraypinningfailfirst =
    1; /* 1: if pinning fails, display systray on the first monitor, False:
          display systray on the last monitor */
static const int showsystray = 1; /* 0 means no systray */
static const int showbar = 1;     /* 0 means no bar */
static const int topbar = 0;      /* 0 means bottom bar */
#define ICONSIZE 16               /* icon size */
#define ICONSPACING 5             /* space between icon and title */
#define SHOWWINICON 1             /* 0 means no winicon */
static const char *fonts[] = {"JetBrainsMono Nerd Font"};
static const char normbordercolor[] = "#3B4252";
static const char normbgcolor[] = "#2E3440";
static const char normfgcolor[] = "#D8DEE9";
static const char selbordercolor[] = "#434C5E";
static const char selbgcolor[] = "#434C5E";
static const char selfgcolor[] = "#ECEFF4";

static const char *colors[][3] = {
    /*               fg           bg           border   */
    [SchemeNorm] = {normfgcolor, normbgcolor, normbordercolor},
    [SchemeSel] = {selfgcolor, selbgcolor, selbordercolor},
};

static const char *const autostart[] = {
    "/usr/lib/polkit-gnome/polkit-gnome-authentication-agent-1", NULL, "sh",
    "-c", "feh --bg-scale --no-fehbg ~/Pictures/favwallpaper/*", NULL,
    //"sh","-c","trayer","--width 8 --height 8 --edge right", NULL,
    //  "sh", "-c","trayer --expand true --widthtype request --edge right
    //  --transparent true --alpha 255 --align right", NULL,
    "sh", "-c", "nm-applet --indicator", NULL, "sh", "-c",
    "~/.local/bin/status", NULL, "sh", "-c", "~/.local/bin/autostart.sh", NULL,
    NULL /* terminate */
};

/* tagging */
static const char *tags[] = {"1", "2", "3", "4"};

static const char ptagf[] = "[%s %s]"; /* format of a tag label */
static const char etagf[] = "[%s]";    /* format of an empty tag */
static const int lcaselbl = 0;         /* 1 means make tag label lowercase */

static const Rule rules[] = {
    /* class                instance  title           tags mask  isfloating
       isterminal  noswallow  monitor */
    {"Alacritty", NULL, NULL, 0, 0, 1},
    {"brave-browser", NULL, NULL, 1, 0, 1},
    {NULL, NULL, "Event Tester", 0, 0, 0}, /* xev */
};

/* layout(s) */
static const float mfact = 0.5; /* factor of master area size [0.05..0.95] */
static const int nmaster = 1;   /* number of clients in master area */
static const int resizehints =
    1; /* 1 means respect size hints in tiled resizals */
static const int lockfullscreen =
    1; /* 1 will force focus on the fullscreen window */

// #include "fibonacci.c"
static const Layout layouts[] = {
    /* symbol     arrange function */
    {"", tile}, /* first entry is default */
    //{"D", deck},
    //   {"(@)", spiral},
    {"", NULL}, /* no layout function means floating behavior */
    //  {"[M]", monocle},
};

/* key definitions */
#define alt Mod1Mask
#define MODKEY Mod4Mask
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
// #define STATUSBAR "dwmblocks"
/* commands */
static const char *launchercmd[] = {"rofi", "-show", "drun", NULL};
static const char *termcmd[] = {"alacritty", NULL};

static Key keys[] = {
    /* modifier                     key                        function argument
     */
    {MODKEY, XK_d, spawn, {.v = launchercmd}},
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
    {MODKEY, XK_l, focusstack, {.i = +1}},
    //{ MODKEY,                       XK_k,                      focusstack, {.i
    //= -1 } },
    {MODKEY, XK_h, focusstack, {.i = +1}},
    //{ MODKEY,                       XK_j,                      focusstack, {.i
    //= -1 } },
    {MODKEY | ShiftMask, XK_t, setlayout, {.v = &layouts[0]}},
    {MODKEY | ShiftMask, XK_y, setlayout, {.v = &layouts[1]}},
    {alt | ShiftMask, XK_h, movestack, {.i = +1}},
    {alt | ShiftMask, XK_l, movestack,{.i = +1} }, 
 // { MODKEY|ShiftMask,             XK_h, movestack,      {.i =
           // -1 } },
           //{ MODKEY|ShiftMask,             XK_k, movestack, {.i = -1 } },
           {MODKEY, XK_i, incnmaster, {.i = +1}},
      //{ MODKEY,                       XK_d,                      incnmaster,
      //{.i = -1 } },
      {MODKEY | ShiftMask, XK_h, setmfact, {.f = -0.05}},
      {MODKEY | ShiftMask, XK_l, setmfact, {.f = +0.05}},
      {MODKEY | ShiftMask, XK_k, setcfact, {.f = +0.25}},
      {MODKEY | ShiftMask, XK_j, setcfact, {.f = -0.25}},
      {MODKEY | ShiftMask, XK_o, setcfact, {.f = 0.00}},
      {MODKEY, XK_Return, zoom, {0}},
      {MODKEY, XK_q, killclient, {0}},
      //{ MODKEY,                       XK_t,                      setlayout,
      //{.v = &layouts[0]} }, { MODKEY,                       XK_v, setlayout,
      //{.v = &layouts[1]} }, { MODKEY,                       XK_f,
      //setfullscreen, {0}
      //},
      {MODKEY | ShiftMask, XK_space, togglefloating, {0}},
      //{ MODKEY,                       XK_0,                      view, {.ui =
      //~0 } }, { MODKEY,                       XK_comma, focusmon,
      //{.i = -1 } }, { MODKEY,                       XK_period, focusmon, {.i =
      //+1 } }, { MODKEY|ShiftMask,             XK_comma, tagmon,
      //{.i = -1 } }, { MODKEY|ShiftMask,             XK_period, tagmon, {.i =
      //+1 } },
      TAGKEYS(XK_1, 0) TAGKEYS(XK_2, 1) TAGKEYS(XK_3, 2) TAGKEYS(XK_4, 3)
          TAGKEYS(XK_5, 4)};

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle,
 * ClkClientWin, or ClkRootWin */
static Button buttons[] = {
    /* click                event mask      button          function argument */
    {ClkTagBar, MODKEY, Button1, tag, {0}},
    {ClkTagBar, MODKEY, Button3, toggletag, {0}},
    //{ ClkClientWin,         MODKEY,         Button1,        moveorplace, {.i =
    // 2} },
    {ClkClientWin, MODKEY, Button3, resizemouse, {0}},
    {ClkTagBar, 0, Button1, view, {0}},
    {ClkTagBar, 0, Button3, toggleview, {0}},
    {ClkTagBar, MODKEY, Button1, tag, {0}},
    {ClkTagBar, MODKEY, Button3, toggletag, {0}},
};
