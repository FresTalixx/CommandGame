# House Explorer / CommandGame 🎮

**House Explorer** is a console-based, text + simple-graphics adventure game, implemented in C++.  
Explore rooms in a mysterious house, find keys, pick up items (like a flashlight), unlock doors, and try to find the exit — if you have the wits, map sense, and keys!

---

## 🔧 Features

- Navigate rooms using arrow keys (north/east/south/west).  
- Pick up items with **T**.  
- Toggle a flashlight on/off with **F** (if you have one).  
- View a simple ASCII-style map showing your current room.  
- Inventory system: see what items you currently hold.  
- Locked rooms and keys: you’ll need to find the right key to unlock certain doors.  
- Hidden and visible items: explore thoroughly to find hidden treasures or tools.  
- A basic “escape the house” win condition — find the exit with the correct key, and you win!

---

## 🚀 How to run / Play

1. Build the project (uses C++, console).  
2. Run the resulting executable.  
3. On start — read the welcome message and press any key to begin.  
4. Once in the game:  
   - Use **arrow keys** to move between rooms.  
   - Press **T** to take items in the current room.  
   - Press **F** to toggle flashlight (if you have it).  
   - Press **Q** to quit the game at any time.  
5. Explore, collect keys and items, unlock rooms, find the exit, and escape.  

---

## 🧠 Game Design / Structure Overview

- **Player** — tracks the player state, current room, inventory, and possible actions.  
- **Room** — each room has a name, description, a list of exits (to other rooms), and can optionally be locked with a required key.  
- **Item** — base class for items in the game (e.g. keys, flashlight). Items can be visible or hidden.  
- **Flashlight / Key** — concrete item types. Keys allow unlocking locked rooms; flashlight helps with visibility (or just flavor).  
- **Actions** — e.g. `ActionGo`, `ActionTake`, `ActionToggleFlashlight`. Player can perform these actions depending on context.  
- **MapRenderer** — draws a simple map of the current room layout + your current position (rudimentary).  
- Game loop handles input (_getch), updates state, draws state, and checks for win or quit.  

---

## 🧩 How to Extend / Customize

You can easily expand the game world or features:

- Add more rooms, link/unlink exits to create a bigger or more complex house.  
- Add more item types (e.g. weapons, notes, puzzles).  
- Add puzzles or locked chests (not just locked doors).  
- Add more actions (e.g. “Use”, “Inspect”, “Drop”, “Combine”).  
- Improve map rendering or even replace with a graphical view (if you move beyond console).  
- Add enemies or time-based events for more challenge.  

---

## 🎯 Intended Audience & Use-Case

This project is ideal if you want:

- A simple, text/console adventure game — fun to extend and experiment with.  
- A lightweight C++ project to learn about object-oriented design, game loops, state management, and console I/O.  
- A demo / starting point for building more complex “escape-room” or narrative games.  

---

## 📝 License & Credits

This is a personal / hobby project. Feel free to use it for learning or educational purposes.  
If you decide to publish or share extended versions, please credit the original code.  

---

Happy spelunking inside the house — may your flashlight not flicker out mid-corridor. 😉  
