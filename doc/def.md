# .def files

The engine provides a customization facility which allows for enhancements to be
made to game without requiring the game itself be modified. These
enhancements include high-resolution textures and 3D models in OpenGL mode. The file that contains the declarations of these enhancements is different for each game.

## Comments

Comments may be indicated with any of these methods:

```
; configuration style comment (single line)
```

```
// C++ style comment (single line)
/_ C style comment (multiple line) _/
```

## Instructions

For the instruction descriptions below, these syntactic conventions apply:

```
instruction-name <required-argument> [optional-argument]
```

Don't include the <> or []. String values must be quoted with "".

The following are the legal instructions that may be used in a .def file.

### include &lt;filename&gt;

```
#include <filename>
```

Processes the script commands in <filename> at the point of the include call.

### define &lt;label&gt; &lt;integer-value&gt;

```
#define <label> <integer-value>
```

Declares _label_ to represent the numeric value _integer-value_. Labels are
referenced by giving the label name in place of an integer value parameter, without surrounding the name with quotes.

- _integer-value_ can itself be a label, in which case the value of the label given is used.

- You may find it convenient to include _NAMES.H_ to predefine many of the tile names in the .art file.

### texture &lt;tilenum&gt;{ ... }

Defines a Hightile texture to replace an ART-file tile. _tilenum_ may be a number, or
a defined label.

The brace-enclosed block may contain:

    pal <palnum> { ... }
        Defines a palette replacement for palette number <palnum>.

        The brace-enclosed block may contain these instructions:

        file <filename>
        name <filename>
            Required.
            <filename> may be any PNG, JPG, TGA, BMP, GIF or PCX file.

        alphacut <cutoff-value>
            Sets the level of transparency at which a pixel in the texture is considered
            opaque. Pixels more transparent than the cut-off are not drawn to the screen
            when rendered. The default setting is 0.32, which is just below the 33%
            transparency level of Build. If your texture has areas that are more
            transparent than the default, you can lower the cut-off level to preserve
            that detail.

        nocompress
            Prevents the texture from being compressed using DXTC/S3TC if texture
            compression is enabled.

Here is an example:

        texture 0 {
            pal 0 { file "tile0pal0.png" }
            pal 1 { file "tile0pal1.png" alphacut 0.1 }
        }

### model &lt;filename&gt;{ ... }

Defines an MD2/3-format model file to replace certain sprites in the game when
running in OpenGL Polymost mode.

The brace-enclosed block may contain these instructions:

    scale <scale-value>
        <scale-value> is a (possibly fractional) value specifying a scaling factor for
        the model when it is rendered, e.g. 1.5 for one-and-a-half times as big.

    shade <shade-offset>
        <shade-offset> is an integer value specifying how much to bias the sprite's
        shade value by.  A negative value for this makes the model brighter. Conversely,
        a positive value makes it darker.

    zadd <offset>
        <offset> is a (possibly fractional) value specifying a height offset for the
        model. Quake models are aligned in the center while Build models are aligned at
        the floor. Using this command will allow Build to use Quake models without
        modification to the MD2/3 file itself.

    skin { ... }
        Defines a skin to be used on the model for all frames declared after this
        command.

        The brace-enclosed block may contain these instructions:

        pal <palnum>
            Specifies which palette this skin maps to.

        surface <surfnum>
            Specifies which MD3 surface this skin should be applied to. This has no
            significance for MD2 models.

        file <filename>
            IMPORTANT: If your model exists in a subdirectory (ie. the model filename
            includes a path to the .md2/3) you will need to give the same path
            to <filename> if the skin is in the same directory.

    anim { ... }
        Defines an animation from a group of frames in the model.

        The brace-enclosed block may contain these instructions:

        frame0 <framename>
        frame1 <framename>
            Specifies the names of the start (frame0) and end (frame1) frames of the
            animation.

        fps <fps-value>
            Specifies the framerate at which the animation should play. This value may be
            fractional.

        flags <flags-value>
            Specifies any special properties the animation should have, the values of
            which should be added together to combine multiple options.

            Valid options are:
                0 – none (looping animation).
                1 – one-shot (plays beginning to end once and stops on the last frame).

    frame { ... }
        Defines a range of ART-file tiles to correspond with the given frame of the model.

        The brace-enclosed block may contain these instructions:

        frame <framename>
        name <framename>
            If <framename> is identical to the starting frame of an animation, the
            engine will play that animation, otherwise the replacement will be static.
            <name> is a synonym for the <frame> instruction.

        tile <tilenum>
        tile0 <tilenum>
        tile1 <tilenum>
            Use the <tile> instruction to specify an ART-file tile which this model
            should replace.
            Use the <tile0> and <tile1> instruction pair to specify a range of ART-file
            tiles. If you use <tile0>, you must also have a <tile1>. You may not use the
            same instruction twice to specify multiple ranges.

    hud { ... }
        Defines a range of ART-file tiles to use with a heads-up-display.

        The brace-enclosed block may contain these instructions:

        tile <tilenum>
        tile0 <tilenum>
        tile1 <tilenum>
            <tile0> and <tile1> together specify a range of ART-file tiles which this
            model frame should replace when rendered as part of the HUD. You can specify
            individual tiles using a single 'tile' command.

        xadd <xoffset>
        yadd <yoffset>
        zadd <zoffset>
        angadd <angoffset>
            Use these offsets to fine-tune the location of the model placement. <xoffset>,
            <yoffset>, and <zoffset> are offsets relative to the viewer's orientation.
            You can use floating point values with them. <angoffset> is a Build
            angle offset. (512 = 90 degrees, 1024 = 180 degrees, etc...).

        hide
            Some weapons use multiple ART tiles for constructing the gun or animation.
            Use this option to hide parts that you don't need in your replacement.

        nobob
            By default, the HUD model offset is affected by the player bobbing offset
            when the player is walking. Use this option to disable that.

        flipped
            Use this option to apply the settings inside the hud block only if the object
            is normally rendered x-flipped (mirror image). Some weapons, such as the
            devastator, are rendered in 2 pieces, the left devastator is actually a
            mirror image of the right.

        nodepth
            Use this to render a HUD model without the use of the depth buffer. Normally,
            you should avoid this. The one exception where this is useful is for the
            spinning nuke menu pointer because it should always be in front - and it just
            happens to be convex ... which is the one case that is safe with the depth
            buffer disabled ... a rather fortunate coincidence :)

