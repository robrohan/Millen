require 'libs/constants'

-- 512 = 90deg
math.randomseed(os.time())

--[[
              -z
               |
               |
          x ---+
              /
             /
            y
--]]
last_ang = 0
initial_x = -512
function draw(dt, time)
  local  last_ang = last_ang
  local newx = 0;

  local sidx = 1
  local sprite = sq.get_sprite(sidx)
  
  -- for k, v in pairs(sprite) do
  --   print(k, type(v), sprite[k])
  -- end

  -- sprite.picnum = 49
  sprite.ang = math.floor(last_ang)

  -- if _G.initial_x == -512 then
  --   _G.initial_x = sprite.x
  -- end

  local initial_x = _G.initial_x
  local end_x = _G.initial_x + 1024

  if sprite.x <= end_x then
    newx = sprite.x + 4
  else
    newx = sprite.x
  end

  sprite.x = newx
  local err = sq.set_sprite(sidx, sprite)

  _G.last_ang = last_ang + 16
  if _G.last_ang >= 2048 then
    _G.last_ang = 0
  end

  ----------------------------------
  -- Looping over sprites by status
  local status_num = 0
  local idx = sq.index_status(status_num)
  while idx ~= -1 do
    local sprite = sq.get_sprite(idx)

    -- print(sprite.picnum .. " :: " 
    --   .. (sprite.cstat & cstat.BLOCKING_HITSCAN) .. " :: " 
    --   .. (sprite.cstat & cstat.BLOCKING) .. " :: " 
    --   .. (sprite.cstat & cstat.TRANSLUSCENCE))

    idx = sq.next_status(idx)
  end
  -- print("---------------")
  ----------------------------------

  ----------------------------------
  -- Looping over sprites by sector
  local sector_num = 0
  local idx = sq.index_sector(sector_num)
  while idx ~= -1 do
    local sprite = sq.get_sprite(idx)
    sprite.lotag = spriteLow.ROTATING_SPRITE

    -- print(sprite.picnum .. " :: " 
    --   .. (sprite.cstat & cstat.BLOCKING_HITSCAN) .. " :: " 
    --   .. (sprite.cstat & cstat.BLOCKING) .. " :: " 
    --   .. (sprite.cstat & cstat.TRANSLUSCENCE))

    sq.set_sprite(idx, sprite)
    idx = sq.next_sector(idx)
  end
  -- print("---------------")
  ----------------------------------

  -- local pid = sq.get_player()
  -- print(pid)
  -- local spr = sq.get_sprite(pid)
  -- print(spr.picnum)

  -- Loading a new map
  -- if time > 1000 then
  --   sq.load_map("kensig.map")
  -- end

end

function main()

    local sidx = 1
    local sprite = sq.get_sprite(sidx)
    _G.initial_x = sprite.x

    print("---> " .. sq.map_name())
    -- sq.log("-----> hello")

  -- local sidx = 1
  -- local sprite = sq.get_sprite(sidx)

  -- for k, v in pairs(sprite) do
  --   print(k, type(v), sprite[k])
  -- end

  -- print("before: " .. sprite.picnum);
  -- sprite.picnum = math.random(23);
  -- print("after: " .. sprite.picnum);

  -- local err = sq.set_sprite(sidx, sprite)
  -- if err then
  --   print "set sprite error"
  -- end

  -- local s = array()
  -- print(getmetatable(s))
  -- print(s.get(1))

  -- print(type(s))
  -- for k, v in pairs(getmetatable(s)) do
  --   print(k, type(v)) -- btw it crashes if the value of v is being printed out.
  -- end
  -- print(s.get(1));

  -----------------------------------------
  -- local status = 1 -- this is set in the level editor
  -- local i = sprite_status_index(status)
  -- while i != -1 do
  --   local sprite = get_sprite(i)

  --   --- do stuff
  --   print(#sprite)

  --   local worked = set_sprite(i, sprite)
  --   if not worked then
  --     error("Sould not update sprite: " .. i)
  --   end

  --   i = next_sprite_status_index(i)
  -- end
  -----------------------------------------

  -----------------------------------------
  -- local sector = 10 -- this can be gotten from the level editor
  -- local si = sprite_sector_index(sector)
  -- while si != -1 do
  --   local sprite = get_sprite(si)

  --   --- do stuff
  --   print(#sprite)

  --   local worked = set_sprite(si, sprite)
  --   if not worked then
  --     error("Sould not update sprite: " .. i)
  --   end

  --   si = next_sprite_sector_index(si)
  -- end
  -----------------------------------------

  -- // insertsprite(short sectnum, short statnum);
  -- // deletesprite(short spritenum);
  -- // changespritesect(short spritenum, short newsectnum);
  -- // changespritestat(short spritenum, short newstatnum);
  -- // hitscan
  -- // cansee
  -- // spawnsprite
  -- // wsayfollow
  -- // wasy
  -- // rotatepoint

  --- warp sector

  -- void shootgun(short snum, int x, int y, int z, short daang, int dahoriz, short dasectnum, unsigned char guntype)
  --   daang2 = ((daang + (krand() & 31) - 16) & 2047);
  --   daz2 = ((100 - dahoriz) * 2000) + ((krand() - 32768) >> 1);
  --   hitscan(x, y, z, dasectnum,              // Start position
  --           sintable[(daang2 + 512) & 2047], // X vector of 3D ang
  --           sintable[daang2 & 2047],         // Y vector of 3D ang
  --           daz2,                            // Z vector of 3D ang
  --           &hitsect, &hitwall, &hitsprite, &hitx, &hity, &hitz, CLIPMASK1);
  -- // hitobject = movesprite((short)i, dax, day, daz, 4L << 8, 4L << 8, CLIPMASK1);
  -- // sprite[hitobject & 4095].picnum
  -- // sprite[hitobject & 4095].lotag
end
