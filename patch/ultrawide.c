/* Ultra-wide mode.
 *
 * A single window on a tag spans the whole window area, which is fine on the
 * laptop panel but leaves an unreadably wide window on the ultra-wide monitor.
 * m->smartov is the outer gap getgaps() hands out when exactly one client is
 * tiled: 0 keeps the old full-width behaviour, ultrawide_ov leaves a margin on
 * each side.
 *
 * setsmartov() is called from the tail of updategeom() (which runs from both
 * setup() and configurenotify()), so docking and undocking picks the right mode
 * on its own: xrandr resizes the root window, dwm gets a ConfigureNotify, and
 * updategeom() runs. It is not called from createmon() because m->mw is only
 * assigned after createmon() returns. Note that a resolution change discards a
 * manual toggleultrawide() override.
 */
void
setsmartov(Monitor *m)
{
	m->smartov = (m->mw >= ultrawide_minw ? ultrawide_ov : 0);
}

void
toggleultrawide(const Arg *arg)
{
	selmon->smartov = (selmon->smartov ? 0 : ultrawide_ov);
	arrange(selmon);
}
