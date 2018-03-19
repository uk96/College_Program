local imageFile
local frame={}
local activeframe 
local currentframe=1
local val=0;
local var=0;
local inc=50;
local x=0;
local y=100;
function love.load()
	love.graphics.setBackgroundColor(255,255,255)
	imageFile = love.graphics.newImage("sprite.jpg")
	for i=1,4 do
		frame[i]=love.graphics.newQuad(5,((i-1)*153.50),600,153.50, imageFile:getDimensions())
		activeframe=frame[currentframe]
	end
	img=love.graphics.newImage("grass.jpg");
	tree=love.graphics.newImage("tree.jpg");
end

function love.draw()
	love.graphics.draw(img,0,450,0,1,1,0,0)
	love.graphics.draw(img,300,450,0,1,1,0,0)
	love.graphics.draw(tree,var-100,351,0,1,1,0,0)
	love.graphics.draw(tree,(var+180)%650-50,351,0,1,1,0,0)
	--love.graphics.draw(tree,(var+360)%650-50,351,0,1,1,0,0)
	love.graphics.draw(tree,(var+440)%650-50,351,0,1,1,0,0)
	love.graphics.draw(imageFile, activeframe,x,y)
end

local elapsedTime=0
function love.update(dt)
	elapsedTime = elapsedTime + dt
	if (elapsedTime > (1-(inc/100))) then
		if(currentframe < 4) then
			if(var<650) then
				var=var+inc
			else	
				var=0
			end
			currentframe=currentframe+1
		else
			currentframe=1
			var=var+inc
		end
		activeframe=frame[currentframe]
		elapsedTime=0
	end
	--if love.keyboard.isDown('d') and inc > 10 then
	--	inc=inc-5
	--elseif love.keyboard.isDown('a') and inc < 90 then
	--	inc=inc+5
	--end	
	
	if love.keyboard.isDown('a') and x > -400 then
		if inc<90 then
			if inc < 75 then
				inc=inc+0.7
			else
				inc=inc+0.7
			end
		end
		x=x-5
	elseif love.keyboard.isDown('d') and x < 400 then
		x=x+5
		if inc > 10 then
			if inc > 15 then
				inc=inc-0.7
			else	
				inc=inc-0.7
			end
		end
	end
	if love.keyboard.isDown('w') and y > -70 then
		y=y-5
	elseif love.keyboard.isDown('s') and y < 200 then
		y=y+5	
	end	
	
end