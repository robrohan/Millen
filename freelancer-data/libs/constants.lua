function protect(tbl)
  return setmetatable({}, {
      __index = tbl,
      __newindex = function(t, key, value)
          error("Attempt to change constant " ..
                 tostring(key) .. " to " .. tostring(value), 2)
      end
  })
end

cstat = {
  -- bit 0: 1 = Blocking sprite (use with clipmove, getzrange)
  BLOCKING              = 1,
  -- bit 1: 1 = transluscence, 0 = normal
  TRANSLUSCENCE         = 2,
  -- bit 2: 1 = x-flipped, 0 = normal
  XFLIPPED              = 4,
  -- bit 3: 1 = y-flipped, 0 = normal
  YFLIPPED              = 8,
  --[[
  bits 5-4: --- 00 = FACE sprite (default)
            --- 01 = WALL sprite (like masked walls)
            --- 10 = FLOOR sprite (parallel to ceilings&floors)
  --]]
  -- bit 6: 1 = 1-sided sprite, 0 = normal
  ONE_SIDED             = 64,
  -- bit 7: 1 = Real centered centering, 0 = foot center
  CENTERED              = 128,
  -- bit 8: 1 = Blocking sprite (use with hitscan / cliptype 1)
  BLOCKING_HITSCAN      = 265,
  -- bit 9: 1 = Transluscence reversing, 0 = normal
  TRANSLUSCENCE_REVERSE = 512,
  --[[
    bits 10-14: reserved
  --]]
  -- bit 15: 1 = Invisible sprite, 0 = not invisible
  INVISIBLE             = 32768
}
cstat = protect(cstat)

sectorLow = {
  NORMAL = 0,             -- Normal sector
  FIRE_HIGH_ONCE = 1,     -- If you are on a sector with this tag, then all sectors
                          --    with same hi tag as this are operated.  Once.
  FIRE_HIGHT_REP = 2,     -- Same as sector[?].tag = 1 but this is retriggable.
  -- sector[?].lotag = 3   A really stupid sector that really does nothing now.
  CLOSE_TO_FLOOR = 4,     -- A sector where you are put closer to the floor
                          --   (such as the slime in DOOM1.DAT)
  -- sector[?].lotag = 5   A really stupid sector that really does nothing now.
  DOOR_UP = 6,            -- A normal door
  DOOR_DOWN = 7,          -- A door the goes down to open.
  DOOR_HORIZ_MID = 8,     -- A door that opens horizontally in the middle.
  DOOR_VERT_MID = 9,      -- A sliding door that opens vertically in the middle.
  WARP_SECTOR = 10,       -- A warping sector with floor and walls that shade.
  WALLS_X_PAN = 11,       -- A sector with all walls that do X-panning.
  WALLS_DRAG = 12,        -- A sector with walls using the dragging function.
  SWINGING_DOORS = 13,    -- A sector with some swinging doors in it.
  REVOLVE_DOORS = 14,     -- A revolving door sector.
  SUBWAY_TRACK = 15,      -- A subway track.
  DOUBLE_SLIDE_DOOR = 16  -- A true double-sliding door.
}
sectorLow = protect(sectorLow)

wallLow = {
  NORMAL = 0,            -- Normal wall
  Y_PANNDING = 1,        -- Y-panning wall
  SWITCH = 2,            -- Switch - If you flip it, then all sectors with same hi
                         --   tag as this are operated.
  STARTING_DIR = 3,      --  Marked wall to determine starting dir. (sector tag 12)
  SWING_PIVOT = 4,       -- Mark on the shorter wall closest to the pivot point
                         --    of a swinging door. (sector tag 13)
  SUBWAY_STOP = 5,       -- Mark where a subway should stop. (sector tag 15)
  DOUBLE_SLIDE_DOOR = 6, -- Mark for true double-sliding doors (sector tag 16)
  WATER_FOUNTAIN = 7,    -- Water fountain
  BOUNCY_WALL = 8,       -- Bouncy wall!
}
wallLow = protect(wallLow)

spriteLow = {
  NORMAL = 0,           -- Normal sprite
  EVIL = 1,             -- If you press space bar on an AL, and the AL is tagged
                        --   with a 1, he will turn evil.
  SHOOT_BOMB = 2,       -- When this sprite is operated, a bomb is shot at its
                        --   position.
  ROTATING_SPRITE = 3,  -- Rotating sprite.
  SWITCH = 4,           -- Sprite switch.
  HOOP_SCORE = 5,       -- Basketball hoop score.
}
spriteLow = protect(spriteLow)