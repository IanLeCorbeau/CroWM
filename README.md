# CroWM

CroWM is a fork of OpenBSD's excellent [cwm(1)](https://man.openbsd.org/cwm).

## Why

I'm not good at, nor do I enjoy, justifying what I do, so this will be
short and sweet. The motivation behind this fork is to 

1. Implement certain features that I want, but are probably too niche to
be even considered by upstream.

2. Get better at writing C.

3. and most importantly, because I want to.

**Other than the extra features, this fork will keep up with upstream
development.**

## Differences with cwm

* Monocle mode: when this mode is enabled, every window opens maximized
by default (minus gaps/bar size).

* Toggle monocle keybind: maximizes all mapped windows.

* Manual tiling (htile, vtile) can be triggered regardless of the window's
state (unless it is in full screen mode). This makes it possible to switch
between layouts even if a window is maximized horizontally or vertically.

* When a window closes, the window that previously had focus gets focused
automatically.

* The default key bindings were changed to be more vim-inspired.

### Future features

* Automatic tiling.

* A possible rewrite using XCB instead of xlib.

There may be more added over time.

## Building and installing

Make sure that libX11, libXft, libXrandr and a working implementation of yacc
are installed.

Then simply run `make && make install`.

## Usage / Config

To launch CroWM add the following line to `.xinitrc`:

    exec crowm

As a starting point, the example .crowmrc may be copied to you home directory.

For extra usage and config options, refer to the crowm(1) and crowmrc(5) manual
pages.

## Panels / Status bars

[Polybar](https://github.com/polybar/polybar) and [lemonbar](https://github.com/LemonBoy/bar)
are confirmed to work, and most other panels/bars should work as well.

Panels and bars which do not have an option to set the `override_redirect`
attribute may be set to `ignore` in `.crowmrc`:

    ignore "windowname"

*windowname* may be found using `xprop(1)` and looking at the `WM_CLASS`
property.
