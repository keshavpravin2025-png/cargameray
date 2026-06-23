# 🏎️ Retro Arcade Car Game

An infinite scrolling 2D arcade driving game built from scratch using **C++** and **Raylib**. All pixel art assets were custom-designed using **LibreSprite**.

---

## 🚀 Features Implemented So Far
* **Infinite Scrolling Track:** Implemented seamless vertical texture wrapping (`TEXTURE_WRAP_REPEAT`).
* **Custom Pixel Art:** Designed a 16x16 red sports car sprite and tiled road textures.
* **Arcade Handling:** Programmed responsive keyboard controls with simulated visual skid mark trails.
* **Collision Detection:** Formulated AABB boundary limits for left and right road shoulders with solid resolution handling.
* **Game Loop & State:** Programmed a central state engine supporting frozen Game Over overlays and live restarts (`R` key).

---

## 🛠️ Tech Stack & Tools
* **Language:** C++17
* **Framework:** Raylib
* **Art Assets:** LibreSprite (Portable Edition)

---

## 📸 Media / Screenshots
*(Tip: You can drag and drop screenshots of your running game window directly into this section while editing on GitHub!)*

---

## 📈 Learning Progress & Log
* **June 2026:** Initialized project window, loaded textures, and fixed basic loop function errors (`WindowShouldClose()`).
* **June 2026:** Solved texture scaling issues using `DrawTexturePro` vs `DrawTextureEx` and implemented road boundary hard-stopping physics.
