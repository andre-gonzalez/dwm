- My version of DWM. A single build serves both the laptop panel and the
  ultra-wide monitor: when a tag holds exactly one tiled window, wide screens
  keep an empty margin on each side instead of letting it span the full width.
  This is detected from the monitor width on every resolution change, and can be
  toggled by hand with MOD+Mod4+w. See `patch/ultrawide.c`.
- I applied the following patches:
  - MoveStack
  - fakefullscreen
  - noborder
  - pertag
  - hide_vacant_tags
  - vanitygaps
  - centeredmaster
  - holdbar
  - tagallmon
  - togglefullscreen
  - warp
  - BAR_STATUSCMD_PATCH
  - BAR_DWMBLOCKS_PATCH

