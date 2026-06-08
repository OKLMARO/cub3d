*This project has been created as part of the 42 curriculum by oamairi, czinsou*

# Description
cub3D is a 42 School project that consists of building a first-person 3D maze
explorer using raycasting, inspired by the original Wolfenstein 3D engine.
The goal is to render a navigable 3D scene from a 2D map using the
Digital Differential Analysis (DDA) algorithm, while managing textures,
colors, and player movement in real time via the MiniLibX graphics library.

The project covers core concepts such as ray-wall intersection math, texture
mapping on directional walls (N/S/E/W), floor and ceiling color rendering,
map parsing and validation, and event-driven window management.

# Instructions

## Requirements

cc

MiniLibX (included or installed separately depending on your system)

A .cub map file following the subject format

## Compilation


```bash
make
```

This produces the `cub3d` executable. To remove object files:

```bash
make clean
```

To remove all generated files including the binary:

```bash
make fclean && make
```

## Execution

```bash
./cub3d map/subject.cub
```

The `.cub` file must define the four wall textures (NO, SO, WE, EA),
floor (F) and ceiling (C) colors in RGB, and a valid map made of `0`, `1`,
and a single player spawn character (`N`, `S`, `E`, or `W`).

## Controls

| Key | Action |
|-----|--------|
| `W` `A` `S` `D` | Move forward / left / backward / right |
| `←` `→` | Rotate camera left / right |
| `ESC` | Exit the program |

# Resources

https://timallanwheeler.com/blog/2023/04/01/wolfenstein-3d-raycasting-in-c/