Here are some HUD examples:

        // A pistol model that was posted a long time ago...
        model "models/m9.md2"
        {
            scale 50 shade 4
            anim { frame0 "idle1" frame1 "idle12" fps 5 flags 0 }
            frame { frame "idle1" tile 2524 }
            anim { frame0 "frame13" frame1 "frame45" fps 24 flags 0 }
            frame { frame "frame13" tile0 2525 tile1 2526 }
            anim { frame0 "reload1" frame1 "reload34" fps 24 flags 0 }
            frame { frame "reload1" tile0 2528 tile1 2529 }

            hud { tile0 2524 tile1 2529 xadd -1.2 yadd -1.0 zadd -1.0 angadd 1536 }

            frame { frame "reload1" tile0 2530 tile1 2532 } //consume tiles with dummy frames
            hud { tile0 2530 tile1 2532 hide } //Make it not draw 2D hands during reload
        }

        // A devastator weapon model that was posted a long time ago...
        model "models/hud_devastator.md2"
        {
            scale 12
            skin { pal 0 file "models/hud_devastator.pcx" }
            frame { frame "Frame 1" tile0 2510 tile1 2511 }
            hud { tile0 2510 tile1 2511 xadd -8.5 yadd +1.83 zadd +10.0 angadd 1024 flipped } //left devastator
            hud { tile0 2510 tile1 2511 xadd +8.5 yadd +5.90 zadd +10.0 angadd 1024 } //right devastator
        }

        // fearpi's activated tripbomb (wall mine)
        model "models/a_tripbomb.md2"
        {
            scale 8
            anim { frame0 "frame1" frame1 "frame1" fps 1 flags 0 }
            frame { frame "frame1" tile 2566 }
            hud { tile 2566 yadd +0.35 zadd 1.2 angadd 1024 }
        }

        // spinning icon (by Killd a ton)
        model "models/spinnuke.md2"
        {
            scale 0.25 shade 0

            //when rendered as respawn timer:
            skin { pal 0 file "models/spinnuke.png" }
            anim { frame0 "spin00" frame1 "spin19" fps 17 flags 0 }
            frame { frame "spin00" tile0 2813 tile1 2819 }
            frame { frame "spin00" tile0 3190 tile1 3196 }
            skin { pal 0 file "models/spinnukeyellow.png" }
            frame { frame "spin00" tile0 3200 tile1 3206 }
            skin { pal 0 file "models/spinnukegreen.png" }
            frame { frame "spin00" tile0 3210 tile1 3216 }

            //when rendered as menu icon:
            hud { tile0 2813 tile1 2819 xadd 0.01 yadd -.02 zadd 1.05 nodepth }
        }

### voxel &lt;filename&gt;{ ... }

Defines a voxel to replace sprites in the game when running in 8-bit classic
rendering mode. _filename_ is the name of the .KVX file containing the voxel.

The brace-enclosed block may contain these instructions:

    tile <tilenum>
        Maps the single tile <tilenum> to be rendered as a voxel.

    tile0 <tilenum>
    tile1 <tilenum>
        These two instructions together define a range of tiles to be rendered as
        voxels. The <tile0> instruction should appear before the <tile1> instruction
        to define a correct range.

    scale <scale>
        <scale> is a (possibly fractional) value specifying a scaling factor for the
        voxel when it is rendered, e.g. 1.5 for one-and-a-half times as big.

### skybox{... }

Defines a skybox that overrides a parallaxing floor or ceiling in OpenGL Polymost rendering mode.

The brace-enclosed block may contain these instructions:

    tile <tilenum>
        Specifies the ART file tile to override.

    pal <palnum>
        Specifies the palette number the skybox should happen for.

    facename <filename>
        Defines a single face of the skybox where 'facename' may be any of these
        keywords appropriate for the face in question:

        Front   Right   Back   Left   Top      Bottom
        =================================================
        ft      rt      bk     lf     up       dn
        front   right   back   left   top      bottom
        forward                lt     ceiling  floor
                                      ceil     down

**NOTE**: All six faces are required to be specified.

### tint{ ... }

Defines a Hightile texture tint to simulate palette effects normally used on ART-file tiles.

The brace-enclosed block may contain these instructions:

    pal <palnum>
        The palette number the tint applies to.

    red <value>
    green <value>
    blue <value>
    r <value>
    g <value>
    b <value>
        Specifies a colour component value, in the range of 0 to 255. Unspecified
        components are assumed to be 255 and any out of range values are clamped to
        the maximum or minimum as appropriate.

    flags <flags-value>
        Specifies any special processing effects to use for the tint. The value of
        <flags-value> may be the sum of any of these values:

            1 – convert to greyscale.
            2 – invert colours.
