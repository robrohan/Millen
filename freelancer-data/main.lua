
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

-- 512 = 90deg
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

  sprite.picnum = 49
  sprite.ang = math.floor(last_ang)

  -- if _G.initial_x == -512 then
  --   _G.initial_x = sprite.x
  -- end

  local initial_x = _G.initial_x
  local end_x = _G.initial_x + 1024
  -- print("--> " .. initial_x)

  if sprite.x <= end_x then
    newx = sprite.x + 4
  else
    newx = sprite.x
  end

  -- print(newx .. ":" .. _G.inital_x)
  sprite.x = newx
  local err = sq.set_sprite(sidx, sprite)

  _G.last_ang = last_ang + 16
  if _G.last_ang >= 2048 then
    _G.last_ang = 0
  end
end

function main()

    local sidx = 1
    local sprite = sq.get_sprite(sidx)
    _G.initial_x = sprite.x

  -- print("-----> hello")
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
end
