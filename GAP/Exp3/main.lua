
--create a display
local value= -1
local angle = 0
local width1 = 100
local height1 = 100
player = {}
function love.load()
  rect = {
    x = 50,
    y = 200,
    width = 100,
    height = 100,
    dragging = { active = false, diffX = 0, diffY = 0 }
  }
   rect1 = {
    x = 200,
    y = 200,
    width = 50,
    height = 50,
    dragging = { active = false, diffX = 0, diffY = 0 }
  }
  love.graphics.setBackgroundColor(0,125,125)
  img=love.graphics.newImage("pikachu.jpg");
end
function love.draw()
	love.graphics.print('Click on pikachu to invoke controls',10, 10)
	love.graphics.print('1 Blue for rotation',200, 30)
	love.graphics.print('2 White for dragging',200, 50)
	love.graphics.rectangle("fill", rect.x, rect.y, rect.width, rect.height)
	--love.graphics.rectangle("fill", rect1.x, rect1.y, rect1.width, rect1.height)
	love.graphics.translate(100,100)
	love.graphics.rotate(angle)
	love.graphics.translate(-100,-100)
	love.graphics.draw(img,rect1.x,rect1.y,0,1,1,0,0)
-- draw a blue rectangle
	love.graphics.setColor(0,0,225)
	love.graphics.rectangle('fill', 50,50, width1, height1)
	love.graphics.setColor(255,255,255)
end

function love.mousepressed(x, y, button)
  if button == "l"
  and x > rect.x and x < rect.x + rect.width
  and y > rect.y and y < rect.y + rect.height and value > 0
  then
    rect.dragging.active = true
    rect.dragging.diffX = x - rect.x
    rect.dragging.diffY = y - rect.y
  elseif button =="l"
  and x > rect1.x and x < rect1.x + rect1.width
  and y > rect1.y and y < rect1.y + rect1.height and value < 0
  then
	value=1
	rect1.x=700
	rect1.y=700
  end
end
function love.update(dt)
  if rect.dragging.active then
    rect.x = love.mouse.getX() - rect.dragging.diffX
    rect.y = love.mouse.getY() - rect.dragging.diffY
  end
  if love.keyboard.isDown('d') and value>0 then
	angle = angle + math.pi * dt
--- else if we press the 'a' key, rotate to the left
  elseif love.keyboard.isDown('a') and value>0 then
	angle = angle - math.pi * dt
	end
end

function love.mousereleased(x, y, button)
  if button == "l" then rect.dragging.active = false end
end