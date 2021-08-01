# MAN-JUMPING-FROM-OBSTACLES

List of Materials:
-16X2 LCD
-BUSH BUTTON
-MINI BREADBOARD
-220 OHM RESISTANCE
-ARDUNIO UNO

Code Description
The button is pressed to start the game, so the button value changes from 0 to 1 and the game starts and is displayed on the LCD. I created 2 characters to make the running man, and I made the position "position%2" to show "PlayerRun1[]" and "PlayerRun2[]" appear on the lcd screen, respectively. The man with the running effect has to jump over an obstacle whose mouth opens and closes by pressing the button. Each button press after the game starts takes a value of 1 and thus shows "Playerjump[]" while jumping. With "obsSpeed = obsSpeed-15" the game speeds up every time you overcome the obstacles. I also provide the movement of the obstacles with the class "YuvarlakHareketi(int i)". The "i" here determines the position on the screen, and the "position% 2" , showing "Yuvarlak1[]" and "Yuvarlak2[]" respectively. The man with the running effect increases the score by 1 point when he crosses the obstacles. When the obstacles are hit, the score result and "Yuvarlak1[]" and "Playerjump[]" are shown on the screen and the game is over, the button value becomes 0.



