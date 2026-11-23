_This project has been created as part of the 42 curriculum by reciak, tkolar._

# Description

This is our cub3D project, offering the illusion of walking in a simple 3d world
from a first person's perspective.

The basic building blocks of that world are cubes being decorated with 4
different textures - one for each cardinal direction.
These blocks are exactly fitting between two planes serving
as ceiling and floor being painted in a respective color.

Beyond some challenging parsing tasks this project allows to apply and develop
mathematics to tackle a number of different tasks:

1. Projection of a 3d world onto a 2d screen.
2. Realize the projection in an efficient way.
3. Model wall collisions, i.e. ensure that the first person player can not walk
   through walls.

## Potentially contentious interpretations of the subject

This section documents decisions we made where we felt that the subject is
ambiguous, and in particular explicitly documents these decisions as
intentional.

### Trailing newlines after the map

The last line of the map may be followed by `0` or `1` newline, but not more.

In particular, this means that the `nl_between_info` test in Vesta Manuyko's
tester fails, as it has two trailing newlines.

#### Why?

To quote the subject:

> **Except for the map content**, each type of element can be separated by one
or more empty lines.

and further:

> Except for the **map content** which **always has to be the last**, each type
of element can be set in any order in the file.

Our interpretation of this is:

The map content is what comes last in the file. There are no more parts after
it that could be separated from it with a newline, and the map itself can also
not contain empty lines. Therefore, only a single newline terminating the
(non-empty) last line of the map is permitted.

### "Closed/surrounded by walls"

Only a single contiguous area is allowed. Not all open tiles need to be
accessible, and there can be spaces inside the map. But there cannot be two or
more areas separated by spaces.

#### Why?

To once again quote the subject:

> The map must be closed/surrounded by walls

This makes no statements about reachability. However, if the map consists of
multiple areas that don't connect, then it as a whole is no longer surrounded
by walls. Each individual area is; the map as a whole isn't.

# Instructions

## Compiling

