# Map Editor Keyboard

Almost all of the keys modify things your mouse cross hairs are focused on / hovering over. Clicking the left mouse button "holds" your focus on that item if the action moves the item (for example sprite rotation or wall height).

## Square Build Editor Bindings

### Moving Around

Basic "Tank Controls":

```
W          = Forward
A          = Turn Left
S          = Turn Right
D          = Backward
Left Shift = Strafe
```

### Some Common Actions:

```
Space       = Create vertex for walls
V           = Texture selector (twice for all textures)
Arrow keys  = Algin textures, ctrl and shift for modifiers
Insert      = Add points to walls
Scrolllock  = player start
Ctrl+Delete = Delete current sector
Tab         = Sector information
T           = Set low tag (ALT for sprites and walls)
H           = Set high tag (ALT for sprites and walls)
```

- To delete a vertex in 2d mode, drag one onto another

### Full Keyboard Shortcuts

| Key        | 2D Mode     | 3D Mode                    | Modifiers            |
| ---------- | ----------- | -------------------------- | -------------------- |
| Q          | Zoom in     | Move Up / Jump             | L CTRL pan down      |
| Z          | Zoom out    | Move Down / Duck           | L CTRL pan up        |
| CAPSLOCK   |             | Toggles Q/Z modes          |                      |
| ↑          |             | Align texture up           | SHIFT Fine CTRL Size |
| ↓          |             | Align texture down         | SHIFT Fine CTRL Size |
| →          |             | Align texture right        | SHIFT Fine CTRL Size |
| ←          |             | Align texture left         | SHIFT Fine CTRL Size |
| PAGE UP    |             | Increase height (focused)  | CTRL sprite ceiling  |
| PAGE DOWN  |             | Decrease height (focused)  | CTRL sprite floor    |
| ,          |             | Rotate sprite left (wall)  | SHIFT small inc      |
| .          |             | Rotate sprite right (wall) | SHIFT small inc      |
| -\_        | -Circle Pts | Darken the focused item    |                      |
| +=         | +Circle Pts | Lighten the focused item   |                      |
| [          |             | Slope the ceiling or floor | SHIFT small inc      |
| ]          |             | Slope the ceiling or floor | SHIFT small inc      |
| F2         |             | 2D view                    |                      |
| F3         | 3D view     |                            |                      |
| B          | Blocking    | Toggle blocking status     |                      |
| F          |             | Flip alignment             |                      |
| O          |             | Sprite wall / wall orient  |                      |
| SCROLLLOCK | Start Pos   |                            |                      |
| F5         | Sector info |                            |                      |
| F6         | Sprite info |                            |                      |
| F7         | Sector edit |                            |                      |
| F8         | Sprite edit |                            |                      |
| T          | Low Tag     | Translucent sprite         | L ALT under cursor   |
|            |             |                            | CTRL toggle display  |
| H          | High Tag    |                            | L ALT under cursor   |
| P          | Set Palette | Parallax ceiling           | ALT Choose Pal (3d)  |
| E          | StatusList? |                            |                      |
| TAB        | Show Info   | Copy texture to clipboard  |                      |
| R SHIFT    | Group Verts |                            | Tap again disable    |
| R ALT      | Sector Sel  |                            | Tap again disable    |
| G          | Toggle Grid |                            |                      |
| L          | Lock Grid   |                            |                      |
| J          | Join Sector |                            |                      |
| ALT X      | Flip Sector |                            |                      |
| X          | Add Sprite  | Add Sprite                 |                      |
| C          | Make Circle | ??                         | Space to commit      |
| SPACE      | Add point   |                            |                      |
| BACKSPACE  | Del point   |                            |                      |
| ENTER      | Check Pnts  | Paste texture              | CTRL to all walls    |
| DELETE     | Del sprite  | Del Sprite                 | R CTRL Sector Del    |
| INSERT     | +Wall point |                            |                      |
| ESC        | Save / Quit |                            |                      |
| F11        |             | Brightness (not working?)  |                      |
| F12        |             | Save screenshot            |                      |
| V          |             | Search texture: x2 for all |                      |
| ?          |             | Reset panning / repeat     |                      |
| ALT Y      |             | Clip sprite distance       |                      |
| 1          |             | Make a one way wall        |                      |
| 2          |             | Bottom wall swap           |                      |
| M          |             | Masking walls              |                      |
| H          |             | Hitscan sensitivity        |                      |
| E          |             | Toggle floor expansion     |                      |
| R          |             | Rotate floor / ceiling     |                      |
| F          |             | Flip floor / ceiling       | ALT alignment        |

