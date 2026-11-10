void
holdbar(const Arg *arg)
{
	if (selmon->showbar)
		return;
	Bar *bar;
	selmon->showbar = 2;
	updatebarpos(selmon);
	for (bar = selmon->bar; bar; bar = bar->next)
		XMoveResizeWindow(dpy, bar->win, bar->bx, bar->by, bar->bw, bar->bh);
	drawbar(selmon);
}

void
keyrelease(XEvent *e)
{
	Bar *bar;
	Monitor *m;
	if (XEventsQueued(dpy, QueuedAfterReading)) {
		XEvent ne;
		XPeekEvent(dpy, &ne);

		if (ne.type == KeyPress && ne.xkey.time == e->xkey.time &&
				ne.xkey.keycode == e->xkey.keycode) {
			XNextEvent(dpy, &ne);
			return;
		}
	}
	if (e->xkey.keycode != XKeysymToKeycode(dpy, HOLDKEY))
		return;
	/* Check every monitor, not only selmon: the focus can move to another
	 * monitor (focusmon, mouse) while the hold key is down, and the bar
	 * that holdbar showed must still hide on the key release. */
	for (m = mons; m; m = m->next) {
		if (m->showbar != 2)
			continue;
		m->showbar = 0;
		updatebarpos(m);
		for (bar = m->bar; bar; bar = bar->next)
			XMoveResizeWindow(dpy, bar->win, bar->bx, bar->by, bar->bw, bar->bh);
		arrange(m);
	}
}