Assuming that any person who is interested in this project
has some basic knowledge about `GNU make` and
[minilibx](https://github.com/42paris/minilibx-linux)
there seems to be no point in giving
detailed installation instructions. Instead we focus
on rules contained in `./Makefile`.

### Rules in `Makefile`

Available rules are:

- `make`, `make cub3D`, `make all`: default target.
  Build the binary `cub3D`.
- `make bonus`: Creates a build that has some bonuses.
- `make clean`: clean up object files.
- `make fclean`: clean up all build artifacts.
- `make re`: `make fclean` followed by `make all`.

## Usage

After building the binary `cub3D` run

```bash
./cub3D <a_map_file.cub>
```

The following keys are then at your disposal:
- <kbd>W</kbd>, <kbd>A</kbd>, <kbd>S</kbd>, <kbd>D</kbd>
- <kbd>Arrow Left</kbd>, <kbd>Arrow Right</kbd>,
- <kbd>PageUp</kbd>, <kbd>PageDown</kbd>
- <kbd>Shift</kbd>
- <kbd>Space</kbd>

Their effect? Just try them out!

# Resources

Two human brains and arms, the mathematics they have learned so far,
and quite a bunch of white paper.

## Acknowledgements

We acknowledge our teachers of mathematics at school and university for sharing
their knowledge and way of looking at things.

Textures for `diamonds.cub` have been adapted from publicly available textures from Minecraft and are the property of Mojang AB. Analogous to the examples showed in the subject, we consider their inclusion in this educational and entirely non-commercial project fair use.

## References

- Discussions with 42 students
- Knowledge on linear algebra as taught at university

## Usage of AI

Both of the authors intentionally did not use AI to generate code for this
project, ensuring a more sustainable learning experience.

reciak occasionally has used ai to find name suggestions for structures when
non of his own ideas he found not convincing enough / potentially misleading,
e.g. for

`struct s_cell_scout` (though at the end this was shortened to `s_scout` ...)

# Appendix: Some mathematical notes to the 3d rendering

## Modelling and Coordinate Systems

The whole map, consisiting of walls, floor and ceiling is internally modelled
by Cartesian coordinates `(x,y,z)` with `x >= 0, y >= 0, z >= 0`,
where the underlying unit vectors form a left system:

A player close to the origin (say at coordinates `(0.5, 0.5, 0)`) who is
looking north would see the vector `e_x` in front, pointing from left to right,
whereas `e_y` would pass by the player on his left side.
`e_z` finally would point upwards to the sky / ceiling.

### Walls

A (visible) wall is essentially given by its four vertices.
These have coordinates involving natural numbers `m, n` depending on the wall
orientation being of one of the following forms:

- Wall in front by a player looking **north**

```math
  (m, n,  1), (m + 1, n, 1),
  (m, n,  0), (m + 1, n, 0)
```

- Wall in front by a player looking **south**

```math
  (m + 1, n, 1), (m, n,  1),
  (m + 1, n, 0), (m, n,  0)
```

- Wall in front by a player looking **east**

```math
  (m, n, 1), (m, n + 1, 1),
  (m, n, 0), (m, n + 1, 0),
```

- Wall in front by a player looking **west**

```math
  (m, n + 1, 1), (m, n, 1),
  (m, n + 1, 0), (m, n, 0),
```

### Camera and Projection screen

The player / the camera is modelled as point `(pos, alt)` where
`pos = (pos_x, pos_y)` is the standing position on the floor and
`alt` the altitude of of the camera (height above the floor).
Moreover a looking direction
`cos(phi), sin(phi) =: v(phi)` is implicitly given by an angle `phi`
in the `x-y` plane being orientated in the usual way
(positive when going the shortest rotation from the positive `x` axis towards
the positive `y` axis).

In front of the camera with a distance of `C3D_CAM_DIST_PROJ_SCR =: D` to it
a projection screen of size `C3D_VIEW_WIDTH x C3D_VIEW_HEIGHT` is placed
which corresponds to what the user will see on the screen, see below.

The center point of this projection screen has coordinates

```math
  (pos + D v(phi), alt)
```

To link points on this (2 dimensional) projection screen with pixels on the
screen it is convenient to introduce an **intermediate coordinate system**
relative to the projection screen by

- specifying the above center point as its origin
- introducing unit vectors `e_a` and `e_b` that are perpendicular to `v(phi)`,
  where `e_b = -e_z` and `e_a` is pointing from the center point horizontally
  "to the right" (from the players perspective).

With respect to that intermediate coordinate  system the corner points of
the project screen have the convenient coordinates

```math
(-C3D_VIEW_WIDTH/2, -C3D_VIEW_HEIGTH/2), (C3D_VIEW_WIDTH/2, -C3D_VIEW_HEIGTH/2)
(-C3D_VIEW_WIDTH/2,  C3D_VIEW_HEIGTH/2), (C3D_VIEW_WIDTH/2,  C3D_VIEW_HEIGTH/2)
```

When describing a point `(x, y, z)` on the camera screen by coordinates
`(a, b)` in the intermediate coordinate system, we shortly refer to
`(a, b)` as _intermediate coordinates_.

## Projection

The 3d illusion is created by a central projection of a 3d model onto
an (imaginated) projection screen in that 3d model world that corresponds
tight to the window where the graphics are rendered into. The next subsections
give more details on how this is done.

### Identifiying Screen pixels positions with points in the projection screen

The graphics of `Cub3D` are rendered in a window area of
`3D_WIN_WIDTH x C3D_WIN_HEIGHT` pixels. The pixel at position `(k, l)` i.e.
at column `k` and row `l` correspond to the point in the projection screen
that has coordinates `(a, b)` (intermediate coordinate system!) with

```math
a = -(C3D_VIEW_WIDTH  / 2) + k * C3D_VIEW_WIDTH  / (C3D_WIN_WIDTH  - 1)   (*)
b = -(C3D_VIEW_HEIGTH / 2) + l * C3D_VIEW_HEIGTH / (C3D_WIN_HEIGTH - 1)   (**).
```

In particular the top- and leftmost pixel position `(0,0)` is identified with
`(-C3D_VIEW_WIDTH/2, -C3D_VIEW_HEIGTH/2)` and the bottom- and rightmost
pixel position `(C3D_WIN_WIDTH  - 1, C3D_WIN_HEIGTH  - 1)` is identified with
`(C3D_VIEW_WIDTH/2, C3D_VIEW_HEIGTH/2)`.

### Projection of a space point to the camera screen

Let `(x, y, z)` be a point (most interestingly: A wall point that is the player
can see from its current position.) If this point is in viewing range,
casting a straight ray from the camera location  `(pos, alt)`) to `(x, y, z)`
will interesect the camera's projection screen in a point with
intermediate coordinates `(a, b)`. By elementary mathematical reasoning,
involving the
Pythagorean Theorem and an intercept theorem (taking orientation into accout),
one finds the relation