## Original Build Editor Bindings (for reference)

| Key        | 2D          | 3D                         | Modifiers           |
| ---------- | ----------- | -------------------------- | ------------------- |
| A          | Zoom in     | Move Up / Jump             | L CTRL pan down     |
| Z          | Zoom out    | Move Down / Duck           | L CTRL pan up       |
| CAPSLOCK   |             | Toggles A/Z modes          |                     |
| ↑          | Forward     | Forward                    | SHIFT move faster   |
| ↓          | Back        | Back                       | SHIFT move faster   |
| →          | Turn Left   | Turn Left                  | SHIFT move faster   |
| ←          | Turn Right  | Turn Right                 | SHIFT move faster   |
| PAGE UP    |             | Increase height (focused)  | CTRL sprite ceiling |
| PAGE DOWN  |             | Decrease height (focused)  | CTRL sprite floor   |
| ,          |             | Rotate sprite left (wall)  | SHIFT small inc     |
| .          |             | Rotate sprite right (wall) | SHIFT small inc     |
| [          |             | Slope the ceiling or floor | SHIFT small inc     |
| ]          |             | Slope the ceiling or floor | SHIFT small inc     |
| B          | Blocking    | Toggle blocking status     |                     |
| F          |             | Flip alignment             |                     |
| O          |             | Sprite wall / wall orient  |                     |
| SCROLLLOCK | Start Pos   |                            |                     |
| F5         | Sector info |                            |                     |
| F6         | Sprite info |                            |                     |
| F7         | Sector edit |                            |                     |
| F8         | Sprite edit |                            |                     |
| T          | Low Tag     | Translucent sprite         | L ALT under cursor  |
|            |             |                            | CTRL toggle display |
| H          | High Tag    |                            | L ALT under cursor  |
| P          | Set Palette | Parallax ceiling           | ALT Choose Pal (3d) |
| E          | StatusList? |                            |                     |
| TAB        | Show Info   | Copy texture to clipboard  |                     |
| R SHIFT    | Group Verts |                            | Tap again disable   |
| R ALT      | Sector Sel  |                            | Tap again disable   |
| G          | Toggle Grid |                            |                     |
| L          | Lock Grid   |                            |                     |
| J          | Join Sector |                            |                     |
| ALT S      | Flip Sector |                            |                     |
| S          | Add Sprite  | Add Sprite                 |                     |
| C          | Make Circle | ??                         | Space to commit     |
| SPACE      | Add point   |                            |                     |
| BACKSPACE  | Del point   |                            |                     |
| ENTER      | Check Pnts  | Paste texture              | CTRL to all walls   |
| DELETE     | Del sprite  | Del Sprite                 | R CTRL Sector Del   |
| INSERT     | +Wall point |                            |                     |
| ESC        | Save / Quit |                            |                     |
| F11        |             | Brightness (not working?)  |                     |
| F12        |             | Save screenshot            |                     |
| V          |             | Search texture: x2 for all |                     |
| ?          |             | Reset panning / repeat     |                     |
| ALT D      |             | Clip distance              |                     |
| 1          |             | Make a one way wall        |                     |
| 2          |             | Bottom wall swap           |                     |
| M          |             | Masking walls              |                     |
| H          |             | Hitscan sensitivity        |                     |
| E          |             | Toggle floor expansion     |                     |
| R          |             | Rotate floor / ceiling     |                     |
| F          |             | Flip floor / ceiling       | ALT alignment       |
| ---        | ---         | ---                        | ---                 |
| KP LEFT    |             | Align wall texture         |                     |
| KP RIGHT   |             | Align wall texture         |                     |
| KP UP      |             | Align wall texture         |                     |
| KP DOWN    |             | Align wall texture         |                     |
| KP -\_     | -Circle Pts | Darken the focused item    |                     |
| KP +=      | +Circle Pts | Lighten the focused item   |                     |
| KP ENTER   | 3D view     | 2D view                    |                     |
