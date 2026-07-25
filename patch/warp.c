void
warp(const Client *c)
{
	int x, y;
	Bar *bar;

	if (!c) {
		XWarpPointer(dpy, None, root, 0, 0, 0, 0, selmon->wx + selmon->ww / 2, selmon->wy + selmon->wh / 2);
		return;
	}

	if (!getrootptr(&x, &y) ||
		(x > c->x - c->bw &&
		 y > c->y - c->bw &&
		 x < c->x + c->w + c->bw*2 &&
		 y < c->y + c->h + c->bw*2))
		return;

	/* don't warp away from any of the monitor's bars */
	for (bar = c->mon->bar; bar; bar = bar->next)
		if ((y >= bar->by && y < bar->by + bar->bh) || (bar->topbar && !y))
			return;

	XWarpPointer(dpy, None, c->win, 0, 0, 0, 0, c->w / 2, c->h / 2);
}