```math
b = (alt - z) * l(a) / d     (***)
```

where `d` is the Euclidean distance from the camera foot point `(pos, 0)`
to the foot point `(x, y, 0)`, and
`l_a = (a^2 + C3D_CAM_DIST_PROJ_SCR^2)^0.5`

## 3d rendering of walls, ceiling and floor

Let a color for the ceiling and a color for the floor and 4 textures
(one for the north, south, east and west walls) be given.
For the ease of notation and not to hide the main point we assume
in this documentation that all textures
consits of the same amout of `(M x N)` pixels.

Given a fixed column `k` the color at pixel position
`(k, l)`, where `0 <= l <= C3D_WIN_HEIGTH  - 1`, can be obtained as follows:

1. Use `(*)` and `(**)` to calculate the intermediate coordinates `(a,b)`
  that correspond to `(k,l)`
2. Convert the intermediate coordiantes `(a,b)` to Cartesian coordinates
   `(x_s, y_s, z_s)` and cast a ray on the floor from `(pos, 0)` through
   `(x_s, y_s, 0)`.
3. Check if this half ray hits a wall and calculate the hit point `(hit, 0)`
   in case.
4. If the ray does not hit a wall, render only ceiling and floor for the pixels
   in column `k` and stop.
5. If the ray does hit a wall consider the whole column points `(hit, z)`,
   `0 <= z <= 1` at once:
   Project the topmost point `(hit, 1) =: p_1` and the bottommost point
   `(hit, 0) =: p_2` to the camera screen; according to `(***)` the projected
   points have intermediate coordinates `(a, b_1)` and `(a, b_2)`.
6. Let `l_1` and `l_2` be pixel rows that approximately correspond
   to `b_1` and `b_2`.
7. Calculate the texture column `k_txr` (`0 <= k_txr <= M - 1`) from
   the noninteger parts of of the nonzero component of `hit`
   and give `(k, l_1)` the color of the texture pixel `(k_txr, 0)`,
   `(k, l_2)` the color of the texture pixel `(k_txr, N - 1)` and
   `(k, l)` with `l_1 < l < l_2` the color of an intermediate texture pixel
   `(k_txr, l_txr(l, l_1, l_2))`.
   Finally color the remaining pixels `(k, l)` in the color of the ceiling
   (`l < l_1`) resp. the color of the floor (`l > l_2`).

**Remark to 2.:** Actually it turns out that 2. can be done very implicitly
via angles.

**Remark 1 to 3.:** The check if the half-ray hit a wall can interestingly
be done without calculating intersection points by applying what reciak
would name a *scout mechanism*. Please contact him if you would like to know
more about it.

**Remark 2 to 3.:** For practical reasons the length of the ray is limited:
The search for a wall stops when a too long
part of the half ray has not hit a wall yet.

**Remark to 7.:** In case that the player is so close to a wall that it
does not fit fully on the window certain adoptions are needed to avoid
out invalid memory accesses.

## Updates

Updates are based on the time since the last frame. Every frame, it is checked
how much time passed since the last frame, and which control inputs are active.

Then, updates are made accordingly. A simplified example: if the player is
moving at 3 tiles per second, and the last frame was 0.04 seconds ago, then the
player will try to move `3 * 0.04 = 0.12` tiles in the direction it is
currently pointing.

## Collision detection

Collision detection is done using the same scout mechanism as rendering,
except that only two steps are made.

Essentially, a square (in the x/y plane) bounding box around the player is
used, and the three corners closest to the move direction each cast a ray.

If these rays hit a wall, and do so at a point closer than the attempted travel
distance, then the distance that the player tries to move is reduced by a
corresponding amount.

The endpoint is then rounded to the grid of allowed player positions,
specifically in the direction of the player to ensure that the bounding box
doesn't glitch into a wall.

This emergently allows sliding along a wall while colliding with it if the
angle is large enough, as there will always be some distance between the
player's bounding box and the wall.
