
math.randomseed(os.time())
-- 512 = 90deg
last_ang = 0
initial_x = -512
function draw(dt, time)
  local  last_ang = last_ang
  local newx = 0;

  local sidx = 1
  local sprite = sq.get_sprite(sidx)
  -- sprite.picnum = 49
  sprite.ang = math.floor(last_ang)

  local initial_x = _G.initial_x
  local end_x = _G.initial_x + 1024

  if sprite.x <= end_x then
    newx = sprite.x + 3
  else
    newx = sprite.x
  end

  sprite.x = newx
  local err = sq.set_sprite(sidx, sprite)

  _G.last_ang = last_ang + 1
  if _G.last_ang >= 2048 then
    _G.last_ang = 0
  end
end

function main()
    local sidx = 1
    local sprite = sq.get_sprite(sidx)
    _G.initial_x = sprite.x
end
